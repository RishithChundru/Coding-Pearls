#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> pq;

pair<int, int> top() {
    return pq[0];
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < pq.size() && pq[left].first < pq[smallest].first)
        smallest = left;
    
    if (right < pq.size() && pq[right].first < pq[smallest].first)
        smallest = right;
    
    if (smallest != i) {
        swap(pq[i], pq[smallest]);
        heapify(smallest);
    }
}

void pop() {
    if (pq.empty()) return;
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();
    if (!pq.empty())
        heapify(0);
}

void push(pair<int, int> i) {
    pq.push_back(i);
    if (pq.size() == 1) return;
    
    int j = pq.size() - 1;
    while (j != 0) {
        int parent = (j - 1) / 2;
        if (pq[parent].first > pq[j].first) {
            swap(pq[parent], pq[j]);
            j = parent;
        } else {
            break;
        }
    }
}

int main() {
    push({3, 100});
    push({1, 200});
    push({2, 300});
    push({0, 400});

    cout << "Top element: (" << top().first << ", " << top().second << ")\n";

    pop();
    cout << "After pop, new top: (" << top().first << ", " << top().second << ")\n";

    return 0;
}
