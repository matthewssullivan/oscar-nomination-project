// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// BSTPictures.h
// 12/01/17
// Used BSTree.h provided by class as basis for BSTreePictures and BSTreePictures

#ifndef BSTREEPICTURES_
#define BSTREEPICTURES_
#include <vector>
#include "PictureNode.h"

using namespace std;

// Binary Search Tree class
class BSTreePictures {
private:
	PictureNode* root;																			// Root of tree
	void addNode(Picture aPicture, PictureNode* leaf);											// This tree is essentially a mirror of the ActorTree, but with more variables
	PictureNode* deleteNode(PictureNode* node, string key);
	void freeNode(PictureNode* leaf);
	void printInorder(PictureNode* node);
	void printInorder(PictureNode*, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
	void printInorderFile(PictureNode*, ofstream&, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
	void printPreorder(PictureNode* node);
	void printPostorder(PictureNode* node);
	PictureNode* findNodeExactFirst(string key, PictureNode* parent);							// Search function that returns the address of the first object with a given key
	void findNodeExactAll(string key, PictureNode* parent, vector<Picture>& data);				// Search function that returns the address of all objects with an exact key
	void findNodeContainsAll(string, PictureNode* parent, vector<Picture>& data);				// Inorder search returning all elements that contain the string in their field
	void findNodeExactStep(string, PictureNode*, vector<Picture>& data);						// Matches exact, but uses inorder processing to do it. Used for fields other than name.
	void toCSV(PictureNode*, ofstream&);														// Converts the BST to a .csv file. Copys the tree down preorder
	void toVector(PictureNode*, vector<Picture>& data);											// Converst the entire BST into a vector.
	int size(PictureNode* node);

public:
	BSTreePictures();
	~BSTreePictures();
	PictureNode* Root() { return root; }
	int sizeTree;														// Contains size variable for use with size() function
	void setRoot(PictureNode * _root) { root = _root; }
	void addNode(Picture aPicture);
	void findNodeExactAll(string key, vector<Picture>& data);
	PictureNode* findNodeExactFirst(string key);
	void findNodeContainsAll(string key, vector<Picture>& data);
	void findNodeExactStep(string key, vector<Picture>& data);
	void printInorder();
	void printInorder(bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
	void printInorderFile(ofstream&, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool);
	void printPreorder();
	void printPostorder();
	void deleteNode(string key);										// Deletes the first node with the key
	void deleteTargetNode(PictureNode*);								// Deletes the first node with the key
	PictureNode* min(PictureNode* node);
	PictureNode* max(PictureNode* node);
	void readFromFile(string, BSTreePictures*);							// Reads from a .csv file into a BST
	int size();
	void changeAllKeys(int&, PictureNode*);								// Steps through the tree and changes the key based on userInput
	void modifyNode(PictureNode*);										// Modifies a node, including deleting and creating a new node when the key variable is changed
	void toCSV(ofstream&);
	void toVector(vector<Picture>& data);
};
#endif  //BST
