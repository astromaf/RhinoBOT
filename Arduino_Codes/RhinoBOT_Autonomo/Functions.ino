  void derecha(){
    habilitar();
    servoI.write(110);
    servoD.write(110);
    delay(20);   
  }

  void izquierda(){
    habilitar();
    servoI.write(110);
    servoD.write(110);
    delay(20);  
  }

  void adelante(){  
   habilitar();
   servoI.write(10);
   servoD.write(180);
   delay(10);
  }
  
  void atras(){  
   habilitar();
   servoI.write(180);
   servoD.write(0);
  }
  
  void parada(){
  servoI.write(90);
  servoD.write(90); 
  servoI.detach();  
  servoD.detach(); 
  }  

  void habilitar(){
  servoD.attach(9);  
  servoI.attach(6);  
  }
 
