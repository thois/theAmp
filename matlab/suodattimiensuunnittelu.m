%% sodis projekti - suodattimien suunnittelu

% upsampling
% tiedosto jossa kaveri soitti yhdellä luennolla kitaraa
% fs = 48000
[x, fs] = audioread('kitara.wav');
% taajuuskuvaa
figure(1);
plotFFT(x,fs, 'linear');
% tässä saan interpoloivan lowpass filterin tiedot
[filtertiedot, b] = interp(x,2);
% Lisätään nollia, joka toinen nolla joka toinen numero sisääntulosta
ups = upsample(x,2);
% Filtteröin upsamplatun kokeilu
ups2 = filter(b,1,ups);

%% Downsamplinki


% lowpass filtteri joka suodattaa pois kaikki yli 24000 Hz taajuudet
% 24kHz saatu siitä että fs/2 = 48 kHz ja jaetan se vielä downsampling
% ratiolla joka on 2 tässä
FIRkokeilu = designfilt('lowpassfir', 'FilterOrder', 17, ...
                'PassbandFrequency', 24000, 'StopbandFrequency', 30000, ...
                'SampleRate' , 96000);
fvtool(FIRkokeilu)
% Fitterin tiedot ylös
COFFERIT = FIRkokeilu.Coefficients;
out = filter(FIRkokeilu, ups2);
downis = downsample(out, 2);

