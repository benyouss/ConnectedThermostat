#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

int sensor_temp=A0;

int out_cooling_Fan=13;

int out_mode_1=3;

int out_mode_2=4;

int out_mode_3=5;

int out_bluet=6;

float val, tempC;

void setup()

{

lcd.begin(16,2);

Serial.begin(9600);

lcd.print(" température ");

pinMode(sensor_temp, INPUT);

pinMode(out_mode_1, OUTPUT);

pinMode(out_mode_2, OUTPUT);

pinMode(out_mode_3, OUTPUT);

pinMode(out_cooling_Fan, OUTPUT);

pinMode(out_bluet,OUTPUT);

}

void loop()

{

val=analogRead(sensor_temp); //acquisition de la valeur de la température sur la broche A0

tempC = (5.0 * val * 100.0)/1024.0; // conversion en Celsius

if (val>60)

{

digitalWrite(out_mode_1, LOW);

digitalWrite(out_mode_2, LOW);

digitalWrite(out_mode_3, HIGH);

digitalWrite(out_cooling_Fan, HIGH);

}

else if(val<= 35)

{

digitalWrite(out_mode_1, HIGH);

digitalWrite(out_mode_2, LOW);

digitalWrite(out_mode_3, LOW);

digitalWrite(out_cooling_Fan, LOW);

}

else

{

digitalWrite(out_mode_1, LOW);
digitalWrite(out_mode_2, HIGH);

digitalWrite(out_mode_3, LOW);

digitalWrite(out_cooling_Fan,LOW);

}

lcd.setCursor(3,1);

lcd.print(int(val));

if (Serial.available()) {

byte c = Serial.read ();

if (c == 'm') {

Serial.println(String(tempC));

digitalWrite(test_bluet , HIGH) ;

delay(100) ;

digitalWrite(test_bluet,LOW);

delay(500);

}

}

}