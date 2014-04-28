/*
  The PrintBot RHINO is an educational robot that can push objects with 
  its dozer and take part in "sumobots fights".
  You can see it in action at :http://youtu.be/r0RgC5rzKug
  The robot has been designed to attach other components such as servos, 
  LEDs, push buttons, a buzzer, and other sensors included in the product 
  "My first robotics kit" distributed by bq.com.
  
  // Subject: This code allows you to control your robot via bluetooth
               using an android application, for example: RoboPad by bq.(coming soon!)
  // Fecha: March'13
  // Robot designed by: Miguel Angel de Frutos. 
  // Property: http://www.bqreaders.com/
  // Licencia: GNU General Public License v3 or later
  // Version: MAF_Rhino2.0
 
*/
 
  #include <Servo.h>             // Libreria para control de los servos
  const int SensorPin = 2;           // Si utilizamos un sensor IR en pin 2
  int SensorState = 0;           // Variable para registar el estado de IR (blanco/negro)
  Servo servoI;                  // Pin 6  
  Servo servoD;                  // Pin 9
  int key;                       // Si queremos controlar por bluetooth
  
  
  ////////////////////////////////////////////////////////////////////////////
    
  void setup()
  {
    Serial.begin(38400);         //Abre el puerto serie
    pinMode(SensorPin, INPUT);
    pinMode(8,OUTPUT);          // Led 8 opcional
    habilitar();
    servoI.write(90);
    servoD.write(90); 
    delay(1000);   
  }//End setup
  
   //////////////////////////////////////////////////////////////////////////// 
  
  void loop(){
    SensorState = digitalRead(SensorPin); //Comprobamos el estado del sensor IR
    
    if (SensorState == HIGH) {      //Si esta sobre blanco, lo podemos controlar...
      digitalWrite(8,LOW);         // Apaga el Led
      
      while ( Serial.available() >= 1)
        {   
         key = Serial.read();        //Lee el bluetooth
         bluestick();                //Decide la orden de movimiento
        }
        
    }
    else {                          //Si esta sobre negro,ha salido del recinto y no se movera...
      digitalWrite(8,HIGH);        //Enciende el led
      parada();
    }
  
  }// End loop
   //////////////////////////////////////////////////////////////////////////// 

