//Jeremiah Kalmus
//p1.cpp
//Driver file using a stack class to determine whether phrases are palindromes.

#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"

using namespace std;

const string READFILE = "/home/fac/sreeder/class/cs2430/p1input.dat";

int main()
{
  Stack pStack;     //Creating a stack object to test if a string is a
                    //palindrome or not.
  
  string lineEdit; 	//Manipulate the original 'line' string to remove 
					//punctuation and spaces and stores it in a new string.
  
  char val;         //Holds the values of pushed and popped characters.
  
  int count;        //Counter to index through lineEdit and compare it
                    //to characters being popped off of the stack.
  
  
  ifstream input;
  string line;
  
  //open the file
  input.open(READFILE);
  
  //check that it is open/readable
  if(input.fail()){
    cout << endl << "Sorry, file not available...exiting program...press enter"
         << endl;
    cin.get();      //Grabs the enter;
    return 0;
  }
  
  //reads the line of data as long as there is another line to read
  //and puts it into a string called "line".
  while(getline(input, line)){
    lineEdit = line;   //lineEdit grabs line so it can remove punctuation.
    count = 0;  //Resets counter to zero to index lineEdit from the beginning
    
    
    //Changes all uppercase characters to lowecase characters.
    for (unsigned int i = 0;i < lineEdit.size();i++){
      
      lineEdit[i] = tolower(lineEdit[i]);
      
      //removes all spaces and punctuation.
      if (!isalnum(lineEdit[i])){
        lineEdit.erase(i--, 1); 
      }
    }
    //ensures the stack is empty when it is time to push a new line
    //to the stack.
	while(!pStack.isEmpty()){
      pStack.pop(val);
	}
    //loops through and pushes values to the stack.
    for (unsigned int i = 0;i < lineEdit.size();i++){
      val = lineEdit[i];
      pStack.push(val);
	}
    
    //Pops a value and compares the last value popped off of the
    //stack to the first index of lineEdit. The popping is
    //comparing the line backwards and lineEdit is comparing it
    //forwards to see if the lines are indeed equivalent.
    pStack.pop(val);
    
    while(!pStack.isEmpty() && (val == (lineEdit[count]))){
      
      count = count + 1;
      pStack.pop(val);
    }
    
    //Outputs whether the line is a palindrome or not.
	if(pStack.isEmpty())
      cout << endl << line << endl << "is a palindrome." << endl;
	
	else
      cout << endl << line << endl << "is NOT a palindrome." << endl;
    
  }
  
  
  //close file
  input.close();
  
  return 0;
}
