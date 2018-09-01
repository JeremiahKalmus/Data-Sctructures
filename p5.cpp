//Jeremiah Kalmus
//P5 - Hashing

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string READFILE = "/home/st/kalmusj1/cs2/ulyss12.txt";
const int TABLESIZE = 33757; //Prime number
const string TERMINATE = "stop"; //Word to exit the program.

struct Table
{
  int count;
  string word;
  Table* next;
};

int hashing(string key, int tableSize);
//Creates a value for easier storage and retrieval in the hash table.
//PRE: Word has been preprocessed
//POST: None

void insert(Table** myList, string key, int location, int& collisionCount,
            double& uniqueCount, Table*& ptr);
//Inserts words into the hash table using the hash value.
//PRE: The hash table must exist, the word has been preprocessed, 
//and a hash value for the word has been generated.
//POST: Word gets inserted into the hash table. The table changes.

void deleteAll(Table** myList, int tableSize);
//Deallocates all allocated memory via destroying all 
//linked list structures in the hash table.
//PRE: The hash table exists
//POST: All linked lists in hash table are deleted.

int search(Table** myList, string key, int location);
//Searches for a word at it's hashvalue location.
//PRE: Hash table must exist.
//POST: None

void preProcess(string& key);
//Formats incoming words and removes unwanted 
//PRE: None
//POST: None

int main()
{
  ifstream input;
  Table* myList[TABLESIZE]; //creating array of pointers
  Table* ptr = nullptr;
  string word;
  int hashedVal = 0;
  int wordCount = 0;
  double uniqueCount = 0;
  int collisionCount = 0;
  int occuranceAmount = 0;
  double loadFactor = 0;
  
  cout << "Hello and welcome to the p5 program. " << endl;
  cout << "This program will go through all the words in "
	   << "the book Ulysses and remove " << endl << "all punctuation "
	   << "and numbers from the words except for apostrophes. " << endl
	   << "The program will take all words greater than 5 characters "
	   << "in length " << endl << "and sort them from a generated "
	   << "hash value. The program will calculate the amount of "
	   << "total words, unique words, " << endl << "the amount of "
	   << "collisions and the load factor. The user can check to see "
       << "if a word " << endl << "is in fact in the book and how many "
       << "times it occured. " << endl << endl;
  
  //open file
  input.open(READFILE);
  
  //check that it is open/readable
  if(input.fail()){
    cout << endl << "Sorry, file not available...exiting program...press enter"
         << endl;
    cin.get();      //Grabs the enter;
    return 0;
  }
  
  for (int i = 0;i < TABLESIZE;i++){
    myList[i] = nullptr;
  }  
  
  while (input >> word){  
	preProcess(word);
	if (word.size() > 5){
      wordCount++; 
      hashedVal = hashing(word, TABLESIZE); 
      insert(myList, word, hashedVal, collisionCount, uniqueCount, ptr);
	}
  }
    //Computes load factor
  loadFactor = (uniqueCount/TABLESIZE);
  
  cout << "Total words larger than 5: " << wordCount << endl;
  cout << "Unique words larger than 5: " << uniqueCount << endl;
  cout << "Collisions: " << collisionCount << endl;
  cout << "Load factor is: " << loadFactor << endl;
  cout << "All the items have been hashed. If you would like "
       << "to search " << endl << "for a word greater than 5 characters "
	   << "from the book Ulysses, " << endl
	   << "then please enter a word you would like to search, (one "
	   << "word at a time) " << endl << "and the amount of occurances "
	   << "that word has in the book will be displayed. " << endl 
	   << "Type 'stop' to exit the program." << endl << endl;
  cout << "Please enter a word to search for greater than 5 characters: "
	   << endl;
  cin >> word;
  cout << endl;
  
  preProcess(word);
  while(word != TERMINATE){
    if (word.size() < 6){
  	  cout << "Sorry, this word is less than 6 characters long." << endl;
    }
    else if (word.size() > 5){
	  hashedVal = hashing(word, TABLESIZE);
	  occuranceAmount = search(myList, word, hashedVal);
      cout << "The amount of times that word occurs is: " << occuranceAmount
           << endl;
    }
    
	cout << "Please enter a word to search for greater than 5 characters: "
		 << endl;
    cin >> word;
	cout << endl;
	preProcess(word);
  }
  cout << "I am now deallocating memory. " << endl << "Goodbye." << endl;
  deleteAll(myList, TABLESIZE);
  
  return 0;
}

int hashing(string key, int tableSize)
{
  unsigned int hashVal = 0;
  
  for (unsigned int i = 0;i < key.length();i++){
	//This is a random math operation that I came up with to 
	//ensure diversity of hash values.
    hashVal = (hashVal^key[i]) + ((key[i] * 61)^key[i]);
  }
  return hashVal % tableSize;
  
}

void insert(Table** myList, string key, int location, int& collisionCount,
            double& uniqueCount, Table*& ptr)
{
  ptr = myList[location];
  int tempCollision = 0;
  
  //Nothing in linked list
  if (myList[location] == nullptr){
	myList[location] = new Table;
    myList[location]->count = 1;
	myList[location]->word = key;
	myList[location]->next = nullptr;
    uniqueCount++;
  }
  else{
	//Traverse until null or key is found
	while (ptr->next != nullptr && ptr->word != key){
	  ptr = ptr->next;
	  tempCollision++;
	}
	if (ptr->word == key){
      ptr->count = ptr->count + 1;
	}
	else{
      ptr->next = new Table;
	  ptr->next->next = nullptr;
      ptr->next->count = 1;
	  ptr->next->word = key;
      uniqueCount++;  
	  collisionCount = (collisionCount + tempCollision);
	}
  }
}
void deleteAll(Table** myList, int tableSize)
{
  Table* delPtr = nullptr;
  
  for (int i = 0;i < tableSize;i++){
	delPtr = myList[i];
	while (delPtr != nullptr){
      delPtr = delPtr->next;
	  delete myList[i];
	  myList[i] = delPtr;
	}
  }
}
int search(Table** myList, string key, int location)
{
  Table* ptr = myList[location];
  
  while (ptr != nullptr && ptr->word != key){
	ptr = ptr->next;
  }
  if (ptr == nullptr){
	return 0;
  }
  else{
	return ptr->count;
  }
}
void preProcess(string& key)
{
  //Adjusts all characters to lower case
  for (unsigned int i = 0;i < key.size();i++){
    key[i] = tolower(key[i]);
    
    //Checks if the character is a kind of punctuation
    //and removes if needed. 
    if ((!isalpha(key[i]))){
      if((key[i] != '\'')){
        key.erase(i--,1);
      }
    }
  }
}
