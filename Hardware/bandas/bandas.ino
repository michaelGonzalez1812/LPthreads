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

  for (int k= 9 ; k<18 ; k++){
     digitalWrite(k, LOW);   //Encendemos el punto
     digitalWrite(k, HIGH);  //Apagamos el punto
  }
}


void loop() {
   // Calculate based on max input size expected for one command
    #define INPUT_SIZE 30
    
    // Get next command from Serial (add 1 for final 0)
    char input[INPUT_SIZE + 1];
    byte size = Serial.readBytes(input, INPUT_SIZE);
    // Add the final 0 to end the C string
    input[size] = 0;
    
    // Read each command pair 
    char* command = strtok(input, "&");
    while (command != 0)
    {
        // Split the command in two values
        char* separator = strchr(command, ',');
        if (separator != 0)
        {
            // Actually split the string: replace ',' with 0
            *separator = 0;
            
            //save band ID
            int bandId = atoi(command);
            ++separator;
            
            //save type os the package
            int type = atoi(separator);
            ++separator;
            ++separator;
            
            //save position
            int position = atoi(separator);

            //print all teh info
            Serial.print("ID banda: ");
            Serial.print(bandId);
            Serial.print(" Tipo: ");
            Serial.print(type);
            Serial.print(" Posicion: ");
            Serial.print(position);
            Serial.println("");
    
           if(bandId == 0){
              if(type == 0){
                //turn off previous 
                digitalWrite(8, LOW);     //apagamos la columna 2
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(9, HIGH);     //Levantamos la columna 1
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
              if(type == 1){
                //turn off previous 
                digitalWrite(9, LOW);     //apagamos la columna 1
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(8, HIGH);     //Levantamos la columna 2
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
              else{
                //turn off previous 
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(9, HIGH);     //Levantamos la columna 1
                digitalWrite(8, HIGH);     //Levantamos la columna 2
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
           }
           else if(bandId == 1){
                if(type == 0){
                //turn off previous 
                digitalWrite(5, LOW);     //apagamos la columna 2
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(6, HIGH);     //Levantamos la columna 1
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
              if(type == 1){
                //turn off previous 
                digitalWrite(6, LOW);     //apagamos la columna 1
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(5, HIGH);     //Levantamos la columna 2
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
              else{
                //turn off previous 
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(6, HIGH);     //Levantamos la columna 1
                digitalWrite(5, HIGH);     //Levantamos la columna 2
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
           }
           else{
                if(type == 0){
                //turn off previous 
                digitalWrite(2, LOW);     //apagamos la columna 2
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(3, HIGH);     //Levantamos la columna 1
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
              if(type == 1){
                //turn off previous 
                digitalWrite(3, LOW);     //apagamos la columna 1
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(2, HIGH);     //Levantamos la columna 2
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
              else{
                //turn off previous 
                digitalWrite((position+8), HIGH);
                //turn on
                digitalWrite(3, HIGH);     //Levantamos la columna 1
                digitalWrite(2, HIGH);     //Levantamos la columna 2
                digitalWrite((position+9), LOW); // set the LED on
                //turn off next
                digitalWrite((position+10), HIGH);
              }
           }
        }
        // Find the next command in input string
        command = strtok(0, "&");
    }
 }
