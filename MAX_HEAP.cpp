#include <iostream>
using namespace std;

class Maxheap{
  public:
  int arr[100];
  int size;
  
  Maxheap(){
    size=0;
    arr[0]=-1;
  }
  
// index of parent = (index of left child)/2 or index of parent = (index of right child)/2
// index of left child = 2*index of left child
// index of right child = 2*index of right child + 1
  
  void insert(int val){
      size++;
      int index=size;
      arr[index]=val;
      
      while(index>1){
          int parent=index/2;
          
          if(arr[parent]<arr[index]){
              swap(arr[parent],arr[index]);
              index=parent;// shifts the index upwards to the top
          }
          
          else{
              return;
          }
      }
  }
  
void Delete() {
  if (size == 0) {
    cout << "Heap empty" << endl;
    return;
  }

  // Step 1: Move the last element to the root
  arr[1] = arr[size];

  // Step 2: Decrement size
  size--;

  // Step 3: Sift down the element at the root to its correct position
  int i = 1;
  while (i < size) {
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    // Find the larger child (if it exists)
    int largerChild = leftChild;
    if (rightChild < size && arr[rightChild] > arr[leftChild]) {
      largerChild = rightChild;
    }

    // If the current node is smaller than its larger child, swap them
    if (largerChild < size && arr[i] < arr[largerChild]) {
      swap(arr[i], arr[largerChild]);
      i = largerChild;
    } 
    else{
      break; // No further swapping needed, element is in its correct position
    }
  }
}
  
  void printMAxHeap(){
      for(int i=1;i<=size;i++){
          cout<<arr[i]<<"\t";
      }
      cout<<"\n";
  }
  
  void heapify(int arr[],int size, int index){
      int largest = index;
      int leftChild=2*index;
      int rightChild=2*index + 1;
      
      if(leftChild<size && arr[largest]<arr[leftChild]){
          largest=leftChild;
      }
      if(rightChild<size && arr[largest]<arr[rightChild]){
          largest=rightChild;
      }
      
      if(arr[largest]!=arr[index]){
          swap(arr[largest],arr[index]);
          heapify(arr,size,largest);
      }
  }
  
};

int main()
{
    Maxheap MH;
    MH.insert(20);
    MH.insert(50);
    MH.insert(77);
    MH.insert(15);
    MH.insert(11);
    MH.insert(63);
    MH.insert(9);
    MH.insert(40);
    
    MH.printMAxHeap();
    
    MH.Delete();
    MH.printMAxHeap();
    
    
    
    int arr[5]={-1,-3,4,0,9};
    int n=5;
    for(int i=n/2;i>0;i--){
        MH.heapify(arr,n,i);
    }
    
    cout<<"After heapify-\n";
    
    for(int i=1;i<5;i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}
