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
- 0|Sat Mar 22 06:15:37 2025|Genesis Block|0|ad8
- 1|Sat Mar 22 06:15:41 2025|Elia sent Erik 1000 Panther Coins|ad8|11b7
- 2|Sat Mar 22 06:15:54 2025|Erik sent Elizabeth 88 Panther Coins|11b7|1386
- 3|Sat Mar 22 06:16:17 2025|Elizabeth sent Elia 45 Panther Coins|1386|1347

#### Format Rules
1. Blocks are listed sequentially
2. Each block contains a fixed number of lines representing its fields
3. The first block (genesis block) typically has:
   - A previous hash of 0 or NULL
4. Subsequent blocks must:
   - Reference the hash of the previous block

#### Flexibility
- Any .txt file matching this structure can be used
- The loadFromFile() method reads and parses the input dynamically
- The saveToFile() method generates output files automatically, so no pre-existing output file is required

## Implementation Details

### Core Classes
---

#### 1. Block

- Represents an individual unit in the blockchain.

Typical Attributes:
- Index (block number)
- Timestamp
- Previous hash
- Current hash

Responsibilities:
- Store block data
- Provide accessors/mutators
- Compute hash values

2. BlockChain

- Manages the collection of blocks and enforces structural integrity.

Responsibilities:
- Maintain a sequence of blocks
- Insert new blocks
- Validate block linkage:
  - Ensure previousHash matches the hash of the last block
  - Handle file input/output operations
- File Processing

The program uses file I/O to:
1. Read structured data from Blocks.txt
2. Parse raw text into Block objects
3. Persist blockchain data to output files

Parsing typically involves:
1. Reading line-by-line
2. Grouping lines into block objects
3. Converting strings into appropriate data types

### Blockchain Construction Logic
---

1. Initialize an empty blockchain
2. Read block data from file
3. For each block:
- Create a Block object
4. Validate:
- If first block → treat as genesis block
- Else → check hash linkage
5. Insert into blockchain if valid
6. After processing all blocks:
  - Output final chain state
