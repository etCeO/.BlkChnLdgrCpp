# BlockChain Node Constructor

- A program that simulates database insertion operations through object-oriented analysis and file processing, modeling how structured data is parsed, validated, and stored to reflect real-world database management workflows.

## Author Info

- Full Name: Ethan E. Lopez
- Chapman Email: etlopez@chapman.edu

## Source Files
- Main.cpp
- BlockChain.cpp
- BlockChain.h
- Block.cpp
- Block.h
- Blocks.txt

## Errors
- N/A

## Usage

- Compile the program using a C++ compiler:

g++ *.cpp -o block.exe


- Run the below executable:

./block

- The program reads block data from a given text file, constructs the blockchain, and runs the insertion and persistence operations based on the implemented logic.

## Input Format

- The program accepts input in the form of a plain .txt file containing data for blockchains.
- Each entry in the file represents a block with the appropriate fields formatted as expected by the defined structure in the program.
- The loadFromFile() method takes data from the Blocks.txt file included, but any text file that uses the same format can replace it.
- The saveToFile() method dynamically generates output files; thus, there is no need for any pre-existing .txt file for this particular method.

## Implementation Details

- The program is implemented in C++ using object-oriented principles.
- Core components include:

1. Block: Represents an individual block containing structured data
2. Blockchain: Provides functionality for block insertion, validation, and management.

- File processing is used to load block data from text files and persist in evaluating blockchain states.
- Modularity and encapsulation are emphasized in the design to simulate realistic blockchain database workflows.
