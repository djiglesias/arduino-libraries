/*******************************************************************************//**
  Automation Direct Stepper Motor Communication

  Receives from the hardware serial, sends to software serial.
  Receives from software serial, sends to hardware serial.
  
  The circuit:
  * RX is digital pin 10 (connect to TX of other device)
  * TX is digital pin 11 (connect to RX of other device)
  
  Note:
  Not all pins on the Mega and Mega 2560 support change interrupts,
  so only the following can be used for RX:
  10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
  
  Not all pins on the Leonardo and Micro support change interrupts,
  so only the following can be used for RX:
  8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

  @author   Mikal Hart
  @date    
  @modified Tom Igoe
  @date     May 2012
  @modified Duncan Iglesias
  @date     August 2017
**********************************************************************************/
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // set the data rate for the SoftwareSerial port
  Serial2.begin(57600);

}

void loop() { // run over and over
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }
  if (Serial.available()) {
    Serial2.write(Serial.read());
  }
}
/*********************************************************************************/