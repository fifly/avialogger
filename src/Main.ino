/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */

//#define SERIAL_TX_BUFFER_SIZE 256
//#define SERIAL_RX_BUFFER_SIZE 256
String comdata = "";
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  delay(200);
}

void loop() // run over and over
{
  delay(2000);
  Serial.println("AT");
  delay(200);
  //Send message
  Serial.println("AT+CGNSPWR=1");
  delay(200);
  //reset GPS in autonomy mode
  Serial.println("AT+CGNSTST=1");
  delay(200);
  while (1)
  {
    while (Serial.available() > 0)
      Serial.write(Serial.read());
    while (Serial.available())
      Serial.write(Serial.read());  //Arduino send the sim808 feedback to computer
  }
}
