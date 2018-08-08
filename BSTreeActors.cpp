// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// BSTreeActors.cpp
// 12/01/17
// Built Based off BSTreeInt.cpp provided by class

#include "BSTreeActors.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor
BSTreeActors::BSTreeActors() {						// Default constructor
	root = nullptr;
}

// Destructor
BSTreeActors::~BSTreeActors() {						// Destructor
	if (root != nullptr)
		freeNode(root);
}

// Free the node
void BSTreeActors::freeNode(ActorNode* leaf)		// Recursive removal of nodes
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

void BSTreeActors::addNode(Actor anActor)			// Add a node
{
	ActorNode * newNode = new ActorNode(anActor);
	newNode->setKey(anActor.getKey());
	if (this->Root()== nullptr)
	{
		this->setRoot(newNode);
	}
	else
		addNode(anActor, this->Root());
}

void BSTreeActors::addNode(Actor anActor, ActorNode* leaf) {	// Add a node (private)
	ActorNode * newNode = new ActorNode(anActor);
	newNode->setKey(anActor.getKey());
	newNode->setLeft(nullptr);
	newNode->setRight(nullptr);
	if ((anActor.getKey() < leaf->Key()))
	{
		if (leaf->Left() == nullptr)
		{
			newNode->setParent(leaf);
			leaf->setLeft(newNode);
		}
		else
			addNode(anActor, leaf->Left());

	}
	else
	{
		if (leaf->Right() == nullptr)
		{
			newNode->setParent(leaf);
			leaf->setRight(newNode);
		}
		else
			addNode(anActor, leaf->Right());
	}
}

ActorNode* BSTreeActors::findNodeExactFirst(string key)			// Find first node based on key
{
	return findNodeExactFirst(key,root);
}

ActorNode* BSTreeActors::findNodeExactFirst(string key, ActorNode* node)	// Private function to find node
{
	if (node == nullptr)								// Base case
	{
		return nullptr;
	}
	if ((key == node->Key()))							// If the search key matches the node's key
	{
		return node;									// Return the node
	}
	if ((key < node->Key()))
	{
		return findNodeExactFirst(key, node->Left());		// If it's smaller go left
	}
	else
	{
		return findNodeExactFirst(key, node->Right());		// if it's greater or equal go right
	}
}

void BSTreeActors::findNodeExactAll(string key, vector<Actor>& data)			// Find all exact nodes if the key is based on the BST
{
	return findNodeExactAll(key, root, data);
}

void BSTreeActors::findNodeExactAll(string key, ActorNode* node, vector<Actor>& data)	// Private find all exact
{
	ActorNode* temp = new ActorNode;				// Temporary node for pushing value onto vector
	if (node == nullptr)							// Base Case
	{
		return;
	}
	if ((key == node->Key()))						// If the key matches
	{
		temp = node;								// Point temp at the node
		temp->nodeActor.setLocation(node);			// Set the location to the actor object
		data.push_back(temp->getActor());			// Push the obect onto the vector
	}
	if ((key < node->Key()))						// Recursively check right and left trees
	{
		return findNodeExactAll(key, node->Left(),data);
	}
	else
	{
		return findNodeExactAll(key, node->Right(),data);
	}
	delete temp;
}

void BSTreeActors::findNodeContainsAll(string key, vector<Actor>& data)
{
	return findNodeContainsAll(key, root, data);
}

// Find a node
void BSTreeActors::findNodeContainsAll(string key, ActorNode* node, vector<Actor>& data)		// Adds all actors from nodes that contain a key to a vector using tree traversal
{
	ActorNode* temp = new ActorNode;
	if (node != nullptr) {
		findNodeContainsAll(key, node->Left(), data);
		if (node->Key().find(key) != string::npos) {
			temp = node;
			temp->nodeActor.setLocation(node);
			data.push_back(temp->getActor());
		}
		findNodeContainsAll(key, node->Right(), data);
	}
	return;

}

void BSTreeActors::findNodeExactStep(string key, vector<Actor>& data)
{
	return findNodeExactStep(key, root, data);
}

void BSTreeActors::findNodeExactStep(string key, ActorNode * node, vector<Actor>& data)		// Very similar to above functions
{																							// Traverses tree and adds all Actors from nodes that match a key exactly to a vector
	ActorNode* temp = new ActorNode;
	if (node != nullptr) {
		findNodeExactStep(key, node->Left(), data);
		if (node->Key()== key) {
			temp = node;
			temp->nodeActor.setLocation(node);
			data.push_back(temp->getActor());
		}
		findNodeExactStep(key, node->Right(), data);
	}
	return;

}

void BSTreeActors::printInorder()			// If no parameters are included, prints all fillds
{
	printInorder(root, true, true, true, true, true);
}

void BSTreeActors::printInorder(bool name, bool year, bool award, bool winner, bool film)		// Passes bool values to indicate which fields are to be printed
{
	printInorder(root, name, year, award, winner, film);
}

