#ifndef FIRFILTER_H
#define FIRFILTER_H

#include <vector>
#include "../JuceLibraryCode/JuceHeader.h"

class FirFilter {

public:

FirFilter();

FirFilter(std::vector<double> coefficients);

AudioSampleBuffer operator() (AudioSampleBuffer& input);

private:
std::vector<double> coefficients;

};

#endif



