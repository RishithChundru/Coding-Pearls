#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapifyDown(int i) {
        int size = heap.size();
        int largest = i, left = 2*i + 1, right = 2*i + 2;

        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    void print() {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    MaxHeap h;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        h.insert(x);
    }

    cout << "Max Heap: ";
    h.print();
    cout << "Extracted max: " << h.extractMax() << endl;
    cout << "After extraction: ";
    h.print();
    return 0;
}