void BSTreeActors::printInorder(ActorNode* node, bool name, bool year, bool award, bool winner, bool film)		// Prints the tree inorder using printInorderfunction
{
	if (node != nullptr)
	{
		printInorder(node->Left(), name, year, award, winner, film);
	//	cout << node->getActor();
		node->printNode(name, year, award, winner, film);
		printInorder(node->Right(), name, year, award, winner, film);
	}
}

void BSTreeActors::printInorderFile(ofstream& myfile, bool name, bool year, bool award, bool winner, bool film)	// same as above, but printing to a file rather than cout
{
	printInorderFile(root, myfile, name, year, award, winner, film);
}

void BSTreeActors::printInorderFile(ActorNode* node, ofstream& myfile, bool name, bool year, bool award, bool winner, bool film)
{
	if (node != nullptr)
	{
		printInorderFile(node->Left(), myfile, name, year, award, winner, film);
		//	cout << node->getActor();
		node->printNodeFile(myfile, name, year, award, winner, film);
		printInorderFile(node->Right(), myfile, name, year, award, winner, film);
	}
}

void BSTreeActors::printPreorder()
{
	printPreorder(root);
	cout << endl;
}

void BSTreeActors::printPreorder(ActorNode* node)		// Prints the tree postorder using overloaded << operator
{
	if (node != nullptr)
	{
		cout << node->Key() << ", ";
		printPreorder(node->Left());
		printPreorder(node->Right());
	}
}

void BSTreeActors::printPostorder()
{
	printPostorder(root);
	cout << endl;
}

void BSTreeActors::printPostorder(ActorNode* node)		// Prints postorder using overloaded << operator
{
	if (node != nullptr)
	{
		printPostorder(node->Left());
		printPostorder(node->Right());
		cout << node->Key() << ", ";
	}
}

void BSTreeActors::toCSV(ofstream& myfile)
{
	toCSV(root, myfile);
}

void BSTreeActors::toCSV(ActorNode* node, ofstream& myfile)	// Traverses tree (preorder and writes to a .csv file
{
	if (node != nullptr)
	{
		myfile << node->nodeActor.getYear() << "," << node->nodeActor.getAward() << "," << node->nodeActor.getWinner() << "," << node->nodeActor.getName() << "," << node->nodeActor.getFilm() << endl;
		toCSV(node->Left(), myfile);
		toCSV(node->Right(), myfile);
	}
}


void BSTreeActors::toVector(vector<Actor>& data)
{
	toVector(root, data);
}

void BSTreeActors::toVector(ActorNode * node, vector<Actor>& data)		// Traverses tree and pushes all Actors onto a vector for ease of sorting
{
	if (node != nullptr)
	{
		toVector(node->Left(), data);
		toVector(node->Right(), data);
		data.push_back(node->nodeActor);
	}
}

void BSTreeActors::deleteNode(string key)							// DeleteNode (Public)
{
	{	
		if (deleteNode(Root(), key) == nullptr)
			setRoot(nullptr);
	}
}

ActorNode* BSTreeActors::deleteNode(ActorNode* root, string key)	// DeleteNode (Private) Written by Thomas Augustine with a few modifications
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
			//Node *temp = root;					// Code wasn't working, replaced with below code
			//root = root->Right();
			//delete temp;
			ActorNode *temp = root->Right();
			root->setKey(temp->Key());
			root->setLeft(temp->Left());
			root->setRight(temp->Right());
			delete temp;
		}
		else if (root->Right() == nullptr) {
			//Node *temp = root;					// See above
			//root = root->Left();
			//delete temp;
			ActorNode *temp = root->Left();
			root->setKey(temp->Key());
			root->setLeft(temp->Left());
			root->setRight(temp->Right());
			delete temp;
		}
		else {
			ActorNode *temp = min(root->Right());
			root->setKey(temp->Key());
			root->setRight(deleteNode(root->Right(), temp->Key()));
		}
	}
	return root;
}

