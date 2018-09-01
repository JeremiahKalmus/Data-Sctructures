//Jeremiah Kalmus
//P3 Driver File

#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
  Tree t1; 	//Making a tree object
  //Constructor Tested
  const int tArr [21] = {11,6,17,3,8,18,19,2,4,7,9,24,1,5,22,26,21, 
                         30,29,32,28};
  //Array of values to be entered into the tree
  const int ARRSIZE = 21;
  const int HALFARR = 11;
  const int MAXVAL = 100;
  const int TRUEVAL = 17;
  const int FALSEVAL = 31;
  const int LEAF = 5;
  const int ONECHILD = 8;
  const int TWOCHILDREN = 30;
  
  
  cout << endl;
  cout << "Hello and welcome to the p3 program." << endl << endl
       << "This program will create a binary search tree and input "
       << "at least 20 values." << endl;
  
  cout << "I will now input the values into a Binary Seach " << endl
       << "Tree and output the entries to the screen." << endl 
       << "To prove that the tree accepts no duplicates, I will "
       << "have each value input twice " << endl 
       << "into the tree." << endl << endl;
  
  //Entering values into the tree
  for(int i = 0;i < ARRSIZE;i++)
	{
      t1.insert(tArr[i]);
      t1.insert(tArr[i]);
      cout << tArr[i] << " ";
      cout << tArr[i] << " ";
      if(i == HALFARR)
        cout << endl;
	}
  cout << endl << endl << "I will now test the copy constructor and "
       << "the overloaded assignment operator." << endl << "The copy "
       << "constructor will make a copy of the first tree object "
       << endl << "then I will add a value to only one of the two "
       << "trees. Here I will test " << endl << "the overloaded "
       << "assignment operator and assign one tree the values of "
       << "the " << endl << "other tree resulting in both trees having "
       << "the same values in the end." << endl << endl;
  
  Tree t2(t1); //Calls and tests copy constructor
  t1.insert(MAXVAL); //inserts 100 into the t1 object
  
  cout << endl << "I will output and show that duplicates have "
       << "not been accepted into the tree " << endl << "using "
       << "both preorder and inorder traversals respectively. " 
       << endl << endl << "Testing the copy constructor. "
       << endl << endl << "Tree one: " << endl;
  
  //prints inorder and preorder for both tree 1 and tree 2	 
  t1.iterativeInOrder();
  cout << endl;
  t1.recPreOrder();
  cout << endl << endl << "Tree two: " << endl;
  t2.iterativeInOrder();
  cout << endl;
  t2.recPreOrder();
  cout << endl << endl << "Now testing the overloaded assignment " 
       << "operator. Assigning tree 1 to tree 2." << endl << endl;
  
  
  //prints inorder and preorder for both tree 1 and tree 2.
  t2 = t1; 
  cout << "Tree one: " << endl;
  t1.iterativeInOrder();
  cout << endl;
  t1.recPreOrder();
  cout << endl << endl << "Tree two: " << endl;
  t2.iterativeInOrder();
  cout << endl;
  t2.recPreOrder();
  
  cout << endl << endl << "Now I will test the search capabilities "
       << "and will search for a key in the tree " << endl << "and "
       << "return its boolean output, (1 or 0). Then, I will test "
       << "the same for " << endl << "a key not in the tree." << endl 
       << endl;
  cout << "Searching for 17 in the tree." << endl << t1.search(TRUEVAL)
       << endl << endl << "Searching for 31 in the tree " << endl
       << t1.search(FALSEVAL) << endl << endl;
  
  cout << "Now finding the min key in the first tree." << endl 
       << t1.findMin() << endl << endl << "Now finding the max "
       << "key in the first tree." << endl << t1.findMax() << endl 
       << endl;
  
  cout << "Now I will find the height of the tree. It should be 9 "
       << "levels tall." << endl << "Tree one has a height of " 
       << t1.height() << endl << endl;
  
  cout << "Finally, I will test the deletion of a single node at "
       << "a time. " << endl << "One for a leaf node, one for a "
       << "node with one child, and another for a " << endl 
       << "node with two children. I will then print in order so "
       << "it can be clearly " << endl << "seen that those values "
       << "have been deleted with the tree structure still intact."
       << endl << endl;
  
  
  cout << "Deleting a leaf: " << endl;
  t1.remove(LEAF);
  cout << "Deleting a node with one child: " << endl; 
  t1.remove(ONECHILD);
  cout << "Deleting a node with two children: " << endl;
  t1.remove(TWOCHILDREN);
  cout << endl << endl;
  t1.iterativeInOrder();
  cout << endl;
  t1.recPreOrder();
  
  cout << endl << endl << "program now exiting. Goodbye!" << endl
       << endl;
  return 0;
}
