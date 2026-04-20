import java.util.*;
import java.util.stream.Collectors;
import java.time.LocalDateTime;

/*

Here’s the **clean, concise problem statement** — no noise, interview-ready:

---

## Problem: Design a Mini Jira System

Design a simplified issue tracking system similar to Jira.

### Functional Requirements

1. **Project Management**

   * Create a project with:

     * `projectId`, `name`, `description`

2. **Issue Management**

   * Each project can have multiple issues
   * Each issue contains:

     * `issueId`, `title`, `description`
     * `status`, `priority`
     * `assignee`, `reporter`
     * `createdAt`

3. **Status Workflow**

   * Supported statuses: `OPEN`, `IN_PROGRESS`, `RESOLVED`
   * Valid transitions:

     * OPEN → IN_PROGRESS → RESOLVED
   * No backward transitions

4. **User Management**

   * Users can create and be assigned issues
   * User fields:

     * `userId`, `name`, `email`

5. **Issue Operations**

   * Create issue in a project
   * Assign issue to a user
   * Change issue status
   * Update issue priority

6. **Search / Filter**

   * Retrieve issues:

     * By status
     * By assignee
     * By project

---

### Non-Functional Requirements

* In-memory implementation (no database)
* Clean, extensible OOP design

---

### Out of Scope

* Comments, attachments, notifications
* Subtasks, epics, permissions
* Persistence layer

---

### Expected Design

* Core classes: `User`, `Project`, `Issue`
* Enums: `Status`, `Priority`
* Services: `IssueService`, `ProjectService`
* Ensure:

  * Valid state transitions
  * Separation of concerns
  * Extensible design

---

This is tight enough to solve in ~30 minutes and still shows strong LLD fundamentals.


*/


/*
===========================================================
🧩 MINI JIRA LLD - COMPLETE SOLUTION (SINGLE FILE)
===========================================================

Features:
- Project management
- Issue creation & lifecycle
- Status transitions (controlled)
- Assignment
- Filtering using Strategy Pattern + Streams

Design Patterns Used:
- Strategy Pattern (for filtering)
- Encapsulation (status transitions inside enum)

===========================================================
*/


// ===========================================================
// 🔹 ENUMS
// ===========================================================

enum Status {
    OPEN,
    IN_PROGRESS,
    RESOLVED;

    // Encapsulate valid transitions
    public boolean canTransitionTo(Status next) {
        return switch (this) {
            case OPEN -> next == IN_PROGRESS;
            case IN_PROGRESS -> next == RESOLVED;
            case RESOLVED -> false;
        };
    }
}

enum Priority {
    LOW,
    MEDIUM,
    HIGH
}


// ===========================================================
// 👤 USER ENTITY
// ===========================================================

class User {
    private final String userId;
    private final String name;
    private final String email;

    public User(String userId, String name, String email) {
        this.userId = userId;
        this.name = name;
        this.email = email;
    }

    public String getUserId() { return userId; }
    public String getName() { return name; }
}


// ===========================================================
// 📁 PROJECT ENTITY
// ===========================================================

class Project {
    private final String projectId;
    private final String name;
    private final String description;

    // Each project contains issues
    private final List<Issue> issues = new ArrayList<>();

    public Project(String projectId, String name, String description) {
        this.projectId = projectId;
        this.name = name;
        this.description = description;
    }

    public void addIssue(Issue issue) {
        issues.add(issue);
    }

    public List<Issue> getIssues() {
        return issues;
    }

    public String getProjectId() {
        return projectId;
    }
}


// ===========================================================
// 🐞 ISSUE ENTITY (CORE BUSINESS OBJECT)
// ===========================================================

class Issue {
    private final String issueId;
    private String title;
    private String description;

    private Status status;
    private Priority priority;

    private User assignee;
    private final User reporter;

    private final LocalDateTime createdAt;

    public Issue(String issueId, String title, String description,
                 Priority priority, User reporter) {

        this.issueId = issueId;
        this.title = title;
        this.description = description;
        this.priority = priority;
        this.reporter = reporter;

        this.status = Status.OPEN;  // default state
        this.createdAt = LocalDateTime.now();
    }

    // Assign issue
    public void assign(User user) {
        this.assignee = user;
    }

    // Update priority
    public void updatePriority(Priority priority) {
        this.priority = priority;
    }

