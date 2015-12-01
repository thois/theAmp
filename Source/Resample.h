#ifndef RESAMPLE_H
#define RESAMPLE_H

#include "../JuceLibraryCode/JuceHeader.h"
#include "FirFilter.h"

class Resample {

 public:

  Resample();


  AudioSampleBuffer& up(const AudioSampleBuffer& in, AudioSampleBuffer& out) const;

  AudioSampleBuffer& down(const AudioSampleBuffer& in, AudioSampleBuffer& out)const;

 private:
  FirFilter lpfUp, lpfDown;
};

#endif
