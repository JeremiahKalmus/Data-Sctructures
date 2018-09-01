//Jeremiah Kalmus
//heap.h
//header file that provides heap operations.

#ifndef HEAP_H
#define HEAP_H

//Creation of the heap
//This will be a minHeap
class Heap
{
  //prublic initializations that are open to being called
  //from the driver.
 public:
  explicit Heap(int heapSize = STARTSIZE);
  //Constructor
  
  ~Heap();
  //Destructor
  
  Heap& operator=(const Heap& rhs);
  //Overloaded assignment operator
  
  Heap(const Heap& h);
  //Copy constructor
  
  void insert(int data);
  //Insert a value into the minHeap
  //Pre: Has a heap object created to hold values
  //Post: Values will be entered into the heap.
  //duplicates okay.
  
  int removeMin();
  //Remove the root of the whole tree (smallest value)
  //Pre: Has a functional heap that is properly ordered.
  //Post: Eliminates the minimum value from the heap and 
  //reduces the size of the heap by one.
  
  void flush(int data);
  //Removes all instances of a key value from the minHeap
  //Pre: Has a heap with values stored in it. 
  //Post: Takes a value and eliminates all instances of it 
  //from the heap.
  
  bool isEmpty();
  //Checks to see if the heap is empty.
  //Pre: A heap object must be created.
  //Post: Checks to see if the heap is empty.
  
 private:
  static const int STARTSIZE = 11;
  const double RESIZE = 1.5;
  static const int MIN = 3;
  int* heapArr;		//dynamic heap array
  int hole;
  int max; 			//Max size of the actual array
  //int data;
  int curSize;		//How many elements fill the current
  //array
  bool resize();
  //Pre: A heap exists.
  //Post: Enlargens the heap to be 1.5 times the original size.
  
  void percDown(int hole);
  //Pre: Heap must exist and values must be entered in the heap.
  //Post: Values are compared with the ones below it and swapped 
  //so the heap is ordered correctly.
  
  
};
#endif
