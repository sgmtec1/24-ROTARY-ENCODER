// Open Source
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

 int CLK = 9;  // Pin 9 to clk on encoder
 int DT = 8;  // Pin 8 to DT on encoder
 
 int RedLed = 4;// RGB
 int GreenLed = 5;
 int BlueLed = 6;
 
 int RotPosition = 0; 
 int rotation;  
 int value;
 boolean LeftRight;
 
 void setup() { 
   lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
   lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
   Serial.begin (9600);
   pinMode (CLK,INPUT);
   pinMode (DT,INPUT);
   pinMode (RedLed, OUTPUT);
   pinMode (GreenLed, OUTPUT);
   pinMode (BlueLed, OUTPUT);
   rotation = digitalRead(CLK);   
 } 
 void loop() { 
   value = digitalRead(CLK);
     if (value != rotation){ // we use the DT pin to find out which way we turning.
     if (digitalRead(DT) != value) {  // Clockwise
       RotPosition ++;
       LeftRight = true;
     } else { //Counterclockwise
       LeftRight = false;
       RotPosition--;
     }
     if (LeftRight){ // turning right will turn on red led.
       Serial.println ("clockwise");
       digitalWrite (RedLed, HIGH);
       digitalWrite (GreenLed, LOW);
       lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
       lcd.print("ESQUERDA    "); //IMPRIME O TEXTO NO DISPLAY LCD
     }else{        // turning left will turn on green led.   
       Serial.println("counterclockwise");
       digitalWrite (RedLed, LOW);
       digitalWrite (GreenLed, HIGH);
       lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
       lcd.print("DIREITA    "); //IMPRIME O TEXTO NO DISPLAY LCD
     }
     Serial.print("Encoder Rotação Posição: ");
     Serial.println(RotPosition);
     lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
     lcd.print("ENCODER POS: "); //IMPRIME O TEXTO NO DISPLAY LCD
     lcd.print(RotPosition); //IMPRIME O TEXTO NO DISPLAY LCD
     lcd.print("   "); //IMPRIME O TEXTO NO DISPLAY LCD
   } 
   rotation = value;
 } 
