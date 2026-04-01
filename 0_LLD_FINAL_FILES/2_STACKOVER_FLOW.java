/*
 * ======================================================
 *              STACK OVERFLOW SYSTEM (LLD)
 * ======================================================
 *
 * Lombok version using @Data, @Builder, @NoArgsConstructor,
 * and @AllArgsConstructor to reduce boilerplate.
 */

import lombok.*;
import java.time.LocalDateTime;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

// ======================================================
// ENUMS
// ======================================================

enum VoteType {
    UPVOTE, DOWNVOTE
}

// ======================================================
// INTERFACES
// ======================================================

interface Votable {
    void addVote(Vote v);
    int getVoteCount();
}

interface Commentable {
    void addComment(Comment c);
    List<Comment> getComments();
}

// ======================================================
// USER
// ======================================================

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
class User {
    @Builder.Default
    private String userId = UUID.randomUUID().toString();
    private String name;
    @Builder.Default
    private int reputation = 0;

    public void increaseReputation(int delta) { reputation += delta; }
    public void decreaseReputation(int delta) { reputation -= delta; }
}

// ======================================================
// TAG
// ======================================================

@Data
@NoArgsConstructor
@AllArgsConstructor
class Tag {
    @Builder.Default
    private String tagId = UUID.randomUUID().toString();
    private String name;

    public Tag(String name) {
        this.tagId = UUID.randomUUID().toString();
        this.name = name.toLowerCase();
    }
}

// ======================================================
// COMMENT
// ======================================================

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
class Comment {
    @Builder.Default
    private String commentId = UUID.randomUUID().toString();
    private String text;
    private User author;
    @Builder.Default
    private LocalDateTime createdAt = LocalDateTime.now();
}

// ======================================================
// VOTE
// ======================================================

@Data
@AllArgsConstructor
@NoArgsConstructor
class Vote {
    private VoteType type;
    private User voter;
}

// ======================================================
// ANSWER (implements Votable, Commentable)
// ======================================================

@Data
class Answer implements Votable, Commentable {
    @Builder.Default
    private String answerId = UUID.randomUUID().toString();
    private User author;
    private String content;
    @Builder.Default
    private LocalDateTime createdAt = LocalDateTime.now();
    @Builder.Default
    private List<Comment> comments = new ArrayList<>();
    @Builder.Default
    private List<Vote> votes = new ArrayList<>();

    public Answer(User author, String content) {
        this.author = author;
        this.content = content;
        this.createdAt = LocalDateTime.now();
    }

    @Override
    public void addComment(Comment c) { comments.add(c); }

    @Override
    public List<Comment> getComments() { return comments; }

    @Override
    public void addVote(Vote v) { votes.add(v); }

    @Override
    public int getVoteCount() {
        return (int) votes.stream().mapToInt(v -> v.getType() == VoteType.UPVOTE ? 1 : -1).sum();
    }
}

// ======================================================
// QUESTION (implements Votable, Commentable)
// ======================================================

@Data
class Question implements Votable, Commentable {
    @Builder.Default
    private String questionId = UUID.randomUUID().toString();
    private String title;
    private String description;
    private User author;
    @Builder.Default
    private LocalDateTime createdAt = LocalDateTime.now();
    @Builder.Default
    private List<Tag> tags = new ArrayList<>();
    @Builder.Default
    private List<Answer> answers = new ArrayList<>();
    @Builder.Default
    private List<Comment> comments = new ArrayList<>();
    @Builder.Default
    private List<Vote> votes = new ArrayList<>();

    public Question(String title, String description, User author, List<Tag> tags) {
        this.title = title;
        this.description = description;
        this.author = author;
        this.tags.addAll(tags);
    }

    public void addAnswer(Answer a) { answers.add(a); }

    @Override
    public void addComment(Comment c) { comments.add(c); }

    @Override
    public List<Comment> getComments() { return comments; }

    @Override
    public void addVote(Vote v) { votes.add(v); }

    @Override
    public int getVoteCount() {
        return (int) votes.stream().mapToInt(v -> v.getType() == VoteType.UPVOTE ? 1 : -1).sum();
    }
}

// ======================================================
// REPUTATION SERVICE
// ======================================================

class ReputationService {
    private static final int UPVOTE_QUESTION_POINTS = 10;
    private static final int UPVOTE_ANSWER_POINTS = 20;
    private static final int DOWNVOTE_PENALTY = 5;

    public void processVote(VoteType type, User author, boolean isAnswer) {
        if (type == VoteType.UPVOTE)
            author.increaseReputation(isAnswer ? UPVOTE_ANSWER_POINTS : UPVOTE_QUESTION_POINTS);
        else
            author.decreaseReputation(DOWNVOTE_PENALTY);
    }
}

