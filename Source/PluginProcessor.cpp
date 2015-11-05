/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


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
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void TheAmpAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void TheAmpAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
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
