#include "FirFilter.h"

FirFilter::FirFilter() {};

FirFilter::FirFilter(std::vector<float> coefficients) :
  coefficients(coefficients) {}

AudioSampleBuffer& FirFilter::operator() (AudioSampleBuffer& buffer) {
  // Initialize circular buffer
  if (cBuffer.getNumChannels() != buffer.getNumChannels()) {
    cBuffer.setSize(buffer.getNumChannels(), coefficients.size());
    cBuffer.clear();
  }

  for (size_t chan = 0; chan < buffer.getNumChannels(); chan++) {
    float* data = buffer.getWritePointer(chan);
    // Pointer to circlebuffer
    float* p = cBuffer.getWritePointer(chan);
    for (size_t n = 0; n < buffer.getNumSamples(); n++) {

      // Stores the input data in to the circular buffer
      p[wp] = data[n];

      // Initialize output sample
      data[n] = 0;
      // Filtering
      for (size_t nx = 0; nx < coefficients.size(); nx++) 
	data[n] += p[(wp-nx+coefficients.size()) % coefficients.size()]
	  *coefficients[nx];

      // Normalization
      data[n] *= 20;

      // Forward circular buffer pointer
      wp = (wp+1) % coefficients.size();
    }
  }

  return buffer;
}
