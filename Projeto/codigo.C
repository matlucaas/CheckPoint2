// C++ code
#include <LiquidCrystal.h>
#include <EEPROM.h>
//Led e Buzzer
	int ledR = 12;
    int ledG = 11;
	int ledY = 10;
    int buzzer = 13;
	int luminosidade = 0; 

//DHT11
	const int analogIn = A1;
	int humiditysensorOutput = 0;
	int RawValue= 0;
	double Voltage = 0;
	double tempC = 0;

//CONTADOR UMIDADE
	int somatorio = 0; 
	int contador = 0; 
	int agora = 0; 
	int atualizaAgora = 0; 
	int mediaH = 0; 

//CONTADOR TEMPERATURA
	int somatorioT = 0; 
	int contadorT = 0; 
	int agoraT = 0; 
	int atualizaAgoraT = 0; 
	int mediaT = 0; 

//CONTADOR LUMINOSIDADE
	int somatorioL = 0; 
	int contadorL = 0; 
	int agoraL = 0; 
	int atualizaAgoraL = 0; 
	int mediaL = 0; 
	
	
	const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
	LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //DHT11
  Serial.begin(9600);
  pinMode(A1, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
}

void loop()
{
  luminosidade = analogRead(A0);
  //DHT11  
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000;
  tempC = (Voltage-500) * 0.1;
  Serial.print("\t Temperatura in C = ");
  Serial.print(tempC,1);
  humiditysensorOutput = analogRead(A2);
  Serial.print("\t Humidity: "); // Exibe o percentual da umidade
  Serial.print(map(humiditysensorOutput,0 ,1023, 0, 100));
  Serial.println("%");
  Serial.print("\t Luminosidade = ");
  Serial.print(luminosidade);
  Serial.print(mediaH);
  Serial.print(mediaT);
  Serial.print(mediaL);
  
  
  //UMIDADE 
  // pega o horario agora
 agora = millis(); 
 // Armazena o valor do sensor num somatorio
 somatorio = somatorio + humiditysensorOutput; 
 // Incrementa o contador, vai ser o nosso divisor
 contador ++; 
 // Só entra nesse if a cada 5 segundos
 if(agora - atualizaAgora >= 5000){ 
 // calcula a media -> media = (soma dos valores)/quantidade de valores
 mediaH = somatorio / contador; 
 // Atualiza o tempo para entrar somente daqui a 5 segundos
 atualizaAgora = millis(); 
 // zera os valores para pegar novas médias
 contador = 0; 
 somatorio = 0; 
 } 
  
 //AGORA TEMPERATURA
 agoraT = millis(); 
 somatorioT = somatorioT + tempC; 
 contadorT ++; 
 if(agoraT - atualizaAgoraT >= 5000){ 
 mediaT = somatorioT / contadorT; 
 atualizaAgoraT = millis(); 
 contadorT = 0; 
 somatorioT = 0; 
 } 
 
 //AGORA LUMINOSIDADE
 agoraL = millis(); 
 somatorioL = somatorioL + luminosidade; 
 contadorL ++; 
 if(agoraL - atualizaAgoraL >= 5000){ 
 mediaL = somatorioL / contadorL; 
 atualizaAgoraL = millis(); 
 contadorL = 0; 
 somatorioL = 0; 
 } 
  
  
  if((mediaL <= 900) and (511 <= mediaH and mediaH <= 716) and (10 <= mediaT and mediaT <= 15))
  {
 		
    	noTone(buzzer);
    	digitalWrite(10, LOW);
  		digitalWrite(12, LOW);
    	digitalWrite(11, HIGH);
    	lcd.setCursor(0, 0);
    	lcd.print("Ambiente OK     ");
  		lcd.setCursor(0, 1);
  		lcd.print("                ");
    	delay(2000);
    	lcd.setCursor(0, 0);
      	lcd.print("Temperatura OK  ");
  		lcd.setCursor(0, 1);
  		lcd.print("Temp. = ");
    	lcd.setCursor(8, 1);
  		lcd.print(mediaT);
    	lcd.setCursor(12, 1);
      	lcd.print("C  ");
  		delay(2000);
    	lcd.clear();
    	lcd.setCursor(0, 0);
      	lcd.print("Umidade OK      ");
  		lcd.setCursor(0, 1);
  		lcd.print("Umidade = ");
    	lcd.setCursor(10, 1);
  		lcd.print(map(mediaH,0 ,1023, 0, 100));
      	lcd.setCursor(13, 1);
      	lcd.print("%  ");
  		delay(2000);
  		
  		
  
  }
  else if((950 > mediaL and mediaL > 900) and (511 <= mediaH and mediaH <= 716) and (10 <= mediaT and mediaT <= 15)){
    	
    	noTone(buzzer);
    	digitalWrite(11, LOW);
  		digitalWrite(12, LOW);
    	digitalWrite(10, HIGH);
      	lcd.setCursor(0, 0);
      	lcd.print("Ambiente a meia ");
  		lcd.setCursor(0, 1);
  		lcd.print("luz             ");
    	delay(2000);
    	lcd.setCursor(0, 0);
      	lcd.print("Temperatura OK  ");
  		lcd.setCursor(0, 1);
    	lcd.print("Temp. = ");
    	lcd.setCursor(8, 1);
  		lcd.print(mediaT);
    	lcd.setCursor(12, 1);
      	lcd.print("C  ");
  		delay(2000);
    	lcd.clear();
    	lcd.setCursor(0, 0);
      	lcd.print("Umidade OK      ");
  		lcd.setCursor(0, 1);
    	lcd.print("Umidade = ");
    	lcd.setCursor(10, 1);
  		lcd.print(map(mediaH,0 ,1023, 0, 100));
      	lcd.setCursor(13, 1);
      	lcd.print("%  ");
  		delay(2000);
  }
  else{ 
    
    tone(buzzer, 1000);
    
    if(mediaL <= 900){
      	digitalWrite(11, LOW);
      	lcd.clear();
      	lcd.setCursor(0, 0);
      	lcd.print("Ambiente ok");
  		delay(2000);
      
    }
    
    if(mediaL > 950){
      	digitalWrite(11, LOW);
      	lcd.clear();
    	digitalWrite(12, HIGH);
      	lcd.setCursor(0, 0);
      	lcd.print("Ambiente muito");
  		lcd.setCursor(0, 1);
  		lcd.print("CLARO");
  		delay(2000);
      
    }
    if(900 < mediaL and mediaL < 950){
      	digitalWrite(11, LOW);
      	lcd.clear();
    	digitalWrite(10, HIGH);
      	lcd.setCursor(0, 0);
      	lcd.print("Ambiente a meia");
  		lcd.setCursor(0, 1);
  		lcd.print("luz");
  		delay(2000);
    }
    
    if(mediaT <= 15 and mediaT >= 10){
      	digitalWrite(11, LOW);
      	lcd.clear();
      	lcd.setCursor(0, 0);
      	lcd.print("Temperatura OK");
  		lcd.setCursor(0, 1);
  		lcd.print("Temp. = ");
    	lcd.setCursor(8, 1);
  		lcd.print(mediaT);
    	lcd.setCursor(12, 1);
      	lcd.print("C  ");
  		delay(2000);
    }
    
    if(mediaT > 15){
      	digitalWrite(11, LOW);
      	lcd.clear();
    	digitalWrite(10, HIGH);
      	lcd.setCursor(0, 0);
      	lcd.print("Temp. ALTA     ");
  		lcd.setCursor(0, 1);
  		lcd.print("Temp. = ");
    	lcd.setCursor(8, 1);
  		lcd.print(mediaT);
    	lcd.setCursor(12, 1);
      	lcd.print("C  ");
  		delay(2000);
    }
    if(mediaT < 10){
      	digitalWrite(11, LOW);
      	lcd.clear();
    	digitalWrite(10, HIGH);
      	lcd.setCursor(0, 0);
      	lcd.print("Temp. BAIXA    ");
  		lcd.setCursor(0, 1);
  		lcd.print("Temp. = ");
    	lcd.setCursor(8, 1);
  		lcd.print(mediaT);
    	lcd.setCursor(12, 1);
      	lcd.print("C  ");
  		delay(2000);
    }
    if(716 >= mediaH and mediaH >= 511){
      	digitalWrite(11, LOW);
    	lcd.clear();
      	lcd.setCursor(0, 0);
      	lcd.print("Umidade OK");
  		lcd.setCursor(0, 1);
  		lcd.print("Umidade = ");
    	lcd.setCursor(10, 1);
  		lcd.print(map(mediaH,0 ,1023, 0, 100));
      	lcd.setCursor(13, 1);
      	lcd.print("%  ");
  		delay(2000);
    }
    if(716 < mediaH){
      	digitalWrite(11, LOW);
    	lcd.clear();
    	digitalWrite(12, HIGH);
      	lcd.setCursor(0, 0);
      	lcd.print("Umidade ALTA    ");
  		lcd.setCursor(0, 1);
  		lcd.print("Umidade = ");
    	lcd.setCursor(10, 1);
  		lcd.print(map(mediaH,0 ,1023, 0, 100));
      	lcd.setCursor(13, 1);
      	lcd.print("%  ");
  		delay(2000);
    }
    if(511 > mediaH){
      	digitalWrite(11, LOW);
    	lcd.clear();
    	digitalWrite(12, HIGH);
      	lcd.setCursor(0, 0);
      	lcd.print("Umidade BAIXA    ");
  		lcd.setCursor(0, 1);
  		lcd.print("Umidade = ");
    	lcd.setCursor(10, 1);
  		lcd.print(map(mediaH,0 ,1023, 0, 100));
      	lcd.setCursor(13, 1);
      	lcd.print("%  ");
  		delay(2000);
    }
    
  }
  
}