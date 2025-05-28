// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA4: Blockchain Ledger

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include <fstream> // includes
#include <iomanip>
#include "BlockChain.h"
#include "Block.h" // includes content from Block class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl


BlockChain::BlockChain() {
// default constructor
    Block* genBlock = new Block(); // create genesis block
    front = genBlock; // assign genBlock as the current front
    back = genBlock; // also assign as the current back
    size = 1; // size starts at 1 because of genesis
    // print genesis details
    cout << "| Genesis Block Created |" << endl;
    cout << "   Index: " << genBlock->index << endl;
    cout << "   Timestamp: " << genBlock->timestamp << endl;
    cout << "   Data: " << genBlock->data << endl;
    cout << "   Previous Hash: " << genBlock->prevHash << endl;
    cout << "   Hash: " << genBlock->hash << endl;
    cout << endl;
}

BlockChain::~BlockChain(){
// default destructor
    deleteBlockChain(); // call private method to clear blocks
}

void BlockChain::addBlock(std::string data){
// a public void method for adding blocks to the BlockChain
// used for creating Blocks after Genesis but NOT for file loading
    int idx = size; // index is current size, which is 1 more than previous block's index
    Block* oldBack = back; // pointer for the current back
    std::string preHash = oldBack->hash; // get current back's hash, which will be the previous hash for the new block
    Block* newBlock = new Block(idx, data, preHash); // create a new block with overloaded constructor
    newBlock->prev = back; // assign the new block's previous pointer to current back
    back->next = newBlock; // assign the current back's next pointer to the new block
    back = newBlock; // make the new block the new back
    cout << endl; // print NEW BLOCK details
    cout << "| New Block Added |" << endl;
    cout << "   Index: " << newBlock->index << endl;
    cout << "   Timestamp: " << newBlock->timestamp << endl;
    cout << "   Data: " << newBlock->data << endl;
    cout << "   Previous Hash: " << newBlock->prevHash << endl;
    cout << "   Hash: " << newBlock->hash << endl;
    cout << endl;
    ++size; // update size
}

void BlockChain::display() {
// a public void method for displaying entire blockchains in the terminal
    Block* current = front; // start from front to keep track of the current block
    int pos = 0; // position is 0 to keep track of indexing
    while (pos < size && current != NULL) {
    // while the index is less than the blockchain's size and the current block is not empty
        // print block details
        cout << "Index: " << current->index << endl;
        cout << "\tTimestamp: " << current->timestamp << endl;
        cout << "\tData: " << current->data << endl;
        cout << "\tPrevious Hash: " << current->prevHash << endl;
        cout << "\tHash: " << current->hash << endl;
        cout << endl;
        ++pos; // increment index (position)
        current = current->next; // assign current to the next block
    }
}

void BlockChain::validate() {
// a public void method for validating blockchains
    bool valid = true; // bool to keep track if the blockchain is valid
    Block* current = front; // start from the front to keep track of the current block
    int pos = 0; // position is 0 to keep track of indexing
    while (pos < size && current != NULL) {
    // while the index is less than the blockchain's size and the current block is not empty
        if (pos > 0) {
            // if the block is not the first block
            if (current->prevHash != current->prev->hash) {
                // check if hash values match properly with preceding hash values
                valid = false; // if this is not true, then the blockchain is invalid
                break; // break from the while loop
            }
        }
        // for all blocks
        std::string hashString = std::to_string(current->index) + current->timestamp + current->data + current->prevHash;
        // check to see if all information adds to the correct hash value
        int hashNum = 0; // used for adding sums of ASCII values
        for (char c : hashString) {
            // for every character in the current string
            hashNum += static_cast<int>(c);
            // convert the char into ASCII and add this to the hashNum
        } 
        std::string hashValue = current->intToHexStream(hashNum);
        // store result in hashValue, a variable containing the correct calculations 
        if (size == 1 || pos == size - 1) {
            // if the size of the blockchain is 1 or you are at the last block
            if (current->hash != hashValue) { // only check the current hash without accessing the next block
                // if the current hash is not correct
                valid = false; // the blockchain is not valid
                break; // break from the while loop
            }
        }
        else {
            // if the size of the blockchain is greater than 1 and you are not at the last block
            if (current->hash != hashValue || current->next->prevHash != hashValue) {
                // check if both the current block's hash and the next block's previous hash match the correct value
                // if both or one of these qualifications aren't met...
                valid = false; // the blockchain is not valid
                break; // break from the while loop
            }
        }
        ++pos; // increment index (position)
        current = current->next; // assign current to next block
    }
    if (valid) { // if the blockchain is valid
        cout << "Result: Blockchain is valid :>" << endl;
        // print so
    }
    else { // if the blockchain is not valid
        cout << "Block " << pos << " has an invalid current hash!" << endl;
        cout << "Result: Blockchain is invalid! :<" << endl;
        // print where the error occurs using position variable
    }
}

