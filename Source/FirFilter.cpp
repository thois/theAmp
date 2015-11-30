#include "FirFilter.h"
#include <iostream>

FirFilter::FirFilter() {};

FirFilter::FirFilter(std::vector<float> coefficients) : coefficients(coefficients) {

}

AudioSampleBuffer FirFilter::operator() (AudioSampleBuffer& input) {
  // Sets circlebuffers size
  if (cBuffer.getNumChannels() != input.getNumChannels()) {
    std::cout << "Alustus\n";
    cBuffer.setSize(input.getNumChannels(), coefficients.size());
    cBuffer.clear();
  }
 // Creates a new AudioSampleBuffer for filtered data
 AudioSampleBuffer filtered(input.getNumChannels(), input.getNumSamples());
  // For-loop that goes trough the channels
  for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
    const float* inputData = input.getReadPointer(chan);
    float* filteredData = filtered.getWritePointer(chan);
    // Pointer to circlebuffer
    float* p = cBuffer.getWritePointer(chan);
    for (int n = 0; n < input.getNumSamples(); n++) {
      // Stores the input data in to the circlebuffer
      p[wp] = inputData[n];
      filteredData[n] = 0;
      for (int nx = 0; nx < coefficients.size(); nx++) {
        // Filtering
	filteredData[n] += p[(wp-nx+coefficients.size()) % coefficients.size()]*coefficients[nx];
      }
      // Normalization
      filteredData[n] /= 2;
      //std::cout << coefficients.size()
	//std::cout << p[(wp-1+coefficients.size()) % coefficients.size()] << std::endl;
      /*
      std::cout << "Buffer:\n" << std::endl;
      for (size_t i = 0; i <filtered.getNumSamples(); i++)
	std::cout << filteredData[i] << std::endl;
      */
      //std::cout << "Readpoint: " << (wp-1+coefficients.size()) % coefficients.size() << std::endl;
      
	//filteredData[n] = p[(wp-2+coefficients.size()) % coefficients.size()];
      
    wp = (wp+1) % coefficients.size();
    }
  }
  // Returns the filtered AudioSampleBuffer
  return filtered;
}
