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

### Program Behavior
---

Upon execution, the program:
1. Loads block data from an input file (default: Blocks.txt)
2. Parses each block entry into structured objects
3. Inserts blocks sequentially into the blockchain
4. Validates each block before insertion (e.g., ensuring proper linkage)
5. Optionally writes the resulting blockchain state to an output file

#### Expected Output

1. Print the blockchain contents to the console
2. Generate a new .txt file representing the updated blockchain

## Input Format

The program reads from a .txt file (default: Blocks.txt) containing structured blockchain data or creates data chains from scratch.

### General Structure
---

Each block in the file should include key fields such as:
- Block index (or ID)
- Timestamp
- Previous hash
- Current hash

Example (Blocks.txt):



Format Rules
Blocks are listed sequentially
Each block contains a fixed number of lines representing its fields
Blank lines may separate blocks (depending on parser design)
The first block (genesis block) typically has:
A previous hash of 0 or NULL
Subsequent blocks must:
Reference the hash of the previous block
Flexibility
Any .txt file matching this structure can be used
The loadFromFile() method reads and parses the input dynamically
The saveToFile() method generates output files automatically, so no pre-existing output file is required

## Implementation Details

- The program is implemented in C++ using object-oriented principles.
- Core components include:

1. Block: Represents an individual block containing structured data
2. Blockchain: Provides functionality for block insertion, validation, and management.

- File processing is used to load block data from text files and persist in evaluating blockchain states.
- Modularity and encapsulation are emphasized in the design to simulate realistic blockchain database workflows.
