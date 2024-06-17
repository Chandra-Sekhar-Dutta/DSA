#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

void insertheap(int array_name[], int& size, int value) 
{
    size++;
    array_name[size] = value;
    int i = size;

    while (i > 1) {
        int parent = i / 2;
        if (array_name[parent] < array_name[i]) {
            swap(array_name[parent], array_name[i]);
            i = parent;
        } else {
            return;
        }
    }
}

int main() 
{
    const int maxSize = 100; // Choose a maximum size for the array
    int heap[maxSize];
    int heapSize = 0;

    // Example usage
    insertheap(heap, heapSize, 10);
    insertheap(heap, heapSize, 5);
    insertheap(heap, heapSize, 15);
    insertheap(heap, heapSize, 3);
    insertheap(heap, heapSize, 3);
    //insertheap(heap, heapSize, 30);

    // Display the resulting heap
    cout << "Heap elements after insertion: ";
    for (int i = 1; i <= heapSize; i++) {
        cout << heap[i] << " ";
    }
    cout <<endl;

    return 0;
}

