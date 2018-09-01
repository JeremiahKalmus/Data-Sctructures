//Jeremiah Kalmus
//Lab 3

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
  int key;
  Node* left;
  Node* right;
};

//Function prototypes
bool insert(Node*& root, int k);
//Inserts k into BST with smallest on the left and
//largest on the right. It will not enter in any
//duplicates.
void inOrder(Node* root);

void preOrder(Node* root);

void postOrder(Node* root);

void deleteAll(Node*& root);

int main()
{
  const int TREESIZE = 10;
  Node* tRoot = nullptr;
  srand(time(0));
  int num = 0;
  int count = 0;

  while(count != TREESIZE){\
    num = rand() % 20;  
    if(insert(tRoot, num) != false)
	  count++;	
  }
  cout << endl;
  inOrder(tRoot);
  cout << endl; 
  
  preOrder(tRoot);
  cout << endl;

  postOrder(tRoot);
  cout << endl;
  
  cout << "Now deleting" << endl;
  deleteAll(tRoot);
  
  return 0;
}

bool insert(Node*& root, int k)
{
  if(root == nullptr){
    root = new Node;
    root->key = k;
    root->left = nullptr;
    root->right = nullptr;
    return true;
  }
  else if(root->key > k)
    return insert(root->left, k);
  else if(root->key < k)
    return insert(root->right, k);
  else
    return false;
}
void inOrder(Node* root)
{
  if(root != nullptr){
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
  }
}
void preOrder(Node* root)
{
  if(root != nullptr){
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}
void postOrder(Node* root)
{
  if(root != nullptr){
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
  }
}
void deleteAll(Node*& root)
{
  if(root != nullptr){
    deleteAll(root->left);
    deleteAll(root->right);
    delete root;
    root = nullptr;
  }
}
