//Jeremiah Kalmus
//tree.h
//header file that provides standard BST operations for the character type. 

#ifndef TREE_H
#define TREE_H

//Creation of the tree
class Tree
{
  //public initializations that are open to being called from the driver file.
 public:
  Tree();								//constructor
  ~Tree();							//destructor
  Tree& operator=(const Tree& rhs);	//overloaded assignment operator
  Tree(const Tree& aTree);			//copy constructor
  bool insert(int k);
	//Insert nodes into the tree with no duplicates.
	//Pre: Contructor is functional and an object is created.
	//Post: A value will be entered into its appropriate place
	//in the list without taking any duplicates.
  
  bool search(int k);
  //Seaches for a particular key in the tree.
  //Pre: That a tree object has been created and there are values in the tree.
  //Post: Will find and return the key that was desired.
  
  int findMin();
  //Find the minimum value in the tree.
  //Pre: A tree object has been created and there are values in the tree.
  //Post: Finds and returns the leftmost value from the list
  
  int findMax();
  //Find the maximum value in the tree.
  //Pre: A tree object has been created and there are values in the tree.
  //Post: Finds and returns the rightmost value from the list
  
  int height();
  //Find how many levels the tree has.
  //Pre: A tree object needs to be existing.
  //Post: Returns the height of the tree.
  
  void iterativeInOrder();
  //Traverses and prints the tree in order non-recursively
  //Pre: The tree object is existant.
  //Post: Prints the values in the tree in order.
  
  void recPreOrder();
  //Traverses and prints the tree starting with the root and then moving
  //to the left and then to the right. 
  //Pre: The tree object needs to be existant.
  //Post: Prints the values in the tree recursively preorder.
  
  void remove(int k);
  
 private:
  struct treeNode	//Struct
  {
    int key;
    treeNode* left;
    treeNode* right;
  };
  treeNode* root;	//Root pointer
  
  
  void remove(treeNode* root, int k);
  //Called function that removes a node from the tree.
  //Pre: Tree needs to exist with values entered in it.
  //Post: Value is deleted from the tree.
  
  void makeDeletion(treeNode*& nodePtr);
  //Deletes the node depending on if it has no children, one child,
  //or two children.
  //Pre: Tree objects needs to exist and values exist in the tree.
  //Post: Specified values in the tree will be deleted.
  
  treeNode* makeCopy(treeNode* r);
  //Makes a copy of the tree.
  //Pre: Needs to have an existant tree to copy from.
  //Pre: Creates a copy of an existing tree.
  
  treeNode* findParent(treeNode* r, int k);
  //Searches for the parent node.
  //Pre: The tree needs to exist.
  //Post: Finds and returns the parent node of the child being looked at.
  
  bool insert(treeNode*& root, int k);
  //Insert nodes into the tree with no duplicates.
  //Pre: Contructor is functional and an object is created.
  //Post: A value will be entered into its appropriate place
  //in the list without taking any duplicates.
  
  bool search(treeNode* root, int k);
  //Seaches for a particular key in the tree.
  //Pre: That a tree object has been created and there are values in the tree.
  //Post: Will find and return the key that was desired.
  
  int findMin(treeNode* r);
  //Find the minimum value in the tree.
  //Pre: A tree object has been created and there are values in the tree.
  //Post: Finds and returns the leftmost value from the list
  
  int findMax(treeNode* r);
  //Find the maximum value in the tree.
  //Pre: A tree object has been created and there are values in the tree.
  //Post: Finds and returns the rightmost value from the list
  
  int height(treeNode* r);
  //Find how many levels the tree has.
  //Pre: A tree object needs to be existing.
  //Post: Returns the height of the tree.
  
  void iterativeInOrder(treeNode* root);
  //Traverses and prints the tree in order non-recursively
  //Pre: The tree object is existant.
  //Post: Prints the values in the tree in order.
  
  void recPreOrder(treeNode* root);
  //Traverses and prints the tree starting with the root and then moving
  //to the left and then to the right. 
  //Pre: The tree object needs to be existant.
  //Post: Prints the values in the tree recursively preorder.
  
  void deleteAll(treeNode*& root);
  //Deletes all the nodes in the tree.
  //Pre: The tree object needs to exist.
  //Post: The tree is emptied and deleted. 
  
  
};
#endif
