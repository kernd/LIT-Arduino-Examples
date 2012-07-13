\


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

  delay(30);

  int* spectrum = myGrid.freqChip->sample();

  int first = ((spectrum[0]) + (spectrum[1]))/2;
  int second = ((spectrum[2]) + (spectrum[3]) + (spectrum[3]))/3;
  int third = ((spectrum[4]) + (spectrum[5]) + (spectrum[6]))/3;

  first = first/150;
  second = second/30;
  third = third/20;

  //divide up grid into three regions

  if(myGrid.freqChip->detectBeat(spectrum, 1, 40))
  {
    for(int r = 0; r < 100; r++)
    {
      myGrid.drawPixel(rand()%18,rand()%18,magenta);                                        
    }
  }
  else
  {
    for(int r = 18; r > 18 - first; r--)
    {
      myGrid.drawXLine(r, 1, 18, blue);
    }
  }

  if(myGrid.freqChip->detectBeat(spectrum, 3, 40))
  {
    for(int r = 0; r < 100; r++)
    {
      myGrid.drawPixel(rand()%18,rand()%18,yellow);

    }
  }
  else
  {
    for(int r = 1; r < second; r++)
    {
      myGrid.drawXLine(r, 1, 9, green);
    }
  }

  if(myGrid.freqChip->detectBeat(spectrum, 5, 40))
  {
    for(int r = 0; r < 100; r++)
    {
      myGrid.drawPixel(rand()%18,rand()%18,white);
    }
  }
  else
  {
    for(int r = 1; r < third; r++)
    {
      myGrid.drawXLine(r, 10, 18, red);
    }
  }

  myGrid.update();
}


