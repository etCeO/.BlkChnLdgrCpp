// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA4: Blockchain Ledger

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <ctime> // includes time
#include <iomanip> // includes manipulators for intToHexStream()
#include <sstream> // includes stringstream
#include "Block.h" // includes contents from header file

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

Block::Block() {
// default constructor
// used for creating the "Genesis Block"
    index = 0; // first index
    std::time_t current_time = std::time(nullptr); // time variable declared for exact time
    char buffer[100]; // buffer declared for extraction
    std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", std::localtime(&current_time));
    // formula for converting into desired format
    // ex. Sat Mar 22 06:15:37 2025
    timestamp = std::string(buffer); // stored in variable as a string
    data = "Genesis Block"; // Genesis Block named
    prevHash = "0"; // default value since no previous hashes
    std::string hashString = std::to_string(index) + timestamp + data + prevHash;
    // concatenates index, timestamp, data, and previous hash into one string
    int hashNum = 0; // used for adding sums of ASCII values
    for (char c : hashString) {
    // for every character in the current string
        hashNum += static_cast<int>(c);
        // convert the char into ASCII and add this to the hashNum
    } 
    hash = intToHexStream(hashNum); // returns a string representing the current hash value
    next = NULL;
    prev = NULL;
    // next and previous pointers are initialized to NULL until reassigned in BlockChain
}

Block::Block(int idx, std::string dta, std::string preHash) {
// overloaded constructor
// used for all other blocks added
    index = idx; // pass index
    std::time_t current_time = std::time(nullptr); // time variable declared for exact time
    char buffer[100]; // buffer declared for extraction
    std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", std::localtime(&current_time));
    // formula for converting into desired format
    // ex. Sat Mar 22 06:15:37 2025
    timestamp = std::string(buffer); // stored in variable as a string
    data = dta; // pass data
    prevHash = preHash; // pass the value of the previous hash
    std::string hashString = std::to_string(index) + timestamp + data + prevHash;
    // concatenates index, timestamp, data, and previous hash into one string
    int hashNum = 0; // used for adding sums of ASCII values
    for (char c : hashString) {
    // for every character in the current string
        hashNum += static_cast<int>(c);
        // convert the char into ASCII and add this to the hashNum
    } 
    hash = intToHexStream(hashNum); // returns a string representing the current hash value
    next = NULL;
    prev = NULL;
    // next and previous pointers are initialized to NULL until reassigned in BlockChain
}

Block::Block(int idx, std::string tmstmp, std::string dta, std::string preHash, std::string hsh) {
// overloaded constructor
// used for file processing (loadFromFile method in BlockChain)
    index = idx; // pass index
    timestamp = tmstmp; // pass timestamp
    data = dta; // pass data
    prevHash = preHash; // pass the value of the previous hash
    hash = hsh; // pass current hash
    next = NULL;
    prev = NULL;
    // next and previous pointers are initialized to NULL until reassigned in BlockChain
}

Block::~Block(){
// default destructor
    next = NULL;
    prev = NULL;
    // next and previous are NULL so block is disconnected
}

// PUBLIC METHODS

std::string Block::intToHexStream(int num) {
// a public string method for converting ASCII numbers into a hash value
    std::stringstream ss; // declare a stringstream
    ss << std::hex << num; // use hex function
    return ss.str(); // return corresponding string
}
