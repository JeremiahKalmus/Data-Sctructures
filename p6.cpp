//Jeremiah Kalmus
//P6 - STL

#include <iostream>
#include <iomanip>
#include <list>
#include <ctime>

using namespace std;

const int MAXSIZE = 10000;
//Largest any randomly generated value can be.

const int TOTALNUMS = 1000;
//Total numbers to be entered into a new list.

const int TEN = 10;
const int ZERO = 0;
const int TWO = 2;
const int FIVE = 5;

void print(list<int> pList);
//Prints the contents in the list.
//PRE: None
//POST: None

void removeMultOfFive(list<int>& pList);
//Removes all multiples of 5 in the list
//PRE: List must be created
//POST: May make the list smaller by removing values.

bool isPrime(int middle);
//Checks to see if a value is prime.
//PRE: List and removePrime function must be created.
//POST: Determines if the value is prime

void removePrime(list<int>& pList, bool& erased);
//Removes a prime value in between two values of mixed parody.
//PRE: List must be created.
//POST: May make the list smaller by removing values.

int main()
{
  srand(time(0));
  int val = 0;
  bool erased = false;
  
  list<int> pList;
  
  //Declaring an iterator
  list<int>::iterator front;
  
  cout << "Hello and welcome to the P6 program. " << endl
       << "This program will utilize the STL and store values into a list. " << endl
       << "It will then remove all multiples of 5, and then it will remove " << endl
       << "all prime numbers in between two numbers of mixed parody. " << endl 
       << "The program will continue to remove prime numbers this way until " << endl
       << "there are no more changes to the list. " << endl << endl;
  
  for(int i = 0;i < TOTALNUMS;i++){
    val = rand() % MAXSIZE;
    pList.push_back(val);
    
  }
  cout << "Printing values stores in the list" << endl;
  print(pList);
  cout << endl;
  removeMultOfFive(pList);
  cout << "Removing all multiples of 5" << endl;
  print(pList);
  cout << endl;
  removePrime(pList, erased);
  cout << "Removing primes between numbers of mixed parody" << endl;
  print(pList);
  
  while(erased == true){
    cout << endl;
    removePrime(pList, erased);
    cout << "Removing primes between numbers of mixed parody" << endl;
    print(pList);
  }
  cout << endl << endl;
  cout << "Last two walks through the list are the same." << endl;
  cout << "Goodbye!" << endl;
  
  return 0;
}

void print(list<int> pList)
{
  list<int>::iterator front = pList.begin();
  int count = 0; 
  
  while(front != pList.end()){
    if(count == TEN){
      cout << endl;
      count = ZERO;
    }
    cout << setw(6);
    cout << (*front) << " ";
    front++;
    count++;
  }
  cout << endl;
}

void removeMultOfFive(list<int>& pList)
{
  list<int>::iterator val = pList.begin();
  int count = 0;
  
  while(count != TOTALNUMS){
    if((*val % FIVE) == ZERO){
      pList.erase(val);
      val--;
    }
    else{
      val++;
      count++;
    }
  }
}

bool isPrime(int middle)
{
  int count = 2;
  bool prime = true;
  
  if(middle == TWO){
    return true;
  }
  else{
    while((prime == true) && (count < middle)){
      if(((middle) % count) == ZERO){
        prime = false;
      }
      count++;
    }
    return prime;
  }
}

void removePrime(list<int>& pList, bool& erased)
{
  list<int>::iterator front = pList.begin();
  list<int>::iterator middle = front;
  middle++;
  list<int>::iterator back = middle;
  back++;
  erased = false;
  
  while(back != pList.end()){
    //Check to see if a prime is in between two numbers
    //of mixed parody
    if(((((*front % TWO) == 1) && ((*back % TWO) == 0))
        || (((*back % TWO) == 1) && ((*front % TWO) == 0)))
       && (isPrime(*middle) == true)){
      
      //Check to see if it is prime
      middle = pList.erase(middle);
      back++;
      erased = true;
      
    }
    else{
      front++;
      middle++;
      back++;
      
    }
  }
}

