// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// BSTreeActors.h
// 12/01/17
// Used BSTree.h provided by class as basis for BSTreeActorNode and BSTreePictures

#ifndef BSTREEACTORS_
#define BSTREEACTORS_
#include <vector>
#include "ActorNode.h"
using namespace std;

// Binary Search Tree class
class BSTreeActors {
private:
	ActorNode* root;													// Root of tree
	void addNode(Actor anActor, ActorNode* leaf);						// Most of these functions are self explanitory. I will comment the ones I made
	ActorNode* deleteNode(ActorNode* node, string key);
	void freeNode(ActorNode* leaf);
	void printInorder(ActorNode* node, bool, bool, bool, bool, bool);
	void printInorderFile(ActorNode* node, ofstream&, bool, bool, bool, bool, bool);
	void printPreorder(ActorNode* node);
	void printPostorder(ActorNode* node);
	ActorNode* findNodeExactFirst(string key, ActorNode* parent);					// Search function that returns the address of the first object with a given key
	void findNodeExactAll(string key, ActorNode* parent, vector<Actor>& data);		// Search function that returns the address of all objects with an exact key
	void findNodeContainsAll(string, ActorNode* parent, vector<Actor>& data);		// Inorder search returning all elements that contain the string in their field
	void findNodeExactStep(string key, ActorNode* parent, vector<Actor>&data);		// Matches exact, but uses inorder processing to do it. Used for fields other than name.
	void toCSV(ActorNode*, ofstream&);												// Converts the BST to a .csv file. Copies the tree down preorder
	void toVector(ActorNode*, vector<Actor>& data);									// Converst the entire BST into a vector.
	int size(ActorNode* node);

public:
	BSTreeActors();
	~BSTreeActors();
	int sizeTree;												// Contains size variable for use with size() function
	ActorNode* Root() { return root; }
	void setRoot(ActorNode * _root) { root = _root; }
	void addNode(Actor anActor);
	void findNodeExactAll(string key, vector<Actor>& data);
	ActorNode* findNodeExactFirst(string key);
	void findNodeContainsAll(string key, vector<Actor>& data);
	void findNodeExactStep(string key, vector<Actor>& data);
	void printInorder();
	void printInorder(bool, bool, bool, bool, bool);
	void printInorderFile(ofstream&, bool, bool, bool, bool, bool);
	void printPreorder();
	void printPostorder();
	void deleteNode(string key);								// Deletes the first node with the key
	void deleteTargetNode(ActorNode*);							// Deletes a node based on node's address
	ActorNode* min(ActorNode* node);
	ActorNode* max(ActorNode* node);
	void readFromFile(string, BSTreeActors*);					// Reads from a .csv file into a BST
	int size();
	void changeAllKeys(int&, ActorNode*);						// Steps through the tree and changes the key based on userInput
	void modifyNode(ActorNode* node);							// Modifies a node, including deleting and creating a new node when the key variable is changed
	void toCSV(ofstream&);							
	void toVector(vector<Actor>& data);
};
#endif  //BST
