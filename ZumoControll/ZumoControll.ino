#include <ZumoMotors.h>
#include <Servo.h>

#define servoPin = 11;
Servo servo;
ZumoMotors motors;

int leftTargetSpeed;
int rightTargetSpeed;
int currLSpeed;
int currRSpeed;
int turnSpeed;
int driveSpeed;
int idleTime;

void setup()
{
  Serial.begin(9600);
  leftTargetSpeed =0;
  rightTargetSpeed =0;
  currLSpeed = 0;
  currRSpeed = 0;
  turnSpeed = 100;
  driveSpeed = 100;
  idleTime = 0;
  newIdleTime();
  turnRight();//temporary
}



void loop()
{
  
  getInstructions();
  //timeOut();
  currLSpeed = motorSpeedControll(leftTargetSpeed,currLSpeed);
  currRSpeed = motorSpeedControll(rightTargetSpeed,currRSpeed);
  motors.setLeftSpeed(currLSpeed);
  motors.setRightSpeed(currRSpeed);
  Serial.println(currRSpeed);
}

void getInstructions()
{
  
}

int motorSpeedControll(int targetSpeed, int currentSpeed)
{
  if(currentSpeed > targetSpeed)
  {
    currentSpeed--;
  }
  else if(currentSpeed < targetSpeed)
  {
    currentSpeed++;
  }
  return currentSpeed;
}

void turnRight()
{
  leftTargetSpeed = turnSpeed;
  rightTargetSpeed = -turnSpeed;
}
void turnLeft()
{
  rightTargetSpeed = turnSpeed;
  leftTargetSpeed = -turnSpeed;
}

void forward()
{
  rightTargetSpeed = driveSpeed;
  leftTargetSpeed = driveSpeed;
}

void backwards()
{
  rightTargetSpeed = -driveSpeed;
  leftTargetSpeed = -driveSpeed;
}

void setSpeedL(int target)
{
  leftTargetSpeed = target;
}

void setSpeedR(int target)
{
  rightTargetSpeed = target;
}

void stopMotors()
{
  leftTargetSpeed = 0;
  rightTargetSpeed = 0;
}

void newIdleTime()
{
  idleTime = millis()+500;
}

boolean timeOut()
{
  boolean result = false;
  if(idleTime < millis())
  {
    stopMotors();
    result = true;
  }
  return result;
}
