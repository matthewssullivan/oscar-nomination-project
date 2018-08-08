// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// BSTreePictures.cpp
// 12/01/17
// Built Based off BSTreeInt.cpp provided by class

#include "BSTreePictures.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;										// NOTE: This is an exact mirror of BSTreeActors.cpp with small exceptions for more variables

// Constructor
BSTreePictures::BSTreePictures() {							// Default Constructor
	root = nullptr;
}

// Destructor
BSTreePictures::~BSTreePictures() {							// Destructor
	if (root != nullptr)
		freeNode(root);
}

// Free the node
void BSTreePictures::freeNode(PictureNode* leaf)			// Private recursive removal of node functions
{
	if (this->Root() == leaf)
	{
		delete leaf;
	}
	else if (leaf != nullptr)

	{
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		delete leaf;
	}
}

// Add a node
void BSTreePictures::addNode(Picture aPicture)
{
	PictureNode * newNode = new PictureNode(aPicture);
	newNode->setKey(aPicture.getKey());
	if (this->Root() == nullptr)
	{
		this->setRoot(newNode);
	}
	else
		addNode(aPicture, this->Root());
}

void BSTreePictures::addNode(Picture aPicture, PictureNode* leaf) {				// Add a node (private)
	PictureNode * newNode = new PictureNode(aPicture);
	newNode->setKey(aPicture.getKey());
	newNode->setLeft(nullptr);
	newNode->setRight(nullptr);
	if ((aPicture.getKey() < leaf->Key()))
	{
		if (leaf->Left() == nullptr)
		{
			newNode->setParent(leaf);
			leaf->setLeft(newNode);
		}
		else
			addNode(aPicture, leaf->Left());

	}
	else
	{
		if (leaf->Right() == nullptr)
		{
			newNode->setParent(leaf);
			leaf->setRight(newNode);
		}
		else
			addNode(aPicture, leaf->Right());
	}
}

PictureNode* BSTreePictures::findNodeExactFirst(string key)				// Find first exact node based on key
{
	return findNodeExactFirst(key, root);
}

// Find a node
PictureNode* BSTreePictures::findNodeExactFirst(string key, PictureNode* node)		// Private find exact node
{
	if (node == nullptr)								// Base case
	{
		return nullptr;
	}
	if ((key == node->Key()))							// if the key matches the key of the picture object
	{
		return node;									// return the node
	}
	if ((key < node->Key()))
	{
		return findNodeExactFirst(key, node->Left());	// if it's smaller, go left down the tree
	}
	else
	{
		return findNodeExactFirst(key, node->Right());	// if it's greater go right
	}
}

void BSTreePictures::findNodeExactAll(string key, vector<Picture>& data)
{
	return findNodeExactAll(key, root, data);
}

// Find a node
void BSTreePictures::findNodeExactAll(string key, PictureNode* node, vector<Picture>& data)	// Find all exact nodes if the key is based on the BST
{
	PictureNode* temp = new PictureNode;				// Temporary node to push actor onto vector
	if (node == nullptr)								// Base case
	{
		return;
	}
	if ((key == node->Key()))							// if it matches
	{
		temp = node;									// set temp to node
		temp->nodePicture.setLocation(node);			// set temp's location to location of node
		data.push_back(temp->getPicture());				// push the picture onto the vector
	}
	if ((key < node->Key()))							// recursively check left and right trees
	{
		return findNodeExactAll(key, node->Left(), data);
	}
	else
	{
		return findNodeExactAll(key, node->Right(), data);
	}
}

void BSTreePictures::findNodeContainsAll(string key, vector<Picture>& data)
{
	return findNodeContainsAll(key, root, data);
}

void BSTreePictures::findNodeContainsAll(string key, PictureNode* node, vector<Picture>& data)	// Adds all actors from nodes that contain a key to a vector using tree traversal
{
	PictureNode* temp = new PictureNode;
	if (node != nullptr) {
		findNodeContainsAll(key, node->Left(), data);
		if (node->Key().find(key) != string::npos) {
			temp = node;
			temp->nodePicture.setLocation(node);
			data.push_back(temp->getPicture());
		}
		findNodeContainsAll(key, node->Right(), data);
	}
	return;
}

void BSTreePictures::findNodeExactStep(string key, vector<Picture>& data)
{
	return findNodeExactStep(key, root, data);
}

