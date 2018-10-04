//Carrega a bibliotecas
#include <Ultrasonic.h>
#include <LiquidCrystal_I2C.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

int ledvermelho = 7;
int ledverde = 8;
int buzzer = 9;
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup()
{
  lcd.begin (16,2);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void aviso(float &distancia){
    if(distancia >= 19){
      digitalWrite(ledvermelho,HIGH);
      digitalWrite(ledverde,LOW);
      tone(buzzer,1500);
      delay(100);
      noTone(buzzer);
      delay(100);
     }else{
      digitalWrite(ledverde,HIGH);
      digitalWrite(ledvermelho,LOW);
      digitalWrite(buzzer,LOW);
     }
}
 
void loop()
{
  
  //Le as informacoes do sensor em cm
  float distancia;
  long microsec = ultrasonic.timing();
  distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  aviso(distancia);
  //Exibe informacoes no lcd
  lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Dist: ");
          lcd.setCursor(6,0);
          lcd.print(distancia);
          lcd.setCursor(10,0);
          lcd.print(" cm");
  delay(500);
  
}
