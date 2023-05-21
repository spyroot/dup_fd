/*
 *
 * Simple duplicate file finder, it does deep check and does it fast.
 * Mus syroot@gmail.com
 */
#include "file_walker.h"
#include "file_comparer.h"

#include <map>
#include <vector>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_paths...>" << std::endl;
        return 1;
    }

    std::vector<std::string> directoryPaths;
    for (int i = 1; i < argc; ++i) {
        const std::string directoryPath(argv[i]);
        if (boost::filesystem::exists(directoryPath) &&
            boost::filesystem::is_directory(directoryPath)) {
            directoryPaths.emplace_back(directoryPath);
        }
    }

    std::map<std::string, std::vector<std::string>> hashToFileMap;

    for (const std::string& directoryPath : directoryPaths) {
        Directory dir(directoryPath);
        dir.walk([&hashToFileMap](const boost::filesystem::path& filePath){
            auto hash = FileDeepHash::compute_evp(filePath.string());
            hashToFileMap[hash].push_back(filePath.string());
        });
    }

    // Print the files with the same hash value
    for (const auto& pair : hashToFileMap) {
        const std::vector<std::string>& files = pair.second;
        if (files.size() > 1) {
            std::cout << "Files with the same hash (" << pair.first << "):" << std::endl;
            for (const std::string& file : files) {
                auto crs = FileDeepHash::compute_crs(file);
                std::cout << file << " crs:" << crs << std::endl;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
