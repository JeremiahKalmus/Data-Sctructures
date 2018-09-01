//Jeremiah Kalmus
//P4 Driver file

#include "heap.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	Heap h1; //Making a heap object
	//constructor tested
	
	srand(time(0));
	int hArr [20];
	const int ARRSIZE = 20;
	int flushVal = 0;
	
	cout << endl;
    cout << "Hello and welcome to the p4 program." << endl << endl
	     << "This program will create a min heap and input "
         << "at least 20 values." << endl << "The default max "
		 << "size of the heap is 10 values so if all 20 values "
		 << endl << "are successfully entered, then the resise "
		 << "function is working correctly." << endl;
  
    cout << "I will now input the values into a min heap " << endl
         << "and output the entries to the screen." << endl 
         << endl << endl;
		 
	//Creating random values and storing them
	//in an array to be later inserted in the heap.
	for(int i = 0; i < ARRSIZE; i++){
		hArr[i] = rand() % ARRSIZE; 
	}
	
	flushVal = hArr[ARRSIZE/2];
	
	 //Entering values into the heap
	 cout << "Inserting: " << endl;
  for(int i = 0;i < ARRSIZE;i++){
      h1.insert(hArr[i]);
      cout << hArr[i] << " ";
    }
	
	 cout << endl << endl << "I will now test the copy constructor and "
       << "the overloaded assignment operator." << endl << "The copy "
       << "constructor will make a copy of the first heap object "
       << endl << "then I will add a value to only one of the two "
       << "heaps. Here I will test " << endl << "the overloaded "
       << "assignment operator and assign one heap the values of "
       << "the " << endl << "other heap resulting in both heaps having "
       << "the same values in the end." << endl << endl;
	   
	   cout << "In addition to this, the remove will be tested while "
			<< "printing the values " << endl << "in order by using "
			<< "the isEmpty() function. " << endl << endl;
	   
	Heap h2(h1); //Calls and tests copy constructor
	Heap h3, h4;	 //Declares another object
	h3 = h2;	 //Assigns the values from h2 to h3
	h4 = h3;
	h1.insert(99); //Inserting random value to test 
				   //for aliasing.
	
	cout << "Deleting: " << endl;
	cout << "h1: " << endl;
	
    while(!h1.isEmpty()){
    cout << h1.removeMin() << " ";
  }
    cout << endl << endl;
	cout << "h2: " << endl;
	
	while(!h2.isEmpty()){
    cout << h2.removeMin() << " ";
  }
    cout << endl << endl;
	cout << "h3: " << endl;
	
	while(!h3.isEmpty()){
    cout << h3.removeMin() << " ";
  }
    cout << endl << endl;
	
	cout << "Now I will flush a value from the heap and then remove "
		 << "the " << endl << "remaining values to show what remains. " 
		 << endl << endl;
	
	cout << "Flushing the value " << flushVal << " from h4."
		 << endl;
	
	h4.flush(flushVal);
	while(!h4.isEmpty()){
    cout << h4.removeMin() << " ";
  }
    cout << endl << endl;
	
	return 0;
}