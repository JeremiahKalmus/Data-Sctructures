//Jeremiah Kalmus
//P2.cpp

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

//function prototypes
void printList(Node* list, ostream& outs);
//prints data values to outs
//pre: none
//post: none

void insertNode(Node*& list, int d);
//inserts node in nondescending order by data
//pre: on first call, list is nullptr
//post: list is updated to contain d

void deleteNode(Node*& list, int d);
//deleted a node contatining d from list
//pre: none
//post: list is updated

void minNode(Node* list, int &val);
//compares nodes to find the smallest in the linked list.
//pre: Linked list is in numerical order.
//post: Stores in val the smallest value in the list.

void maxNode(Node* list, int &val);
//compares nodes to find the largest in the linked list.
//pre: Linked list is in numerical order.
//post: Stores in val the largest value in the list.

void middleNode(Node* list, int &val);
//compares nodes to find a middle value in the linked list.
//pre: Linked list is in numerical order.
//post: Stores in val a middle value from within the list.

const string OUTFILE1 = "P2OutputA.txt";
const string OUTFILE2 = "P2OutputB.txt";
const int MAX = 50;
const int MAXRAND = 100;
const int ZERO = 0;

int main()
{
  ofstream outfile;
  srand(time(0));
  int input = 0;
  int val = 0;
  Node* head = nullptr;
  Node* delPtr = nullptr;
  
  cout << "Welcome! This program will first create " << MAX
       << " values and insert them into a list." << endl 
	   << "The list will be in order from smallest to "
	   << "largest and insert the values into a " << endl
	   << "text file called P2OutputA.txt." << endl << endl;
  
  //create list nodes - at least 50
  for (int i = 0;i < MAX;i++){
    input = rand() % MAXRAND;
    insertNode(head, input);
  }
  
  outfile.open(OUTFILE1);
  printList(head, cout);
  printList(head, outfile);
  outfile.close();	
  
  cout << "Now the smallest, largest, and a middle value "
	   << "will be deleted from the list and stored in "
	   << "another file called P2OutputB.txt. " << endl 
	   << endl;
  
  //delete smallest
  minNode(head, val);
  deleteNode(head, val);
  
  //delete largest
  maxNode(head, val);
  deleteNode(head, val);
  
  //delete something in the middle
  middleNode(head, val);
  deleteNode(head, val);
  
  
  outfile.open(OUTFILE2);
  printList(head, cout);
  printList(head, outfile);
  outfile.close();
  
  cout << "Now, the list will be deleted. " << endl;
  
  // delete linked list
  while(head != nullptr){
    delPtr = head;
    head = head->next;
    delete delPtr; 
  } 
  
  return 0;
}
void printList(Node* list, ostream& outs)
{
  Node* temp = list;
  
  //Traverse and print.
  while(temp != nullptr){
    outs << temp->data << endl;
    temp = temp->next;
  }
  cout << endl;
}

void insertNode(Node*& list, int d)
{
  Node * newNode = new Node;
  Node * nodePtr;
  Node * prevPtr = nullptr;
  
  newNode->data = d;
  
  //If list is empty, create a node and assign it to head.
  if (list == nullptr)
	{
	  list = newNode;
	  newNode->next = nullptr;
	}
  
  //Find the right place for the node to be placed.
  else
	{
	  nodePtr = list;
	  while (nodePtr != nullptr && nodePtr->data < d)
		{
		  prevPtr = nodePtr;
		  nodePtr = nodePtr->next;
		}
      
	  if (prevPtr == nullptr)
		{
		  list = newNode;
		  newNode->next = nodePtr;
		}
	  else
		{
		  prevPtr->next = newNode;
		  newNode->next = nodePtr;
		}
	}
}

void deleteNode(Node*& list, int d)
{
  Node* delPtr, *ptr;
  
  //algorithm for deleting
  if(list->data == d){
    delPtr = list;
    list = list->next;
    delete delPtr;
  }
  
  else{
    //find node to be deleted
    ptr = list;
    while(ptr->next != nullptr && ptr->next->data < d){
      ptr = ptr->next;
    }
    
    if(ptr->next != nullptr && ptr->next->data == d){
      delPtr = ptr->next; 
      ptr->next = delPtr->next;
	  delete delPtr;
    }
  }
}

void minNode(Node* list, int &val)
{	
  //Takes the incoming val and compares it with the list to
  //see if it is the smallest val.
  val = list->data;
  for (int i = 0;i < MAX;i++){
    if(list != nullptr && list->next != nullptr){
      if(val > list->next->data){
        list = list->next;
        val = list->data;
      }
      else
        list = list->next;
      
    }
  }
}

void maxNode(Node* list, int &val)
{
  //Takes the incoming val and compares it with the list to
  //see if it is the largest val.
  val = list->data;
  for (int i = 0;i < MAX;i++){
    if(list != nullptr && list->next != nullptr){
      if(val < list->next->data){
        list = list->next;
        val = list->data;
      }
      else
        list = list->next;
      
    }
  }
}

void middleNode(Node* list, int &val)
{
  //Finding a node in the middle and deleting it.
  int midPoint = (MAX / 2);
  val = list->data;
  for (int i = 0;i < midPoint;i++){
    if(list != nullptr && list->next != nullptr){
      list = list->next;
      val = list->data;
    }
  }
}
