/*
  The PrintBot RHINO is an educational robot that can push objects with 
  its dozer and take part in "sumobots fights".
  You can see it in action at :http://youtu.be/r0RgC5rzKug
  The robot has been designed to attach other components such as servos, 
  LEDs, push buttons, a buzzer, and other sensors included in the product 
  "My first robotics kit" distributed by http://www.bqreaders.com/
  
  // Subject: RhinoBot operates autonomously.If detects a black line border, 
              turns right to keep itself into the delimited area.
  // Fecha: March'13
  // Robot designed by: Miguel Angel de Frutos. (madebyfrutos.es)
  // Property: http://diy.bq.com/ 
  // Licencia: GNU General Public License v3 or later
  // Version: MAF_Rhino4.0
 
*/
 
  #include <Servo.h>             // Libreria para control de los servos
  
  const int SensorPin = 2;           // Si utilizamos un sensor IR en pin 2
  int SensorState = 0;           // Variable para registar el estado de IR (blanco/negro)
  Servo servoI;                  // Pin 6  
  Servo servoD;                  // Pin 9
  
  ////////////////////////////////////////////////////////////////////////////
    
  void setup()
  {
    pinMode(SensorPin, INPUT);
    pinMode(8,OUTPUT);          // Led 8 opcional
    habilitar();
    servoI.write(90);
    servoD.write(90); 
    delay(1000);   
  }//End setup
  
   //////////////////////////////////////////////////////////////////////////// 
  
  void loop(){
     SensorState = digitalRead(SensorPin);  //Lee el estado del sensor IR
     
  if (SensorState == HIGH) {                // Si esta sobre blanco..¡Avanza!
    digitalWrite(13,LOW);                   // Luz apagada
     adelante();      
  }
  else {                                   // Si esta sobre negro: ¡Para! Marcha atras...y ¡Gira!
    digitalWrite(13,HIGH);
    parada();
    atras();
    delay(500);
    izquierda();
    delay(500);
    
  }
  }// End loop
   //////////////////////////////////////////////////////////////////////////// 

