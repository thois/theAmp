#include "upsampling.h"

// upsample: tuplataan taajuus

AudioSampleBuffer upsampling(AudioSampleBuffer &input){
// Sis‰‰n inputti bufferina
// Kutsutaan upsampling funktiota, joka palauttaa uuden Audiobufferin ulos
output = upsampling(input);
// Suodattimen tiedot
float suodatin [] = [ -2.2737*10^-13, -0.0068,0,0.0395,-9.0949*10^-13,-0.1427,0.6098,1,0.6098,0,-0.1427,-9.0949*10^-13, 0.0395,0,-0.0068,-2.2737*10^-13];
FirFilter lpf(suodatin);
// Palauttaa uuden suodatettu nimisen Audiobufferin ulos
suodatettu = lpf(output);
return suodatettu;	
}
