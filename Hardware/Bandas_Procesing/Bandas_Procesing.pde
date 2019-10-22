/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      Hardware file processing
 * ***********************************************************/
 
import processing.serial.*;
import java.io.*;
int mySwitch=0;
int counter=0;
String [] subtext0;
String [] subtext1;
String [] subtext2;
Serial myPort;


void setup(){
   //Create a switch that will control the frequency of text file reads.
   //When mySwitch=1, the program is setup to read the text file.
   //This is turned off when mySwitch = 0
   mySwitch=1;
   
   //Open the serial port for communication with the Arduino
   //Make sure the COM port is correct
   myPort = new Serial(this, "/dev/ttyACM0", 9600);
   myPort.bufferUntil('\n');
}

void draw() {
  //while(true){
     if (mySwitch>0){
       /*The readData function can be found later in the code.
       This is the call to read a CSV file on the computer hard-drive. */
       subtext0 = readData("/home/e3r8ick/TEC/Operativos/Proyecto1/LPthreads/Bandas/Banda0.txt");
       subtext1 = readData("/home/e3r8ick/TEC/Operativos/Proyecto1/LPthreads/Bandas/Banda1.txt");
       subtext2 = readData("/home/e3r8ick/TEC/Operativos/Proyecto1/LPthreads/Bandas/Banda2.txt");
       
       //write in the arduino
       //BandaId , Type , Position & BandaId , Type , Position & BandaId , Type , Position
       System.out.println("0,"+subtext0[0]+","+subtext0[1]+"&"+"1,"+subtext1[0]+","+subtext1[1]+"&"+"2,"+subtext2[0]+","+subtext2[1]);
       myPort.write("0,"+subtext0[0]+","+subtext0[1]+"&"+"1,"+subtext1[0]+","+subtext1[1]+"&"+"2,"+subtext2[0]+","+subtext2[1]);
       /*The following switch prevents continuous reading of the text file, until
       we are ready to read the file again. */
       mySwitch=0;
       delay(200);
     }else{
       //If the text file has run out of numbers, then read the text file again in 5 seconds.
       delay(500);
       mySwitch=1;
     }
  //}
} 


/* The following function will read from a CSV or TXT file */
String[] readData(String myFileName){
 
   File file=new File(myFileName);
   BufferedReader br=null;
   String[] subtext = {};
   
   try{
     br=new BufferedReader(new FileReader(file));
     String text=null;
     
     /* keep reading each line until you get to the end of the file */
     while((text=br.readLine())!=null){
     /* Spilt each line up into bits and pieces using a comma as a separator */
     subtext = splitTokens(text,",");
     }
   }catch(FileNotFoundException e){
     e.printStackTrace();
   }catch(IOException e){
     e.printStackTrace();
   }finally{
     try {
       if (br != null){
       br.close();
       }
     } catch (IOException e) {
       e.printStackTrace();
     }
   }
   return subtext;
}