void BSTreePictures::findNodeExactStep(string key, PictureNode * node, vector<Picture>& data)	// Traverses tree and adds all Actors from nodes that match a key exactly to a vector
{
	PictureNode* temp = new PictureNode;
	if (node != nullptr) {
		findNodeExactStep(key, node->Left(), data);
		if (node->Key()==key) {
			temp = node;
			temp->nodePicture.setLocation(node);
			data.push_back(temp->getPicture());
		}
		findNodeExactStep(key, node->Right(), data);
	}
	return;

}

void BSTreePictures::printInorder()				// Prints the trees inorder, preorder, and postorder, respectively
{
	printInorder(root, true, true, true, true, true, true, true, true, true, true);
}

void BSTreePictures::printInorder(bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis) 
{
	printInorder(root, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
}

void BSTreePictures::printInorder(PictureNode* node, bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis)
{
	if (node != nullptr)
	{
		printInorder(node->Left(), name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
		node->printNode(name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
		//cout << node->getPicture();
		printInorder(node->Right(), name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
	}
}

void BSTreePictures::printInorderFile(ofstream& myfile, bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis) {
	printInorderFile(root, myfile, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
}

void BSTreePictures::printInorderFile(PictureNode* node, ofstream& myfile, bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis)
{
	if (node != nullptr)
	{
		printInorderFile(node->Left(), myfile, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
		node->printNodeFile(myfile, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
		//cout << node->getPicture();
		printInorderFile(node->Right(), myfile, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
	}
}



void BSTreePictures::printPreorder()
{
	printPreorder(root);
	cout << endl;
}

void BSTreePictures::printPreorder(PictureNode* node)
{
	if (node != nullptr)
	{
		cout << node->Key() << ", ";
		printPreorder(node->Left());
		printPreorder(node->Right());
	}
}

void BSTreePictures::printPostorder()
{
	printPostorder(root);
	cout << endl;
}

void BSTreePictures::printPostorder(PictureNode* node)
{
	if (node != nullptr)
	{
		printPostorder(node->Left());
		printPostorder(node->Right());
		cout << node->Key() << ", ";
	}
}

void BSTreePictures::toCSV(ofstream& myfile)
{
	toCSV(root, myfile);
}

void BSTreePictures::toCSV(PictureNode* node, ofstream& myfile)	// Traverses tree (preorder) and writes to a .csv file
{
	if (node != nullptr)
	{
		myfile << node->nodePicture.getName() << "," << node->nodePicture.getYear() << "," << node->nodePicture.getNominations() << "," << node->nodePicture.getRating() << ",";
		myfile << node->nodePicture.getDuration() << "," << node->nodePicture.getGenre1() << "," << node->nodePicture.getGenre2() << "," << node->nodePicture.getRelease() << ",";
		myfile << node->nodePicture.getMetacritic() << "," << node->nodePicture.getSynopsis() << endl;
		toCSV(node->Left(), myfile);
		toCSV(node->Right(), myfile);
	}
}

void BSTreePictures::toVector(vector<Picture>& data)
{
	toVector(root, data);
}

void BSTreePictures::toVector(PictureNode * node, vector<Picture>& data)		// Traverses tree and pushes all Actors onto a vector for ease of sorting
{
	if (node != nullptr)
	{
		toVector(node->Left(), data);
		toVector(node->Right(), data);
		data.push_back(node->nodePicture);
	}
}


void BSTreePictures::deleteNode(string key)			// Code given by instructor, traverses tree and deletes first node that matches the key
{
	{
		if (deleteNode(Root(), key) == nullptr)
			setRoot(nullptr);
	}
}

//deleteNode (Private)
PictureNode* BSTreePictures::deleteNode(PictureNode* root, string key)
{

	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */


	if (root == nullptr) return root;
	else if (key < root->Key())
		root->setLeft(deleteNode(root->Left(), key));
	else if (key > root->Key())
		root->setRight(deleteNode(root->Right(), key));
	else {
		// Case 1: No Child
		if (root->Left() == nullptr && root->Right() == nullptr) {
			delete root;
			root = nullptr;
			// Case 2: one child
		}
		else if (root->Left() == nullptr) {
			//Node *temp = root;			// Code wasn't working, replaced with code below
			//root = root->Right();
			//delete temp;
			PictureNode *temp = root->Right();
			root->setKey(temp->Key());
			root->setLeft(temp->Left());
			root->setRight(temp->Right());
			delete temp;
		}
		else if (root->Right() == nullptr) {
			//Node *temp = root;			// See above
			//root = root->Left();
			//delete temp;
			PictureNode *temp = root->Left();
			root->setKey(temp->Key());
			root->setLeft(temp->Left());
			root->setRight(temp->Right());
			delete temp;
		}
		else {
			PictureNode *temp = min(root->Right());
			root->setKey(temp->Key());
			root->setRight(deleteNode(root->Right(), temp->Key()));
		}
	}
	return root;
}

void BSTreePictures::deleteTargetNode(PictureNode * target)				// Modified version of above delete node function. Does not traverse tree, but is passed an address in the tree to delete directly
{																		// Used with location variable in Picture object to target specific records for deletion and modification
	if (target == nullptr)
		return;
	else {
		// Case 1: No Child
		if (target->Left() == nullptr && target->Right() == nullptr) {
			delete target;
			target = nullptr;
			// Case 2: one child
		}
		else if (target->Left() == nullptr) {
			PictureNode *temp = target->Right();
			target->setKey(temp->Key());
			target->nodePicture = (temp->nodePicture);		//added this
			target->setLeft(temp->Left());
			target->setRight(temp->Right());
			delete temp;
		}
		else if (target->Right() == nullptr) {
			PictureNode *temp = root->Left();
			target->setKey(temp->Key());
			target->nodePicture = (temp->nodePicture);		//added this
			target->setLeft(temp->Left());
			target->setRight(temp->Right());
			delete temp;
		}
		else {
			PictureNode *temp = min(target->Right());
			target->setKey(temp->Key());
			target->nodePicture = (temp->nodePicture);		//added this
			target->setRight(deleteNode(root->Right(), temp->Key()));
		}
		return;
	}
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
PictureNode* BSTreePictures::min(PictureNode* node)
{
	PictureNode* tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Left())
	{
		tempNode = min(node->Left());
	}
	else
		tempNode = node;

	return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
PictureNode* BSTreePictures::max(PictureNode* node)
{
	PictureNode * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}

void BSTreePictures::readFromFile(string file, BSTreePictures* tree)			// reads from a .csv file into the tree
{
	Picture newPicture;
	ifstream myfile(file);
	string name;				// Data members
	int year;
	int nominations;
	float rating;
	int duration;
	string genre1;
	string genre2;
	string release;
	int metacritic;
	string synopsis;
	PictureNode* location;
	string first;
	string temp;
	while (myfile.is_open() == false && file != "-1") {
		cout << "File not found, please enter correct file, or enter -1 to exit program" << endl;
		getline(cin, file);
		myfile.open(file);
	}
	if (myfile.is_open())
	{
		getline(myfile, first);
		while (myfile.peek() != EOF) {
			getline(myfile, name, ',');
			getline(myfile, temp, ',');
			stringstream(temp) >> year;
			getline(myfile, temp, ',');
			stringstream(temp) >> nominations;
			getline(myfile, temp, ',');
			stringstream(temp) >> rating;
			getline(myfile, temp, ',');
			stringstream(temp) >> duration;
			getline(myfile, genre1, ',');
			getline(myfile, genre2, ',');
			getline(myfile, release, ',');
			getline(myfile, temp, ',');
			stringstream(temp) >> metacritic;
			getline(myfile, synopsis);
			tree->addNode(Picture(name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis));
		}
		myfile.close();
	}
}


int BSTreePictures::size()
{
	return size(root);
}

int BSTreePictures::size(PictureNode* node)		// Traverses the tree, incrementing int sizeTree and returning the size of the tree
{
	if (node != nullptr)
	{
		size(node->Left());
		sizeTree++;
		size(node->Right());
	}
	return sizeTree;
}

void BSTreePictures::changeAllKeys(int& userInput, PictureNode* node)		// Is passed user menu selection to change all keys to any string in Picture Class
{
	if (userInput == 1) {
		if (node != nullptr)
		{
			changeAllKeys(userInput, node->Left());
			node->setKey(node->getPicture().getName());
			changeAllKeys(userInput, node->Right());
		}
	}
	else if (userInput == 2) {
		if (node != nullptr)
		{
			changeAllKeys(userInput, node->Left());
			node->setKey(node->getPicture().getGenre1());
			changeAllKeys(userInput, node->Right());
		}
	}
	else if (userInput == 3) {
		if (node != nullptr)
		{
			changeAllKeys(userInput, node->Left());
			node->setKey(node->getPicture().getGenre2());
			changeAllKeys(userInput, node->Right());
		}
	}
	else if (userInput == 4) {
		if (node != nullptr)
		{
			changeAllKeys(userInput, node->Left());
			node->setKey(node->getPicture().getRelease());
			changeAllKeys(userInput, node->Right());
		}
	}
	else if (userInput == 5) {
		if (node != nullptr)
		{
			changeAllKeys(userInput, node->Left());
			node->setKey(node->getPicture().getSynopsis());
			changeAllKeys(userInput, node->Right());
		}
	}
}

void BSTreePictures::modifyNode(PictureNode * node)			// Is passed a node address and directly targets that node for modification
{
	int userInput = 0;
	int userChoice;
	bool namechange = false;
	string switchString = "";
	string userString;
	while (switchString != "-1") {
		cout << "Please select field you would like to modify" << endl;
		cout << "1. Name 2. Year 3. Nominations 4. Rating 5. Duration 6. Genre1 7. Genre2 8. Release 9. Metacritic 10. Synopsis" << endl;
		cin >> userInput;
		cin.ignore();
		switch (userInput)
		{
		case 1:
			namechange = true;
			cout << "Please enter new name" << endl;								// All options are the same, with the exception ot the first case, since the BST is sorted by name
			getline(cin, userString);
			if (node->nodePicture.getName() == node->nodePicture.getKey()) {		// Checks to see if the Name is the Key
				node->nodePicture.setKey(userString);								// If so, sets Key to the new value
			};
			node->nodePicture.setName(userString);									// Sets name to the new value											// Deletes original node, preserving the function of the BST
			break;
		case 2:
			cout << "Please enter new year" << endl;
			cin >> userChoice;
			cin.ignore();
			node->nodePicture.setYear(userChoice);									// No need to add a new node and delete the old if the name is unchanged, even if the key is different, as the BST is sorted by name
			break;
		case 3:
			cout << "Please how many nominations the picture had" << endl;
			cin >> userChoice;
			cin.ignore();
			node->nodePicture.setNominations(userChoice);
			break;
		case 4:
			cout << "Please the movie's new rating" << endl;
			cin >> userChoice;
			cin.ignore();
			node->nodePicture.setRating(userChoice);
			break;
		case 5:
			cout << "Please the movie's new Duration" << endl;
			cin >> userChoice;
			cin.ignore();
			node->nodePicture.setRating(userChoice);
			break;
		case 6:
			cout << "Please enter new Genre1" << endl;
			getline(cin, userString);
			if (node->nodePicture.getGenre1() == node->nodePicture.getKey()) {
				node->nodePicture.setKey(userString);
			};
			node->nodePicture.setGenre1(userString);
			break;
		case 7:
			cout << "Please enter new Genre2" << endl;
			getline(cin, userString);
			if (node->nodePicture.getGenre2() == node->nodePicture.getKey()) {
				node->nodePicture.setKey(userString);
			};
			node->nodePicture.setGenre2(userString);
			break;
		case 8:
			cout << "Please enter new release month" << endl;
			getline(cin, userString);
			if (node->nodePicture.getRelease() == node->nodePicture.getKey()) {
				node->nodePicture.setKey(userString);
			};
			node->nodePicture.setRelease(userString);
			break;
		case 9:
			cout << "Please the movie's new metacritic rating" << endl;
			cin >> userChoice;
			cin.ignore();
			node->nodePicture.setMetacritic(userChoice);
			break;
		case 10:
			cout << "Please enter new synopsis" << endl;
			getline(cin, userString);
			if (node->nodePicture.getSynopsis() == node->nodePicture.getKey()) {
				node->nodePicture.setKey(userString);
			};
			node->nodePicture.setSynopsis(userString);
			break;
		default:
			break;
		}
		cout << "New Record information" << endl;
		node->nodePicture.printPicture();
		cout << endl;
		cout << "If you are finished, please enter -1, please enter any other number" << endl;
		getline(cin, switchString);
	}
	if (namechange == true)
	{
		addNode(node->nodePicture);												// Adds a new node to the tree with the new value
		deleteTargetNode(node);
	}
}