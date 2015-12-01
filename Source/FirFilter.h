#ifndef FIRFILTER_H
#define FIRFILTER_H

#include <vector>
#include "../JuceLibraryCode/JuceHeader.h"

class FirFilter {

 public:
  
  //TODO remove
  FirFilter();

  FirFilter(std::vector<float> coefficients);

  AudioSampleBuffer& operator() (AudioSampleBuffer& input);


 private:
  std::vector<float> coefficients;
  AudioSampleBuffer cBuffer;
  int wp = 0;
};

#endif



