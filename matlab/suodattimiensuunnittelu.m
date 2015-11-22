%% sodis projekti - suodattimien suunnittelu

% upsampling
% tiedosto jossa kaveri soitti yhdell� luennolla kitaraa
% fs = 48000
[x, fs] = audioread('guitar.wav');
soundsc(x,fs);
% taajuuskuvaa
figure(1);
plotFFT(x,fs, 'linear');
% t�ss� saan interpoloivan lowpass filterin tiedot
[filtertiedot, b] = interp(x,2);
% Lis�t��n nollia, joka toinen nolla joka toinen numero sis��ntulosta
ups = upsample(x,2);
% Filtter�in upsamplatun kokeilu
ups2 = filter(b,1,ups);

%% Downsamplinki


% lowpass filtteri joka suodattaa pois kaikki yli 24000 Hz taajuudet
% 24kHz saatu siit� ett� fs/2 = 48 kHz ja jaetan se viel� downsampling
% ratiolla joka on 2 t�ss�
FIRkokeilu = designfilt('lowpassfir','StopbandAttenuation',40 , ...
                'PassbandFrequency', 18000, 'StopbandFrequency', 24000, ...
                'SampleRate' , 96000, 'DesignMethod','equiripple' );
fvtool(FIRkokeilu)
% Fitterin tiedot yl�s
COFFERIT = FIRkokeilu.Coefficients;
out = filter(FIRkokeilu, ups2);
downis = downsample(out, 2);

