#include "DriveStage.h"

DriveStage::DriveStage(int fs, int lpfIn, int lpfC, int lpfO, double rkRp, double vPlus) : rkRp(rkRp), vPlus(vPlus), lpfIn((double)lpfIn/fs, channels), lpfC((double)lpfC/fs, channels), lpfO((double)lpfO/fs, channels) {}

AudioSampleBuffer& DriveStage::operator() (AudioSampleBuffer& buffer) {
  if (channels != buffer.getNumChannels()) {
    channels = buffer.getNumChannels();
    lpfIn.setChannels(channels);
    lpfC.setChannels(channels);
    lpfO.setChannels(channels);
    

    // Initialize last samples buffer
    feedbackSample = std::vector<float>(channels, 0.0);
  }
  for(size_t chan = 0; chan < channels; chan++) {
    float* data = buffer.getWritePointer(chan);
    for(size_t i = 0; i < buffer.getNumSamples(); i++) {
      float temp = lpfIn(data[i], chan) + feedbackSample[chan];
      temp = fTube(temp);
      feedbackSample[chan] = lpfC((vPlus - temp)*rkRp, chan);
      data[i] = temp - lpfO(temp, chan);
    }
  }
}

float DriveStage::fTube(float input) {
  //TODO
  return input;
}
