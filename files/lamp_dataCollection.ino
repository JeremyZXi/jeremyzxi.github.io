#define LED_PIN 11
#define POTENTIOMETER_PIN A1
#define LDRpin A0
#define LEDStatus_PIN 7
#define BUTTON_PIN 8
int LDRValue = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LEDStatus_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LDRpin, INPUT);
}

void loop()
{
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  int brightness = potentiometerValue / 4;
  analogWrite(LED_PIN, brightness);
  if(digitalRead(BUTTON_PIN)){
    LDRValue = analogRead(LDRpin);
    Serial.print(LDRValue);
    Serial.print(',');
    Serial.print(brightness);
    Serial.println();
    digitalWrite(LEDStatus_PIN,HIGH);
    delay(10);
    digitalWrite(LEDStatus_PIN,LOW);
    delay(100);
  }
  
}