#include <stdlib.h>
#include <fstream>
#include <iostream>

class removeFile {
 private:
  std::ifstream filein;
  std::ofstream fileout;
  std::string filename;
  std::string tmp;

 public:
  removeFile(std::string filename);
  ~removeFile();
};

removeFile::removeFile(std::string filename)
    : filename(filename), tmp(filename + ".tmp") {}

removeFile::~removeFile() {}

int main() {
  using namespace std;

  string filename = "demo.txt";
  string tmp = filename + ".tmp";
  ifstream filein(filename);  // File to read from
  ofstream fileout(tmp);      // Temporary file
  if (!filein || !fileout) {
    cout << "Error opening files!" << endl;
    return 1;
  }
  srand(time(NULL));

  typedef std::istreambuf_iterator<char> buf_iter;
  for (buf_iter i(filein), e; i != e; ++i) {
    char c = rand() % (253 + 1 - 1) + 1;
    fileout << c;
  }

  filein.close();
  fileout.close();
  filein.open(tmp);
  fileout.open(filename);

  if (!filein || !fileout) {
    cout << "Error opening files!" << endl;
    return 1;
  }

  for (buf_iter i(filein), e; i != e; ++i) {
    char c = *i;
    fileout << c;
  }
  return 0;
}