close all;
clear all;
R1 = 1E6;
R2 = 2.7E3;
R3 = 56E3;
R4 = 150E3;
R5 = 3.3E6;
R6 = 3.3E3;
C1 = 270E-12;
C2 = 10E-6;
C3 = 3.3E-6;
C4 = 4700E-12;
C5 = 10E-6;
vref = 0.125;
vcc = 5;
signal_amplitude = 0.1E-6;
f = 100/60;
snr = 10;

t=[0:0.001:20];
original_signal = signal_amplitude*sin(2*pi*f*t);
original_signal += signal_amplitude/snr*rand(size(t));
original_signal += signal_amplitude*(rand(size(t)).*sin(2*pi*50*t));
original_signal += signal_amplitude*(rand(size(t)).*sin(2*pi*100*t));
original_signal += signal_amplitude*(rand(size(t)).*sin(2*pi*0.05*t));
for i=1:size(original_signal)(2)
if fmod(i,4)==1
signal_sampled(i) = original_signal(i);
else
signal_sampled(i) = signal_amplitude*rand();
endif;
endfor;

sys1 = tf([vref],[1 0]); 
sys2 = tf([R1],[R1*C1 1]);
sys3 = sys1 + sys2;
sys4 = tf([R3*C2*C3 0],[R2*R3*C2*C2*C3 R3*C2*C3+R2*C2*C3+R2*C2*C2 C2]);
sys5 = sys3*sys4;
sys6 = -R5/R4*tf([1],[R5*C4 1]);
sys7 = vref*tf([1],[1 0]);
sys8 = -sys6*tf([vref],[1 0]);
sys9 = sys8 + sys6;
sys10 = sys9*sys5;
sys11 = tf([1],[R6*C5 1]);
sys12 = sys10*sys11;

plot(t,1E6*original_signal,'b');
hold on;
plot(t,1E6*signal_sampled,'c');
lsim(sys12, signal_sampled, t, 'r');
hold on;
lsim(sys12, original_signal, t, 'b');
axis([0 20 -5 5]);
