// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA4: Blockchain Ledger

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include "BlockChain.h" // includes BlockChain class
#include "Block.h" // includes Block class

using std::cout; // shortens output to cout
using std::cin; // shortens input to cin
using std::endl; // shortens newline to endl

int main() { // main method
// takes in a txt file and processes its contents

    cout << endl; // newline for neatness

    try { // try the following program
        BlockChain bc; // create a default blockchain
        int choice = 0; // variable to keep track of actions in switch-case
        // defaults to 0 for proper reading
        std::string blockData; // data when adding a new block
        std::string savedTxt; // file when saving a blockchain
        std::string loadTxt; // file when reading a blockchain
        bool menu = true; // boolean to keep track while the menu is running
        while (menu) {
        // while the user types valid input and does not want to exit the program
            cout << endl;
            // output instructions
            cout << "Welcome to your Panther Blockchain Ledger:" << endl;
            cout << "1. Add a New Block" << endl;
            cout << "2. Display the Blockchain" << endl;
            cout << "3. Validate the Blockchain" << endl;
            cout << "4. Save Blockchain to File" << endl;
            cout << "5. Load Blockchain from File" << endl;
            cout << "6. Exit" << endl;
            // allow the user to enter their choice
            cout << "Enter your choice: ";
            cin >> choice;
            // read input
            switch (choice) {
            // if choice...
                case 1: // 1
                // ADD A NEW BLOCK
                    cout << "Enter block data: ";
                    std::getline(cin, blockData);
                    std::getline(cin, blockData);
                    // input block data and add a new block to the chain
                    bc.addBlock(blockData);
                    break;
                case 2: // 2
                // DISPLAY THE BLOCKCHAIN
                    cout << endl;
                    cout << "   Blockchain State" << endl;
                    cout << endl;
                    bc.display();
                    // call display method
                    // prints all blocks
                    break;
                case 3: // 3
                // VALIDATE THE BLOCKCHAIN
                    cout << endl;
                    cout << "Performing blockchain validation..." << endl;
                    bc.validate();
                    // call validate method
                    // outputs if chain is valid or what is wrong
                    break;
                case 4: // 4
                // SAVE BLOCKCHAIN TO FILE
                    cout << "Enter filename to save the blockchain: ";
                    std::getline(cin, savedTxt);
                    std::getline(cin, savedTxt);
                    // cin >> savedTxt;
                    // input file name and save the blockchain to the file
                    bc.saveToFile(savedTxt);
                    cout << "Blockchain saved to file: " << savedTxt << endl;
                    break;
                case 5: // 5
                // LOAD BLOCKCHAIN FROM FILE
                    cout << "Enter filename to load the blockchain: ";
                    std::getline(cin, loadTxt);
                    std::getline(cin, loadTxt);
                    // input file name and read the blockchain to be stored in bc
                    bc.loadFromFile(loadTxt);
                    cout << "Blockchain loaded from file: " << loadTxt << endl;
                    // output to confirm the blockchain has been read
                    break;
                case 6: // 6
                // END THE PROGRAM
                    cout << "Thank You! Goodbye! :>" << endl;
                    menu = false; // menu is false so while loop exits
                    break;
                default: // any other number
                // END THE PROGRAM
                // and tell them they made an error
                    cout << "invalid input.. try again" << endl;
                    menu = false; // menu is false so while loop exits
                    break;
                    // any other number is invalid, so handle exceptions
            }
        }
    }
    catch (const std::exception& e) { // if something goes wrong
        std::cerr << "Error loading file... " << e.what() << endl;
        // print an error occurred and communicate what happened
        return 1; // end the program
    }

    cout << endl; // newline for neatness

    return 0; // ends the program when success

}