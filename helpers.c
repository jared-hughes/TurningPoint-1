#include "movement_highlevel.c"

// ---- HELPERS

int deDead(int in, int threshold)
{
    // deal with dead zone
    if (abs(in) < threshold)
    {
        return 0;
    }
    return in;
}

int deDead(int in)
{
    return deDead(in, 10);
}

void waitMS(int millis)
{
    wait1Msec(millis);
}

void wait(int seconds)
{
    wait1Msec(seconds * 1000);
}

void driveDistance(int distance)
{
    // calibrate so distance is in inches (1/24 of tile)
    driveStraight(sgn(distance) * 60);
    // TOCALIBRATE
    waitMS(abs(distance) * 10);
    stopDriving();
}

int angleMultiplier = 1;
void rotateAngle(int angle)
{
    // calibrate so angle is in degrees
    // positive --> clockwise
    // TOCALIBRATE
    rotateInPlace(sgn(angle) * 60);
    waitMS(abs(angle) * 10);
    stopDriving();
}

void shoot(int flag, int distanceFromBase)
{
    // 3 for top flag, 2 for middle flag
    int dx = distanceFromBase;
    int dy;
    if (flag == 3)
    {
        dy = 46;
    }
    else if (flag == 2)
    {
        dy = 32;
    }
    // TODO: now do some physics and speed curve to determine motor control
}

// ---- DO: observe input and act upon it

// drive

void doDrive()
{
    // one-joystick drive on left joystick (ch 3 and 4)
    int y = deDead(vexRT[Ch3]);
    int x = deDead(vexRT[Ch4]);
    int leftSpeed = x + y;
    int rightSpeed = x - y;
    moveDrive(leftSpeed, rightSpeed);
}

// conveyor

void doConveyor()
{
    // buttons 6U and 6D move conveyor up and down
    if (vexRT[Btn6U])
    {
        moveConveyor(127);
    }
    else if (vexRT[Btn6D])
    {
        moveConveyor(-127);
    }
    else
    {
        moveConveyor(0);
    }
}

// flywheel

void doFlywheel()
{
    // button 8U runs flywheel
    if (vexRT[Btn8U])
    {
        moveFlywheel(60);
    }
    else
    {
        moveFlywheel(0);
    }
}

// arm

void doArms()
{
    // Right joystick (ch2) controls arms
    int speed = deDead(vexRT[Ch2]);
    moveArms(speed);
}

// claw

bool lastClawButtonValue = false;
bool clawFlipped = true;
int clawDir = 0;

void flipClaw()
{
    moveClaw(60);
    // TOCALIBRATE
    waitMS(500);
    moveClaw(0);
}

/*void doClaw() {
	/* Button 7U to flip the claw 180 deg
	 * Buttons 5U and 5D move claw back and forth

	// for flipping 180
	bool currentClawButtonValue = vexRT[Btn7U] ? true : false;
	if (currentClawButtonValue && !lastClawButtonValue) {
		flipClaw();
	}
	lastClawButtonValue = currentClawButtonValue;
	// for back and forth
	int clawSpeed = 100;
	if (vexRT[Btn5U]) {
		moveClaw(clawSpeed);
	} else if (vexRT[Btn5D]) {
		moveClaw(-clawSpeed);
	} else {
		moveClaw(0);
	}
}
*/
