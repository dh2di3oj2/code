/*
 This reads a wave file from an SD card and plays it using the I2S interface to
 a MAX98357 I2S Amp Breakout board.

 Circuit:
 * Arduino Zero, MKR Zero or MKR1000 board
 * SD breakout or shield connected
 * MAX98357:
   * GND connected GND
   * VIN connected 5V
   * LRC connected to pin 0 (Zero) or pin 3 (MKR1000, MKR Zero)
   * BCLK connected to pin 1 (Zero) or pin 2 (MKR1000, MKR Zero)
   * DIN connected to pin 9 (Zero) or pin A6 (MKR1000, MKR Zero)

 created 15 November 2016
 by Sandeep Mistry
 */


//buttons

const int skipPin = 1;  // the number of the pushbutton pin

int skipState = 0;  // variable for reading the pushbutton status

int song = 0;  //song number


const int buttonPin =0;  // the number of the pushbutton pin

int buttonState = 0;  // variable for reading the pushbutton status


#include <SD.h>
#include <ArduinoSound.h>

// filename of wave file to play
const char filename[] = "1.WAV";
const char filename2[] = "2.WAV";

// variable representing the Wave File
SDWaveFile waveFile;
SDWaveFile waveFile2;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);  //115200
/*   while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  } */

  // setup the SD card, depending on your shield of breakout board
  // you may need to pass a pin number in begin for SS
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDCARD_SS_PIN)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // create a SDWaveFile
  waveFile = SDWaveFile(filename);
  waveFile2 = SDWaveFile(filename2);

  // check if the WaveFile is valid
  if (!waveFile) {
    Serial.println("wave file 1 is invalid!");
    while (1)
      ;  // do nothing
  }
  if (!waveFile2) {
    Serial.println("wave file 2 is invalid!");
    while (1)
      ;  // do nothing
  }




  Serial.println("info about file 1");

  // print out some info. about the wave file
  Serial.print("Bits per sample = ");
  Serial.println(waveFile.bitsPerSample());

  long channels = waveFile.channels();
  Serial.print("Channels = ");
  Serial.println(channels);

  long sampleRate = waveFile.sampleRate();
  Serial.print("Sample rate = ");
  Serial.print(sampleRate);
  Serial.println(" Hz");

  long duration = waveFile.duration();
  Serial.print("Duration = ");
  Serial.print(duration);
  Serial.println(" seconds");

 

  // check if the I2S output can play the wave file
  if (!AudioOutI2S.canPlay(waveFile)) {
    Serial.println("unable to play wave file using I2S!");
    while (1)
      ;  // do nothing
  }




  // info about file 2
  Serial.println("info about file 2");

  // print out some info. about the wave file
  Serial.print("Bits per sample = ");
  Serial.println(waveFile2.bitsPerSample());

   channels = waveFile2.channels();
  Serial.print("Channels = ");
  Serial.println(channels);

   sampleRate = waveFile2.sampleRate();
  Serial.print("Sample rate = ");
  Serial.print(sampleRate);
  Serial.println(" Hz");

   duration = waveFile2.duration();
  Serial.print("Duration = ");
  Serial.print(duration);
  Serial.println(" seconds");

  // adjust the playback volume
  AudioOutI2S.volume(100);

  // check if the I2S output can play the wave file
  if (!AudioOutI2S.canPlay(waveFile2)) {
    Serial.println("unable to play wave file 2 using I2S!");
    while (1)
      ;  // do nothing
  }


}




void loop() {

  //code a button that switches between the two files

  skipState = digitalRead(skipPin);
  buttonState = digitalRead(buttonPin);
   Serial.print("p");
  Serial.println(buttonState);
  Serial.print("s");
  Serial.println(skipState);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (skipState == LOW) {
    song++;  // increment
    if (song == 2) {
      song = 0;  // reset
    }
  }

  if (buttonState == HIGH) {



    // play the wave file
    if (song == 0) {
      Serial.println("playing wave file 1");
      AudioOutI2S.play(waveFile);
      
    }
    if (song == 1) {
      Serial.println("playing wave file 2");

      AudioOutI2S.play(waveFile2);
      

    }
  }
  delay(500);
}
