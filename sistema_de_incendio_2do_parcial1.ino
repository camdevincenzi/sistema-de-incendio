// C++ code
//

#define LEDAZUL 13
#define LEDROJO 12
#define BOTON1 0xEF10BF00
#define BOTON2 0xEE11BF00
#define BOTON3 0xED12BF00
#define BOTON4 0xEB14BF00
#define LEDAZUL 13
#define LEDROJO 12

/*	Se produce un incendio si:
  	en otoño la temperatura supera los 50°,
  	en invierno la temperatura supera los 40°,
  	en primavera la temperatura supera los 60°,
  	en verano la temperatura supera los 70°	  
    
/*** CONTROL REMOTO IR ***/
#include <IRremote.h>
int CONTROL_REMOTO = 11;
IRrecv irrecv(CONTROL_REMOTO);

/*** LCD ***/
#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

/*** SERVO ***/
#include <Servo.h>
Servo servo;

float temperatura;
int inclinacion;
int destello;

void setup()
{
  pinMode(LEDAZUL, OUTPUT);
  pinMode(LEDROJO, OUTPUT);
  lcd.begin(16, 2);
  IrReceiver.begin(CONTROL_REMOTO, DISABLE_LED_FEEDBACK);
  Serial.begin(9600);
  servo.attach(3);
}

void loop(){
  temperatura = map(analogRead(A0),0,1023,-49,451);
  servo.write(0);
  
  mostrar_temperatura();
  
  if (IrReceiver.decode()){
	IrReceiver.resume();
  }
  
  if (IrReceiver.decodedIRData.decodedRawData == BOTON1){
    if (temperatura > 49){
      detectar_incendio();
    } else if (temperatura < 40){
      mostrar_estacion("OTONIO          ");
      apagarLed(LEDROJO);
      titilar(LEDAZUL, 1000);
    } else {
      mostrar_estacion("OTONIO          ");
      titilar(LEDROJO, 1000);
    }
  }
  
  if (IrReceiver.decodedIRData.decodedRawData == BOTON2){
    if (temperatura > 39){
   	  detectar_incendio();
    } else if (temperatura < 30){
      mostrar_estacion("INVIERNO          ");
      apagarLed(LEDROJO);
      titilar(LEDAZUL, 1000);
    } else {
      mostrar_estacion("INVIERNO          ");
      titilar(LEDROJO, 1000);
    }
  }
  
  if (IrReceiver.decodedIRData.decodedRawData == BOTON3){
    if (temperatura > 59){
      detectar_incendio();
    } else if (temperatura < 50){
      mostrar_estacion("PRIMAVERA          ");
      apagarLed(LEDROJO);
      titilar(LEDAZUL, 1000);
    } else {
      mostrar_estacion("PRIMAVERA          ");
      titilar(LEDROJO, 1000);
    }
  }
  
  if (IrReceiver.decodedIRData.decodedRawData == BOTON4){
    if (temperatura > 69){
      detectar_incendio();
  	} else if (temperatura < 60){
      mostrar_estacion("VERANO          ");
      apagarLed(LEDROJO);
      titilar(LEDAZUL, 1000);
    } else {
      mostrar_estacion("VERANO          ");
      titilar(LEDROJO, 1000);
    }
  }
}

void mostrar_temperatura(){
	lcd.setCursor(0, 0);
  	lcd.print("TMP: ");
  	lcd.print(temperatura);
}

void mostrar_estacion(char estacion[]){
	lcd.setCursor(0, 1);
  	lcd.print(estacion);
    delay(100);
}

void mostrar_alerta_incendio(){
  	lcd.setCursor(0, 1);
  	lcd.print("ALERTA INCENDIO");
  	delay(100);
}

void activar_servo(){
  for(inclinacion = 0; inclinacion <= 180; inclinacion += 10){
  	servo.write(inclinacion);
    delay(50);
  }
  for(inclinacion = 180; inclinacion >= 0; inclinacion -= 10){
  	servo.write(inclinacion);
    delay(50);
  }
}

void detectar_incendio(){
  mostrar_alerta_incendio();
  prenderLed(LEDROJO);
  activar_servo();
}

void titilar(int led, int tiempo){
  digitalWrite(led, HIGH);
  delay(tiempo);
  digitalWrite(led, LOW);
  delay(tiempo);
}

void prenderLed(int led) {
  digitalWrite(led, HIGH);
}

void apagarLed(int led) {
  digitalWrite(led, LOW);
}