FirFilter::FirFilter(std::vector<double> coefficients) : coefficients(coefficients) {}

AudioSampleBuffer& FirFilter::operator() (AudioSampleBuffer& input) {
	AudioSampleBuffer suodatettu(input.getNumChannels(), inputput.getNumSamples());
	for (size_t chan = 0; chan < input.getNumChannels(); chan++) {
		float* inputData = input.getReadPointer(chan);
		float* suodatettuData = suodatettu.getWritePointer(chan);
		for (int n = 0: n < input.getNumSamples; n++) {
			for (int nx = 0: nx < coefficants.length(); nx++) {
				if (n-nx < 0)
					break;
				suodatettuData[n] = suodatettuData[n] + inputData[n-nx]*coefficants[nx];
	}
	}
	}
return output;
}
