#ifndef FILECOMPARER_H
#define FILECOMPARER_H

#include <string>
#include <boost/crc.hpp>

class FileDeepHash {
public:
    static bool areIdentical(const std::string & filePath1, const std::string  & filePath2) ;
    static std::string compute_evp(const std::string& filePath);
    static std::uint32_t compute_crs(const std::string& filePath);
    };

#endif // FILECOMPARER_H
