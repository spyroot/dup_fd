//
// Recursive walker with callback
// spyroot@gmail.com

#ifndef DUP_FINDER_FILE_WALKER_H
#define DUP_FINDER_FILE_WALKER_H
#include <iostream>
#include <iostream>
#include <boost/filesystem.hpp>
#include <utility>
#ifndef BOOST_ALL_DYN_LINK
#   define BOOST_ALL_DYN_LINK
#endif

using namespace boost::filesystem;
using FileCallback = std::function<void(const boost::filesystem::path&)>;

// File
class File {
public:
    explicit File(boost::filesystem::path  path): path_(std::move(path)) {}
    void print() const {
        std::cout << "File: " << path_.string() << std::endl;
    }

private:
    boost::filesystem::path path_;
};

// Directory walker
class Directory {
public:
    explicit Directory(boost::filesystem::path path): path_(std::move(path)) {}

    void print() const {
        std::cout << "Directory: " << path_.string() << std::endl;
    }

    void walk(const FileCallback& callback) const
    {
        try {
            if (boost::filesystem::exists(path_) && boost::filesystem::is_directory(path_)) {
                for (boost::filesystem::directory_entry const& entry: boost::filesystem::directory_iterator(path_)) {
                    if (boost::filesystem::is_directory(entry.path())) {
                        Directory dir(entry.path());
                        dir.print();
                        dir.walk(callback);
                    } else {
                        // callback function
                        callback(entry.path());
                    }
                }
            }
        } catch (const boost::filesystem::filesystem_error& ex) {
            std::cerr << ex.what() << std::endl;
        }
    }

private:
    boost::filesystem::path path_;
};

#endif //DUP_FINDER_FILE_WALKER_H
