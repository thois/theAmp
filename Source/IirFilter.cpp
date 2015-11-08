#include "IirFilter.h"

IirFilter::IirFilter(double coefficient, int channels) : coefficient(coefficient) {
	lastSample = std::vector<float>(channels, 0.0);
}

void IirFilter::setChannels(int channels) {
  lastSample = std::vector<float>(channels, 0.0);
}

float IirFilter::operator() (float sample, int chan) {
	lastSample[chan] = (1-coefficient)*sample + coefficient * lastSample[chan];
	return lastSample[chan];
}
