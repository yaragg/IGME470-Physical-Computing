//#include <stdio.h>
//#include <stdlib.h>
//#include "sample.h"

#define SIZE 970

char blah[SIZE];

float autoCorrelateFrequency(char * sample, int len, float sampleFreq)
{
  long sum = 0;
  long sum_old = 0;
  int thresh = 0,i,k;
  char pd_state = 0;
  int period = 0;  // 0 results in inf
//    FILE *fp;
//    fp=fopen("test.txt", "w");
  // Autocorrelation
  for (i=0; i < len; i++)
  {
//    fprintf(fp,"%d,%d,",i,rawData[i]);
    sum_old = sum;
    sum = 0;

    for (k=0; k <len-i; k++)
    {
      sum += (sample[k]) * (sample[k+i]);
    }
    sum /= k ;  //this should be k-1, but if so the last point will result in divide by zero
//    fprintf(fp,"%ld\n",sum);
    // Peak Detect State Machine
    // 0: initial, set threshold
    // 1: detect positive slope
    // 2: detect negative slope
    // 3: peak found
    if (pd_state == 0)
    {
      thresh = sum / 2;
      pd_state = 1;
    }
    else if (pd_state == 1 && (sum > thresh) && (sum - sum_old) > 0)
    {
      pd_state = 2;
    }
    else if (pd_state == 2 && (sum - sum_old) <= 0)
    {
      period = i;
      pd_state = 3;
    }
  }
//    fclose(fp);
  return sampleFreq/period;
}

void loop()
{
}

void setup() 
{
  Serial.begin(115200);
  Serial.println("FrequencyDSP");
  Serial.println("------------");
  
  for(int i=0; i< SIZE; i++){
    blah[i] = analogRead(A0);
  }

  uint32_t start = millis();
//  float fr = autoCorrelateFrequency(rawData, sizeof(rawData), 22050);
float fr = autoCorrelateFrequency(blah, sizeof(blah), 22050);
  uint32_t stop = millis();

  Serial.print("freq:\t");
  Serial.println(fr);
  Serial.print("time:\t");
  Serial.println(stop - start);
}


//int main()
//{
//  float fr = autoCorrelateFrequency(rawData, sizeof(rawData), 22050);
//
//  printf("freq: %f\n",fr);
//
//    return 0;
//}
