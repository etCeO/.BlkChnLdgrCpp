// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA4: Blockchain Ledger

#ifndef BLOCKCHAIN_H // instantiates class once
#define BLOCKCHAIN_H // defines BlockChain class

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes ifstream and ofstream
#include <iomanip> // includes manipulators for intToHexSteam() from Block
#include "Block.h" // includes content from Block class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

class BlockChain { // class body

    private: // private variables and methods
        Block* front; // defines the front Block of the chain
        Block* back; // defines the back Block of the chain
        int size; // counts how many Blocks are in the chain
        void deleteBlockChain(); // deletes all blocks from the BlockChain
        void removeFront(); // deletes only the front of the BlockChain

    public: // public constructors and methods
        BlockChain(); // default constructor
        ~BlockChain(); // default destructor
        void addBlock(std::string data); // adds a new block to the blockchain
        void display(); // prints all block information in the blockchain
        void validate(); // validates the blockchain and prints errors
        void saveToFile(std::string outFileName); // saves the blockchain to a new file
        void loadFromFile(std::string inFileName); // loads and modifies the blockchain from an existing file

};

#endif // end of class definition