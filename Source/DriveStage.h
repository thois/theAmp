#ifndef DRIVESTAGE_H
#define DRIVESTAGE_H

#include "IirFilter.h"
#include <vector>
#include <string>
#include "../JuceLibraryCode/JuceHeader.h"

class DriveStage {

 public:

  DriveStage(int fs, int lpfIn, int lpfC, int lpfO, double rkRp, double vPlus);

  AudioSampleBuffer& operator() (AudioSampleBuffer& buffer);

  double getGain() const;

  void setGain(double gain);

 private:
  int channels = 0;
  double gain = 1;
  double rkRp, vPlus;
  IirFilter lpfIn, lpfC, lpfO;
  std::vector<float> feedbackSample, tube;

  // Makes tube amplification
  float fTube(float input) const;

};

#endif
