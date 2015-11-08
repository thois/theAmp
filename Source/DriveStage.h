#ifndef DRIVESTAGE_H
#define DRIVESTAGE_H

#include "IirFilter.h"
#include <vector>
#include "../JuceLibraryCode/JuceHeader.h"

class DriveStage {

public:

DriveStage(int fs, int lpfIn, int lpfC, int lpfO, double rkRp, double vPlus);

AudioSampleBuffer& operator() (AudioSampleBuffer& buffer);

private:
int channels = 0;
double rkRp, vPlus;
IirFilter lpfIn, lpfC, lpfO;
std::vector<float> feedbackSample;



 float fTube(float input);

};

#endif
