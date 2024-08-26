#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

bool fileExists(const std::string& filename);
std::string generateUniqueFilename(const std::string& baseFilename);
bool performCaesarCipher(std::string& content, bool encrypt);
bool encryptFile(const std::string& filename, bool encrypt);

#endif