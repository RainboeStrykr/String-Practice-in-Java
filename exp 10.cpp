#include <iostream>
#include <climits>
using namespace std;

const int MAX = 20;

int n;
int cost[MAX][MAX];
bool visited[MAX];
int minCost = INT_MAX;
int bestPath[MAX];

// Function to copy current path to best path
void copyPath(int currPath[]) {
    for (int i = 0; i < n; i++)
        bestPath[i] = currPath[i];
}

// Backtracking function
void tsp(int currCity, int count, int currCost, int currPath[]) {

    // If all cities are visited and return edge exists
    if (count == n && cost[currCity][0] > 0) {
        int totalCost = currCost + cost[currCity][0];

        if (totalCost < minCost) {
            minCost = totalCost;
            copyPath(currPath);
        }
        return;
    }

    // Try all cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[currCity][i] > 0) {

            visited[i] = true;
            currPath[count] = i;

            tsp(i, count + 1, currCost + cost[currCity][i], currPath);

            visited[i] = false; // Backtrack
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int currPath[MAX];
    visited[0] = true; // Start from city 0
    currPath[0] = 0;

    tsp(0, 1, 0, currPath);

    if (minCost == INT_MAX) {
        cout << "No feasible tour exists.\n";
    } else {
        cout << "\nOptimal Tour: ";
        for (int i = 0; i < n; i++)
            cout << bestPath[i] << " -> ";
        cout << "0";

        cout << "\nMinimum Cost: " << minCost << endl;
    }

    return 0;
}
