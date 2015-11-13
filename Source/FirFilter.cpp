#include "FirFilter.h"

FirFilter::FirFilter() {};

FirFilter::FirFilter(std::vector<double> coefficients) : coefficients(coefficients) {}

AudioSampleBuffer FirFilter::operator() (AudioSampleBuffer& input) {
  AudioSampleBuffer suodatettu(input.getNumChannels(), input.getNumSamples());
  for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
    const float* inputData = input.getReadPointer(chan);
    float* suodatettuData = suodatettu.getWritePointer(chan);
    for (int n = 0; n < input.getNumSamples(); n++) {
      for (int nx = 0; nx < coefficients.size(); nx++) {
	if (n-nx < 0)
	  break;
	suodatettuData[n] = suodatettuData[n] + inputData[n-nx]*coefficients[nx];
      }
    }
  }
  return suodatettu;
}