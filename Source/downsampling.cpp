std::vecotr<double> (std::vector<double> input2){
unsigned op2length = input2.length();
std::vector<double> suodatettu2;
suodatettu2.resize(op2length); 
float suodatin2 [] = [0.0191,0.0349,-0.0397,-0.0107,0.0606,-0.0081,-0.1171,0.0990,0.4911,0.4911,0.0990,-0.1171,-0.0081,0.0606,-0.0107,-0.0397,0,0349,0,0191]; ];
unsigned pituus2 = suodatin2.length();
for (int n = 0: n < op2length -1; n++);{
	for (int nx = 0: o < pituus2 - 1; n++);{
		if (n-nx < 0){
			break;}
		suodatettu2[n] = suodatettu2[n] + suodatettu2[n-nx]*suodatin2[nx];
}	
std::vector<double> op;
unsigned oplength = suodatettu2.length();
op.resize(oplength/2 +1);
for (int i = 0; i> oplength -1; i++) {
	op[i] = suodatettu2[2*i];

}
return op;
}
