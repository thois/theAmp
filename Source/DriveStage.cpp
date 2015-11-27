#include "DriveStage.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <unistd.h>

DriveStage::DriveStage(int fs, int lpfIn, int lpfC, int lpfO, double rkRp, double vPlus) : rkRp(rkRp), vPlus(vPlus), lpfIn((double)lpfIn/fs, channels), lpfC((double)lpfC/fs, channels), lpfO((double)lpfO/fs, channels) {
  readTubeFromFile("../../../../theAmp/Data/F_tube_1.txt");
}



AudioSampleBuffer& DriveStage::operator() (AudioSampleBuffer& buffer) {
  if (channels != buffer.getNumChannels()) {
    channels = buffer.getNumChannels();
    lpfIn.setChannels(channels);
    lpfC.setChannels(channels);
    lpfO.setChannels(channels);
    

    // Initialize last samples buffer
    feedbackSample = std::vector<float>(channels, 0.0);
  }
  for(size_t chan = 0; chan < channels; chan++) {
    float* data = buffer.getWritePointer(chan);
    for(size_t i = 0; i < buffer.getNumSamples(); i++) {
      float temp = lpfIn(gain*data[i], chan) + feedbackSample[chan];
      temp = fTube(temp);
      feedbackSample[chan] = lpfC((vPlus - temp)*rkRp, chan);
      data[i] = temp - lpfO(temp, chan);
    }
  }
}

float DriveStage::fTube(float input) {
  //std::cout << (input+1)/2*tube.size();
  int idx = (input+1)/2*tube.size();
  if (idx < 0)
    idx = 0;
  else if (idx >= tube.size())
    idx = tube.size()-1;  
  return tube[idx];
}

void DriveStage::readTubeFromFile(std::string filename) {
  char result[ PATH_MAX ];
  getcwd(result, PATH_MAX );
  std::cout << "Path: " << std::string(result) << std::endl;
  std::ifstream file;
  file.open(filename);
  std::cout << "File opened" << std::endl;
  float tmp;
  while (file.good() && !file.eof()) {
    std::cout << "Reading " << std::endl;
    file >> tmp;
    //std::cout << tmp << std::endl;
    tube.push_back(tmp);
  }
  file.close();
}

double DriveStage::getGain() {
  return gain;
}

void DriveStage::setGain(double gain) {
  this->gain = gain;
}
