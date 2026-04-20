import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

// ENUMS
enum BookState {
    AVAILABLE, BORROWED
}

// BOOK
class Book {
    String title;
    String author;
    String isbn;
    int year;
    volatile BookState state;

    Book(String title, String author, String isbn, int year) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.year = year;
        this.state = BookState.AVAILABLE;
    }

    public synchronized boolean borrow() {
        if (state == BookState.AVAILABLE) {
            state = BookState.BORROWED;
            return true;
        }
        return false;
    }

    public synchronized void returnBook() {
        state = BookState.AVAILABLE;
    }
}

// MEMBER
class Member {
    String name;
    String memberId;
    String contact;
    List<Book> borrowedBooks = new ArrayList<>();

    Member(String name, String id, String contact) {
        this.name = name;
        this.memberId = id;
        this.contact = contact;
    }
}

// STRATEGY: BORROW RULE
interface BorrowingStrategy {
    boolean canBorrow(Member member);
}

// SIMPLE RULE
class DefaultBorrowingStrategy implements BorrowingStrategy {
    private final int maxBooks;

    DefaultBorrowingStrategy(int maxBooks) {
        this.maxBooks = maxBooks;
    }

    @Override
    public boolean canBorrow(Member member) {
        return member.borrowedBooks.size() < maxBooks;
    }
}

// LIBRARY (SINGLETON)
class Library {
    private static Library instance;

    Map<String, Book> books = new ConcurrentHashMap<>();
    Map<String, Member> members = new ConcurrentHashMap<>();

    BorrowingStrategy strategy;

    private Library() {
        strategy = new DefaultBorrowingStrategy(3);
    }

    public static synchronized Library getInstance() {
        if (instance == null) instance = new Library();
        return instance;
    }

    // BOOK MANAGEMENT
    public void addBook(Book book) {
        books.put(book.isbn, book);
    }

    public void removeBook(String isbn) {
        books.remove(isbn);
    }

    public void updateBook(Book book) {
        books.put(book.isbn, book);
    }

    // MEMBER MANAGEMENT
    public void addMember(Member member) {
        members.put(member.memberId, member);
    }

    // BORROW
    public boolean borrowBook(String memberId, String isbn) {
        Member m = members.get(memberId);
        Book b = books.get(isbn);

        if (m == null || b == null) return false;

        synchronized (b) {
            if (!strategy.canBorrow(m)) {
                System.out.println("Limit reached");
                return false;
            }

            if (b.borrow()) {
                m.borrowedBooks.add(b);
                return true;
            }
        }
        return false;
    }

    // RETURN
    public void returnBook(String memberId, String isbn) {
        Member m = members.get(memberId);
        Book b = books.get(isbn);

        if (m == null || b == null) return;

        synchronized (b) {
            b.returnBook();
            m.borrowedBooks.remove(b);
        }
    }
}

// MAIN
public class LibrarySystem {
    public static void main(String[] args) {
        Library lib = Library.getInstance();

        Book b1 = new Book("Java", "James", "111", 2020);
        Book b2 = new Book("DSA", "CLRS", "222", 2015);

        lib.addBook(b1);
        lib.addBook(b2);

        Member m1 = new Member("Aditya", "M1", "999");
        lib.addMember(m1);

        lib.borrowBook("M1", "111");
        lib.borrowBook("M1", "222");

        lib.returnBook("M1", "111");
    }
}