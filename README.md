*******************************************************
*  Name      :  Matt Sullivan        
*  Student ID:  ************              
*  Class     :  CSCI 2421           
*  HW#       :  Final Project             
*  Due Date  :  12/01/2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

Demonstrates a binary search tree. Contains two BSTs, one of actors, on of pictures. Both BSTs are sorted by name. Allows user to sort by any field, and search by any string 
field. Allows user to call another search until the user is satisfied. Also creates reports and prints either to string or file. Can convert the BST back into a .csv file.
 Allows user to add, sort, or modify records. All requirements have been met, with the exception of R9, which was reevaluated by Dr. Augustine.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that demonstrates all of the functions listed above.

Name: database.cpp
   File containing the BSTs, the search vectors, the nodePtrs used to access for modify and delete, and many different functions

Name: database.h
   .h file for database.cpp

Name: BSTreeActors.cpp
   File containing code to construct and call functions on a BST made of ActorNodes

Name: BSTreeActors.h
   .h file for BSTreeActors.h

Name: BSTreePictures.cpp
   File containing code to construct and call functions on a BST made of PictureNodes

Name: BSTreePictures.h
   .h file for BSTreePictures.h

Name: ActorNode.cpp
   File containing code to create and implement Nodes of a BST containing an Actor object as their main datatype

Name: ActorNode.h
   .h file for ActorNode.cpp

Name: PictureNode.cpp
   File containing code to create and implement Nodes of a BST containing an Picture object as their main datatype

Name: PictureNode.h
   .h file for PictureNode.cpp

Name: Actor.h
   .h file declaring Actor.h class. Also contains functions so no Actor.cpp class needed

Name: Picture.h
   .h file declaring Picture. class. Also contains functions so no Picture.cpp class needed

Name: actor-actress.csv
   .csv file made of 5 different fields to be read into BSTreeActors

Name: pictures.csv
   .csv file made of 10 different fields to be read into BSTreePictures

Name: nominations.csv
   .csv file made of 5 different fields. Unused by my program, just wanted to include it so if you look at the data, the fields change depending on the type of award
   after 1930, actors/actress nominations are in the correct format, while many others flip the film and the name value. I didn't notice until after class on Thursday
   and I wasn't sure how to proceed with extra credit.

sullivanProjectReadme.txt
   File giving overview, instructions how to run

sullivanDesign.docx
   Deeper Report on functionality, design, includes diagrams of program function and menu input.
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed on VS 2017  tested on CSE grid.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the projectThe homework file is compressed.  
   Uncompress into your network environment. All files should be in the same directory.

   Now you should see a directory named homework with the files:
        main.cpp
	database.cpp
	database.h
	BSTreeActors.cpp
	BSTreeActors.h
	BSTreePictures.cpp
	BSTreePictures.h
	ActorNode.cpp
	ActorNode.h
   	PictureNode.cpp
	PictureNode.h
	Actor.h
	Picture.h
	actor-actress.csv
	pictures.csv
	nominations.csv
        sullivanProjectReadme.txt
	sullivanDesign.docx
	makefile

2. Build the program.

    Change to the directory that contains the file by:
    % cd [sullivanFinalProject] 

    Compile the program by:
    % make

3. Run the program by:
   % ./sullivanProject

4. Delete the obj files, executables, and core dump by
   %./make clean
