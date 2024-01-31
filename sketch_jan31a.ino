// Define motion sensor pin
const int motionSensorPin = 2;
// Define LED pin
const int ledPin = 12;
// Define motion flag
volatile bool motionDetected = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set motion sensor pin as input
  pinMode(motionSensorPin, INPUT);
  
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Attach interrupt to motion sensor pin
  attachInterrupt(digitalPinToInterrupt(motionSensorPin), motionDetectedISR, CHANGE);
}

void loop() {
  // No need for code here since we're using interrupts
}

// Interrupt Service Routine (ISR) for motion detection
void motionDetectedISR() {
  // Read motion sensor input
  int motionSensorState = digitalRead(motionSensorPin);
  
  // Update motion flag
  motionDetected = (motionSensorState == HIGH);
  
  // Print motion status
  Serial.print("Motion Detected: ");
  Serial.println(motionDetected ? "Yes" : "No");

  // Act based on motion status
  if (motionDetected) {
    digitalWrite(ledPin, HIGH); // Turn on LED
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED
  }
}
