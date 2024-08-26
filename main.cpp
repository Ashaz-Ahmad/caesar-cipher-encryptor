#include <iostream>
#include <cstdio>
#include "encryption.hpp"

using namespace std;

int main()
{
    string filename;
    char mode;

    cout << "Please enter a filename: ";
    getline(cin >> ws, filename);

    cout << "Encrypt or Decrypt the file? Enter your choice (E/D): ";
    cin >> mode;

    if (tolower(mode) == 'e')
    {
        if (encryptFile(filename, true))
        {
            cout << "Encryption completed successfully." <<endl;
            char response;
            cout << "Do you want to delete '" << filename << "' and only keep the encrypted version of the file? You can always decrypt it and get the original version back again. (Y/N): ";
            cin >> response;

            if (tolower(response) == 'n')
            {
                cout << filename << " has not been deleted." <<endl;
            } else 
            {
                if (remove(filename.c_str()) == 0)
                {
                    cout << "File '" << filename << "' was deleted successfully. Only the encrypted version remains." << endl;
                }
                else
                {
                    cerr << "Error: Unable to delete the file '" << filename << "'." << endl;
                }
            }
            
        } else 
        {
            cerr << "Error: encryption failed." <<endl;
        }  
    } else if (tolower(mode) == 'd')
    {
        if (encryptFile(filename, false))
        {
            cout << "Decryption completed successfully." <<endl;
            char response;
            cout << "Do you want to delete '" << filename << "' and only keep the decrypted version of the file? You can always encrypt it again. (Y/N): ";
            cin >> response;

            if (tolower(response) == 'n')
            {
                cout << filename << " has not been deleted." <<endl;
            } else 
            {
                if (remove(filename.c_str()) == 0)
                {
                    cout << "File '" << filename << "' was deleted successfully. Only the decrypted version remains." << endl;
                }
                else
                {
                    cerr << "Error: Unable to delete the file '" << filename << "'." << endl;
                }
            }
        } else
        {
            cerr << "Error: decryption failed." <<endl;
        } 
    } else
    {
        cerr << "Error: invalid mode selected. Please input either 'E' for encryption or 'D' for decryption." <<endl;
    }

    return 0;
}