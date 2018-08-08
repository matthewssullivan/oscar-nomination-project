// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// Database.h
// 12/01/17

#pragma once
#include "BSTreeActors.h"
#include "BSTreePictures.h"

using namespace std;

class Database {
public:
	BSTreeActors actorTree;				// Creates actor BST
	BSTreePictures pictureTree;			// Creates picture PST
	BSTreeActors nomineeTree;			//Nominees share same format as actors

	BSTreeActors *ActorTreePtr;			// Creates pointers to respective BST
	BSTreePictures *PictureTreePtr;
	BSTreeActors *NomineeTreePtr;

	ActorNode* ActorNodePtr;			// Creates pointers to specific nodes in BST
	PictureNode* PictureNodePtr;
	ActorNode* NomineeNodePtr;


	vector<Actor> searchResultsActors;			// Vectors for search data results
	vector<Picture> searchResultsPictures;
	vector<Actor> searchResultsNominees;

	int userInput = 0;

	Database() {ActorTreePtr = &actorTree; PictureTreePtr = &pictureTree; };		// Default constructor sets ActorTreePtr to point at actorTree, and PictureTreePtr to point at PictureTree
	void displayMenu();																// All of these functions are called by the display menu function and all are named for what they do
	void searchActorVector();
	void searchPictureVector();
	void displayActorVector();
	void displayPictureVector();
	void addNode();
	void selectActor();
	void selectPicture();
	void sortSearchVector();
	void displayBSTInorder();
	void printBSTtoCSV();
	void printReport();
	void searchDatabase();		
	void printTreeToFile();
	void printVector();
	void printVectorToFile();
	void readFromFile();	
	void displayVectors();
	void deleteInfo();		//Deletes info from either BST
	void modifyInfo();
	int selectTree();		// These two functions each contain common menu options that was repeated many times throughout the program
	int yesNo();			// I used these two functions to reduce the number of lines in Database.cpp

};