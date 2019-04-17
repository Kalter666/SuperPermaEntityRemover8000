#include <filesystem>
#include <iostream>
#include <vector>

#include "removeFile.cpp"

class dir {
 public:
  std::string name;
  std::vector<std::string> files;
  std::vector<dir> dirs;
  bool isDir;
};

class removeDir {
 private:
  std::string rootPath;
  std::vector<dir> dirs;

  std::vector<dir> buildTree() {
    for (const auto& entry :
         std::filesystem::directory_iterator(removeDir::rootPath))
      std::cout << entry.path() << std::endl;
  }

 public:
  removeDir(std::string path);
  ~removeDir();
};

removeDir::removeDir(std::string path) : rootPath(path) {}

removeDir::~removeDir() {}
