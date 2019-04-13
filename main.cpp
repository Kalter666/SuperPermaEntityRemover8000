#include <iostream>

#include "removeFile.cpp"

int main() {
  std::string filename;

  std::cout << "Welcome to SuperPermaEntityRemover8000!!!" << std::endl;
  std::cout << "Please enter path to your file: ";
  std::cin >> filename;

  removeFile f{filename};
  if (f.remove() != 0) {
    std::cout << "Something went wrong!\n Test your luck another time...";
    return 1;
  }
  std::cout << filename << " - Successfully deleted!";

  return 0;
}