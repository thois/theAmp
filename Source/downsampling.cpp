#include "downsampling.h"

AudioSampleBuffer downsampling(AudioSampleBuffer &input){

float suodatin2 [] = [0.0191,0.0349,-0.0397,-0.0107,0.0606,-0.0081,-0.1171,0.0990,0.4911,0.4911,0.0990,-0.1171,-0.0081,0.0606,-0.0107,-0.0397,0.0349,0.0191];
FirFilter lpf2(suodatin2);
suodatettu = lpf2(input);
output = downsampling(suodatettu);
return output;
}
