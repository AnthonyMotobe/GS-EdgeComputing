int redLed = 13;
int yelLed = 12;
int greLed = 11;
int pirInputPin = 2;
int pirState = LOW;
int val = 0;
int quantity = 0;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yelLed, OUTPUT);
  pinMode(greLed, OUTPUT);
  pinMode(pirInputPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pirInputPin);

  if (val == HIGH) {
    quantity = quantity + 1;

    Serial.println("Movimento detectado!");

    pirState = HIGH;
  } else {
    if (pirState == HIGH){
      Serial.println("Movimento finalizado");
      Serial.println(quantity);
      pirState = LOW;
    }
  }
  
  if () {
  }
  delay(500);
}
