// Matt Sullivan
//	104396771
// CSCI 2421 001
// Final Project
// Databse.cpp
// 12/01/17


#include "Database.h"
#include<algorithm>					// inluded for sort
#include<fstream>					// included for reading in/out of a file
#include<iomanip>
#include<sstream>

using namespace std;

	void Database::displayMenu()			// Main menu display function
	{
		while (userInput != -1) {
			cout << "Welcome to the Binary Search Tree demonstration program" << endl;		// Message to user
			cout << "Please make a selection below" << endl;
			cout << "1. Read into BST from file" << endl;
			cout << "2. Search for records in BSTs" << endl;
			cout << "3. Add a record to a BST" << endl;
			cout << "4. Modify a specfic record" << endl;						
			cout << "5. Delete a specific record from the search results" << endl;
			cout << "6. Display the current search list" << endl;
			cout << "7. Display the BST inorder" << endl;
			cout << "8. Re-sort the current search lists" << endl;
			cout << "9. Save the current BST to a csv file" << endl;
			cout << "10. Generate and print a report to a file" << endl;
			cout << "0. Exit Program" << endl;
			cin >> userInput;

			switch (userInput) {				// Used switch function. All functions are modular and are later in database.cpp
			case 1:
				readFromFile();
				break;
			case 2:
				searchDatabase();
				break;
			case 3:
				addNode();
				break;
			case 4:
				modifyInfo();
				break;
			case 5:
				deleteInfo();
				break;
			case 6: 
				printVector();
				break;
			case 7:
				displayBSTInorder();
				break;
			case 8:
				sortSearchVector();
				break;
			case 9:
				printBSTtoCSV();
				break;
			case 10:
				printReport();
				break;
			case 0:
				cout << "Thank you for using the BST demonstration program" << endl;
				return;
			default:
				userInput =0;
			}
		}
	}

	void Database::searchActorVector()		// Searching an actor vector for objects
	{
		int userInput = 0;
		int searchType;
		string searchTerm;
		vector<Actor> newVector;
		while (userInput != 1 && userInput != 2 && userInput !=3) {			//While loop for menu
			cout << "What field would you like to search by?" << endl;		// User selects field
			cout << "1. Actor/Actress Name" << endl;
			cout << "2. Award" << endl;
			cout << "3. Film" << endl;
			cin >> userInput;
			cin.ignore();
			while (cin.fail()) {											// Code to prevent bad user input from infinitely looping program this is used in most cases where cin >> appears
				cout << "Please make a valid selection" << endl;			// Code adapted from concepts learned in http://www.dynamicguru.com/tips/cpp-check-if-input-is-valid-data-type-using-cin-fail/
				cin.clear();												
				cin.ignore(numeric_limits<streamsize>::max(), '\n');		// Stack overflow provided the streamsize::(max) part of the code
				cin >> userInput;
			}
			cout << "Would you like to search exact term, or contains term" << endl;	// Message to user
			cout << "1. Exact" << endl;													// User selects type of search they want to run
			cout << "2. Contains" << endl;
			cin >> searchType;
			while (cin.fail()) {											// Checking the stream
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> searchType;
			}
			cin.ignore();
			cout << "Please enter search term" << endl;						// User entered search term
			getline(cin, searchTerm);
			if (userInput == 1)												// If the user is searching by name
			{
				for (int i = 0; i < searchResultsActors.size(); i++)						// Step through vector
				{
					searchResultsActors[i].setKey(searchResultsActors[i].getName());		// update Key on each object to name
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());				// sort vector
				if (searchType == 1) {														// for exact search
					for (int i = 0; i < searchResultsActors.size(); i++)
					{
						if (searchResultsActors[i].getKey() == searchTerm)					// if the keys match exactly
						{
							newVector.push_back(searchResultsActors[i]);					// push the Actors onto newVector
						}
					}
					searchResultsActors = newVector;										// assign the main search value the value of newVector
					return;
				}
				if (searchType == 2) {							
					// contains search
					for (int i = 0; i < searchResultsActors.size(); i++)
					{
						if (searchResultsActors[i].getKey().find(searchTerm) != string::npos)		// Use the same process as above, only with contains
						{
							newVector.push_back(searchResultsActors[i]);
						}
					}
					searchResultsActors = newVector;
					return;
				}
			}
			if (userInput == 2)												// Searching using awards instead of name. Exactly the same as above
			{
				for (int i = 0; i < searchResultsActors.size(); i++)
				{
					searchResultsActors[i].setKey(searchResultsActors[i].getAward());
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());
				if (searchType == 1) {
					for (int i = 0; i < searchResultsActors.size(); i++)
					{
						if (searchResultsActors[i].getKey() == searchTerm)
						{
							newVector.push_back(searchResultsActors[i]);
						}
					}
					searchResultsActors = newVector;
					return;
				}
				if (searchType == 2) {
					for (int i = 0; i < searchResultsActors.size(); i++)
					{
						if (searchResultsActors[i].getKey().find(searchTerm) != string::npos)
						{
							newVector.push_back(searchResultsActors[i]);
						}
					}
					searchResultsActors = newVector;
					return;
				}
			}
			if (userInput == 3)																		// Searching using Film, otherwise identical to the above
			{
				for (int i = 0; i < searchResultsActors.size(); i++)
				{
					searchResultsActors[i].setKey(searchResultsActors[i].getFilm());
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());
				if (searchType == 1) {
					for (int i = 0; i < searchResultsActors.size(); i++)
					{
						if (searchResultsActors[i].getKey() == searchTerm)
						{
							newVector.push_back(searchResultsActors[i]);
						}
					}
					searchResultsActors = newVector;
					return;
				}
				if (searchType == 2) {
					for (int i = 0; i < searchResultsActors.size(); i++)
					{
						if (searchResultsActors[i].getKey().find(searchTerm) != string::npos)
						{
							newVector.push_back(searchResultsActors[i]);
						}
					}
					searchResultsActors = newVector;
					return;
				}
			}
		}
	}

	void Database::searchPictureVector()			// Searching the picture vector. Identical to the above with the exception of different members to search for
	{
		int userInput = 0;
		int searchType;
		string searchTerm;
		vector<Picture> newVector;
		while (userInput != -1 && userInput != 1 && userInput != 2 && userInput !=3 && userInput !=4 && userInput !=5) {
			cout << "What field would you like to search by?" << endl;
			cout << "1. Name" << endl;
			cout << "2. Genre1" << endl;
			cout << "3. Genre2" << endl;
			cout << "4. Release" << endl;
			cout << "5. Synopsis" << endl;
			cout << "-1 to exit" << endl;
			cin >> userInput;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cout << "Would you like to search exact term, or contains term" << endl;
			cout << "1. Exact" << endl;
			cout << "2. Contains" << endl;
			cin >> searchType;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> searchType;
			}
			cin.ignore();
			cout << "Please enter search term" << endl;
			getline(cin, searchTerm);
			if (userInput == 1)
			{
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getName());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
				if (searchType == 1) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey() == searchTerm)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
				if (searchType == 2) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey().find(searchTerm) != string::npos)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
			}
			if (userInput == 2)
			{
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getGenre1());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
				if (searchType == 1) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey() == searchTerm)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
				if (searchType == 2) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey().find(searchTerm) != string::npos)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
			}
			if (userInput == 3)
			{
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getGenre2());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
				if (searchType == 1) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey() == searchTerm)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
				if (searchType == 2) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey().find(searchTerm) != string::npos)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
			}
			if (userInput == 4)
			{
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getRelease());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
				if (searchType == 1) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey() == searchTerm)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
				if (searchType == 2) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey().find(searchTerm) != string::npos)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
			}
			if (userInput == 5)
			{
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getSynopsis());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
				if (searchType == 1) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey() == searchTerm)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
				if (searchType == 2) {
					for (int i = 0; i < searchResultsPictures.size(); i++)
					{
						if (searchResultsPictures[i].getKey().find(searchTerm) != string::npos)
						{
							newVector.push_back(searchResultsPictures[i]);
						}
					}
					searchResultsPictures = newVector;
					return;
				}
			}
		}
	}

	void Database::displayActorVector()												// Displays the actor vector
	{
		if (searchResultsActors.empty())											// If it's empty, print error message
			cout << "There is no Actor/Actress search data available" << endl;
		else
			cout << setw(40) << left << "| Name";
		cout << setw(8) << left << "| Year";
		cout << setw(40) << left << "| Award";
		cout << setw(10) << left << "| Winner";
		cout << setw(70) << left << "| Film";
		cout << "|" << endl;
		for (int i = 0; i < searchResultsActors.size(); i++)
		{
			cout << "| " << setw(38) << left << searchResultsActors[i].getName();
			cout << "| " << setw(6) << left << searchResultsActors[i].getYear();
			cout << "| " << setw(38) << left << searchResultsActors[i].getAward();
			cout << "| " << setw(8) << left;
			if (searchResultsActors[i].getWinner())
				cout << "Yes";
			else
				cout << "No";

			cout << "| " << setw(68) << left << searchResultsActors[i].getFilm();
			cout << "|" << endl;
		}
	}
	

	void Database::displayPictureVector()											// Exactly the same as above, but with pictures
	{
		if (searchResultsPictures.empty())
			cout << "There is no Picture search data available" << endl;
		else
		cout << setw(60) << left << "| Name";
		cout << setw(8) << left << "| Year";
		cout << setw(15) << left << "| Nominations";
		cout << setw(10) << left << "| Rating";
		cout << setw(12) << left << "| Duration";
		cout << setw(12) << left << "| Genre 1";
		cout << setw(12) << left << "| Genre 2";
		cout << setw(12) << left << "| Release";
		cout << setw(15) << left << "| Metacritic";
		cout << "|" << endl;
		for (int i = 0; i < searchResultsPictures.size(); i++)
		{
		cout << "| " << setw(58) << left << searchResultsPictures[i].getName();
		cout << "| " << setw(6) << left << searchResultsPictures[i].getYear();
		cout << "| " << setw(13) << left << searchResultsPictures[i].getNominations();
		cout << "| " << setw(8) << left << searchResultsPictures[i].getRating();
		cout << "| " << setw(10) << left << searchResultsPictures[i].getDuration();
		cout << "| " << setw(10) << left << searchResultsPictures[i].getGenre1();
		cout << "| " << setw(10) << left << searchResultsPictures[i].getGenre2();
		cout << "| " << setw(10) << left << searchResultsPictures[i].getRelease();
		cout << "| " << setw(13) << left << searchResultsPictures[i].getMetacritic();
		cout << endl;
		cout << "| Synopsis: " << setw(148) << left << searchResultsPictures[i].getSynopsis();
		cout << "|" << endl << endl;
		}
	}

	void Database::addNode()	// Function to add either a new actor or picture node to their respective trees
	{
		int addNodeInput;		// userInput variable
		Actor newActor;			// temporary Actor file
		Picture newPicture;		// temporary Picture file
		int year;				// temporary member variables
		string award;
		int winner;
		string name;
		string film;
		int nominations;
		float rating;
		int duration;
		string genre1;
		string genre2;
		string release;
		int metacritic;
		string synopsis;
		
		addNodeInput = selectTree();
		if (addNodeInput == 1)											// Adding to actor tree
		{
			stringstream numConvert;									// Stringstream was suggested on Piazza, read up on in on Cplusplus.com and stack overflow
			string numString;
			cout << "Please enter the Actor/Actress' name" << endl;
			getline(cin, name);											// Uses getline for strings, cin for ints and floats(if applicable)
			newActor.setName(name);
			cout << "Please enter the year" << endl;
			cin >> year;
			while (cin.fail()) {										// Checking cin
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
			newActor.setYear(year);
			cout << "Please enter the award" << endl;
			getline(cin, award);
			newActor.setAward(award);
			cout << "Please indicate if the actor won the award using 1, or did not using 0" << endl;
			cin >> winner;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
			newActor.setWinner(winner);
			cout << "Please enter the film" << endl;
			getline(cin, film);
			newActor.setFilm(film);
			newActor.setKey(name);				// Since BST is sorted by name, name should be the key for insertion into the tree
			actorTree.addNode(newActor);		// Adds a new node to the tree

		}
		if (addNodeInput == 2)				// Exactly the same as above, but with pictures instead of actor objects
		{

			cout << "Please enter the picture's name" << endl;
			getline(cin, name);
			newPicture.setName(name);
			cout << "Please enter the picture's year" << endl;
			cin >> year;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
			newPicture.setYear(year);
			cout << "Please how many nominations the picture had" << endl;
			cin >> nominations;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
			newPicture.setNominations(nominations);
			cout << "Please the picture's rating" << endl;
			cin >> rating;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
			newPicture.setRating(rating);
			cout << "Please the picture's new duration in minutes" << endl;
			cin >> duration;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
			newPicture.setRating(duration);
			cout << "Please enter the picture's Genre1" << endl;
			getline(cin, genre1);
			newPicture.setGenre1(genre1);
			cout << "Please enter the picture's Genre2" << endl;
			getline(cin, genre2);
			newPicture.setGenre2(genre2);
			cout << "Please enter picture's release month" << endl;
			getline(cin, release);
			newPicture.setRelease(release);
			cout << "Please the picture's metacritic rating" << endl;
			cin >> metacritic;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
			newPicture.setMetacritic(metacritic);
			cout << "Please enter picture's synopsis" << endl;
			getline(cin, synopsis);
			newPicture.setSynopsis(synopsis);
			if (pictureTree.Root() == nullptr) {
				newPicture.setKey(name);
			}
			else {
				newPicture.setKey(pictureTree.Root()->getPicture().getKey());
			}
			pictureTree.addNode(newPicture);
		}

	}

	void Database::selectActor()												// A function to select an actor, saves the address as a global variable to modify or delete later
	{
		if (searchResultsActors.empty())										// Needs to be search results
		{
			cout << "No records in search results" << endl;
			return;
		}
		int userInput = 0;
		cout << "Please select a record from the following:" << endl;			
		for (int i = 0; i < searchResultsActors.size(); i++)					// Displays the results contained in the vector, along with their direct access
		{
			cout << i << ". ";
			searchResultsActors[i].printActor();
			cout << endl;
		}
		cin >> userInput;
		while (cin.fail()) {
			cout << "Please make a valid selection" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> userInput;
		}
		cin.ignore();
		while (userInput >= searchResultsActors.size()) {						// Bounds checking
			cout << "Please select a valid record number" << endl;
			cin >> userInput;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
			cin.ignore();
		}
		ActorNodePtr = searchResultsActors[userInput].getLocation();			// Assigns global ActorNodePtr to the address (in the BST) of the record selected from the results
	}

	void Database::selectPicture()												// Exactly the same as above, except with pictures.
	{
		if (searchResultsPictures.empty())
		{
			cout << "No records in search results" << endl;
			
			return;
		}
		int userInput = 0;
		cout << "Please select a record from the following:" << endl;
		for (int i = 0; i < searchResultsPictures.size(); i++)
		{
			cout << i << ". ";
			searchResultsPictures[i].printPicture();
			cout << endl;
		}
		cin >> userInput;
		while (cin.fail()) {
			cout << "Please make a valid selection" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> userInput;
		}
		while (userInput >= searchResultsPictures.size()) {
			cout << "Please select a valid record number" << endl;
			cin >> userInput;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> userInput;
			}
		}
		PictureNodePtr =searchResultsPictures[userInput].getLocation();
	}

	void Database::sortSearchVector()													// Function to allow user to select the value they want the results to be sorted by, used in conjunction with the report function
	{
		int sortSearchInput;
		int searchBy;
		stringstream numConvert;
		string numString;
		cout << "Please select which seach results you would like to resort" << endl;
		sortSearchInput = selectTree();
		if (sortSearchInput == -1) {
			return;
		}
		if (sortSearchInput == 1)																// Sorting the actor results
		{
			cout << "Please indicate the value you would like the results sorted by" << endl;
			cout << "1. Actor/Actress Name" << endl;
			cout << "2. Year" << endl;
			cout << "3. Award" << endl;
			cout << "4. Film" << endl;
			cout << "5. Winner" << endl;
			cin >> searchBy;
			while (cin.fail()) {																// Checking cin
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> searchBy;
			}
			cin.ignore();
			while (searchBy != 1 && searchBy != 2 && searchBy != 3 && searchBy != 4 && searchBy !=5)								// More error checking
			{
				cout << "Please make a valid selection." << endl;
				cin.clear();
				cin.ignore();
				cin >> searchBy;
			}
			if (searchBy == 1) {																// If searching by name
				for (int i = 0; i < searchResultsActors.size(); i++)							// Step through the vector
				{
					searchResultsActors[i].setKey(searchResultsActors[i].getName());			// set key to name for each object
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());				// sort the object using overloaded < operator (compares keys)
			}
			if (searchBy == 2) {																// If sorting by year
				for (int i = 0; i < searchResultsActors.size(); i++)
				{
					numConvert << searchResultsActors[i].getYear();							// use stringstream to convert int year into a string
					numString = numConvert.str();											// converts numConvet into a string
					searchResultsActors[i].setKey(numString);								// sets the key to the string equivalent of year
					numConvert.str(std::string());											// clears the stringstream buffer
					numConvert.clear();
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());
			}
			if (searchBy == 3) {																// The same as name but for award
				for (int i = 0; i < searchResultsActors.size(); i++)
				{
					searchResultsActors[i].setKey(searchResultsActors[i].getAward());
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());
			}
			if (searchBy == 4) {																// Same as name but for film
				for (int i = 0; i < searchResultsActors.size(); i++)
				{
					searchResultsActors[i].setKey(searchResultsActors[i].getFilm());
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());
			}
			if (searchBy == 5) {																// Same as year but with winner
				for (int i = 0; i < searchResultsActors.size(); i++)
				{
					numConvert << searchResultsActors[i].getWinner();
					numString = numConvert.str();
					searchResultsActors[i].setKey(numString);
					numConvert.str(std::string());
					numConvert.clear();
				}
				sort(searchResultsActors.begin(), searchResultsActors.end());
			}
		}
		if (sortSearchInput == 2)																// Exactly the same as above, but for using pictures and picture member variables
		{
			cout << "Please indicate the value you would like the results sorted by" << endl;
			cout << "1. Name" << endl;
			cout << "2. Year" << endl;
			cout << "3. Nominations" << endl;
			cout << "4. Rating" << endl;
			cout << "5. Duration" << endl;
			cout << "6. Genre1" << endl;
			cout << "7. Genre2" << endl;
			cout << "8. Release" << endl;
			cout << "9. Metacritic" << endl;
			cout << "10. Synopsis" << endl;
			cin >> searchBy;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore();
				cin >> searchBy;
			}
			cin.ignore();
			while (searchBy != 1 && searchBy != 2 && searchBy != 3 && searchBy != 4 && searchBy != 5)
			{
				cout << "Please make a valid selection." << endl;
				cin.clear();
				cin.ignore();
				cin >> searchBy;
			}
			if (searchBy == 1) {
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getName());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 2) {																// 
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					numConvert << searchResultsPictures[i].getYear();
					numString = numConvert.str();
					searchResultsPictures[i].setKey(numString);
					numConvert.str(std::string());
					numConvert.clear();
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 3) {																// 
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					numConvert << searchResultsPictures[i].getNominations();
					numString = numConvert.str();
					searchResultsPictures[i].setKey(numString);
					numConvert.str(std::string());
					numConvert.clear();
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 4) {																// 
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					numConvert << searchResultsPictures[i].getRating();
					numString = numConvert.str();
					searchResultsPictures[i].setKey(numString);
					numConvert.str(std::string());
					numConvert.clear();
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 5) {																// 
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					numConvert << searchResultsPictures[i].getDuration();
					numString = numConvert.str();
					searchResultsPictures[i].setKey(numString);
					numConvert.str(std::string());
					numConvert.clear();
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 6) {
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getGenre1());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 7) {
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getGenre2());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 8) {
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getRelease());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 9) {																// 
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					numConvert << searchResultsPictures[i].getMetacritic();
					numString = numConvert.str();
					searchResultsPictures[i].setKey(numString);
					numConvert.str(std::string());
					numConvert.clear();
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
			if (searchBy == 10) {
				for (int i = 0; i < searchResultsPictures.size(); i++)
				{
					searchResultsPictures[i].setKey(searchResultsPictures[i].getSynopsis());
				}
				sort(searchResultsPictures.begin(), searchResultsPictures.end());
			}
		}
	}

	void Database::displayBSTInorder()										// Function to allow user to print entire BST inorder
	{
		int inOrderSelect;
		cout << "Welcome to the print tree inorder function" << endl;
		inOrderSelect =selectTree();
		if (inOrderSelect == 1)												// Prints actorTree inorder
		{
			actorTree.printInorder();
		}
		if (inOrderSelect == 2)												// Prints pictureTree inorder
		{
			pictureTree.printInorder();
		}
	}

	void Database::printBSTtoCSV()											// Function to write the BST to a .csv file
	{
		int csvSelect;
		ofstream myfile;
		string fileSelect;
		cout << "Welcome to the write tree to a csv file function" << endl;
		csvSelect = selectTree();
		if(csvSelect==-1)
		{
			return;
		}
		if (csvSelect == 1) {
			cout << "Please enter 'Save' to save to default file, or type an alternate file name to save as" << endl;		// Allow a "Save" or "Save As" function
			getline(cin, fileSelect);
			if (fileSelect == "Save")									// Save function
			{
				myfile.open("actor-actress.csv", ios::trunc);			// Opens default file and clears it
				myfile << "Year,Award,Winner,Name,Film" << endl;		// Prints opening line
				actorTree.toCSV(myfile);								// Prints the rest of the tree
			}
			else {
				myfile.open(fileSelect, ios::trunc);					// Does the same, but with a user defined file
				myfile << "Year,Award,Winner,Name,Film" << endl;
				actorTree.toCSV(myfile);
			}
			myfile.close();
		}
		if (csvSelect == 2) {											// Same process, but with pictureTree
			cout << "Please enter 'Save' to save to default file, or type an alternate file name to save as" << endl;
			getline(cin, fileSelect);
			if (fileSelect == "Save")
			{
				myfile.open("pictures.csv", ios::trunc);
				myfile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << endl;
				pictureTree.toCSV(myfile);
			}
			else {
				myfile.open(fileSelect);
				myfile << "name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis" << endl;
				pictureTree.toCSV(myfile);
			}
			myfile.close();
		}
	}

	void Database::searchDatabase()
	{
		int userSelect = 0;										// User menu selection variables
		int typeSelect = 0;
		int fieldSearch = 0;
		int moreInput = 0;
		int defaultkey = 1;
		string userString;
		while (userSelect != 1 && userSelect != 2) {			// checks which BST you want to search
			cout << "Welcome to the Search function" << endl;
			userSelect = selectTree();
			if (userSelect == -1) {
				return;
			}
		}
		while (typeSelect != 1 && typeSelect != 2) {											// Checks what kind of search you would like to complete
			cout << "Would you like to search for exact field or contains field" << endl;
			cout << "1. Exact" << endl;
			cout << "2. Contains" << endl;
			cin >> typeSelect;
			while (cin.fail()) {																// Error checking
				cout << "Please make a valid selection" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> typeSelect;
			}
			cin.ignore();
		}

		if (userSelect == 1)																	// searching actor tree
		{
			searchResultsActors.clear();														// clear the vector
			ActorTreePtr->changeAllKeys(defaultkey, ActorTreePtr->Root());						// switch the keys of the tree
			cout << "What field would you like to search by?" << endl;
			cout << "Please be aware that any search other than by name will be less efficient" << endl;	// Message to user
			cout << "1. Actor/Actress Name" << endl;
			cout << "2. Award" << endl;
			cout << "3. Film" << endl;
			cout << "-1 to exit" << endl;
			cin >> fieldSearch;
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;								// Error checking
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> fieldSearch;
			}
			cin.ignore();
		}
		else if (userSelect == 2)																// Searching the picture ture
		{
			searchResultsPictures.clear();														// clear picture results vector
			PictureTreePtr->changeAllKeys(defaultkey, PictureTreePtr->Root());					// switching the keys of the tree
			cout << "What field would you like to search by?" << endl;							//message to user
			cout << "Please be aware that any search other than by name will be less efficient" << endl;
			cout << "1. Name" << endl;
			cout << "2. Genre 1" << endl;
			cout << "3. Genre 2" << endl;
			cout << "4. Release" << endl;
			cout << "5. Synopsis" << endl;
			cout << "-1 to exit" << endl;
			cin >> fieldSearch;																	// Select what field to search
			while (cin.fail()) {
				cout << "Please make a valid selection" << endl;								// error checking
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> fieldSearch;
			}
			cin.ignore();
		}
		cout << "Please enter search term" << endl;
		getline(cin, userString);
		if (userSelect == 1 && typeSelect == 1 && fieldSearch == 1)								// If seaching Actor tree for exact name
		{
			ActorTreePtr->findNodeExactAll(userString, searchResultsActors);					// Call findNodeExactAll with these parameters
		}
		else if (userSelect == 1 && typeSelect == 1 && fieldSearch != 1)						// If searching Actor tree for exact other parameter
		{
			ActorTreePtr->changeAllKeys(fieldSearch, ActorTreePtr->Root());						// Change keys
			ActorTreePtr->findNodeExactStep(userString, searchResultsActors);					// Perform search
		}
		else if (userSelect == 1 && typeSelect == 2 && fieldSearch == 1)						// Searching actor tree for contains name
		{
			ActorTreePtr->findNodeContainsAll(userString, searchResultsActors);
		}
		else if (userSelect == 1 && typeSelect == 2 && fieldSearch != 1)						// searching actor tree for contains other fields
		{
			ActorTreePtr->changeAllKeys(fieldSearch, ActorTreePtr->Root());
			ActorTreePtr->findNodeContainsAll(userString, searchResultsActors);
		}
		else if (userSelect == 2 && typeSelect == 1 && fieldSearch == 1)						// searching picture tree for exact name
		{
			PictureTreePtr->findNodeExactAll(userString, searchResultsPictures);				
		}
		else if (userSelect == 2 && typeSelect == 1 && fieldSearch != 1)						// searching picture tree for exact other fields
		{
			PictureTreePtr->changeAllKeys(fieldSearch, PictureTreePtr->Root());
			PictureTreePtr->findNodeExactAll(userString, searchResultsPictures);
		}
		else if (userSelect == 2 && typeSelect == 2 && fieldSearch == 1)						// searching picture tree for contains name
		{
			PictureTreePtr->findNodeContainsAll(userString, searchResultsPictures);
		}
		else if (userSelect == 2 && typeSelect == 2 && fieldSearch != 1)						// searching picture tree for contains other fields
		{
			PictureTreePtr->changeAllKeys(fieldSearch, PictureTreePtr->Root());
			PictureTreePtr->findNodeContainsAll(userString, searchResultsPictures);
		}

		if (userSelect == 1)
		{
			while (moreInput != -1) {
				cout << "There are " << searchResultsActors.size() << " files returned. Would you like to display the files returned?" << endl;	// Message to user, allows for subsearch
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> moreInput;
				while (cin.fail()) {
					cout << "Please make a valid selection" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> moreInput;
					while (moreInput != 1 && moreInput != 2)						// Error message
					{
						cout << "Please make a valid selection." << endl;
						cin.clear();
						cin.ignore();
						cin >> moreInput;
					}
				}
				if (moreInput == 1)														// Displays search result at request of user
				{
					displayActorVector();
				}
				cout << "Would you like to start a subsearch on these files?" << endl;	// Subsearch
				int moreInput = 0;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> moreInput;
				while (cin.fail()) {
					cout << "Please make a valid selection" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> moreInput;
					while (moreInput != 1 && moreInput != 2)						// Error message
					{
						cout << "Please make a valid selection." << endl;
						cin.clear();
						cin.ignore();
						cin >> moreInput;
					}
				}
				if (moreInput == 1)													// Searches the vector of search results
				{
					searchActorVector();
				}
				else
					break;
			}
		}

		if (userSelect == 2) {														// Same as above, but with the picture tree
			while (moreInput != -1) {
				cout << "There are " << searchResultsPictures.size() << " files returned. Would you like to display the files returned?" << endl;
				moreInput = yesNo();
				if (moreInput == 1)
				{
					displayPictureVector();
				}
				cout << "Would you like to start a subsearch on these files?" << endl;
				int moreInput = 0;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> moreInput;
				while (cin.fail()) {
					cout << "Please make a valid selection" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> moreInput;
					while (moreInput != 1 && moreInput != 2)						// Error message
					{
						cout << "Please make a valid selection." << endl;
						cin.clear();
						cin.ignore();
						cin >> moreInput;
					}
				}
				if (userInput == 1)
				{
					searchPictureVector();
				}
				else
					break;
			}
		}
	}

	void Database::printVector()																	// Code to print reports from a vector
	{
		int userPrompt;
		int menuSwitch;
		bool name = false;
		bool year = false;
		bool award = false;
		bool winner = false;
		bool film = false;
		bool nominations = false;
		bool rating = false;
		bool duration = false;
		bool genre1 = false;
		bool genre2 = false;
		bool release = false;
		bool metacritic = false;
		bool synopsis = false;

		string userChoice;
		cout << "Please indicate which tree you would like to print a report of:" << endl;			// User input
		userPrompt = selectTree();
		if (userPrompt == -1) {
			return;
		}
		if (userPrompt == 1) {																		// Menu that toggles values to print between 0 (no) and 1 (yes)
			while (userPrompt != -1) {
				cout << "What field would you like to toggle?" << endl;
				cout << setw(25) << left << "1. Actor/Actress Name" << name << endl;
				cout << setw(25) << left << "2. Year" << year << endl;
				cout << setw(25) << left << "3. Award" << award << endl;
				cout << setw(25) << left << "4. Winner" << winner << endl;
				cout << setw(25) << left << "5. Film" << film << endl;
				cout << "6. Toggle All" << endl;
				cout << "7. Print all fields" << endl;
				cout << "0. Exit and print" << endl;

				cin >> menuSwitch;																	// Menu switch
				switch (menuSwitch) {
				case 1:
					name = !name;
					break;
				case 2:
					year = !year;
					break;
				case 3:
					award = !award;
					break;
				case 4:
					winner = !winner;
					break;
				case 5:
					film = !film;
					break;
				case 6:
					name = !name;
					year = !year;
					award = !award;
					winner = !winner;
					film = !film;
					break;
				case 7:
					name = true;
					year = true;
					award = true;
					winner = true;
					film = true;
				case 0:
					userPrompt = -1;

				}
				cout << endl;
			}
			if (name) {															// Prints table of file as slected by user
				cout << setw(40) << left << "| Name";
			}
			if (year) {
				cout << setw(8) << left << "| Year";
			}
			if (award) {
				cout << setw(40) << left << "| Award";
			}
			if (winner) {
				cout << setw(10) << left << "| Winner";
			}
			if (film) {
				cout << setw(70) << left << "| Film";
			}
			cout << "|" << endl;
			for (int i = 0; i < searchResultsActors.size(); i++)								// Prints values of files contained in vector to the table
			{
				if (name) {
					cout << "| " << setw(38) << left << searchResultsActors[i].getName();
				}
				if (year) {
					cout << "| " << setw(6) << left << searchResultsActors[i].getYear();
				}
				if (award) {
					cout << "| " << setw(38) << left << searchResultsActors[i].getAward();
				}
				if (winner) {
					cout << "| " << setw(8) << left;
					if (searchResultsActors[i].getWinner())
						cout << "Yes";
					else
						cout << "No";
				}
				if (film) {
					cout << "| " << setw(68) << left << searchResultsActors[i].getFilm();
				}
				cout << "|" << endl;
			}
		}
			
		cout << endl;
		if (userPrompt == 2) {																	// Exactly the same as above, but with picture tree
			while (userPrompt != -1) {
				cout << "What field would you like to toggle?" << endl;
				cout << setw(20) << left << "1. Picture Name" << name << endl;
				cout << setw(20) << left << "2. Year" << year << endl;
				cout << setw(20) << left << "3. Nominations"  << nominations << endl;
				cout << setw(20) << left << "4. Rating" << rating << endl;
				cout << setw(20) << left << "5. Duration"  << duration << endl;
				cout << setw(20) << left << "6. Genre 1"  << genre1 << endl;
				cout << setw(20) << left << "7. Genre 2"  << genre2 << endl;
				cout << setw(20) << left << "8. Release month" << release << endl;
				cout << setw(20) << left << "9. Metacritic Score " << metacritic << endl;
				cout << setw(20) << left << "10. Synopsis" << synopsis << endl;
				cout << "11. Toggle All" << endl;
				cout << "12. Print all fields" << endl;
				cout << "0. Exit and print" << endl;
				cin >> menuSwitch;
				switch (menuSwitch) {
				case 1:
					name = !name;
					break;
				case 2:
					year = !year;
					break;
				case 3:
					nominations = !nominations;
					break;
				case 4:
					rating = !rating;
					break;
				case 5:
					duration = !duration;
					break;
				case 6:
					genre1 = !genre1;
					break;
				case 7:
					genre2 = !genre2;
					break;
				case 8:
					release = !release;
					break;
				case 9:
					metacritic = !metacritic;
					break;
				case 10:
					synopsis = !synopsis;
					break;
				case 11:
					name = !name;
					year = !year;
					nominations = !nominations;
					rating = !rating;
					duration = !duration;
					genre1 = !genre1;
					genre2 = !genre2;
					release = !release;
					metacritic = !metacritic;
					synopsis = !synopsis;
					break;
				case 12:
					name = true;
					year = true;
					nominations = true;
					rating = true;
					duration = true;
					genre1 = true;
					genre2 = true;
					release = true;
					metacritic = true;
					synopsis = true;
				case 0:
					userPrompt = -1;
				}
				cout << endl;
			}
			if (name) {
				cout << setw(60) << left << "| Name";
			}
			if (year) {
				cout << setw(8) << left << "| Year";
			}
			if (nominations) {
				cout << setw(15) << left << "| Nominations";
			}
			if (rating) {
				cout << setw(10) << left << "| Rating";
			}
			if (duration) {
				cout << setw(12) << left << "| Duration";
			}
			if (genre1) {
				cout << setw(12) << left << "| Genre 1";
			}
			if (genre2) {
				cout << setw(12) << left << "| Genre 2";
			}
			if (release) {
				cout << setw(12) << left << "| Release";
			}
			if (metacritic) {
				cout << setw(15) << left << "| Metacritic";
			}
			if (synopsis) {
				cout << setw(150) << left << "| Synopsis";
			}
			}
			cout << "|" << endl;
			for (int i = 0; i < searchResultsPictures.size(); i++)
			{
				if (name) {
					cout << "| " << setw(58) << left << searchResultsPictures[i].getName();
				}
				if (year) {
					cout << "| " << setw(6) << left << searchResultsPictures[i].getYear();
				}
				if (nominations) {
					cout << "| " << setw(13) << left << searchResultsPictures[i].getNominations();
				}
				if (rating) {
					cout << "| " << setw(8) << left << searchResultsPictures[i].getRating();
				}
				if (duration) {
					cout << "| " << setw(10) << left << searchResultsPictures[i].getDuration();
				}
				if (genre1) {
					cout << "| " << setw(10) << left << searchResultsPictures[i].getGenre1();
				}
				if (genre2) {
					cout << "| " << setw(10) << left << searchResultsPictures[i].getGenre2();
				}
				if (release) {
					cout << "| " << setw(10) << left << searchResultsPictures[i].getRelease();
				}
				if (metacritic) {
					cout << "| " << setw(13) << left << searchResultsPictures[i].getMetacritic();
				}
				if (synopsis) {
					cout << endl;
					cout << "| Synopsis: " << setw(148) << left << searchResultsPictures[i].getSynopsis();
				}
				cout << "|" << endl;
			}
		}
	void Database::printVectorToFile()							// This is exactly the same type of code as above, with the exception
	{															// being that it prints to filestream rather than outstream
		int userPrompt;
		int menuSwitch;
		ofstream(myfile);

		bool name = false;
		bool year = false;
		bool award = false;
		bool winner = false;
		bool film = false;
		bool nominations = false;
		bool rating = false;
		bool duration = false;
		bool genre1 = false;
		bool genre2 = false;
		bool release = false;
		bool metacritic = false;
		bool synopsis = false;

		string userChoice;
		cin.ignore();
		cout << "Please enter 'Save' to save in the default file, or enter a new file name" << endl;	// Options for filestream
		getline(cin, userChoice);
		if (userChoice == "Save")
		{
			myfile.open("report.txt", ios::trunc);
		}
		else
			myfile.open(userChoice, ios::trunc);
		if (myfile.is_open()) {
			userPrompt = selectTree();
			if (userPrompt == -1) {
				return;
			}
			if (userPrompt == 1) {															// Otherwise the same
				while (userPrompt != -1) {
					cout << "What field would you like to toggle?" << endl;
					cout << setw(25) << left << "1. Actor/Actress Name" << name << endl;
					cout << setw(25) << left << "2. Year" << year << endl;
					cout << setw(25) << left << "3. Award" << award << endl;
					cout << setw(25) << left << "4. Winner" << winner << endl;
					cout << setw(25) << left << "5. Film" << film << endl;
					cout << "6. Toggle All" << endl;
					cout << "7. Print all fields" << endl;
					cout << "0. Exit and print" << endl;

					cin >> menuSwitch;
					switch (menuSwitch) {
					case 1:
						name = !name;
						break;
					case 2:
						year = !year;
						break;
					case 3:
						award = !award;
						break;
					case 4:
						winner = !winner;
						break;
					case 5:
						film = !film;
						break;
					case 6:
						name = !name;
						year = !year;
						award = !award;
						winner = !winner;
						film = !film;
						break;
					case 7:
						name = true;
						year = true;
						award = true;
						winner = true;
						film = true;
					case 0:
						userPrompt = -1;

					}
					cout << endl;
				}
				if (name) {
					myfile << setw(40) << left << "| Name";
				}
				if (year) {
					myfile << setw(8) << left << "| Year";
				}
				if (award) {
					myfile << setw(40) << left << "| Award";
				}
				if (winner) {
					myfile << setw(10) << left << "| Winner";
				}
				if (film) {
					myfile << setw(70) << left << "| Film";
				}
				myfile << "|" << endl;
				for (int i = 0; i < searchResultsActors.size(); i++)
				{
					if (name) {
						myfile << "| " << setw(38) << left << searchResultsActors[i].getName();
					}
					if (year) {
						myfile << "| " << setw(6) << left << searchResultsActors[i].getYear();
					}
					if (award) {
						myfile << "| " << setw(38) << left << searchResultsActors[i].getAward();
					}
					if (winner) {
						myfile << "| " << setw(8) << left;
						if (searchResultsActors[i].getWinner())
							myfile << "Yes";
						else
							myfile << "No";
					}
					if (film) {
						myfile << "| " << setw(68) << left << searchResultsActors[i].getFilm();
					}
					myfile << "|" << endl;
				}
			}

			cout << endl;
			if (userPrompt == 2) {
				while (userPrompt != -1) {
					cout << "What field would you like to toggle?" << endl;
					cout << setw(20) << left << "1. Picture Name" << name << endl;
					cout << setw(20) << left << "2. Year" << year << endl;
					cout << setw(20) << left << "3. Nominations" << nominations << endl;
					cout << setw(20) << left << "4. Rating" << rating << endl;
					cout << setw(20) << left << "5. Duration" << duration << endl;
					cout << setw(20) << left << "6. Genre 1" << genre1 << endl;
					cout << setw(20) << left << "7. Genre 2" << genre2 << endl;
					cout << setw(20) << left << "8. Release month" << release << endl;
					cout << setw(20) << left << "9. Metacritic Score " << metacritic << endl;
					cout << setw(20) << left << "10. Synopsis" << synopsis << endl;
					cout << "11. Toggle All" << endl;
					cout << "12. Print all fields" << endl;
					cout << "0. Exit and print" << endl;
					cin >> menuSwitch;
					switch (menuSwitch) {
					case 1:
						name = !name;
						break;
					case 2:
						year = !year;
						break;
					case 3:
						nominations = !nominations;
						break;
					case 4:
						rating = !rating;
						break;
					case 5:
						duration = !duration;
						break;
					case 6:
						genre1 = !genre1;
						break;
					case 7:
						genre2 = !genre2;
						break;
					case 8:
						release = !release;
						break;
					case 9:
						metacritic = !metacritic;
						break;
					case 10:
						synopsis = !synopsis;
						break;
					case 11:
						name = !name;
						year = !year;
						nominations = !nominations;
						rating = !rating;
						duration = !duration;
						genre1 = !genre1;
						genre2 = !genre2;
						release = !release;
						metacritic = !metacritic;
						synopsis = !synopsis;
						break;
					case 12:
						name = true;
						year = true;
						nominations = true;
						rating = true;
						duration = true;
						genre1 = true;
						genre2 = true;
						release = true;
						metacritic = true;
						synopsis = true;
					case 0:
						userPrompt = -1;
					}
					cout << endl;
				}
				if (name) {
					myfile << setw(60) << left << "| Name";
				}
				if (year) {
					myfile << setw(8) << left << "| Year";
				}
				if (nominations) {
					myfile << setw(15) << left << "| Nominations";
				}
				if (rating) {
					myfile << setw(10) << left << "| Rating";
				}
				if (duration) {
					myfile << setw(12) << left << "| Duration";
				}
				if (genre1) {
					myfile << setw(12) << left << "| Genre 1";
				}
				if (genre2) {
					myfile << setw(12) << left << "| Genre 2";
				}
				if (release) {
					myfile << setw(12) << left << "| Release";
				}
				if (metacritic) {
					myfile << setw(15) << left << "| Metacritic";
				}
				if (synopsis) {
					myfile << setw(228) << left << "| Synopsis";
				}
			}
			myfile << "|" << endl;
			for (int i = 0; i < searchResultsPictures.size(); i++)
			{
				if (name) {
					myfile << "| " << setw(58) << left << searchResultsPictures[i].getName();
				}
				if (year) {
					myfile << "| " << setw(6) << left << searchResultsPictures[i].getYear();
				}
				if (nominations) {
					myfile << "| " << setw(13) << left << searchResultsPictures[i].getNominations();
				}
				if (rating) {
					myfile << "| " << setw(8) << left << searchResultsPictures[i].getRating();
				}
				if (duration) {
					myfile << "| " << setw(10) << left << searchResultsPictures[i].getDuration();
				}
				if (genre1) {
					myfile << "| " << setw(10) << left << searchResultsPictures[i].getGenre1();
				}
				if (genre2) {
					myfile << "| " << setw(10) << left << searchResultsPictures[i].getGenre2();
				}
				if (release) {
					myfile << "| " << setw(10) << left << searchResultsPictures[i].getRelease();
				}
				if (metacritic) {
					myfile << "| " << setw(13) << left << searchResultsPictures[i].getMetacritic();
				}
				if (synopsis) {
					myfile << "| Synopsis: " << setw(226) << left << searchResultsPictures[i].getSynopsis();
				}
				myfile << "|" << endl;
			}
		}
	}

	void Database::printTreeToFile()						// This prints a tree inorder into a file
	{														// Otherwise very similar to the above for vectors
		int userPrompt;
		int menuSwitch;
		ofstream(myfile);

		bool name = false;					// Bool variables to determine what fields are printed
		bool year = false;
		bool award = false;
		bool winner = false;
		bool film = false;
		bool nominations = false;
		bool rating = false;
		bool duration = false;
		bool genre1 = false;
		bool genre2 = false;
		bool release = false;
		bool metacritic = false;
		bool synopsis = false;

		string userChoice;

		cout << "Please enter 'Save' to save in the default file, or enter a new file name" << endl;	// Select where to write out
		getline(cin, userChoice);
		if (userChoice == "Save")
		{
			myfile.open("report.txt", ios::trunc);
		}
		else
			myfile.open(userChoice, ios::trunc);
		if (myfile.is_open()) {
			cout << "Please indicate which tree you would like to print a report of:" << endl;
			userPrompt = selectTree();
			if (userPrompt == -1) {
				return;
			}
			if (userPrompt == 1) {
				while (userPrompt != -1) {
					cout << "What field would you like to toggle?" << endl;
					cout << setw(25) << left << "1. Actor/Actress Name" << name << endl;
					cout << setw(25) << left << "2. Year" << year << endl;
					cout << setw(25) << left << "3. Award" << award << endl;
					cout << setw(25) << left << "4. Winner" << winner << endl;
					cout << setw(25) << left << "5. Film" << film << endl;
					cout << "6. Toggle All" << endl;
					cout << "7. Print all fields" << endl;
					cout << "0. Exit and print" << endl;

					cin >> menuSwitch;
					switch (menuSwitch) {
					case 1:
						name = !name;
						break;
					case 2:
						year = !year;
						break;
					case 3:
						award = !award;
						break;
					case 4:
						winner = !winner;
						break;
					case 5:
						film = !film;
						break;
					case 6:
						name = !name;
						year = !year;
						award = !award;
						winner = !winner;
						film = !film;
						break;
					case 7:
						name = true;
						year = true;
						award = true;
						winner = true;
						film = true;
					case 0:
						userPrompt = -1;

					}
					cout << endl;
				}
				if (name) {
					myfile << setw(40) << left << "| Name";
				}
				if (year) {
					myfile << setw(8) << left << "| Year";
				}
				if (award) {
					myfile << setw(40) << left << "| Award";
				}
				if (winner) {
					myfile << setw(10) << left << "| Winner";
				}
				if (film) {
					myfile << setw(70) << left << "| Film";
				}
				myfile << "|" << endl;
				
				actorTree.printInorderFile(myfile, name, year, award, winner, film);			// Calls print inorder on the BST rather than on the vector
			}

			cout << endl;
			if (userPrompt == 2) {																// Exactly the same as the above, but with the picture tree
				while (userPrompt != -1) {
					cout << "What field would you like to toggle?" << endl;
					cout << setw(20) << left << "1. Picture Name" << name << endl;
					cout << setw(20) << left << "2. Year" << year << endl;
					cout << setw(20) << left << "3. Nominations" << nominations << endl;
					cout << setw(20) << left << "4. Rating" << rating << endl;
					cout << setw(20) << left << "5. Duration" << duration << endl;
					cout << setw(20) << left << "6. Genre 1" << genre1 << endl;
					cout << setw(20) << left << "7. Genre 2" << genre2 << endl;
					cout << setw(20) << left << "8. Release month" << release << endl;
					cout << setw(20) << left << "9. Metacritic Score " << metacritic << endl;
					cout << setw(20) << left << "10. Synopsis" << synopsis << endl;
					cout << "11. Toggle All" << endl;
					cout << "12. Print all fields" << endl;
					cout << "0. Exit and print" << endl;
					cin >> menuSwitch;
					switch (menuSwitch) {
					case 1:
						name = !name;
						break;
					case 2:
						year = !year;
						break;
					case 3:
						nominations = !nominations;
						break;
					case 4:
						rating = !rating;
						break;
					case 5:
						duration = !duration;
						break;
					case 6:
						genre1 = !genre1;
						break;
					case 7:
						genre2 = !genre2;
						break;
					case 8:
						release = !release;
						break;
					case 9:
						metacritic = !metacritic;
						break;
					case 10:
						synopsis = !synopsis;
						break;
					case 11:
						name = !name;
						year = !year;
						nominations = !nominations;
						rating = !rating;
						duration = !duration;
						genre1 = !genre1;
						genre2 = !genre2;
						release = !release;
						metacritic = !metacritic;
						synopsis = !synopsis;
						break;
					case 12:
						name = true;
						year = true;
						nominations = true;
						rating = true;
						duration = true;
						genre1 = true;
						genre2 = true;
						release = true;
						metacritic = true;
						synopsis = true;
					case 0:
						userPrompt = -1;
					}
					cout << endl;
				}
				if (name) {
					myfile << setw(60) << left << "| Name";
				}
				if (year) {
					myfile << setw(8) << left << "| Year";
				}
				if (nominations) {
					myfile << setw(15) << left << "| Nominations";
				}
				if (rating) {
					myfile << setw(10) << left << "| Rating";
				}
				if (duration) {
					myfile << setw(12) << left << "| Duration";
				}
				if (genre1) {
					myfile << setw(12) << left << "| Genre 1";
				}
				if (genre2) {
					myfile << setw(12) << left << "| Genre 2";
				}
				if (release) {
					myfile << setw(12) << left << "| Release";
				}
				if (metacritic) {
					myfile << setw(15) << left << "| Metacritic";
				}
				if (synopsis) {
					myfile << setw(228) << left << "| Synopsis";
				}
			}
			myfile << "|" << endl;
			pictureTree.printInorderFile(myfile, name, year, nominations, rating, duration, genre1, genre2, release, metacritic, synopsis);
		}
	}

	void Database::readFromFile()					// Reads from .csv file into BST
	{
		int userPrompt;
		string userChoice;
		cout << "Please indicate if you would like to read into the Actors/Actresses search tree, or the Pictures search tree" << endl;		// User selection
		userPrompt = selectTree();
		if (userPrompt == -1) {
			return;
		}
		cout << "Please enter 1 if you want to read from default file, or type anything else to search for that filename" << endl;			// user selection
		cin >> userChoice;
		if (userPrompt == 1) {
			if (userChoice == "1")
				ActorTreePtr->readFromFile("actor-actress.csv", ActorTreePtr);			// Default read actor tree
			else
				ActorTreePtr->readFromFile(userChoice, ActorTreePtr);					// Custom read actor tree
		}
		if (userPrompt == 2) {
			if (userChoice == "1")
				PictureTreePtr->readFromFile("pictures.csv", PictureTreePtr);			// default read picture tree
			else
				PictureTreePtr->readFromFile(userChoice, PictureTreePtr);				// default read picture tree

		}
	}

	void Database::displayVectors()														// function for displaying vectors for either search tree
	{
		int userPrompt = 0;
		while (userPrompt != -1)
		{
			cout << "Please select the search data you would like to display:" << endl;
			userPrompt = selectTree();
			if (userPrompt == -1) {
				return;
			}
			if (userPrompt == 1)
			{
				displayActorVector();
				userPrompt = -1;
			}
			if (userPrompt == 2)
			{
				displayPictureVector();
				userPrompt = -1;
			}
			else
				cout << "Please make a valid selection" << endl;
		}
	}

	void Database::deleteInfo()			// Function to delete a node directly using its address
	{
		int userPrompt = 0;
		int userInput = 0;
		while (userPrompt != -1)
		{
			cout << "Please select the search data you would like to display:" << endl;
			userPrompt = selectTree();
			if (userPrompt == -1) {
				return;
			}
			if (userPrompt == 1)
			{
				selectActor();				// Selects an actor from the actor results
			}
			if (userPrompt == 2)
			{
				selectPicture();			// Selects a picture from the picture results
			}

			if (userPrompt == 1) {
				while (ActorNodePtr != nullptr && userInput != -1) {
					cout << "Do you wish to delete the following record in the tree?" << endl;		// confirms file deletion

					ActorNodePtr->getActor().printActor();
					cout << endl;
					userInput = yesNo();
					while (userInput != 1 && userInput != 2)
						cout << "Please enter a valid input" << endl;								// If the user confirms, deletes the node at the address
					if (userInput == 1)
					{
						actorTree.deleteTargetNode(ActorNodePtr);
						userInput = -1;
					}
					else
						break;
				}
			}
			if (userPrompt == 2)
			{
				while (PictureNodePtr != nullptr && userInput != -1) {
					cout << "Do you wish to delete the following record in the tree?" << endl;		// confirms file deletion
					PictureNodePtr->getPicture().printPicture();
					cout << endl;
					userInput = yesNo();
					while (userInput != 1 && userInput != 2)
						cout << "Please enter a valid input" << endl;								
					if (userInput == 1)
					{	
						pictureTree.deleteTargetNode(PictureNodePtr);								// If the user confirms, deletes the node at the address
						userInput = -1;
					}
					else
						break;
				}
			}
			else
				userPrompt = -1;
		}
	}

	void Database::modifyInfo()							// Exactly the same as above, but modifying the value rather than deleting it
	{
		int userPrompt = 0;
		int userInput = 0;
		while (userPrompt != -1)
		{
			cout << "Please select the search data you would like to display:" << endl;
			userPrompt = selectTree();
			if (userPrompt == -1) {
				return;
			}
			if (userPrompt == 1)
			{
				selectActor();
			}
			if (userPrompt == 2)
			{
				selectPicture();
			}

			if (userPrompt == 1) {
				while (ActorNodePtr != nullptr && userInput != -1) {
					cout << "Do you wish to modify the following record in the tree?" << endl;

					ActorNodePtr->getActor().printActor();
					cout << endl;
					userInput = yesNo();
					while (userInput != 1 && userInput != 2)
						cout << "Please enter a valid input" << endl;
					if (userInput == 1)
					{
						actorTree.modifyNode(ActorNodePtr);
						userInput = -1;
					}
					else
						break;
				}
			}
			if (userPrompt == 2)
			{
				while (PictureNodePtr != nullptr && userInput != -1) {
					cout << "Do you wish to modify the following record in the tree?" << endl;
					PictureNodePtr->getPicture().printPicture();
					cout << endl;
					userInput = yesNo();
					while (userInput != 1 && userInput != 2)
						cout << "Please enter a valid input" << endl;
					if (userInput == 1)
					{
						pictureTree.modifyNode(PictureNodePtr);
						userInput = -1;
					}
					else
						break;
				}
			}
			else
				userPrompt = -1;
		}
	}
	
	int Database::selectTree()						// Code to replace common menu selection and file checking throghout my code
	{
		int userInput;
		cout << "Please select a tree" << endl;		// User selects which tree
		cout << "1. Actor/Actress Tree" << endl;
		cout << "2. Picture Tree" << endl;
		cout << "-1 to exit" << endl;
		cin >> userInput;
		while (cin.fail()) {												// Checking cin
			cout << "Please make a valid selection" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> userInput;
		}
		cin.ignore();
		if (userInput == -1)
			return -1;
		while (userInput != 1 && userInput != 2)						// Error message
		{
			cout << "Please make a valid selection." << endl;
			cin.clear();
			cin.ignore();
			cin >> userInput;
		}
		return userInput;
	}

	int Database::yesNo()			// Also a menu selection/input checking function that reduces space in the code
	{
		int userInput = 0;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> userInput;
		while (cin.fail()) {
			cout << "Please make a valid selection" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> userInput;
			while (userInput != 1 && userInput != 2)						// Error message
			{
				cout << "Please make a valid selection." << endl;
				cin.clear();
				cin.ignore();
				cin >> userInput;
			}
		}
		return userInput;

	}
	void Database::printReport()		// Print report function to combine all of the reporting functions in a single user interface
	{
		int userInput = 0;
		int displayInput = 0;
		int typeInput = 0;
		cout << "Welcome to the Generate Report function" << endl;
		cout << "Would you like to:" << endl;
		cout << "1. Print report to screen" << endl;							// Asks user where to print information to
		cout << "2. Print report to file" << endl;
		cout << "-1 Exit" << endl;
		cin >> displayInput;													// Gets display input
		cin.ignore();
		while (cin.fail()) {
			cout << "Please make a valid selection" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> displayInput;
			while (displayInput != 1 && displayInput != 2)						// Error message
			{
				cout << "Please make a valid selection." << endl;
				cin.clear();
				cin.ignore();
				cin >> displayInput;
			}
		}
		if (displayInput == -1) {
			return;
		}
		cout << "Would you like to:" << endl;							// Asks user to choose between printing BST, or vector with most recent results
		cout << "1. Print print search results" << endl;
		cout << "2. Print entire tree" << endl;
		cin >> typeInput;
		cin.ignore();
		while (cin.fail()) {
			cout << "Please make a valid selection" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> typeInput;
			cin.ignore();
		}
		while (typeInput != 1 && typeInput != 2)						// Error message
		{
			cout << "Please make a valid selection." << endl;
			cin.clear();
			cin.ignore();
				cin >> typeInput;
		}
		if (displayInput == 1 && typeInput == 1)			// If print to screen and search
		{
			printVector();									// Calls printVector
		}
		if (displayInput == 2 && typeInput == 1)			// If print to file and search
		{
			printVectorToFile();							// Calls printVectorToFile
		}
		if (displayInput == 1 && typeInput == 2)			// If print to screen and BST
		{
			displayBSTInorder();							// Calls displayBSTInorder
		}
		if (displayInput == 2 && typeInput == 2)			// If print to file and BST
		{
			printTreeToFile();								// Calls printTreeToFile
		}
	}