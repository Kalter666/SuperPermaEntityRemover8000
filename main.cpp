#include <stdlib.h>
#include <fstream>
#include <iostream>

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