/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "FenderEQ.h"
#include "Resample.h"


const float defaultGain = 1.0f;
//==============================================================================
TheAmpAudioProcessor::TheAmpAudioProcessor()
{
    lastUIWidth = 400;
    lastUIHeight = 200;
    gain = defaultGain;
    
    lastPosInfo.resetToDefault();
    fender.set_values(0.5, 0.5, 0.5);
}

TheAmpAudioProcessor::~TheAmpAudioProcessor()
{
}

//==============================================================================
const String TheAmpAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int TheAmpAudioProcessor::getNumParameters()
{
    return 6;
}

float TheAmpAudioProcessor::getParameter (int index)
{
  switch (index) {
  case 0:
    return 0.2*driveStages[0].getGain();
  case 1:
    return 0.2*driveStages[1].getGain();
  case 2:
    return 0.2*driveStages[1].getGain();
  case 3:
    return fender.get_treble();
  case 4:
    return fender.get_middle();
  case 5:
    return fender.get_low();
  }
  return 0.f;
}

void TheAmpAudioProcessor::setParameter (int index, float newValue)
{
    if (newValue > 1)
        newValue = 1;
    if (newValue < 0)
        newValue = 0;
    switch (index) {
    case 0:
      driveStages[0].setGain(newValue/0.2);
      break;
    case 1:
      driveStages[1].setGain(newValue/0.2);
      break;
    case 2:
      driveStages[2].setGain(newValue/0.2);
      break;
    case 3:
        fender.set_values(fender.get_low(), fender.get_middle(), newValue);
	break;
    case 4:
        fender.set_values(fender.get_low(), newValue, fender.get_treble());
	break;
    case 5:
        fender.set_values(newValue, fender.get_middle(), fender.get_treble());
	break;
    }
}

const String TheAmpAudioProcessor::getParameterName (int index)
{
  if (index >= 0 && index < 3)
        return "gain";
    else if (index == 3)
        return "treble";
    else if (index == 4)
        return "middle";
    else if (index == 5)
        return "bass";
    else
        return "out of bounds";
}

const String TheAmpAudioProcessor::getParameterText (int index)
{
    return String();
}

const String TheAmpAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String TheAmpAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool TheAmpAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool TheAmpAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool TheAmpAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TheAmpAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TheAmpAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double TheAmpAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TheAmpAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TheAmpAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TheAmpAudioProcessor::setCurrentProgram (int index)
{
}

const String TheAmpAudioProcessor::getProgramName (int index)
{
    return String();
}

void TheAmpAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TheAmpAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
  
	fender.set_samplerate_and_channels(sampleRate, getNumInputChannels());
	// TODO How Vplus parameters are normalized?
	driveStages.push_back(DriveStage(sampleRate, 15000, 50, 20, 0.015, 0.0025));
	driveStages.push_back(DriveStage(sampleRate, 6000, 60, 20, 0.010, 0.0025));
	driveStages.push_back(DriveStage(sampleRate, 6000, 70, 20, 0.008, 0.0025));
}

void TheAmpAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void TheAmpAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
  //AudioSampleBuffer tmp = resample.up(buffer);
  fender(buffer);
  //driveStages[0](buffer);
  for (DriveStage& stage : driveStages)
    stage(buffer);
  //resample.down(tmp, buffer);
}
//==============================================================================
bool TheAmpAudioProcessor::hasEditor() const
{
    //return true; // (change this to false if you choose to not supply an editor)
    return false;
}

AudioProcessorEditor* TheAmpAudioProcessor::createEditor()
{
    return new TheAmpAudioProcessorEditor (*this);
}

//==============================================================================
void TheAmpAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
}

void TheAmpAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    // This getXmlFromBinary() helper function retrieves our XML from the binary blob..
    
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TheAmpAudioProcessor();
}
