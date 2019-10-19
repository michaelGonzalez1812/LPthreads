void setup()                           // Prog_37_1
   {   
      for (int j=2; j<19; j++)
      pinMode(j, OUTPUT);
   }

void loop()
   {
      digitalWrite(2, HIGH);     //Levantamos la columna 1
      digitalWrite(3, HIGH);     //Levantamos la columna 2
      digitalWrite(5, HIGH);     //Levantamos la columna 4
      digitalWrite(6, HIGH);     //Levantamos la columna 5
      digitalWrite(8, HIGH);     //Levantamos la columna 7
      digitalWrite(9, HIGH);     //Levantamos la columna 8

      for (int k= 10 ; k<18 ; k++)
       {
           digitalWrite(k, LOW);   //Encendemos el punto
           delay(250);
           digitalWrite(k, HIGH);  //Apagamos el punto
       }

    }
