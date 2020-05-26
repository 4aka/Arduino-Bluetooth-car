/**
 * Before do something, please read "README"
 *
 * Here are uses 2 motors:
 *    the first motor drives forward\backward only
 *    the second one turns left\right only.
**/

// See picture for understending how does it set.
int motorLeft = 2;
int motorRight = 4;
int motorForward = 7;
int motorBack = 8;

void setup()
{
  pinMode(motorLeft, OUTPUT);
  pinMode(motorRight, OUTPUT);
  pinMode(motorForward, OUTPUT);
  pinMode(motorBack, OUTPUT);
  
  Serial.begin(9600); // for HC-05

  Stop();
}

void loop()
{
  if (Serial.available() > 0)
  {
    Stop();
    char command = Serial.read();

    // Serial.println(command);

    // This latters app send by bluetooh in different cases.
    // Do not change this latters!
    switch (command) {
      case 'F': forward();       break; // drive forward
      case 'B': back();          break; // drive backward
      case 'L': left();          break; // drive left
      case 'R': right();         break; // drive right
      case 'G': forward_left();  break; // drive forward and left
      case 'I': forward_right(); break; // drive forward and right
      case 'H': back_left();     break; // drive backward and left
      case 'J': back_right();    break; // drive backward and right
    }
  }
}

void forward()
{
  digitalWrite(motorForward, HIGH);
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorBack, LOW);
}

void back()
{
  digitalWrite(motorBack, HIGH);
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorForward, LOW);
}

void left() {
  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorForward, LOW);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorBack, LOW);
}

void right() {
  digitalWrite(motorRight, HIGH);
  digitalWrite(motorForward, LOW);
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorBack, LOW);
}

void forward_left()
{
  digitalWrite(motorForward, HIGH);
  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorBack, LOW);
}

void forward_right()
{
  digitalWrite(motorForward, HIGH);
  digitalWrite(motorRight, HIGH);
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorBack, LOW);
}

void back_left()
{
  digitalWrite(motorBack, HIGH);
  digitalWrite(motorLeft, HIGH);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorForward, LOW);
}

void back_right()
{
  digitalWrite(motorBack, HIGH);
  digitalWrite(motorRight, HIGH);
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorForward, LOW);
}

void Stop()
{
  digitalWrite(motorLeft, LOW);
  digitalWrite(motorRight, LOW);
  digitalWrite(motorForward, LOW);
  digitalWrite(motorBack, LOW);
}
