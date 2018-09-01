
//Jeremiah Kalmus
//tree.cpp
//Implementation file for the tree class

using namespace std;

//Referencing header file
#include "tree.h"
#include <iostream>
#include <stack>

//Constructor 
Tree::Tree()
{
  root = nullptr;
}
Tree::~Tree()
{
  deleteAll(root);
}
Tree& Tree::operator=(const Tree& rhs)
{
  if(this != &rhs){
    deleteAll(root);
    root = makeCopy(rhs.root);
  }
  return *this;
}
Tree::Tree(const Tree& aTree)
{
  if(aTree.root == nullptr)
    root = nullptr;
  else
    root = makeCopy(aTree.root);
}	
bool Tree::insert(int k)
{
  return insert(root,k);
}
bool Tree::insert(treeNode*& root, int k)
{
  if(root == nullptr){
    root = new treeNode;
    root->key = k;
    root->left = nullptr;
    root->right = nullptr;
    return true;
  }else if(root->key == k)
    return false;
  else if(root->key > k)
    return insert(root->left, k);
  else
    return insert(root->right, k);
}
bool Tree::search(int k)
{
  return search(root,k);
}
bool Tree::search(treeNode* root, int k)
{
  if(root == nullptr)
    return false;
  else if(root->key == k)
    return true;
  else if(root->key > k)
    return search(root->left, k);
  else
    return search(root->right, k);
}
int Tree::findMin()
{
  return findMin(root);
}
int Tree::findMin(treeNode* r)
{
  if(r->left == nullptr)
    return r->key;
  else
    return findMin(r->left);
}
int Tree::findMax()
{
  return findMax(root);
}
int Tree::findMax(treeNode* r)
{
  if(r->right == nullptr)
    return r->key;
  else
    return findMax(r->right);
}
int Tree::height()
{
  return height(root);
}
int Tree::height(treeNode* r)
{
  if(r == nullptr)
    return 0;
  else{
    int lHeight = height(r->left);
    int rHeight = height(r->right);
    if(lHeight > rHeight)
      return 1 + lHeight;
    else
      return 1 + rHeight;
  }
}
void Tree::iterativeInOrder()
{
  iterativeInOrder(root);
}
void Tree::iterativeInOrder(treeNode* root)
{
  stack <treeNode*> stack;
  treeNode* current = root;
  
  while(current != nullptr || !stack.empty()){
    if(current != nullptr){
      stack.push(current);
      current = current->left;
    }else{
      current = stack.top();
			stack.pop();
			cout << current->key << " ";
			current = current->right;
    }
  }
}
void Tree::recPreOrder()
{
  recPreOrder(root);
}
void Tree::recPreOrder(treeNode* root)
{
  if(root != nullptr){
    cout << root->key << " ";
    recPreOrder(root->left);
    recPreOrder(root->right);
  }
}
void Tree::deleteAll(treeNode*& root)
{
  if(root != nullptr){
		deleteAll(root->left);
		deleteAll(root->right);
		delete root;
		root = nullptr;
  }
}
void Tree::remove(int k)
{
  remove(root,k);
}
void Tree::remove(treeNode* root, int k)
{
	treeNode* parent;
	if(root == nullptr)
      return;
	if(root->key == k)
      {
		makeDeletion(root);
      }
	else{
		parent = findParent(root, k);
		if(parent != nullptr){
          if(parent->left != nullptr && parent->left->key == k)
            makeDeletion(parent->left);
          else
            makeDeletion(parent->right);
		}
	}
}
void Tree::makeDeletion(treeNode*& nodePtr)
{
  treeNode* tmpNodePtr;
  
  if(nodePtr->right == nullptr){
    //only left child or none
    tmpNodePtr = nodePtr;
    nodePtr = nodePtr->left;
		delete tmpNodePtr;
  }else if(nodePtr->left == nullptr){
    //only right child
    tmpNodePtr = nodePtr;
    nodePtr = nodePtr->right;
    delete tmpNodePtr;
  }else{
    //there are two children
    tmpNodePtr = nodePtr->right;
    while(tmpNodePtr->left)
      tmpNodePtr = tmpNodePtr->left;
		tmpNodePtr->left = nodePtr->left;
		tmpNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tmpNodePtr;
        
  }
}
Tree::treeNode* Tree::makeCopy(treeNode* r)
{
  if(r == nullptr)
    return nullptr;
  else{
		treeNode* temp = new treeNode;
		temp->key = r->key;
		temp->left = makeCopy(r->left);
		temp->right = makeCopy(r->right);
		return temp;
	}
}
Tree::treeNode* Tree::findParent(treeNode* r, int k)
{

  if(k < r->key){
    if(k == r->left->key)
      return r;
		else
          return findParent(r->left, k);
  }else{
    if(k == r->right->key)
      return r;
		else
          return findParent(r->right, k);
  }
  
}
