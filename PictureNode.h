// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// PictureNode.h
// 12/01/17
//Used node.h provided by class as basis for both PictureNode.h and Pictures.h

#ifndef PictureNode_
#define PictureNode_
#include <iomanip>
#include <fstream>
#include "Picture.h"
using namespace std;

//Binary Tree Node
class PictureNode {
private:	
	//string key; //This should be the datatype of your key...sorted field in tree
	PictureNode* left;	//Accessor pointers
	PictureNode* right;
	PictureNode* parent;
public:
	PictureNode() { nodePicture = Picture(); left = nullptr; right = nullptr; parent = nullptr; };	//Default constuctor
	Picture nodePicture;
	PictureNode(const Picture &anPicture) {
		nodePicture = anPicture;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	};		// Constructor w/information;



	void setLeft(PictureNode* aLeft) { left = aLeft; };
	void setRight(PictureNode* aRight) { right = aRight; };
	void setParent(PictureNode* aParent) { parent = aParent; };
	void setKey(string aKey) { nodePicture.setKey(aKey); }				// Key is now contained in Picture object nodePicture;
	void printNode(bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis) {
		{
			if (name) {
				cout << "| " << setw(58) << std::left << nodePicture.getName();
			}
			if (year) {
				cout << "| " << setw(6) << std::left << nodePicture.getYear();
			}
			if (nominations) {
				cout << "| " << setw(13) << std::left << nodePicture.getNominations();
			}
			if (rating) {
				cout << "| " << setw(8) << std::left << nodePicture.getRating();
			}
			if (duration) {
				cout << "| " << setw(10) << std::left << nodePicture.getDuration();
			}
			if (genre1) {
				cout << "| " << setw(10) << std::left << nodePicture.getGenre1();
			}
			if (genre2) {
				cout << "| " << setw(10) << std::left << nodePicture.getGenre2();
			}
			if (release) {
				cout << "| " << setw(10) << std::left << nodePicture.getRelease();
			}
			if (metacritic) {
				cout << "| " << setw(13) << std::left << nodePicture.getMetacritic();
			}
			if (synopsis) {
				cout << "| Synopsis: " << setw(226) << std::left << nodePicture.getSynopsis();
			}
			cout << "|" << endl;
		}
	};
	void printNodeFile(ostream& myfile, bool name, bool year, bool nominations, bool rating, bool duration, bool genre1, bool genre2, bool release, bool metacritic, bool synopsis) {
		{
			if (name) {
				myfile << "| " << setw(58) << std::left << nodePicture.getName();
			}
			if (year) {
				myfile << "| " << setw(6) << std::left << nodePicture.getYear();
			}
			if (nominations) {
				myfile << "| " << setw(13) << std::left << nodePicture.getNominations();
			}
			if (rating) {
				myfile << "| " << setw(8) << std::left << nodePicture.getRating();
			}
			if (duration) {
				myfile << "| " << setw(10) << std::left << nodePicture.getDuration();
			}
			if (genre1) {
				myfile << "| " << setw(10) << std::left << nodePicture.getGenre1();
			}
			if (genre2) {
				myfile << "| " << setw(10) << std::left << nodePicture.getGenre2();
			}
			if (release) {
				myfile << "| " << setw(10) << std::left << nodePicture.getRelease();
			}
			if (metacritic) {
				myfile << "| " << setw(13) << std::left << nodePicture.getMetacritic();
			}
			if (synopsis) {
				myfile << "| Synopsis: " << setw(226) << std::left << nodePicture.getSynopsis();
			}
			myfile << "|" << endl;
		}
	};

	string Key() { return nodePicture.getKey(); };		
	Picture getPicture() { return nodePicture; };
	PictureNode* Left() { return left; };
	PictureNode* Right() { return right; };
	PictureNode* Parent() { return parent; };
};



#endif