void BSTreeActors::deleteTargetNode(ActorNode * target)			// Instead of stepping through tree with a key, has a ActorNode* Target and deletes that target directly
{																// Used in conjunction with the location variable to allow user to select records to delete directly
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
			ActorNode *temp = target->Right();
			target->setKey(temp->Key());
			target->nodeActor = (temp->nodeActor);		//added this
			target->setLeft(temp->Left());
			target->setRight(temp->Right());
			delete temp;
		}
		else if (target->Right() == nullptr) {
			ActorNode *temp = root->Left();
			target->setKey(temp->Key());
			target->nodeActor = (temp->nodeActor);		//added this
			target->setLeft(temp->Left());
			target->setRight(temp->Right());
			delete temp;
		}
		else {
			ActorNode *temp = min(target->Right());
			target->setKey(temp->Key());
			target->nodeActor = (temp->nodeActor);		//added this
			target->setRight(deleteNode(root->Right(), temp->Key()));
		}
		return;
	}
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
ActorNode* BSTreeActors::min(ActorNode* node)
{
	ActorNode* tempNode = node;
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
ActorNode* BSTreeActors::max(ActorNode* node)
{
	ActorNode * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}

void BSTreeActors::readFromFile(string file, BSTreeActors* tree)		// Function to read from a csv file into a BST
{
	Actor newActor;
	ifstream myfile(file);
	int year;
	string award;
	int winner;
	string name;
	string film;
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
			getline(myfile, temp, ',');
			stringstream(temp) >> year;								// stringstream is used to convert temp to integers for integer values so we can use getline for convenience
			getline(myfile, award, ',');
			getline(myfile, temp, ',');
			stringstream(temp) >> winner;
			getline(myfile, name, ',');
			getline(myfile, film);
			tree->addNode(Actor(year, award, winner, name, film));			// Create new node with actor using variables read
		}
		myfile.close();
	}
	else
	{
		while (file != "-1") {
			cout << "File not found, please enter correct file, or enter -1 to exit program" << endl;	// Error handling
			getline(cin, file);
			readFromFile(file, tree);
		}
	}
	

}

int BSTreeActors::size()
{
	return size(root);
}

int BSTreeActors::size(ActorNode* node)		// Steps through the tree and iterates value sizeTree to determine size of the BST
{
	if (node != nullptr)
	{
		size(node->Left());
		sizeTree++;
		size(node->Right());
	}
	return sizeTree;
}

void BSTreeActors::changeAllKeys(int& userInput, ActorNode* node)		// Based on user input, steps through entire tree and sets the key value (for sorting and searching) to Name, Award, or Film
{
		if (userInput == 1) {
			if (node != nullptr)
			{
				changeAllKeys(userInput, node->Left());					// Uses inorder traversal of the tree
				node->setKey(node->getActor().getName());
				changeAllKeys(userInput, node->Right());
			}
		}
		else if (userInput == 2) {
			if (node != nullptr)
			{
				changeAllKeys(userInput, node->Left());
				node->setKey(node->getActor().getAward());
				changeAllKeys(userInput, node->Right());
			}
		}
		else if (userInput == 3) {
			if (node != nullptr)
			{
				changeAllKeys(userInput, node->Left());
				node->setKey(node->getActor().getFilm());
				changeAllKeys(userInput, node->Right());
			}
		}
}

void BSTreeActors::modifyNode(ActorNode * node)			// Code to modify a node in the tree
{
	int userInput = 0;
	int userChoice;
	bool nameChange = false;
	string switchString="";
	string userString;
	while (switchString != "-1") {
		cout << "Please select field you would like to modify" << endl;			// message to user
		cout << "1. Name" << endl << "2. Award" << endl << "3. Winner" << endl << "4. Year" << endl << "5. Film" << endl;
		cin >> userInput;
		cin.ignore();
		switch (userInput)
		{
		case 1:
			nameChange = true;
			cout << "Please enter new name" << endl;							// All options are the same, with the exception ot the first case, since the BST is sorted by name
			getline(cin, userString);
			if (node->nodeActor.getName() == node->nodeActor.getKey()) {		// Checks to see if the Name is the Key
				node->nodeActor.setKey(userString);								// If so, sets Key to the new value
			};
			node->nodeActor.setName(userString);								// Sets name to the new value
			break;
		case 2:
			cout << "Please enter new award" << endl;
			getline(cin, userString);
			if (node->nodeActor.getAward() == node->nodeActor.getKey()) {
				node->nodeActor.setKey(userString);								// No need to add a new node and delete the old if the name is unchanged, even if the key is different, as the BST is sorted by name
			};
			node->nodeActor.setAward(userString);
			break;
		case 3:
			cout << "Please enter a 1 if the actor won, or a 0 if they did not" << endl;
			cin >> userChoice;
			cin.ignore();
			node->nodeActor.setWinner(userChoice);
			break;
		case 4:
			cout << "Please enter new year" << endl;
			cin >> userChoice;
			cin.ignore();
			node->nodeActor.setYear(userChoice);
			break;
		case 5:
			cout << "Please enter new Film" << endl;
			getline(cin, userString);
			if (node->nodeActor.getFilm() == node->nodeActor.getKey()) {
				node->nodeActor.setKey(userString);
			};
			node->nodeActor.setFilm(userString);
			break;
		}
		cout << "New Record information" << endl;
		node->nodeActor.printActor();
		cout << endl;
		cout << "Please enter -1 to exit, or press any other key to continue modifying the record" << endl;
		getline(cin, switchString);
	}
	if (nameChange == true) {
		addNode(node->nodeActor);											// Adds a new node to the tree with the new value
		deleteTargetNode(node);												// Deletes original node, preserving the function of the BST
	}
}
