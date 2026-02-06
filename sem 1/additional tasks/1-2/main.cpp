#include <iostream>
#include <climits> 

using namespace std;

int main() {
    int Q1, P1, Q2, P2, A;
    cin >> Q1 >> P1 >> Q2 >> P2 >> A;

    int minCost = INT_MAX;
 
    for (int x = 0; x <= (A + Q1 - 1) / Q1; x++) {
        int carried = x * Q1;
        int remaining = A - carried;
        if (remaining < 0) remaining = 0;

       
        int y = (remaining + Q2 - 1) / Q2; 
        int cost = x * P1 + y * P2;

        if (cost < minCost) {
            minCost = cost;
        }
    }

    cout << minCost << endl;
    return 0;
}
