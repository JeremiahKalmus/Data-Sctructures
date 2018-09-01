//Jeremiah Kalmus
//Lab 2
//

#include <iostream>
#include <ctime> 

using namespace std;

int main()
{
  int num;
  int amount;
  unsigned seed = time(0);
  srand(seed);
  
  //Part 1: Asking the user for a value and storing it in the regular
  //        variable.
  
  cout << "Please enter a whole number: " << endl;
  cin >> num;
  cout << endl;
  
  //Part 2: Having the pointer variable point to 'num'.
  int *ptr;
  ptr = &num;
  
  
  //Part 3: Having both 'num' and 'ptr' print the values and the addresses
  //        they have associated with them by calling a function.
  
  cout << "The value of the regular variable is: " << num << endl;
  cout << "The address in which the regular variable is located is: "
       << &num << endl;
  cout << "The value of the pointer variable is: " << *ptr << endl;
  cout << "The address in which the pointer variable is pointing to, is: "
       << ptr << endl << endl;
  
  //Part 4: Using the pointer variable to allocate memory for a single
  //        value.
  
  ptr = nullptr;
  ptr = new int;
  
  //Part 5: Store a chosen value into the newly allocated memory.
  
  *ptr = 9;
  
  //Part 6: Print same lines as part 3 but with the new value.
  cout << "The value of the regular variable is: " << num << endl;
  cout << "The address of the regular variable is: " << &num << endl;
  cout << "The value of the pointer variable is: " << *ptr << endl;
  cout << "The address in which the pointer variable is pointing to, is: "
	   << ptr << endl << endl;
  
  //Part 7: Deallocating memory
  delete ptr;
  
  //Part 8: Asking the user to input a small number and allocating that
  //		much space in a dynamically allocated array. 
  
  cout << "Please enter a whole number between 1 and 9: " << endl;
  cin >> amount; 
  cout << endl;		
  
  ptr = new int[amount];
  
  //Part 9: Store random values in the dynamically allocated array.
  for (int i = 0; i < amount; i++) 
    ptr[i] = rand() % 100;
  
  //Part 10: Print all elements in the array.
  cout << "[";
  for (int i = 0; i < amount - 1; i++) 
    cout << ptr[i] << " ";

  cout << ptr[(amount - 1)] << "]" << endl;
      
  
  //Part 11: Deallocate the memory in the array.
  delete[]ptr;
  
  return 0;
}

