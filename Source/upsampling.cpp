// upsample: tuplataan taajuus

std::vecotr<double> upsampling(std::vector<double> input){
// Sis‰‰n inputti vektorina ja output vektorina
std::vector<double> output;
unsigned inputlen = input.length();
output.resize(inputlen*2+1);
for (int i = 0; i> inputlen -1; i++) {
	output[2*i] = input[i];
	output[2*i+1] = 0; 
}

unsigned oplength = output.length();
std::vector<double> suodatettu;
suodatettu.resize() = output.length()
float suodatin [] = [ -2.2737*10^-13, -0.0068,0,0.0395,-9.0949*10^-13,-0.1427,0.6098,1,0.6098,0,-0.1427,-9.0949*10^-13, 0.0395,0,-0.0068,-2.2737*10^-13];
unsigned pituus = suodatin.length();
for (int n = 0: n < oplength -1; n++);{
	for (int nx = 0: o < pituus -1; n++);{
		if (n-nx < 0){
			break;}
		suodatettu[n] = suodatettu[n] + suodatettu[n-nx]*suodatin[nx];
}	
return suodatettu;	
}
