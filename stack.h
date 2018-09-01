//Jeremiah Kalmus
//stack.h
//header file that provides standard stack operations for the character type.

#ifndef STACK_H
#define STACK_H

//Creation of the stack
class Stack
{
  //public initializations that are open to being called from the driver file.
 public:
  explicit Stack(int stackSize = 16); //constructor
  ~Stack();                           //destructor 
  Stack& operator=(const Stack& rhs); //overloaded assignment operator
  Stack(const Stack& s);              //copy constructor
  bool push(char data);               //push value onto a the stack.
  bool pop(char& data);               //pop value off of a stack.
  bool isEmpty();                     //Checks to see if stack is empty.

  //private initializations of members that can only be used within the scope
  //of .h and .cpp files.
 private:
  const int MIN = 2;
  bool full();                        //Checks to see if stack is full.
  bool resize();                      //resizes if stack is full
  int top;                            //checks to see top value of stack.
  char *list;                         //Holds the characters to be pushed
                                      //on stack.
  int size;  
};
#endif
