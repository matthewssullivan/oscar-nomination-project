// Matt Sullivan
// SID: 104396771
// CSCI 2421 001
// Final Project
// Picture.h
// 12/01/17
//Used node.h provided by class as basis for both PictureNode.h and Pictures.h

#pragma once
#include <iostream>
#include <string>
using namespace std;

class PictureNode;				// This is the same as the ActorNode with more variables
class Picture {
private:
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
	PictureNode* location;		// This variable is used to store the location of the ActorNode in the BST when it is returned in a search for modification or deletion

	string key;					// Key is now contained in the Actor Object instead of the Node

public:							
	Picture() {					// Default Constructor
		name = "";
		year = 0;
		nominations = 0;
		rating = 0;
		duration = 0;
		genre1 = "";
		genre2 = "";
		release = "";
		metacritic = 0;
		synopsis = "";
		key = "";
		location = nullptr;
	};
	Picture(string aName, int aYear, int aNom, float aRating, int aDuration,string aGenre1, string aGenre2, string aRelease, int aMeta, string aSynopsis) {			// Constructor with info
		name = aName;
		year = aYear;
		nominations = aNom;
		rating = aRating;
		duration = aDuration;
		genre1 = aGenre1;
		genre2 = aGenre2;
		release = aRelease;
		metacritic = aMeta;
		synopsis = aSynopsis;
		key = aName;
		location = nullptr;
	};		// Constructor w/information;
	Picture(const Picture &aPicture) {					// Copy constructor
		name = aPicture.getName();
		year = aPicture.getYear();
		nominations = aPicture.getNominations();
		rating = aPicture.getRating();
		duration = aPicture.getDuration();
		genre1 = aPicture.getGenre1();
		genre2 = aPicture.getGenre2();
		release = aPicture.getRelease();
		metacritic = aPicture.getMetacritic();
		synopsis = aPicture.getSynopsis();
		key = aPicture.getKey();
		location = aPicture.getLocation();
	}

	void setName(string aName) { name = aName; }									// Modifiers
	void setYear(int aYear) { year = aYear; }
	void setNominations(int numNominations) { nominations = numNominations; }
	void setRating(float aRating) { rating = aRating; }
	void setDuration(int aDuration) { duration = aDuration; }
	void setGenre1(string aGenre) { genre1 = aGenre; }
	void setGenre2(string aGenre) { genre2 = aGenre; }
	void setRelease(string aRelease) { release = aRelease; }
	void setMetacritic(int aMetacritic) { metacritic = aMetacritic; }
	void setSynopsis(string aSynopsis) { synopsis = aSynopsis; }
	void setLocation(PictureNode* aLocation) { location = aLocation; };
	void setKey(string aKey) { key = aKey; };

	string getName() const { return name; }												// Accessors
	int getYear() const { return year; }
	int getNominations() const { return nominations; }
	float getRating() const { return rating; }
	int getDuration() const { return duration; }
	string getGenre1() const { return genre1; }
	string getGenre2() const { return genre2; }
	string getRelease() const { return release; }
	int getMetacritic() const { return metacritic; }
	string getSynopsis() const { return synopsis; }
	string getKey() const { return key; }

	PictureNode * getLocation() const { return location; }

	void printPicture() {		// Replaces below < overloaded operator due to problems with the CSE grid
		cout << "Name: " << this->getName() << " Year: " << this->getYear() << " Nomination: " << this->getNominations() << " Rating: " << this->getRating() << " Duration: ";
		cout << this->getDuration() << " Genre1: " << this->getGenre1() << " Genre2: " << this->getGenre2() << " Release month: " << this->getRelease() << " Metacritic Rating: " << this->getMetacritic() << endl;
		cout << "Synopsis: " << this->getSynopsis() << endl;
		return;

	}
	//friend ostream &operator <<(ostream& out, Picture& aPicture)		// Overloaded << operator for debugging
	//{
	//	out << "Name: " << aPicture.getName() << " Year: " << aPicture.getYear() << " Nomination: " << aPicture.getNominations() << " Rating: " << aPicture.getRating() << " Duration: ";
	//	out << aPicture.getDuration() << " Genre1: " << aPicture.getGenre1() << " Genre2: " << aPicture.getGenre2() << " Release month: " << aPicture.getRelease() << " Metacritic Rating: " << aPicture.getMetacritic() << endl;
	//	out << "Synopsis: " << aPicture.getSynopsis() << endl << " Key: " << aPicture.getKey() << " Location: " << aPicture.getLocation() << endl;
	//	return out;
	//}
	bool operator <(Picture other) const {		// Overloaded < operator for sorting
		if (key < other.getKey())
		{
			return true;
		}
		else
			return false;
	}
};