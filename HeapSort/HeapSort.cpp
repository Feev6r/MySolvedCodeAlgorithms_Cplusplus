#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    std::vector<int> heap;

    void siftUp(int i) {

        int parent = (i - 1) / 2;

        while (i != 0 && heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void siftDown(int i) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        while ((left < heap.size() && heap[i] > heap[left]) || (right < heap.size() && heap[i] > heap[right])) {
           
            int smallest = (right >= heap.size() || heap[left] < heap[right]) ? left : right;

            swap(heap[i], heap[smallest]);
            
            i = smallest;

            left = 2 * i + 1;
            right = 2 * i + 2;
        }
    }

public:
    MinHeap(const vector<int>& arr = {}) {

        heap = arr;
        
        for (int i = heap.size() - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    void insert(int element) {

        heap.push_back(element);
        siftUp(heap.size() - 1);
    }

    int getMin() {
        return heap.empty() ? -1 : heap[0];  // Assuming -1 represents None
    }

    int extractMin() {

        if (heap.empty()) return -1;  // Assuming -1 represents None

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        siftDown(0);
        return minVal;
    }

    void updateByIndex(int i, int newVal) {
        int oldVal = heap[i];

        heap[i] = newVal;
        if (newVal < oldVal) {
            siftUp(i);
        }
        else {
            siftDown(i);
        }
    }

    void update(int oldVal, int newVal) {

        auto it = find(heap.begin(), heap.end(), oldVal);

        if (it != heap.end()) {

            int index = it - heap.begin();
            updateByIndex(index, newVal);
        }
    }
};

class MaxHeap {
private:
    std::vector<int> heap;

    void siftUp(int i) {
        int parent = (i - 1) / 2;
        while (i != 0 && heap[i] > heap[parent]) {
            std::swap(heap[i], heap[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void siftDown(int i) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        while ((left < heap.size() && heap[i] < heap[left]) || (right < heap.size() && heap[i] < heap[right])) {

            int largest = (right >= heap.size() || heap[left] > heap[right]) ? left : right;
            std::swap(heap[i], heap[largest]);
            i = largest;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
    }

public:
    MaxHeap(const std::vector<int>& arr = {}) {
        heap = arr;
        for (int i = heap.size() - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    void insert(int element) {
        heap.push_back(element);
        siftUp(heap.size() - 1);
    }

    int getMax() {
        return heap.empty() ? -1 : heap[0];  // Assuming -1 represents None
    }

    int extractMax() {
        if (heap.empty()) return -1;  // Assuming -1 represents None
      
        int maxVal = heap[0];
       
        heap[0] = heap.back();
        heap.pop_back();
       
        siftDown(0);
        return maxVal;
    }

    void updateByIndex(int i, int newVal) {
        int oldVal = heap[i];
        heap[i] = newVal;
        if (newVal > oldVal) {
            siftUp(i);
        }
        else {
            siftDown(i);
        }
    }

    void update(int oldVal, int newVal) {
        auto it = find(heap.begin(), heap.end(), oldVal);
        if (it != heap.end()) {
            int index = it - heap.begin();
            updateByIndex(index, newVal);
        }
    }
};

vector<int> heapsort(vector<int>& arr) {

    MinHeap heap(arr);  
    vector<int> sortedArr;
    
    while (heap.getMin() == -1) {
    
        sortedArr.push_back(heap.extractMin());
    }
    return sortedArr;
}

class PriorityQueue {
private:
    MaxHeap queue;

public:
    void enqueue(int element) {
        queue.insert(element);
    }

    int peek() { 
        return queue.getMax();
    }

    int dequeue() { 
        return queue.extractMax();
    }

    bool isEmpty() {
        return queue.getMax() == -1;
    }

    void changePriorityByIndex(int i, int newVal) {
        queue.updateByIndex(i, newVal);
    }

    void changePriority(int oldVal, int newVal) {
        queue.update(oldVal, newVal);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

