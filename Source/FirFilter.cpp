#include "FirFilter.h"

FirFilter::FirFilter() {};

FirFilter::FirFilter(std::vector<double> coefficients) : coefficients(coefficients) {

}

AudioSampleBuffer FirFilter::operator() (AudioSampleBuffer& input) {
 if (cBuffer,getNumChannels != input.getNumChannels())
    cBuffer.setSize(input.getNumChannels(), coefficients.size();
 AudioSampleBuffer filtered(input.getNumChannels(), input.getNumSamples());
  for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
    const float* inputData = input.getReadPointer(chan);
    float* filteredData = filtered.getWritePointer(chan);
    float* p = cBuffer.getWritePointer(chan);
    for (int n = 0; n < input.getNumSamples(); n++) {
      p[wp] = inputData[n];
      
      for (int nx = 0; nx < coefficients.size(); nx++) {
	filteredData[n] += p[(wp-nx) % coefficients.size()]*coefficients[nx];
      }
    wp = (wp+1) % coefficients.size();
    }
  }
  return filtered;
}
