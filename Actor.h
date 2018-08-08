// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// Actor.h
// 12/01/17
// Used node.h provided by class as basis for both ActorNode.h and Actor.h

#include <iostream>
#include <string>
using namespace std;

class ActorNode;
class Actor{
private:
	int year;		// Data members
	string award;
	int winner;
	string name;
	string film;
	string key;				// Key is now contained in the Actor Object instead of the Node
	ActorNode* location;	// This variable is used to store the location of the ActorNode in the BST when it is returned in a search for modification or deletion

public:
	Actor() {		// Default constructor
		year = 0;
		award = "";
		winner = 0;
		name = "";
		film = "";
		key = "";
		location = nullptr;
	};
	Actor(int aYear, string anAward, int aWinner, string aName, string aFilm) {		// Constructor with variables
		year = aYear;
		award = anAward;
		winner = aWinner;
		name = aName;
		film = aFilm;
		key = aName;
		location = nullptr;
	};		
	Actor(const Actor &anActor) {				// Copy constructor
		year = anActor.getYear();
		award = anActor.getAward();
		winner = anActor.getWinner();
		name = anActor.getName();
		film = anActor.getFilm();
		key = anActor.getKey();
		location = anActor.getLocation();
	}

	void setYear(int aYear) { year = aYear; }			// Modifiers
	void setAward(string anAward) { award = anAward; }
	void setWinner(int aWinner) { winner = aWinner; }
	void setName(string aName) { name = aName; }
	void setFilm(string aFilm) { film = aFilm; }
	void setKey(string aKey) { key = aKey; };
	void setLocation(ActorNode* aLocation) { location = aLocation; };

	int getYear() const { return year; }						// Accessors
	string getAward() const { return award; }
	int getWinner() const { return winner; }
	string getName() const { return name; }
	string getFilm() const { return film; }
	string getKey()const { return key; }
	ActorNode * getLocation() const { return location; }

	void printActor() {																											// Replaces overloaded << operator due to problem with CSE grid
		cout << "Name: " << this->getName() << " Year: " << this->getYear() << " Award: " << this->getAward() << " Winner: ";
		if (this->getWinner() == 1)
			cout << "Yes";
		else
			cout << "No";
		cout << " Film: " << this->getFilm() << endl;
		return;

	}
	//friend ostream &operator <<(ostream& out, Actor& anActor)			// Overloaded << operator for testing
	//{
	//	out << "Name: " << anActor.getName() << " Year: " << anActor.getYear() << " Award: " << anActor.getAward() << " Winner: ";
	//	if (anActor.getWinner() == 1)
	//		out << "Yes";
	//	else
	//		out << "No";
	//	out << " Film: " << anActor.getFilm() << " Key: " << anActor.getKey() << " Location: " << anActor.getLocation() << endl;
	//	return out;

	//}
	bool operator <(Actor other) const {		// Overloaded < operator for sort
		if (key < other.getKey())
		{
			return true;
		}
		else
			return false;
	}
};