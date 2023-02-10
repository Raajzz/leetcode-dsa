#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Heap{
  public:
  vector<int> heap_array;
  Heap(int size){
    heap_array.reserve(size);
  }
  // this returns the top/root of the heap
  int top(){
    return heap_array[0];
  }
  // this returns the top of the heap and removes the top of the heap
  int pop(){
    int top = heap_array[0];
    swap(heap_array[0], heap_array[heap_array.size()-1]);
    heap_array.resize(heap_array.size()-1);
    int index = 0;
    while((2*index+2) <= (heap_array.size() - 1)){
      int min_index = (heap_array[2*index + 1] < heap_array[2*index + 2])?(2*index + 1):(2*index + 2);
      if(heap_array[index] >= heap_array[min_index]){
        swap(heap_array[index], heap_array[min_index]);
      } else {
        break;
      }
      index = min_index;
    }
    if((2*index+2) > (heap_array.size() - 1) && (2*index+1) <= (heap_array.size() - 1)){
      if(heap_array[index] > heap_array[2*index + 1]){
        swap(heap_array[index], heap_array[2*index + 1]);
      }
    }
    return top;
  }

  // this function is used to push the element inside the heap
  void push(int element){
    heap_array.push_back(element);
    int index = heap_array.size() - 1;
    while(index > 0){
      if(heap_array[index] < heap_array[(index-1)/2]){
        swap(heap_array[index], heap_array[(index-1)/2]);
      }
      index = (index-1)/2;
    }
  }

};

int main(){
  Heap hp(10);

  hp.push(32);
  cout << hp.pop() << "\n";
  hp.push(30);
  hp.push(48);
  hp.push(13);
  cout << hp.pop() << "\n";
  hp.push(10);
  cout << hp.pop() << "\n";
  hp.push(8);
  hp.push(38);
  for(auto val : hp.heap_array){
    cout << val << " ";
  }

  return 0;
}

/**
 * The output for the above driver code is 
 * 32
 * 13
 * 10
 * 8  38  30  48
 */
