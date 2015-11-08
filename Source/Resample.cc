#include "Resample.h"

Resample::Resample() {
  std::vector<double> coefficients{-2.2737*pow(10,-13), -0.0068,0,0.0395,-9.0949*pow(10,-13),-0.1427,0.6098,1,0.6098,0,-0.1427,-9.0949*pow(10,-13), 0.0395,0,-0.0068,-2.2737*pow(10,-13)};

  lpfUp = FirFilter(coefficients);
  coefficients = {0.0191,0.0349,-0.0397,-0.0107,0.0606,-0.0081,-0.1171,0.0990,0.4911,0.4911,0.0990,-0.1171,-0.0081,0.0606,-0.0107,-0.0397,0.0349,0.0191};

  Resample::lpfDown = FirFilter(coefficients);
}

AudioSampleBuffer Resample::up(AudioSampleBuffer &input){

  AudioSampleBuffer output(input.getNumChannels(), 2*input.getNumSamples());
  for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
    const float* inputData = input.getReadPointer(chan);
    float* outputData = output.getWritePointer(chan);
    for (int i = 0; i> input.getNumSamples(); i++) {
      outputData[2*i] = inputData[i];
      outputData[2*i+1] = 0; 
    }
  }
  return input = lpfUp(output);
}

AudioSampleBuffer Resample::down(AudioSampleBuffer &input){
  AudioSampleBuffer output(input.getNumChannels(), input.getNumSamples()/2);
  for (size_t chan2 = 0; chan2 < input.getNumChannels(); chan2++) {
    const float* inputData = input.getReadPointer(chan2);
    float* outputData = output.getWritePointer(chan2);
    for (int i = 0; i < output.getNumSamples(); i++) {
      outputData[i] = inputData[2*i];

    }
  }
  return lpfDown(output);
}
