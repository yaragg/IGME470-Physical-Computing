#define MIC_PIN A0
#define SAMPLE_RATE 8000
#define FFT_N 128
#define LOG_OUT 1
#include <FFT.h>

int bin_size = 8000/FFT_N;

//data must be stored in fft_input array as per the FFT library

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int maxVal = -1;
  int maxIndex = -1;
  
  for(int i=0; i<FFT_N*2; i=i+2)
  {
    fft_input[i] = analogRead(MIC_PIN);
    fft_input[i+1] = 0;
  }
  
  fft_window();
  fft_reorder();
  fft_run();
  fft_mag_log();
  
  for(int i=0; i<FFT_N/2; i++)
  {
    int x = sqrt(fft_log_out[i*2]*fft_log_out[i*2] + fft_log_out[i*2-1]*fft_log_out[i*2-1]);
    if(x > maxVal)
    {
      maxVal = x;
      maxIndex = i;
    }
  }
  
  Serial.print(maxIndex*bin_size);

}
