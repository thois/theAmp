#include "FileReader.h"

void myFileReader(std::ifstream& file, std::vector<float>& res) {
  float tmp;
  while (file.good() && !file.eof()) {
    file >> tmp;
    std::cout << tmp << std::endl;
    res.push_back(tmp);
  }
}
