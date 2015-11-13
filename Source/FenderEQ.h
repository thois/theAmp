//
//  FenderEQ.h
//  EQ
//
//  Created by Roope Kiiski on 02.10.2015.
//
//

#ifndef FenderEQ_h
#define FenderEQ_h

#include "../JuceLibraryCode/JuceHeader.h"

class FenderEQ
{
private:
    //Values of the physical components:
    double r1 = 250000;         // 250  kOhm
    double r2 = 1000000;        // 1    MOhm
    double r3 = 25000;          // 25   kOhm
    double r4 = 56000;          // 56   kOhm
    double c1 = 0.00000000025;  // 0.25 nF
    double c2 = 0.000000020;	// 20	nF
    double c3 = 0.000000020;    // 20   nF
    //Variables for calculating the transfer function:
    double varb1, varb2, varb3, vara0, vara1, vara2, vara3;
    //Potentiometer parameters (l = low, m = mid and t = treble):
    double l, m, t;
    //Zeroes and poles of the transfer function:
    double B0, B1, B2, B3, A0, A1, A2, A3;
    //Simple buffers of length 3 (no need for longer, and because its so small, it isn't neccessary to use circular buffer). 
    double feedback[3][2] = {{0}};
    double feedforward[3][2] = {{0}};

	double fs = 48000;
    
    int channels = 1;
    
public:
    //Functions to set new values to the filter:
    void set_values(double, double, double);
    
    //Function to filter data:
    double filter_sample(double, int);

	//Function to set correct samplerate:
	void set_samplerate_and_channels(double, int);

	AudioSampleBuffer& operator() (AudioSampleBuffer& buffer);
    
};


#endif /* FenderEQ_h */
