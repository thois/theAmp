#ifndef FIRFILTER_H
#define FIRFILTER_H

#include <vector>

class FirFilter {

public:

FirFilter(std::vector<double> coefficients);

AudioSampleBuffer& operator() (AudioSampleBuffer& input);

private:
std::vector<double> coefficients;

};

#endif



