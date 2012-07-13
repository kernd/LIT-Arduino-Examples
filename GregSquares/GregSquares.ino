


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
  
}

void loop()
{
  
  myGrid.allOff();
  
  //delay(30);
  int* spectrum = myGrid.freqChip->sample();


  if(myGrid.freqChip->detectBeat(spectrum, 1, 20))
  {
       myGrid.drawRectangle(1,8,8,11,11, blue);
  }
  
  
  if(myGrid.freqChip->detectBeat(spectrum, 2, 30))
  {
       myGrid.drawRectangle(0,6,6,13,13, magenta);
  }
  
  if(myGrid.freqChip->detectBeat(spectrum, 3, 30))
  {
       myGrid.drawRectangle(0,5,5,14,14, green);
  }
  
  if(myGrid.freqChip->detectBeat(spectrum, 4, 30))
  {
       myGrid.drawRectangle(0,4,4,15,15, cyan);
  }
  
  if(myGrid.freqChip->detectBeat(spectrum, 5, 30))
  {
       myGrid.drawRectangle(0,3,3,16,16,yellow);
  }
  
  if(myGrid.freqChip->detectBeat(spectrum, 6, 30))
  {
       myGrid.drawRectangle(0,2,2,17,17, white);
  }
  
  if(myGrid.freqChip->detectBeat(spectrum, 7, 30))
  {
       myGrid.drawRectangle(0,1,1,18,18, green);
  }
 

  myGrid.update(); 
  


}
