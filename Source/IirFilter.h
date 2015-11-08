#ifndef IIRFILTER_H
#define IIRFILTER_H

#include <vector>

class IirFilter {

public:

IirFilter(double coefficient, int channels);

 void setChannels(int channels);

float operator() (float sample, int chan);

private:
std::vector<float> lastSample;
double coefficient;

};

#endif

