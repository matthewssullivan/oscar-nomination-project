// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// ActorNode.h
// 12/01/17
// Used node.h provided by class as basis for both ActorNode.h and Actor.h

#ifndef ActorNode_
#define ActorNode_
#include <iomanip>
#include "Actor.h"
#include <fstream>
using namespace std;

//Binary Tree Node
class ActorNode {
private:
	ActorNode* left;	//Accessor pointers
	ActorNode* right;
	ActorNode* parent;
public:
	ActorNode() { nodeActor = Actor(); left = nullptr; right = nullptr; parent = nullptr; };	//Default constuctor
	Actor nodeActor;								// Contains Actor object (which contains key)

	ActorNode(const Actor &anActor) {		// Constructor for ActorNode with an Actor object
		nodeActor = anActor;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	};		// Constructor w/information;



	void setLeft(ActorNode* aLeft) { left = aLeft; };				//Pointer modifiers
	void setRight(ActorNode* aRight) { right = aRight; };
	void setParent(ActorNode* aParent) { parent = aParent; };
	void setKey(string aKey) { nodeActor.setKey(aKey); }

	string Key() { return nodeActor.getKey(); };			// Accessors
	void printNode(bool name, bool year, bool award, bool winner, bool film) {
		if (name) {
			cout << "| " << setw(38) << std::left  << nodeActor.getName();
		}
		if (year) {
			cout << "| " << setw(6) << std::left << nodeActor.getYear();
		}
		if (award) {
			cout << "| " << setw(38) << std::left << nodeActor.getAward();
		}
		if (winner) {
			cout << "| " << setw(8) << std::left;
			if (nodeActor.getWinner())
				cout << "Yes";
			else
				cout << "No";
		}
		if (film) {
			cout << "| " << setw(68) << std::left << nodeActor.getFilm();
		}
		cout << "|" << endl;
	};
	void printNodeFile(ofstream& myfile, bool name, bool year, bool award, bool winner, bool film) {
		if (name) {
			myfile << "| " << setw(38) << std::left << nodeActor.getName();
		}
		if (year) {
			myfile << "| " << setw(6) << std::left << nodeActor.getYear();
		}
		if (award) {
			myfile << "| " << setw(38) << std::left << nodeActor.getAward();
		}
		if (winner) {
			myfile << "| " << setw(8) << std::left;
			if (nodeActor.getWinner())
				myfile << "Yes";
			else
				myfile << "No";
		}
		if (film) {
			myfile << "| " << setw(68) << std::left << nodeActor.getFilm();
		}
		myfile << "|" << endl;
	}

	Actor getActor() { return nodeActor; };
	ActorNode* Left() { return left; };
	ActorNode* Right() { return right; };
	ActorNode* Parent() { return parent; };
};
#endif