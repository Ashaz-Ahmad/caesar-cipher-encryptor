# Caesar Cipher Encryptor

## Overview

This is a simple encryption and decryption program using the Caesar Cipher method. The program allows users to encrypt or decrypt text files using a fixed shift of 16 characters in the alphabet. After encryption or decryption, the program can optionally delete the original file, keeping only the processed version (encrypted or decrypted).

## Features

- Encrypts text files using Caesar Cipher with a shift of 16 characters
- Decrypts previously encrypted text files
- Generates unique filenames for encrypted or decrypted files if the user does not wish to overwrite existing files
- Optionally deletes the original file after encryption or decryption
- Provides basic error handling for file operations (file existence, emptiness, etc.)

## Requirements

- C++17 or higher.
- A C++ compiler such as GCC or Clang.

## How to Install and Run the Program

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Ashaz-Ahmad/caesar-cipher-encryptor.git
   cd caesar-cipher-encryptor
   ```
2. **Compile the Project Using `make`**:
    ```bash
    make
    ```

    This will compile the program and generate the executable called `encryptor`.

3. **Run the Executable**:
    ```bash
    ./encryptor
    ```

## Usage

After running the executable, you will be prompted to enter a file name, as well as your choice of encrypting or decrypting the file.

- If you encrypt a file, the resultant file will be saved with the same file name, prefixed with "encrypted_"
- If you decrypt a file, the resultant file will be saved with the same file name, with the prefix "encrypted_" removed

The program will also check if there is already a file with the same name as the resultant file in the current directory whenever performing encryption/decryption. It will prompt the user asking if they want to overwrite the existing file or not. If not, it will generate a unique file name for the resultant file.

Lastly, the program will ask if you want to delete the original file that was encrypted/decrypted by the program.