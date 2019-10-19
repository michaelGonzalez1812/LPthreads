/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Hardware Arduino simulation
 * ***********************************************************/

void setup() { 
  // initialize the digital pins as an output.
  {   
    for (int j=2; j<19; j++)
    pinMode(j, OUTPUT);
  }
  // Turn the Serial Protocol ON
  Serial.begin(9600);
}

void loop() {
   byte byteRead;
  
   /* check if data has been sent from the computer: */
   if (Serial.available()) {
   
     /* read the most recent byte */
     byteRead = Serial.read();
     //You have to subtract '0' from the read Byte to convert from text to a number.
     byteRead=byteRead-'9';
     
     //Turn off all LEDs if the byte Read = 0
     if(byteRead==9){
       //Turn off all LEDS
       digitalWrite(2, LOW);
       digitalWrite(3, LOW);
       digitalWrite(4, LOW);
       digitalWrite(5, LOW);
       digitalWrite(6, LOW);
       digitalWrite(7, LOW);
       digitalWrite(8, LOW);
       digitalWrite(9, LOW);
       digitalWrite(10, LOW);
     }
     
     //Turn LED ON depending on the byte Read.
     if(byteRead>0){
      digitalWrite((byteRead+1), HIGH); // set the LED on
     }
   }
 }
