#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

// --- The Solution Function ---
int solution(int N, vector<int> &A, vector<int> &B) {
    // If there are no nodes, 0 seconds.
    if (N == 0) return 0;

    // 1. Build the graph and calculate initial degrees
    vector<vector<int>> adj(N);
    vector<int> degree(N, 0);

    for (size_t i = 0; i < A.size(); ++i) {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
        degree[A[i]]++;
        degree[B[i]]++;
    }

    // 2. Initialize the queue with all vertices that have degree <= 1
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (degree[i] <= 1) {
            q.push(i);
        }
    }

    int seconds = 0;
    
    // We also track how many nodes we have "removed" to handle cases where 
    // the queue might process nodes but technically the remaining graph is stable immediately.
    // However, the problem asks for the number of seconds the PROCESS continues.
    // If the queue is non-empty, a "second" of disappearance is occurring.

    while (!q.empty()) {
        int current_batch_size = q.size();
        
        // If we are entering the loop, it means vertices are disappearing this second.
        seconds++;
        
        // Process all nodes that disappear in this specific second (simultaneous removal)
        while (current_batch_size--) {
            int u = q.front();
            q.pop();

            // "Remove" u by decrementing neighbors' degrees
            for (int v : adj[u]) {
                // If degree is already <= 0, this neighbor was already removed or processed.
                // We only care about neighbors currently in the graph.
                if (degree[v] > 0) {
                    degree[v]--;

                    // If a neighbor's degree drops to exactly 1, it becomes vulnerable 
                    // for the NEXT second. We use == 1 to ensure we only add it once.
                    if (degree[v] == 1) {
                        q.push(v);
                    }
                }
            }
            // Mark u as removed (optional, effectively done by not processing it again)
            degree[u] = 0; 
        }
    }

    return seconds;
}

// --- Helper function to run tests neatly ---
void run_test(int id, int N, vector<int> A, vector<int> B, int expected) {
    cout << "Test Case " << id << ": ";
    int result = solution(N, A, B);
    
    if (result == expected) {
        cout << "[PASS] Result: " << result << endl;
    } else {
        cout << "[FAIL] Expected: " << expected << ", Got: " << result << endl;
    }
}

// --- Main Function ---
int main() {
    // Example 1: N=7, Returns 2
    // A specific graph structure described in the problem (Image 2)
    run_test(1, 7, {0, 1, 2, 1, 4, 4}, {1, 2, 0, 4, 5, 6}, 2);

    // Example 2: N=7, Returns 2
    // A graph with a triangle (0-1-2) and a tail ending in isolated nodes
    // Vertices 3, 5, 6 disappear first. Then 4 disappears. 0,1,2 remain.
    run_test(2, 7, {0, 1, 2, 4, 5}, {1, 2, 3, 5, 6}, 2);

    // Example 3: N=4, Returns 0
    // A square cycle (0-1-2-3-0). All degrees are 2. Nothing disappears.
    run_test(3, 4, {0, 1, 2, 3}, {1, 2, 3, 0}, 0);

    // Example 4: N=4, Returns 1
    // A triangle (0-1-2) and an isolated vertex 3. 
    // Vertex 3 disappears in 1st second. Triangle remains.
    run_test(4, 4, {0, 1, 2}, {1, 2, 0}, 1);

    // Extra Edge Case: Single line 0-1-2-3
    // Sec 1: 0 and 3 disappear (leaves 1-2).
    // Sec 2: 1 and 2 disappear (now degree 1 or 0).
    // Returns 2.
    run_test(5, 4, {0, 1, 2}, {1, 2, 3}, 2);

    // Extra Edge Case: Star graph (center 0, leaves 1,2,3,4)
    // Sec 1: Leaves 1,2,3,4 disappear.
    // Sec 2: Center 0 disappears (degree becomes 0).
    // Returns 2.
    run_test(6, 5, {0, 0, 0, 0}, {1, 2, 3, 4}, 2);

    return 0;
}