    // Controlled status transition
    public void changeStatus(Status newStatus) {
        if (!this.status.canTransitionTo(newStatus)) {
            throw new IllegalStateException(
                "Invalid transition: " + this.status + " -> " + newStatus
            );
        }
        this.status = newStatus;
    }

    // Getters
    public Status getStatus() { return status; }
    public User getAssignee() { return assignee; }
    public String getIssueId() { return issueId; }

    @Override
    public String toString() {
        return issueId + " [" + status + "] (" + priority + ")";
    }
}


// ===========================================================
// 🎯 STRATEGY PATTERN (FILTERING)
// ===========================================================

interface IssueFilterStrategy {
    List<Issue> filter(List<Issue> issues);
}


// Filter by Status
class StatusFilter implements IssueFilterStrategy {
    private final Status status;

    public StatusFilter(Status status) {
        this.status = status;
    }

    public List<Issue> filter(List<Issue> issues) {
        return issues.stream()
                .filter(i -> i.getStatus() == status)
                .collect(Collectors.toList());
    }
}


// Filter by Assignee
class AssigneeFilter implements IssueFilterStrategy {
    private final String userId;

    public AssigneeFilter(String userId) {
        this.userId = userId;
    }

    public List<Issue> filter(List<Issue> issues) {
        return issues.stream()
                .filter(i -> i.getAssignee() != null &&
                             i.getAssignee().getUserId().equals(userId))
                .collect(Collectors.toList());
    }
}


// ===========================================================
// ⚙️ ISSUE SERVICE (BUSINESS LOGIC)
// ===========================================================

class IssueService {

    // Acts like in-memory DB
    private final Map<String, Issue> issueMap = new HashMap<>();

    // Create Issue
    public Issue createIssue(String issueId, String title, String desc,
                             Priority priority, User reporter, Project project) {

        Issue issue = new Issue(issueId, title, desc, priority, reporter);
        issueMap.put(issueId, issue);
        project.addIssue(issue);

        return issue;
    }

    // Assign Issue
    public void assignIssue(String issueId, User user) {
        getIssue(issueId).assign(user);
    }

    // Change Status
    public void changeStatus(String issueId, Status status) {
        getIssue(issueId).changeStatus(status);
    }

    // Update Priority
    public void updatePriority(String issueId, Priority priority) {
        getIssue(issueId).updatePriority(priority);
    }

    // Apply filtering using Strategy
    public List<Issue> filterIssues(List<Issue> issues, IssueFilterStrategy strategy) {
        return strategy.filter(issues);
    }

    // Fetch all issues of project
    public List<Issue> getIssuesByProject(Project project) {
        return project.getIssues();
    }

    private Issue getIssue(String issueId) {
        if (!issueMap.containsKey(issueId)) {
            throw new RuntimeException("Issue not found");
        }
        return issueMap.get(issueId);
    }
}


// ===========================================================
// 📁 PROJECT SERVICE
// ===========================================================

class ProjectService {

    private final Map<String, Project> projectMap = new HashMap<>();

    public Project createProject(String id, String name, String desc) {
        Project p = new Project(id, name, desc);
        projectMap.put(id, p);
        return p;
    }

    public Project getProject(String id) {
        return projectMap.get(id);
    }
}


// ===========================================================
// 🚀 MAIN (DEMO / DRIVER CODE)
// ===========================================================

public class Main {
    public static void main(String[] args) {

        ProjectService projectService = new ProjectService();
        IssueService issueService = new IssueService();

        // Users
        User u1 = new User("U1", "Aditya", "a@mail.com");
        User u2 = new User("U2", "Dev", "d@mail.com");

        // Create Project
        Project project = projectService.createProject(
                "P1", "Jira Clone", "LLD Practice");

        // Create Issues
        issueService.createIssue("I1", "Fix Login", "Bug in auth",
                Priority.HIGH, u1, project);

        issueService.createIssue("I2", "Fix API", "Timeout issue",
                Priority.MEDIUM, u1, project);

        // Assign + Update
        issueService.assignIssue("I1", u2);
        issueService.changeStatus("I1", Status.IN_PROGRESS);

        // 🔥 Filtering using Strategy + Streams
        List<Issue> openIssues = issueService.filterIssues(
                project.getIssues(),
                new StatusFilter(Status.OPEN)
        );

        System.out.println("Open Issues: " + openIssues);

        List<Issue> assignedToU2 = issueService.filterIssues(
                project.getIssues(),
                new AssigneeFilter("U2")
        );

        System.out.println("Assigned to U2: " + assignedToU2);
    }
}