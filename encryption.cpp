#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <filesystem>
#include "encryption.hpp"

using namespace std;

bool fileExists(const string& filename)
{
    return filesystem::exists(filename); 
}

string generateUniqueFilename(const string& baseFilename)
{
    int counter = 1;
    string uniqueFilename = baseFilename;
    
    while (fileExists(uniqueFilename))
    {
        uniqueFilename = baseFilename + "_" + to_string(counter);
        counter++;
    }
    return uniqueFilename;
}

bool performCaesarCipher(string& content, bool encrypt)
{
    int shift = encrypt ? 16 : -16;

    for (char& ch: content)
    {
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }
    return true;
}

bool encryptFile(const string& filename, bool encrypt)
{
    if (!fileExists(filename))
    {
        cerr << "Error: The file '" << filename << "' does not exist." << endl;
        return false;
    }

    if (filesystem::file_size(filename) == 0)
    {
        cerr << "Error: The file '" << filename << "' is empty." << endl;
        return false;
    }
    
    ifstream inFile(filename);

    if (!inFile)
    {
        cerr << "Error: Failed to open the file '" << filename << endl;
        return false;
    }
    
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();


    if (performCaesarCipher(content, encrypt))
    {
        string outputFilename;

        if (encrypt)
        {
            outputFilename = "encrypted_" + filename;
        }
        else
        {
            if (filename.find("encrypted_") == 0)
            {
                outputFilename = filename.substr(10); 
            }
            else
            {
                outputFilename = "decrypted_" + filename; 
            }
        }

        if (fileExists(outputFilename))
        {
            char response;
            cout << "Warning: The file '" << outputFilename << "' already exists. Do you want to overwrite it? (Y/N): ";
            cin >> response;
            if (tolower(response) == 'n')
            {
                outputFilename = generateUniqueFilename(outputFilename);
                cout << "The new file will be saved as '" << outputFilename << "' instead." << endl;
            }
            else
            {
                cout << "The file has been overwritten" << endl;
            }
        }

        ofstream outFile(outputFilename);

        if (!outFile)
        {
            cerr << "Error: Failed to create the output file '" << outputFilename << "'. Please check if you have write permissions." << endl;
            return false;
        }
        outFile << content;
        outFile.close();
        return true;
    } else
    {
        cerr << "Error: Caesar Cipher operation failed." << endl;
        return false;
    }
}