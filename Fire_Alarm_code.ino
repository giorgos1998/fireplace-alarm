int greenLed = 13;
int Smoke = A5; //Gas sensor
int sensorThres = 350; //Activation threshold value
int buzzer = 11;
int i = 0;
int redLed1 = 8;
int redLed2 = 9;

void setup() {  
  /*
   * Sets the LED pins as output pins, the gas sensor pin as an
   * input pin and starts the serial
   */
  pinMode(greenLed, OUTPUT);
  pinMode(redLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(Smoke, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(Smoke); //Read from the gas sensor

  Serial.print("Gas sensor reading: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres) // Checks if it has reached the threshold value
  {
    /*
     * In the following loop, the buzzer plays a warning sound and the
     * 2 red LEDs look like a warning siren
     */
    for (i = 200; i <=800; i++)
    {
      digitalWrite(redLed1, HIGH);
      digitalWrite(redLed2, LOW);
      tone(buzzer, i) ;
      delay (1) ;
    }
    delay(100);
    for (i = 800; i >=200; i--)
    {
      digitalWrite(redLed1, LOW);
      digitalWrite(redLed2, HIGH);
      tone(buzzer, i) ;
      delay (1) ;
    }
    noTone(buzzer);
  }
  else{
    /*
     * Reset all the LEDs and blick the green LED to indicate
     * that everything is working
     */
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(100);
    digitalWrite(greenLed, LOW);
    delay(500);
  }
  delay(100); //Delay between each code loop
}
