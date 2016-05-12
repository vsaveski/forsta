int sensorEtt = A0;
int sensorTva = A1;
int sensorTre = A2;
int Buzzer = 7;

int ledEtt = 2;
int ledTva = 3;
int ledTre = 4;


int valueEtt = 0;
int valueTva = 0;
int valueTre = 0;

int state = 0;

void setup() {
  
    Serial.begin(9600);
    pinMode(sensorEtt, INPUT);
    pinMode(sensorTva, INPUT);
    pinMode(sensorTre, INPUT);

    pinMode(ledEtt, OUTPUT);
    pinMode(ledTva, OUTPUT);  
    pinMode(ledTre, OUTPUT);

    pinMode(Buzzer, OUTPUT);

}

void loop() {
  
    valueEtt = analogRead(sensorEtt);
    /*Serial.println(valueEtt);*/
    if(valueEtt > 960) {
        digitalWrite(ledEtt, HIGH);
        state++;
        delay(200);
        Serial.println(state);
    }
   
    valueTva = analogRead(sensorTva);
    /*Serial.println(valueTva);*/
    if(valueTva > 960) {
        digitalWrite(ledTva, HIGH); 
        state++;
        delay(200);
        Serial.println(state);
    }
    
    valueTre = analogRead(sensorTre);
    /*Serial.println(valueTre);*/
    if(valueTre > 960) {
        digitalWrite(ledTre, HIGH);
        state++;
        delay(200);
        Serial.println(state);
    }

    
    if (state == 3) { 
        tone(Buzzer, 400); 
        digitalWrite(ledTva, HIGH);
        delay(500);
        digitalWrite(ledTva, LOW);
        tone(Buzzer, 800); 
        digitalWrite(ledEtt, HIGH);
        delay(500);
        digitalWrite(ledEtt, LOW);
        tone(Buzzer, 400); 
        digitalWrite(ledTva, HIGH);
        delay(500);
        digitalWrite(ledTva, LOW);
        tone(Buzzer, 800); 
        digitalWrite(ledTre, HIGH);
        delay(500);
        digitalWrite(ledTre, LOW);
        tone(Buzzer, 400); 
        digitalWrite(ledTva, HIGH);
        delay(500);
        digitalWrite(ledTva, LOW);
        tone(Buzzer, 800); 
        digitalWrite(ledEtt, HIGH);
        delay(500);
        digitalWrite(ledEtt, LOW);
        noTone(Buzzer);

        state = 0;
        digitalWrite(ledTre, LOW);
    }


}
