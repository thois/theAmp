function plotFFT(y, fs, scaling)
% Plots the fourier transfoerm of the time domain input signal y

    %FFT
    L = length(y);
    
    % FFT produces L components so scale by the signal length
    Y = fft(y)/L;
    
    % Frequency axis from 0 to Nyquist frequency (fs/2). L/2 data points.
    f = (fs/2) * linspace(0, 1, L/2 + 1);

    % Plot single-sided amplitude spectrum. Multiply by 2 to compensate
    % mirroring over Nyquist.
    
    if strcmp(scaling, 'log')
        semilogx(f,2*abs(Y(1:L/2+1)));
    elseif strcmp(scaling, 'linear')
        plot(f,2*abs(Y(1:L/2+1)));
    else
        fprintf('invalid parameter scaling. Use ''linear'' or ''log''\n');
    end
    
    title('Single-Sided Amplitude Spectrum of y(t)')
    xlabel('Frequency (Hz)')
    ylabel('|Y(f)|')

end