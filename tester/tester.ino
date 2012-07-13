// LED Array Testing Code
// Light Integrated Threads
// 
// 
//#include <Fans.h>
#include <FFT.h>
#include <SPI.h>
#include <LPD8806.h>
//#include <LEDArray.h>
#include <Grid.h>

//Fans myFan(50);
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
} 
void loop()
{
  for (int n=0;n<50;n++)
  {
    myGrid.strip->setPixelColor(n,0,0,127);
  }
  myGrid.strip->show();
  


}
