//Jeremiah Kalmus
//Lab 4

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool insert(int h[], int value, int& size);

int removeMin(int h[], int& size);

void percolateDown(int h[], int hole, int size);

const int MAXSIZE = 25;
const int NUMCAP = 50;
const int ARRSIZE = 21;
const int TWICE = 2;

int main()
{
  srand(time(0));
  int inputArrOne[ARRSIZE];
  int hArr[MAXSIZE];
  int curSize = 0;
  int val = 0;
  int maxSize = 0;
  
  
  
for(int i = 0;i < TWICE;i++){
	  cout << endl << "Values inserted into the heap: " 
       << endl;
  for(int i = 1;i <= ARRSIZE;i++){
	val = rand() % NUMCAP;
    inputArrOne[i] = val;
    cout << inputArrOne[i] << " ";
  }
  cout << endl << endl << "Contents of the heap: " << endl;  

  for(int i = 1;i <= ARRSIZE;i++){
    insert(hArr,inputArrOne[i],curSize);
  }
  for (int i = 1; i <= curSize; i++)
    cout << hArr[i] << " ";
  cout << endl << endl;  
  maxSize = curSize;
  cout << "Values emptied from the heap: " << endl;
  for(int i = 0; i < maxSize;i++){
    cout << removeMin(hArr,curSize) << " ";
  }

  cout << endl << endl;
  cout << "---------------------------------------"
	   << "-------------------" << endl;
}
  return 0;
}
bool insert(int h[], int value, int& size)
{
  if(size == MAXSIZE)
    return false;

  int hole = size + 1;
  while(hole > 1 && value < h[hole/2]){
    h[hole] = h[hole/2];
    hole = hole/2;
    }
  h[hole] = value;
  size++;
  return true;
}
int removeMin(int h[], int& size)
{
  int temp = h[1];
  
  h[1] = h[size];
  size--;
  percolateDown(h, 1, size);
  return temp;

}
void percolateDown(int h[], int hole, int size)
{
  int temp = h[hole];

  while((hole*2 <= size && h[hole*2] < temp)
        || (hole*2+1 <= size && h[hole*2+1] < temp)){
    if(hole*2+1 <= size && h[hole*2+1] < h[hole*2]){
      h[hole] = h[hole*2+1];
        hole = hole*2+1;
        }else{
        h[hole] = h[hole*2];
        hole = hole*2;
      }
    }
    h[hole] = temp;
}
