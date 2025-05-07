#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        minHeap.push(x);
    }

    cout << "Minimum element: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Next min: " << (minHeap.empty() ? -1 : minHeap.top()) << endl;

    return 0;
}
