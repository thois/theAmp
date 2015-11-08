AudioSampleBuffer downsampling(AudioSampleBuffer &input){

AudioSampleBuffer output(input.getNumChannels(), input.getNumSamples()/2);
for (size_t chan2 = 0; chan2 < input.getNumChannels(); chan2++) {
	float* inputData = input.getReadPointer(chan2);
	float* outputData = output.getWritePointer(chan2);
	for (int i = 0; i < outputData.getNumSamples(); i++) {
		outputData[i] = inputData[2*i];

	}
}
return output;
}
