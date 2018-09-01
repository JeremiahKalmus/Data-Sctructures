//Jeremiah Kalmus
//heap.cpp
//Implementation file for heap class

//using namespace std;

//Referencing header file
#include "heap.h"

//Constructor
Heap::Heap(int heapSize)
{
  if(heapSize < MIN)
    max = STARTSIZE;
  else{
    max = heapSize;
    heapArr = new int[max];
    
    curSize = 0;
  }
}

Heap::~Heap()
{
  delete [] heapArr;
}
Heap& Heap::operator=(const Heap& rhs)
{
  if(this != &rhs){
    curSize = rhs.curSize;
    max = rhs.max;
	
    //deletes the list heapArr information.
    delete [] heapArr;
	
    //creates a new list.
    heapArr = new int[max];
	
    //stores that list information as rhs.
    for(int i = 1;i <= curSize;i++)
      heapArr[i] =  rhs.heapArr[i];
  }
  return *this;
}
Heap::Heap(const Heap& h)
{
  heapArr = new int [MIN];
  *this = h;
}
void Heap::insert(int data)
{
  if(curSize == max){
	resize();
  }
  hole = curSize + 1;
  while(hole > 1 && data < heapArr[hole/2]){
    heapArr[hole] = heapArr[hole/2];
    hole = hole/2;
  }
  heapArr[hole] = data;
  curSize++;
  
}
int Heap::removeMin()
{
  int temp = heapArr[1];
  
  heapArr[1] = heapArr[curSize];
  curSize--;
  percDown(hole);
  return temp;
}
void Heap::flush(int data)
{	
  int spot = 1;
  while(spot <= curSize){
    if(heapArr[spot] == data){
      heapArr[spot] = heapArr[curSize];
      percDown(heapArr[spot]);
      curSize--;
    }
    else
      spot++;
  }
}
bool Heap::isEmpty()
{
  if(curSize == 0)
    return true;
  else
    return false;
}

//Private functions

bool Heap::resize()
{
  //Resizes heap to 1.5 times the previous size.
  int tempSize = double(max) * RESIZE;
  int* temp = new int [tempSize];
  
  if(temp == nullptr)
    return false;
  
  for(int i = 1;i <= curSize;i++) //copy data
    temp[i] = heapArr[i];
  
  delete [] heapArr; //deallocate
  max = tempSize; //update
  heapArr = temp;
  return true;
}
void Heap::percDown(int hole)
{
  hole = 1;
  int temp = heapArr[hole];
  
  while((hole*2 <= curSize && heapArr[hole*2] < temp)
        || (hole*2+1 <= curSize && heapArr[hole*2+1] < temp)){
    if(hole*2+1 <= curSize && heapArr[hole*2+1] < heapArr[hole*2]){
      heapArr[hole] = heapArr[hole*2+1];
      hole = hole*2+1;
    }else{
      heapArr[hole] = heapArr[hole*2];
      hole = hole*2;
    }
  }
  heapArr[hole] = temp;
}

