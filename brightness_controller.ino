const byte led_gpio = 32;
#define POTENTIOMETER_PIN 15

void setup() {
  Serial.begin(9600);
  pinMode(POTENTIOMETER_PIN,INPUT);
  // put your setup code here, to run once:
  ledcAttachPin(led_gpio,0);
  ledcSetup(0,4000,8);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(analogValue, 0, 4095, 0, 255);
  ledcWrite(0,brightness);
  Serial.println(brightness);
  delay(30);
  

}
