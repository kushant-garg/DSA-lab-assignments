#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int top() {
        return heap[0];
    }

    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    void heapify(int i) {
        int n = heap.size();
        int largest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < n && heap[l] > heap[largest]) largest = l;
        if (r < n && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
};