#include "Resample.h"

Resample::Resample() {
  std::vector<double> coefficients{-2.2737*pow(10,-13), -0.0068,0,0.0395,-9.0949*pow(10,-13),-0.1427,0,0.6098,1,0.6098,0,-0.1427,-9.0949*pow(10,-13), 0.0395,0,-0.0068,-2.2737*pow(10,-13)};

  //std::vector<double> coefficients{1};

  lpfUp = FirFilter(coefficients);
  coefficients = {0.0146,0.0239,0.0042,-0.0226,-0.0196,0.0258,0.0434,-0.0150,-0.0855,-0.0261,0.1893,0.3956,0.3956,0.1893,-0.0261,-0.0855,-0.0150,0.0434,0.0258,-0.0196,-0.0226,0.0042,0.0239,0.0146};

  lpfDown = FirFilter(coefficients);
}

AudioSampleBuffer Resample::up(AudioSampleBuffer &input){

  AudioSampleBuffer output(input.getNumChannels(), 2*input.getNumSamples());
  for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
    const float* inputData = input.getReadPointer(chan);
    float* outputData = output.getWritePointer(chan);
    for (int i = 0; i < input.getNumSamples(); i++) {
      outputData[2*i] = inputData[i];
      outputData[2*i+1] = 0; 
    }
  }
  //return lpfUp(output);
  return output;
}

AudioSampleBuffer& Resample::down(AudioSampleBuffer& input, AudioSampleBuffer& output){
  //input = lpfDown(input);
  for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
    const float* inputData = input.getReadPointer(chan);
    float* outputData = output.getWritePointer(chan);
    for (int i = 0; i < output.getNumSamples(); i++) {
      outputData[i] = inputData[2*i];

    }
  }
  return output;
}
