/*
We are writing software to collect and manage data on how fast racers can complete obstacle courses. An obstacle course is a series of difficult physical challenges (like walls, hurdles, and ponds) that a racer must go through.

Each course consists of multiple obstacles. The software stores how long it takes for racers to finish each obstacle, and provides useful statistics based on those times.

Definitions:
* A "run" is a particular attempt to complete an entire obstacle course
* A "run collection" is a group of runs on a particular course by the user.
* An "obstacle" is a portion of a course. We track how long it takes to finish each portion of the course

For example, here are some times for an obstacle course with four obstacles:

 Obstacles:    O1  O2  O3  O4
    Run 1:      3   4   5   6    (total: 18 seconds)
    Run 2:      4   4   4   5    (total: 17 seconds)
    Run 3:      4   5   4   6    (total: 19 seconds)
    Run 4:      5   5   3        (13 seconds, but run is incomplete)

All of these runs for one obstacle course (including the incomplete run) make up a run collection.

To begin with, we present you with two tasks:
1-1) Read through and understand the code below. Please take as much time as necessary, and feel free to run the code.
1-2) The test for RunCollection is not passing due to a bug in the code. Make the necessary changes to RunCollection to fix the bug.
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cassert>

/* Data about a particular course. */

/*
  course( count ), 


  Run{
    
    list< int > A ;  

  }


*/


class Course {
public:
  std::string title; // The name of the obstacle course
  int obstacleCount; // The number of obstacles in the course
  
  Course(const std::string& courseTitle, int obstacles) {
    title = courseTitle;
    obstacleCount = obstacles;
  }
  
  bool operator==(const Course& other) const {
    return title == other.title && obstacleCount == other.obstacleCount;
  }
  
  size_t hashCode() const {
    return (title.empty() ? 0 : std::hash<std::string>()(title)) * obstacleCount;
  }
};

/* Data and methods about a single run of the obstacle course */
class Run {
public:
  Course course; // The Course object this run is for
  bool complete; // true if the run is a full run of the course
                 // false if the run is in progress or was aborted
  std::vector<int> obstacleTimes; // The times it took to complete each obstacle
  
  Run(const Course& runCourse) : course(runCourse) {
    complete = false;
  }
  
  void addObstacleTime(int obstacleTime) {
    // When an obstacle is completed, add the time to the current run.
    // Params:
    //   obstacleTime: the time in seconds it took to complete the obstacle
    if (complete) {
      throw std::runtime_error("Cannot add obstacle to complete run");
    }
    obstacleTimes.push_back(obstacleTime);
    if ((int)obstacleTimes.size() == course.obstacleCount) {
      complete = true;
    }
  }
  
  int getRunTime() const {
    // Returns the total time this run has taken.
    // If the run is not complete, it returns the time taken so far.
    int totalTime = 0;
    for (int time : obstacleTimes) {
      totalTime += time;
    }
    return totalTime;
  }
};

class RunCollection {
public:
  Course course; // the Course this RunCollection is for
  std::vector<Run> runs; // the Run objects for this particular course
  
  RunCollection(const Course& collectionCourse) : course(collectionCourse) {
    // course = collectionCourse;
  }

  int getNumRuns() const {
    // Returns the number of runs in this collection
    return runs.size();
  }
  
  void addRun(const Run& run) {
    // Adds a run to this collection
    if (!(run.course == course)) {
      throw std::invalid_argument("run's Course is not the same as the RunCollection's");
    }
    runs.push_back(run);
  }
  
  int personalBest() const {
    // Returns the best finish time achieved in this RunCollection
    int bestTime = std::numeric_limits<int>::max();
    for (const Run& run : runs) {
      bestTime = std::min(bestTime, run.getRunTime());
    }
    return bestTime;
  }
};

// This is not a complete test suite, but tests some basic functionality of the above code, and
// shows some examples of using the code.
void testRun() {
  std::cout << "Running testRun" << std::endl;
  Course testCourse("Test course", 2);
  Run testRun(testCourse);
  testRun.addObstacleTime(3);
  assert(!testRun.complete && "Test run should not be complete");
  testRun.addObstacleTime(5);
  assert(testRun.complete && "Test run should be complete");
  std::vector<int> expectedObstacleTimes = {3, 5};
  assert(testRun.obstacleTimes == expectedObstacleTimes && "obstacleTimes should be [3, 5]");
  assert(testRun.getRunTime() == 8 && "getRunTime should return 8");
  try {
    testRun.addObstacleTime(4);
    assert(false);
  } catch (const std::exception& e) {
    // expected
  }
}

RunCollection makeRunCollection(const Course& course, const std::vector<std::vector<int>>& obstacleData) {
  // Create a new RunCollection for test purposes.
  // Params:
  //   course: the Course object this RunCollection is for
  //   obstacleData: a vector of int vectors. Each vector represents obstacle times for a single
  //                 run of the course.
  RunCollection runCollection(course);
  for (const std::vector<int>& runData : obstacleData) {
    Run run(course);
    for (int obstacleTime : runData) {
      run.addObstacleTime(obstacleTime);
    }
    runCollection.addRun(run);
  }
  return runCollection;
}

void testRunCollection() {
  // Tests basic RunCollection functionality
    
  //    Obstacles: O1  O2  O3  O4
  //    Run 1:      3   4   5   6    (total: 18 seconds)
  //    Run 2:      4   4   4   5    (total: 17 seconds)
  //    Run 3:      4   5   4   6    (total: 19 seconds)
  //    Run 4:      5   5   3        (13 seconds, but run is incomplete)
  std::cout << "Running testRunCollection" << std::endl;
  std::vector<std::vector<int>> obstacleData = {{3, 4, 5, 6},
                                                {4, 4, 4, 5},
                                                {4, 5, 4, 6},
                                                {5, 5, 3}};
  Course testCourse("Test course", 4);
  RunCollection runCollection = makeRunCollection(testCourse, obstacleData);

  int numRuns = obstacleData.size();
  assert(runCollection.getNumRuns() == numRuns && "Number of runs should be 3");
  assert(runCollection.personalBest() == 17 && "personalBest should be 17");
}

int main() {
  testRun();
  testRunCollection();
  return 0;
}