#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int pump=13;
int LED=12;
int buz=11;
int d=0;

int ledState = LOW; 
int pumpState = LOW; 
unsigned long previousMillis = 0; 
const long interval = 200;  
unsigned long previousMillis2 = 0; 
const long interval2 = 30000;  

void setup() 
{
  lcd.begin(16, 2);
  pinMode(LED, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(pump, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
 {
  d=Serial.read();
 
  if(d == 'p' )
      { 
        lcd.clear();
        lcd.print(" Fire Detected ");
        Serial.println(" Fire Detected");
   
        Blink();
      
        digitalWrite(pump, HIGH);
        digitalWrite(buz, HIGH);
        delay(100);
      }

   if(d == 's' )
      {  
        lcd.clear();
        lcd.print("Capturing Video...");
        digitalWrite(LED, LOW); 
        digitalWrite(buz, LOW); 
        unsigned long currentMillis2 = millis();
       if ((unsigned long)(currentMillis2 - previousMillis2) >= interval2)
          {
            digitalWrite(pump, LOW);
            previousMillis2 = currentMillis2;
           }
      
        delay(5);
      }
 
 }

void Blink()
 {
   unsigned long currentMillis = millis();
   if (currentMillis - previousMillis >= interval)
     {
      previousMillis = currentMillis;
        if (ledState == LOW)
        {
          ledState = HIGH;
         } else
         {
          ledState = LOW;
          }
       digitalWrite(LED, ledState);
       digitalWrite(buz, ledState);
      }
  }
