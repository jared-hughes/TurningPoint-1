// ---- MOVE: advanced movement (autom helpers)

// drive

void rotateLeftFixed(int speed)
{
    moveDrive(0, speed);
}

void rotateRightFixed(int speed)
{
    moveDrive(speed, 0);
}

void rotateInPlace(int speed)
{
    /* positive speed: turn right
   * negative speed: turn left
	 */
    moveDrive(speed, -speed);
}

void driveStraight(int speed)
{
    moveDrive(speed, speed);
}

void stopDriving()
{
    moveDrive(0, 0);
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
