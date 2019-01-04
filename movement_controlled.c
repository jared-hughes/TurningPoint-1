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
    if (conveyorUpButton)
    {
        moveConveyor(127);
    }
    else if (conveyorDownButton)
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
    if (flywheelButton)
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
    int speed = deDead(vexRT[armJoystick]);
    moveArms(speed);
}

// claw

bool lastClawButtonValue = false;
bool clawFlipped = true;
int clawDir = 0;

void doClaw() {
	/* Button 7U to flip the claw 180 deg
	 * Buttons 5U and 5D move claw back and forth
	 */
	// for flipping 180
	bool currentClawButtonValue = clawButton ? true : false;
	if (currentClawButtonValue && !lastClawButtonValue) {
		flipClaw();
	}
	lastClawButtonValue = currentClawButtonValue;
}
