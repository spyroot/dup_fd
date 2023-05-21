#include "file_comparer.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/evp.h>
#include <iostream>

bool FileDeepHash::areIdentical(
        const std::string & filePath1,
        const std::string  & filePath2) {
    return computeSHA256(filePath1) == computeSHA256(filePath2);
}

std::string FileDeepHash::computeSHA256(const std::string& filePath)
{
    std::ifstream file(filePath, std::ifstream::binary);
    if (!file) {
        std::cerr << "Cannot open file: " << filePath << std::endl;
        return "";
    }

    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len, i;

    md = EVP_get_digestbyname("sha256");

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, nullptr);

    char buffer[32768];
    while (file.good()) {
        file.read(buffer, sizeof(buffer));
        EVP_DigestUpdate(mdctx, buffer, file.gcount());
    }

    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);

    std::ostringstream shaStr;
    shaStr << std::hex;
    for (i = 0; i < md_len; i++) {
        shaStr << std::setw(2) << std::setfill('0') << (int)md_value[i];
    }
    return shaStr.str();
}
