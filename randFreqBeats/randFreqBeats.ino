


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

int* spectrum;

//int color[3];

//FFT fft(fftAnalogPin,fftStrobePin,fftResetPin);

void setup()
{
  Serial.begin(9600);
  myGrid.strip->begin(); 
  myGrid.update();
  //delay(2000);
  /*
  for(int n=0;n<1000;n++)
  {
    spectrum = myGrid.freqChip->sample();
    
    for (int m=0;m<6;m++)
    {
      Serial.print(spectrum[m]);
      Serial.print(", ");
    }
    Serial.print(spectrum[6]);
    Serial.println();
  }
  */
  //pooparray = myGrid.freqChip->read();
}

void loop()
{
  
  myGrid.allOff();
  
  delay(30);
  int* spectrum = myGrid.freqChip->sample();
  int denom = 5;

  if(myGrid.freqChip->detectBeat(spectrum, 1, 30))
  {
    int first = sqrt(spectrum[0])*5;
    for(int i=0; i < first; i++)
    {
      myGrid.strip->setPixelColor(rand()%324, 0, 0, 127);
    }
  }
  
  if(myGrid.freqChip->detectBeat(spectrum, 2, 30))
  {
    int second = sqrt(spectrum[1])/denom;
    for(int i=0; i < second; i++)
    {
      myGrid.strip->setPixelColor(rand()%324, 65, 0, 127);
    }
  }
 
  if(myGrid.freqChip->detectBeat(spectrum, 3, 40))
  {
    int third = sqrt(spectrum[2])/2;
    for(int i=0; i < third; i++)
    {
      myGrid.strip->setPixelColor(rand()%324, 0, 127, 65);
    }
  }
 
  if(myGrid.freqChip->detectBeat(spectrum, 4, 50))
  {
    int fourth = sqrt(spectrum[3])/denom;
    for(int i=0; i < fourth; i++)
    {
      myGrid.strip->setPixelColor(rand()%324, 0, 127, 0);
    }
  }
 
  if(myGrid.freqChip->detectBeat(spectrum, 5, 50))
  {
    int fifth = sqrt(spectrum[4])/denom;
    for(int i=0; i < fifth; i++)
    {
      myGrid.strip->setPixelColor(rand()%324, 65, 127, 0);
    }
  }
 
  if(myGrid.freqChip->detectBeat(spectrum, 6, 50))
  {
    int sixth = sqrt(spectrum[5])/denom;
    for(int i=0; i < sixth; i++)
    {
      myGrid.strip->setPixelColor(rand()%324, 127, 127, 0);
    }
  }
 
  if(myGrid.freqChip->detectBeat(spectrum, 7, 30))
  {
    int seventh = sqrt(spectrum[6])/denom;
    for(int i=0; i < seventh; i++)
    {
      myGrid.strip->setPixelColor(rand()%324, 127, 127, 127);
    }
  }

  myGrid.update(); 
  


}
