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


- Run the executable:

./block

- The program loads block data from a text file, constructs the blockchain, and performs insertion and persistence operations based on the implemented logic.

## Input Format

- The program accepts a plain text (.txt) file containing blockchain block data.
- Each entry in the file represents a block with fields formatted according to the expected structure defined in the program.
- The provided Blocks.txt file is used by the loadFromFile() method but may be replaced with any text file that follows the same format.
- The saveToFile() method generates output files dynamically and does not require a pre-existing text file.

## Implementation Details

- The program is implemented in C++ using object-oriented principles.
- Core components include:
  
1. Block: Represents an individual block containing structured data.
2. Blockchain: Manages block insertion, validation, and ledger integrity.

- File processing is used to load block data from text files and persist the blockchain state to disk.
- The design emphasizes modularity, encapsulation, and separation of concerns to simulate realistic blockchain database workflows.
