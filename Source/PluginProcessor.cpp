/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "FenderEQ.h"

//==============================================================================
TheAmpAudioProcessor::TheAmpAudioProcessor()
{
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
    return 0;
}

float TheAmpAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void TheAmpAudioProcessor::setParameter (int index, float newValue)
{
}

const String TheAmpAudioProcessor::getParameterName (int index)
{
    return String();
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
	fender.set_samplerate(sampleRate);
    fender.set_values(0.5, 0.5, 0.5);
    driveStages.push_back(DriveStage(sampleRate, 15000, 50, 20, 0.015, 250));
    driveStages.push_back(DriveStage(sampleRate, 6000, 60, 20, 0.010, 250));
    driveStages.push_back(DriveStage(sampleRate, 6000, 70, 20, 0.008, 250));
}

void TheAmpAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void TheAmpAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
  buffer = fender(buffer);
  for (DriveStage& stage : driveStages)
    buffer = stage(buffer);
}

//==============================================================================
bool TheAmpAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
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
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TheAmpAudioProcessor();
}