// ======================================================
// SEARCH SERVICE
// ======================================================

class SearchService {
    public List<Question> searchByKeyword(List<Question> questions, String keyword) {
        return questions.stream()
            .filter(q -> q.getTitle().toLowerCase().contains(keyword.toLowerCase())
                      || q.getDescription().toLowerCase().contains(keyword.toLowerCase()))
            .toList();
    }

    public List<Question> searchByTag(List<Question> questions, String tagName) {
        return questions.stream()
            .filter(q -> q.getTags().stream()
                    .anyMatch(t -> t.getName().equalsIgnoreCase(tagName)))
            .toList();
    }

    public List<Question> searchByUser(List<Question> questions, String userId) {
        return questions.stream()
            .filter(q -> q.getAuthor().getUserId().equals(userId))
            .toList();
    }
}

// ======================================================
// STACKOVERFLOW PLATFORM
// ======================================================

class StackOverflowPlatform {
    private final List<Question> allQuestions = Collections.synchronizedList(new ArrayList<>());
    private final ReputationService reputationService = new ReputationService();

    public Question postQuestion(User user, String title, String description, List<Tag> tags) {
        Question q = new Question(title, description, user, tags);
        allQuestions.add(q);
        System.out.println("Question posted: " + title);
        return q;
    }

    public Answer postAnswer(User user, Question question, String content) {
        Answer a = new Answer(user, content);
        question.addAnswer(a);
        System.out.println("Answer posted by " + user.getName());
        return a;
    }

    public void commentOn(Commentable item, User user, String text) {
        item.addComment(Comment.builder().text(text).author(user).build());
    }

    public void vote(Votable item, User voter, VoteType type, User author, boolean isAnswer) {
        item.addVote(new Vote(type, voter));
        reputationService.processVote(type, author, isAnswer);
    }

    public List<Question> getAllQuestions() { return allQuestions; }
}

// ======================================================
// MANAGEMENT SERVICE (Facade Layer)
// ======================================================

class StackOverflowManagementService {
    private final StackOverflowPlatform platform = new StackOverflowPlatform();
    private final SearchService searchService = new SearchService();

    public Question postQuestion(User user, String title, String description, List<Tag> tags) {
        return platform.postQuestion(user, title, description, tags);
    }

    public Answer postAnswer(User user, Question question, String content) {
        return platform.postAnswer(user, question, content);
    }

    public void voteOnQuestion(User voter, Question q, VoteType type) {
        platform.vote(q, voter, type, q.getAuthor(), false);
    }

    public void voteOnAnswer(User voter, Answer a, VoteType type) {
        platform.vote(a, voter, type, a.getAuthor(), true);
    }

    public void commentOnQuestion(User user, Question q, String text) {
        platform.commentOn(q, user, text);
    }

    public void commentOnAnswer(User user, Answer a, String text) {
        platform.commentOn(a, user, text);
    }

    public List<Question> searchByKeyword(String keyword) {
        return searchService.searchByKeyword(platform.getAllQuestions(), keyword);
    }

    public List<Question> searchByTag(String tag) {
        return searchService.searchByTag(platform.getAllQuestions(), tag);
    }

    public List<Question> searchByUser(User user) {
        return searchService.searchByUser(platform.getAllQuestions(), user.getUserId());
    }

    public List<Question> getAllQuestions() {
        return platform.getAllQuestions();
    }
}

// ======================================================
// DRIVER
// ======================================================

public class StackOverflowSystem {
    public static void main(String[] args) {
        StackOverflowManagementService service = new StackOverflowManagementService();

        User alice = User.builder().name("Alice").build();
        User bob = User.builder().name("Bob").build();

        Tag java = new Tag("Java");
        Tag lld = new Tag("LLD");

        Question q1 = service.postQuestion(alice, "What is SOLID?", "Can someone explain SOLID principles?", List.of(java, lld));
        Answer a1 = service.postAnswer(bob, q1, "SOLID stands for five design principles...");

        service.voteOnQuestion(bob, q1, VoteType.UPVOTE);
        service.voteOnAnswer(alice, a1, VoteType.UPVOTE);

        service.commentOnQuestion(bob, q1, "Good question!");
        service.commentOnAnswer(alice, a1, "Nice answer.");

        System.out.println("Reputation of Alice: " + alice.getReputation());
        System.out.println("Reputation of Bob: " + bob.getReputation());

        List<Question> results = service.searchByKeyword("SOLID");
        System.out.println("Search Results by keyword 'SOLID': " + results.size());
    }
}
