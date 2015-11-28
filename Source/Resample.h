#ifndef RESAMPLE_H
#define RESAMPLE_H

#include "../JuceLibraryCode/JuceHeader.h"
#include <cmath>
#include "FirFilter.h"
#include <vector>

class Resample {

 public:

Resample();


  AudioSampleBuffer up(AudioSampleBuffer& input);

  AudioSampleBuffer& down(AudioSampleBuffer& input, AudioSampleBuffer& output);

private:
FirFilter lpfUp, lpfDown;
};

#endif
