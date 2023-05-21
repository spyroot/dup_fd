#ifndef FILECOMPARER_H
#define FILECOMPARER_H

#include <string>

class FileDeepHash {
public:
    static bool areIdentical(const std::string & filePath1, const std::string  & filePath2) ;
    static std::string computeSHA256(const std::string& filePath);
};

#endif // FILECOMPARER_H
