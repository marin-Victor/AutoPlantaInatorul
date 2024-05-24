// Constants
const int RELAY_PIN = 2;
const int SENSOR_PIN = A0;
const int THRESHOLD = 40;

const int FORWARD_PIN = 8;

// Variables
int sensorValue;

// Function Prototypes
void setupPins();
void readSensor();
void controlForwardMotion();
void controlRelay();

// Setup function
void setup() {
  setupPins();
  Serial.begin(9600);
}

// Main loop
void loop() {
  readSensor();
  controlForwardMotion();
  controlPump();
}

// Function Definitions

void setupPins() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(FORWARD_PIN, OUTPUT);
  digitalWrite(FORWARD_PIN, HIGH);
  digitalWrite(RELAY_PIN, HIGH);
}

void readSensor() {
  sensorValue = analogRead(SENSOR_PIN);
  Serial.println(sensorValue);
}

void controlForwardMotion() {
  if (sensorValue < THRESHOLD) {
    digitalWrite(FORWARD_PIN, LOW);
    delay(5000);
    digitalWrite(FORWARD_PIN, HIGH);
  }
}

void controlPump() {
  String data = Serial.readString();
  if (data == "start") {
    digitalWrite(RELAY_PIN, LOW);
    delay(5000);
    digitalWrite(RELAY_PIN, HIGH);
  }
}