void BlockChain::saveToFile(std::string outFileName) {
// a public void method that saves a blockchain to a new txt file
// outFile is the file name to be written
   
    std::ofstream outFile(outFileName); // declare writing
    
    if (outFile.is_open()) {
        // if the file is open
        Block* current = front; // begin at the front
        int pos = 0; // variable for indexing
        while (pos < size && current != NULL) {
            // while index is less than the size and the current is not NULL
            // write all block information to the file in the format
            // 0|Sat Mar 22 06:15:37 2025|Genesis Block|0|ad8
            outFile << current->index << "|";
            outFile << current->timestamp << "|";
            outFile << current->data << "|";
            outFile << current->prevHash << "|";
            outFile << current->hash << endl;
            ++pos; // increment position
            current = current->next; // assign the current to the next block
        }
        outFile.close(); // close writing
    }
    else { // if unable to open, print error
        cout << "Something went wrong when writing to the file!" << endl;
    }
}

void BlockChain::loadFromFile(std::string inFileName) {
// a public void method for reading blockchains from a file and storing them in the program
// inFile is the name of the txt file to be read
// assumes we are loading the file immediately after starting the program, NOT after steps have been implemented
    
    std::ifstream inFile(inFileName); // declare reading
    std::string line; // string to keep track of txt lines

    if (inFile.is_open()) {
        // if the file is opened
        deleteBlockChain(); // remove the front Genesis block and continue
        while (std::getline(inFile, line)) {
        // for every line in the txt file
            std::stringstream ss(line); // create a stringstream
            std::string value; // assign value as a placeholder
            std::string blockArr[5]; // create an array of strings to store 5 pieces of block information
            // 1) the index, 2) the timestamp, 3) the data, 4) the previous hash, 5) the current hash
            int valueNum = 0; // value indexing
            while (std::getline(ss,value,'|')) {
                // for every value separated by | in a single line
                if (valueNum < 5) {
                // if indexing is less than 5
                    blockArr[valueNum] = value;
                    // place the value in the appropriate spot (0-4)
                    ++valueNum; // increment index in array
                }
                else {
                // if there is an invalid index, say so
                    cout << "Invalid index found :<" << endl;
                    break;
                }
            }

            if (valueNum != 5) continue; // for lines that don't have 5 pieces of info, skip

            int idx = std::stoi(blockArr[0]); // convert index 0 in block array to an integer and assign this as the index
            std::string tmstmp = blockArr[1]; // assign index 1 in block array to the timestamp
            std::string dta = blockArr[2]; // assign index 2 to the data
            std::string preHash = blockArr[3]; // assign index 3 to the previous hash
            std::string hsh = blockArr[4]; // assign last index to the current hash

            Block* newBlock = new Block(idx, tmstmp, dta, preHash, hsh);
            // use second overloaded constructor to create a new Block

            if (idx != 0) {
                // if this is not the first block
                newBlock->prev = back; // assign the new block's previous pointer to the old back
                back->next = newBlock; // assign the old back's next pointer to the new block
            }
            else {
                // if this is the first block
                front = newBlock; // the front is the new block
            }
            back = newBlock; // assign new block to the back
            ++size; // increment size
        }
    }
    else {
        // if an error occurs when reading, print so
        cout << "Something went wrong reading from the file!" << endl;
    }
}

void BlockChain::removeFront(){
// a private void method that removes the front block in the blockchain
    if (size == 0) {
        // if the chain is empty
        return; // stop operations
    }
    else if (size == 1) {
        // if there is only one block
        delete front; // simply delete the front
        front = NULL;
        back = NULL;
        // then assign pointers to null
    }
    else {
        // if there are two blocks or more
        Block* currFront = front; // identify the current front
        front = front->next; // assign front to the current front's next pointer
        front->prev = NULL; // assign the new front's previous (old front) to NULL
        delete currFront; // delete the current front
    }
    --size; // decrement the size
}

void BlockChain::deleteBlockChain() {
// private void method for clearing all the blocks in the blockchain
// used in destructor and loadFromFile() methods
    Block* current = front; // assign a block to the current front
    while (size > 0) {
        // while the blockchain is not empty
        removeFront(); // keep removing from the front until it is
    }
    front = NULL;
    back = NULL;
    // assign pointers to NULL since the blockchain is now empty
    size = 0; // assign size to 0
}
