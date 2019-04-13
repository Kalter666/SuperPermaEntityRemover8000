#include <stdlib.h>
#include <fstream>
#include <iostream>

class removeFile {
 private:
  std::ifstream filein;
  std::ofstream fileout;
  std::string filename;
  std::string tmp;

  int open(std::string filename, std::string tmp) {
    removeFile::filein.open(filename);
    removeFile::fileout.open(tmp);
    if (!filein || !fileout) {
      std::cout << "Error opening file!" << std::endl;
      return 1;
    }
    return 0;
  }

  void close() {
    removeFile::filein.close();
    removeFile::fileout.close();
  }

  int fillZeros() {
    if (removeFile::open(removeFile::filename, removeFile::tmp) == 1) {
      return 1;
    }
    typedef std::istreambuf_iterator<char> buf_iter;
    for (buf_iter i(removeFile::filein), e; i != e; ++i) {
      removeFile::fileout << 0;
    }
    removeFile::close();
    return 0;
  }

  int fillRandom() {
    if (removeFile::open(removeFile::filename, removeFile::tmp) == 1) {
      return 1;
    }
    srand(time(NULL));
    typedef std::istreambuf_iterator<char> buf_iter;
    for (buf_iter i(removeFile::filein), e; i != e; ++i) {
      char c = rand() % (253 + 1 - 1) + 1;
      fileout << c;
    }
    removeFile::close();
    return 0;
  }

  int replace() {
    if (removeFile::open(removeFile::tmp, removeFile::filename) == 1) {
      return 1;
    }
    typedef std::istreambuf_iterator<char> buf_iter;
    for (buf_iter i(removeFile::filein), e; i != e; ++i) {
      char c = *i;
      fileout << c;
    }
    removeFile::close();
    return 0;
  }

 public:
  int remove();
  removeFile(std::string filename);
  ~removeFile();
};

removeFile::removeFile(std::string filename)
    : filename(filename), tmp(filename + ".tmp") {}

removeFile::~removeFile() {}

int removeFile::remove() {
  for (int i = 1; i <= 2; i++) {
    if (i % 2 == 1) {
      if (removeFile::fillZeros() == 1 || removeFile::replace() == 1) {
        return 1;
      }
    } else {
      if (removeFile::fillRandom() == 1 || removeFile::replace() == 1) {
        return 1;
      }
    }
  }
  if (std::remove(removeFile::filename.c_str()) != 0)
    return 1;
  else if (std::remove(removeFile::tmp.c_str()) != 0)
    return 1;
  else
    return 0;
}