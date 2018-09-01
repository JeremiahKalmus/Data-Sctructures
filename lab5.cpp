//Jeremiah Kalmus
//Lab 5

#include <iostream>
#include <fstream>

using namespace std;

const string INPUTFILE = "/home/fac/sreeder/class/cs2430/countyPop.dat";
const int COL = 8;
const int PRINT_MAX = 10;
const int MAX = 3200;

struct Population
{
  int censusCount;
  string place;
};

void printFirstLast(const Population set[], int numRecords);
void mergeSort(Population set[], Population temp[], int first, int last);
void merge(Population set[], Population temp[], int leftPos, int rightPos,
           int rightEnd);

int main()
{
  int count = 0;
  ifstream inputFile;
  Population list[MAX];
  Population temp[MAX];
  
  inputFile.open(INPUTFILE);
  
  if(inputFile.fail()){
    cout << "File cannot open...exiting...";
    cin.get();
    return 0;
  }
  
  while(inputFile >> list[count].censusCount){
    getline(inputFile, list[count].place);
    count++;
  }
  cout << endl;
  cout << "Before sorting: " << endl;
  printFirstLast(list, count);
  mergeSort(list, temp, 0, count-1); 
  cout << "After sorting: " << endl;
  printFirstLast(list, count);
  
  inputFile.close();
  return 0;
}
void printFirstLast(const Population set[], int numRecords)
{
  cout << "First 10... " << endl;
  for(int i = 0;i < PRINT_MAX;i++){
    cout << set[i].censusCount << ", " << set[i].place << endl;
  }
  cout << endl << endl;
  cout << "Last 10..." << endl;
  for(int i = 0;i < PRINT_MAX;i++){
    cout << set[(numRecords - 10) + i].censusCount << ", "
         << set[(numRecords - 10) + i].place << endl;
  }
  cout << endl << endl;
}

void mergeSort(Population set[], Population temp[], int first, int last)
{
  if(first < last){
    int center = (first + last) / 2;
    mergeSort(set, temp, first, center);
    mergeSort(set, temp, center + 1, last);
    merge(set, temp, first, center + 1, last);
  }
}

void merge(Population set[], Population temp[], int leftPos, int rightPos,
           int rightEnd)
{
  int leftEnd = rightPos - 1;
  int tempPos = leftPos;
  int numElements = rightEnd - leftPos + 1;
  
  while(leftPos <= leftEnd && rightPos <= rightEnd){
    if(set[leftPos].censusCount <= set[rightPos].censusCount){
      temp[tempPos].censusCount = set[leftPos].censusCount;
      temp[tempPos].place = set[leftPos].place;
      leftPos++;
      tempPos++;
      
    }
	else{
      temp[tempPos].censusCount = set[rightPos].censusCount;
      temp[tempPos].place = set[rightPos].place;
      tempPos++;
      rightPos++;
	}
  }
  
  while(leftPos <= leftEnd){
    temp[tempPos].censusCount = set[leftPos].censusCount;
    temp[tempPos].place = set[leftPos].place;
    tempPos++;
    leftPos++;
  }
  
  while(rightPos <= rightEnd){
    temp[tempPos].censusCount = set[rightPos].censusCount;
    temp[tempPos].place = set[rightPos].place;
    tempPos++;
    rightPos++;
  }
  //copy temp back to set
  for(int i = 0;i < numElements; i++){
    set[rightEnd] = temp[rightEnd];
    rightEnd--;
  }
  
}

