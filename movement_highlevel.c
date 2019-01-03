#include "movement_atomic.c"

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