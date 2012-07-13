// LED Array Testing Code
// Light Integrated Threads
// 
// 
#include <FFT.h>
#include <SPI.h>
#include <LPD8806.h>
//#include <LEDArray.h>
#include <Grid.h>

Grid myGrid(18,18);

int maxVal = 0;
int maxIndex = 0;
int weights[7] = {5,4,3,3,3,3,2};
int weightedSpectrum[7] = {0,0,0,0,0,0,0};
int *spectrum;
//int color[3];

//FFT fft(fftAnalogPin,fftStrobePin,fftResetPin);

void setup()
{
  Serial.begin(9600);
  myGrid.strip->begin(); 
  myGrid.update();
  
  delay(2000);
  
}

void loop()
{
  
  myGrid.allOff();
 
  spectrum = myGrid.freqChip->sample();
  Serial.println(spectrum[3]);
  
  /*
  for(int i = 0; i < 7; i++)
  {
    Serial.println(spectrum[i]);
  }
  Serial.println();
  Serial.println();
  */
  
  
  for(int i = 0; i < 7; i++)
  {
    
    int temp1 = spectrum[i];
    int temp2 = weights[i];
    int temp3 = temp1*temp2;
    int a=2;
    int b=3;
    weightedSpectrum[i] = a*b;
    //int poop = temp1*temp2;
    
    //Serial.println(weightedSpectrum[i]);
    
    Serial.print(spectrum[i]);
    Serial.print(" ");
    Serial.print(weights[i]);
    Serial.print(" ");
    //Serial.print(weightedSpectrum[i]);
    Serial.println();
    
    /*
    Serial.print("In band ");
    Serial.print(i);
    Serial.print(", ");
    Serial.print(" spectrum is: ");    
    Serial.print(spectrum[i]);
    Serial.print(" weighted spectrum is: ");
    Serial.print(weightedSpectrum[i]);
    Serial.println();
    //*/
  }
  Serial.println();
  Serial.println();
  
  /*
  for(int i = 0; i < 7; i++)
  {
    weightedSpectrum[i] = spectrum[i]*weights[i];
    if(weightedSpectrum[i] > maxVal) 
    {
      maxVal = weightedSpectrum[i];
      maxIndex = i+1;
    }
    Serial.print(i);
    Serial.print(" ");
    Serial.print(spectrum[i]);
    Serial.print(" ");
    Serial.print(weightedSpectrum[i]);
    Serial.print(" ");
    Serial.print(maxVal);
    Serial.print(" ");
    Serial.println(maxIndex);
  }
 */
    
  
  switch (maxIndex)
  {
    case 1:
      myGrid.allOff();
      myGrid.oFace(blue);
      myGrid.update();
      delay(500);
      break;
    case 2:
      myGrid.allOff();
      myGrid.oFace(magenta);
      myGrid.update();
      delay(500);
      break;
    case 3:
      myGrid.allOff();
      myGrid.smiley1(cyan);
      myGrid.rightEyeOpen(cyan);
      myGrid.leftEyeOpen(cyan);
      myGrid.update();
      delay(300);
      break;
    case 4:
      myGrid.allOff();
      myGrid.smiley1(red);
      myGrid.rightEyeOpen(red);
      myGrid.leftEyeOpen(red);
      myGrid.update();
      delay(300);
      break;
    case 5:
      myGrid.allOff();
      myGrid.smiley1(green);
      myGrid.rightWink(green);
      myGrid.leftEyeOpen(green);
      myGrid.update();
      delay(200);
      break;
    case 6:
      myGrid.allOff();
      myGrid.smiley1(yellow);
      myGrid.leftWink(yellow);
      myGrid.rightEyeOpen(yellow);
      myGrid.update();
    //  delay(200);
      break;
    case 7:
      myGrid.allOff();
      myGrid.smiley1(white);
      myGrid.leftWink(white);
      myGrid.rightWink(white);
      myGrid.update();
      delay(100);
      break;
  }
  
  maxIndex = 0;
  maxVal = 0;
 
}
