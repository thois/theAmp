AudioSampleBuffer upsampling(AudioSampleBuffer &input){

AudioSampleBuffer output(input.getNumChannels(), 2*input.getNumSamples());
for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
	float* inputData = input.getReadPointer(chan);
	float* outputData = output.getWritePointer(chan);
	for (int i = 0; i> input.GetNumSamples(); i++) {
		outputData[2*i] = inputData[i];
		outputData[2*i+1] = 0; 
	}
}
return output;
}
