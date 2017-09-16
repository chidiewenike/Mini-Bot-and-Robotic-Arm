#include <IRremote.h>

int receiver = 3;
int sensor = 2;
int pirState = LOW;
int val = 0;
IRrecv irrecv(receiver);
decode_results pressed;

void setup() 
{
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(2, INPUT);
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop() 
{
  if(irrecv.decode(&pressed))
    {
    IR_Val();
    irrecv.resume();  
    }
}

void IR_Val()
{
  switch(pressed.value)
    {
    /* UP */   
    case 0xFF629D: 
      Serial.println("Forward");
      digitalWrite(6,HIGH); 
      digitalWrite(5, LOW); 
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      break;
      
    /* LEFT */  
    case 0xFF22DD: 
      Serial.println("LEFT");
 
      break;
       
    /* OK */   
    case 0xFF02FD: 
      stop();
      break;
      
    /* RIGHT */  
    case 0xFFC23D: 
      break;
      
    /* DOWN */  
    case 0xFFA857: 
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      break;
    case 0xFF6897: Serial.println(" 1"); break;
    case 0xFF9867: Serial.println(" 2"); break;
    case 0xFFB04F: Serial.println(" 3"); break;
    case 0xFF30CF: Serial.println(" 4"); break;
    case 0xFF18E7: Serial.println(" 5"); break;
    case 0xFF7A85: Serial.println(" 6"); break;
    case 0xFF10EF: Serial.println(" 7"); break;
    case 0xFF38C7: Serial.println(" 8"); break;
    case 0xFF5AA5: Serial.println(" 9"); break;
    case 0xFF42BD: Serial.println(" *"); break;
    case 0xFF4AB5: Serial.println(" 0"); break;
    case 0xFF52AD: Serial.println(" #"); break;
    case 0xFFFFFFFF: Serial.println(" Repeat"); break;



    default:
      Serial.println("other button   ");
    }
    delay(500);
}

void stop()
{
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

