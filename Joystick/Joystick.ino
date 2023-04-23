//Jostick KY-023

/*Conexcion Jostick
VRX -> A1
VRY -> A0
SW -> Pin Digital 50
*/

int X;        // variable para almacenar valor leido del eje X
int Y;        // variable para almacenar valor leido del eje y
int ledRojo = 4;
int LedVerde = 3;
int LedAzul = 2;
int PULSADOR = 50;    // pulsador incorporado pin digital 10
int SW;       // variable para almacenar valor leido del pulsador

void setup(){
  pinMode(ledRojo,OUTPUT);
  pinMode(LedVerde,OUTPUT);
  pinMode(LedAzul,OUTPUT);
  pinMode(PULSADOR, INPUT);   // pulsador como entrada
  // entradas analogicas no requieren inicializacion
}

void loop(){

  X = analogRead(A0);     // lectura de valor de eje x
  Y = analogRead(A1);     // lectura de valor de eje x
  SW = digitalRead(PULSADOR);   // lectura de valor de pulsador

  //Eje X
  if (X >= 0 && X < 480){         // si X esta en la zona izquierda
    analogWrite(ledRojo, map(X, 0, 480, 255, 0));   // brillo LED proporcional
  } else {
    analogWrite(ledRojo, 0);        // X en zona de reposo, apaga LED
  }
  if (X > 520 && X <= 1023){          // si X esta en la zona derecha
    analogWrite(ledRojo, map(X, 520, 1023, 0, 255));  // brillo LED proporcional
  } else {
    analogWrite(ledRojo, 0);        // X en zona de reposo, apaga LED
  }

  //Eje Y
  if (Y >= 0 && Y < 480){         // si Y esta en la zona de abajo
    analogWrite(LedVerde, map(Y, 0, 480, 255, 0));   // brillo LED proporcional
  } else {
    analogWrite(LedVerde, 0);          // Y en zona de reposo, apaga LED
  }
  if (Y > 520 && Y <= 1023){          // si Y esta en la zona de arriba
    analogWrite(LedVerde, map(Y, 520, 1023, 0, 255));   // brillo LED proporcional
  } else {
     analogWrite(LedVerde, 0);          // Y en zona de reposo, apaga LED     
  }
         
  digitalWrite(LedAzul, !SW);    // escribe en LED valor opuesto al leido del pulsador
  
}
