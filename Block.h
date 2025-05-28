// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA4: Blockchain Ledger

#ifndef BLOCK_H // instantiates class once
#define BLOCK_H // defines class name

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <ctime> // includes time
#include <iomanip> // includes manipulators for intToHexStream()
#include <sstream> // includes stringstream

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

class Block { // class body

    public: // public variables and constructors
        int index; // block index
        std::string timestamp; // to store timestamps
        std::string data; // user data
        std::string prevHash; // previous hash value from prior block
        std::string hash; // current hash value determined by previous variables
        Block* next; // the Block's next block
        Block* prev; // the Block's previous block
        // next and previous pointers for Blocks to keep track of adding and position
        Block(); // default constructor for Genesis Block
        Block(int idx, std::string dta, std::string preHash); // overloaded constructor for continuing blocks
        Block(int idx, std::string tmstmp, std::string dta, std::string preHash, std::string hsh);
        // overloaded constructor for loadFromFile()
        ~Block(); // default destructor
        std::string intToHexStream(int num); // converts number to corresponding hash value

};

#endif // ends class definition