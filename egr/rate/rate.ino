
#include <SD.h>
#include <SPI.h>
#include <AudioZero.h>
const int flexPin = A4;			// Pin connected to voltage divider output
File myFile = SD.open("cic2.wav");
int rate = 4410000;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    AudioZero.begin(rate);
    Serial.println(rate);
    delay(5);
    AudioZero.play(myFile);
    delay(3000);
    AudioZero.end();
    //rate = rate + 50;
}
