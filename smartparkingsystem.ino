// ==========================================
// SMART PARKING SYSTEM
// Arduino UNO + 2 HC-SR04 + Red/Green LEDs
// ==========================================

// -------- SLOT 1 --------
const int trig1 = 2;
const int echo1 = 3;

const int green1 = 4;
const int red1 = 5;

// -------- SLOT 2 --------
const int trig2 = 6;
const int echo2 = 7;

const int green2 = 8;
const int red2 = 9;

// Distance at which a slot is considered occupied
const int occupiedDistance = 15;


// ==========================================
// FUNCTION TO MEASURE DISTANCE
// ==========================================

long getDistance(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  // If no echo is received
  if (duration == 0)
  {
    return 999;
  }

  long distance = duration * 0.034 / 2;

  return distance;
}


// ==========================================
// SETUP
// ==========================================

void setup()
{
  // Ultrasonic sensors
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  // LEDs
  pinMode(green1, OUTPUT);
  pinMode(red1, OUTPUT);

  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);

  // Start Serial Monitor
  Serial.begin(9600);
}


// ==========================================
// MAIN LOOP
// ==========================================

void loop()
{
  // Read Slot 1
  long distance1 = getDistance(trig1, echo1);

  // Small gap between sensors
  delay(50);

  // Read Slot 2
  long distance2 = getDistance(trig2, echo2);


  // ========================================
  // SLOT 1
  // ========================================

  if (distance1 <= occupiedDistance)
  {
    // CAR PARKED
    digitalWrite(red1, HIGH);
    digitalWrite(green1, LOW);
  }
  else
  {
    // SLOT FREE
    digitalWrite(red1, LOW);
    digitalWrite(green1, HIGH);
  }


  // ========================================
  // SLOT 2
  // ========================================

  if (distance2 <= occupiedDistance)
  {
    // CAR PARKED
    digitalWrite(red2, HIGH);
    digitalWrite(green2, LOW);
  }
  else
  {
    // SLOT FREE
    digitalWrite(red2, LOW);
    digitalWrite(green2, HIGH);
  }


  // ========================================
  // SERIAL MONITOR
  // ========================================

  Serial.print("Slot 1: ");
  Serial.print(distance1);
  Serial.print(" cm");

  Serial.print("     Slot 2: ");
  Serial.print(distance2);
  Serial.println(" cm");


  delay(200);
}