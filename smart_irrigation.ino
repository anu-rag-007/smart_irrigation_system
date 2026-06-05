/*
  Smart Irrigation System
  Group: Arshan Khan, Anurag Sharma, Gaurav Rawat, Sahil Bora, Jay Manral
  Subject: Environmental Impact Analysis
  Cost: Under Rs.1000
  
  Connections:
  - Soil Moisture Sensor AO → Arduino A0
  - Relay IN → Arduino D8
  - Relay COM → Battery (+)
  - Relay NO → Pump (+)
  - Battery (-) → Pump (-)
*/

int sensorPin = A0;
int pumpPin   = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);  // HIGH = relay OFF at start (Active LOW relay)
}

void loop() {
  int val = analogRead(sensorPin);
  Serial.println(val);

  if (val > 600) {
    // Soil is DRY → LOW turns relay ON → pump runs
    digitalWrite(pumpPin, LOW);
    Serial.println("PUMP ON");
  } else {
    // Soil is WET → HIGH turns relay OFF → pump stops
    digitalWrite(pumpPin, HIGH);
    Serial.println("PUMP OFF");
  }

  delay(2000);
}