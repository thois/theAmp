//
//  FenderEQ.cpp
//  EQ
//
//  created by roope Kiiski on 02.10.2015.
//
//

#include "FenderEQ.h"
#include <cmath>


void FenderEQ::set_samplerate(double samplerate)
{
    fs = samplerate;
}

void FenderEQ::set_values(double low, double mid, double treble)
{
	//This function updates the variables and transfer function's coefficients according to the changes user did to the potentiometers.
	//Possible updates: update only neccessary vars depending on which potentiometers were changed.

	l = low;
	m = mid;
	t = treble;

	varb1 = t*c1*r2 + m*c3*r3 + l*(c1*r2 + c2*r2) + (c1*r3 + c2*r3);

	varb2 = t*(c1*c2*r2*r4 + c1*c3*r2*r4)
		- (m*m)*(c1*c3*r3*r3 + c2*c3*r3*r3)
		+ m*(c1*c3*r2*r3 + c1*c3*r3*r3 + c2*c3*r3*r3)
		+ l*(c1*c2*r2*r2 + c1*c2*r2*r4 + c1*c3*r2*r4)
		+ l*m*(c1*c3*r2*r3 + c2*c3*r2*r3)
		+ (c1*c2*r2*r3 + c1*c2*r3*r4 + c1*c3*r3*r4);

	varb3 = l*m*(c1*c2*c3*r2*r2*r3 + c1*c2*c3*r2*r3*r4)
		- m*m*(c1*c2*c3*r2*r3*r3 + c1*c2*c3*r3*r3*r4)
		+ m*(c1*c2*c3*r2*r3*r3 + c1*c2*c3*r3*r3*r4)
		+ (t*c1*c2*c3*r2*r3*r4) - (t*m*c1*c2*c3*r2*r3*r4)
		+ (t*l*c1*c2*c3*r2*r2*r4);

	vara0 = 1;

	vara1 = (c1*r2 + c1*r3 + c2*r3 + c2*r4 + c3*r4)
		+ m*c3*r3 + l*(c1*r2 + c2*r2);

	vara2 = m*(c1*c3*r2*r3 - c2*c3*r3*r4 + c1*c3*r3*r3 + c2*c3*r3*r3)
		+ l*m*(c1*c3*r2*r3 + c2*c3*r2*r3) - m*m*(c1*c3*r3*r3 + c2*c3*r3*r3)
		+ l*(c1*c2*r2*r4 + c1*c2*r2*r2 + c1*c3*r2*r4 + c2*c3*r2*r4)
		+ (c1*c2*r2*r4 + c1*c3*r2*r4 + c1*c2*r3*r4
		+ c1*c2*r2*r3 + c1*c3*r3*r4 + c2*c3*r3*r4);

	vara3 = l*m*(c1*c2*c3*r2*r2*r3 + c1*c2*c3*r2*r3*r4)
		- m*m*(c1*c2*c3*r2*r3*r3 + c1*c2*c3*r3*r3*r4)
		+ m*(c1*c2*c3*r3*r3*r4 + c1*c2*c3*r2*r3*r3 - c1*c2*c3*r2*r3*r4)
		+ l*c1*c2*c3*r2*r2*r4 + c1*c2*c3*r2*r3*r4;

	//Update transfer function's coefficients:

	B0 = -2 * varb1*fs - 4 * varb2*pow(fs, 2) -  8 * varb3*pow(fs, 3);
	B1 = -2 * varb1*fs + 4 * varb2*pow(fs, 2) + 24 * varb3*pow(fs, 3);
	B2 =  2 * varb1*fs + 4 * varb2*pow(fs, 2) - 24 * varb3*pow(fs, 3);
	B3 =  2 * varb1*fs - 4 * varb2*pow(fs, 2) +  8 * varb3*pow(fs, 3);

	A0 = -    vara0 - 2 * vara1*fs - 4 * vara2*pow(fs, 2) - 8  * vara3*pow(fs, 3);
	A1 = -3 * vara0 - 2 * vara1*fs + 4 * vara2*pow(fs, 2) + 24 * vara3*pow(fs, 3);
	A2 = -3 * vara0 + 2 * vara1*fs + 4 * vara2*pow(fs, 2) - 24 * vara3*pow(fs, 3);
	A3 = -    vara0 + 2 * vara1*fs - 4 * vara2*pow(fs, 2) + 8  * vara3*pow(fs, 3);

	B0 = B0 / A0;
	B1 = B1 / A0;
	B2 = B2 / A0;
	B3 = B3 / A0;

	A1 = A1 / A0;
	A2 = A2 / A0;
	A3 = A3 / A0;
	A0 = A0 / A0;
}

double FenderEQ::filter_sample(double sample, int channel)
{
	double output;
	output = feedforward[2][channel] * B3 + feedforward[1][channel] * B2
    + feedforward[0][channel]*B1 + sample*B0 - feedback[2][channel]*A3
    - feedback[1][channel]*A2 - feedback[0][channel]*A1;
	output = output / A0;
    feedforward[2][channel] = feedforward[1][channel];
    feedforward[1][channel] = feedforward[0][channel];
    feedforward[0][channel] = sample;
    feedback[2][channel] = feedback[1][channel];
    feedback[1][channel] = feedback[0][channel];
    feedback[0][channel] = output;
    return output;
}
