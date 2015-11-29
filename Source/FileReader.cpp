#include "FileReader.h"

void fileReader(const std::string& filename, std::vector<float>& res) {
  std::ifstream file;
  file.open(filename);
  float tmp;
  while (file.good() && !file.eof()) {
    file >> tmp;
    std::cout << tmp << std::endl;
    res.push_back(tmp);
  }
  file.close();
}
