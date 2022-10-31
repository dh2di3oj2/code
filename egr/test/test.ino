
#include <SD.h>
#include <SPI.h>
#include <AudioZero.h>
const int flexPin = A4;			// Pin connected to voltage divider output
File myFile = SD.open("cic2.wav");

void setup()
{

  // debug output at 115200 baud
Serial.begin(9600);

  while (!Serial) {

    ; // wait for serial port to connect. Needed for native USB port only

  }


  // setup SD-card
Serial.print("Initializing SD card...");

  if (!SD.begin(SDCARD_SS_PIN)) {

    Serial.println(" failed!");

    while(true);

  }

Serial.println(" done.");


// 44.1kHz stereo => 88200 sample rate

AudioZero.begin(88200);
pinMode(flexPin, INPUT);
/* File myFile = SD.open("cic2.wav");

if (!myFile) {

    // if the file didn't open, print an error and stop

    Serial.println("error opening test.wav");

    while (true);
} */

}

void loop() {  






//Serial.println("opened file");
//AudioZero.end();
Serial.println(analogRead(flexPin));
//delay(100);
if (analogRead(flexPin) != 1023)
{

  // open wave file from sdcard

  

  

  

    Serial.print("Playing");



   // until the file is not finished
  AudioZero.begin(1125);
    delay(5);
    AudioZero.play(myFile);
    delay(3000);
    //AudioZero.end();

    Serial.println("End of file. Thank you for listening!");
    //while(true);

  }


AudioZero.end();


 delay(50);
}  
