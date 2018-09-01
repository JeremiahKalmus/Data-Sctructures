//Jeremiah Kalmus
//stack.cpp
//Implementation file for the stack class

//Referencing header file.
#include "stack.h"

//Constructor
//Allows a stack object to be made when called. 
Stack::Stack(int stackSize)
{
  if(stackSize < MIN)
    size = 16;
  else
    size = stackSize;

  //allocate memory & set top
  list = new char[size];

  top = 0;
}

//Destructor that removes all allocated memory to a stack object.
Stack::~Stack()
{
  delete [] list;
}

//Overloaded assignment operator that allows objects to be
//compared to each other
Stack& Stack::operator=(const Stack& rhs)
{
  //copies the information to new top and size variables
  if(this != &rhs){
    top = rhs.top;
    size = rhs.size;

    //deletes the list information.
    delete [] list;

    //creates a new list.
    list = new char[size];

    //stores that list with the same information as rhs
    for(int i=0;i<top;i++)
      list[i]=rhs.list[i];
  }
  return *this;
}

//copy constructor copies the normal constructor.
Stack::Stack(const Stack& s)
{
  *this = s;
}

//Pushes value on the stack 
bool Stack::push(char data)
{
  if(full()){
	if(!resize()){
		return false;	
	  }
	 else{
		resize();
	  }
  }
  //top of list getting the data and moving the
  //top of the stack.
  list[top] = data;
  top++;
  return true; 
 }

//pops off of the stack
bool Stack::pop(char& data)
{
  if(isEmpty()){
    return false;
  }
  else{
    top--;
    data = list[top];
    return true;
  }
}

//checks the stack is empty
bool Stack::isEmpty()
{
  return top == 0;
}

//checks if stack is full
bool Stack::full()
{
  return top == size;
}

//resizes stack to 1.5 times the previous size.
bool Stack::resize()
{
  int tempSize = double(size) * 1.5;
  char* temp = new char[tempSize];

  //check if memory got requested?
  
  if(temp == nullptr)
	return false;
  
  for(int i = 0;i < size;i++){ //copy data
    temp[i] = list[i];
  }
  delete [] list;  //deallocate
  size = tempSize; //update
  list = temp;
  return true;
}
