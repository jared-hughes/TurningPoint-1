#define clawPosA 1218
#define clawPosB 4000

int clawTarget;

void flipClaw() {
	int pos = SensorValue[clawPot];
	if (abs(pos - clawPosA) < abs(pos - clawPosB)) {
		clawTarget = clawPosB;
	} else {
		clawTarget = clawPosA;
	}
}

task clawController() {
	while(true) {
		// TOCALIBRATE
		int error = clawTarget - SensorValue[clawPot];
		// adjust multiplier as kP (proportionality coefficient)
		int motorPower = error / 7;
		motorPower = bound(motorPower, 127);
		motorPower = deDead(motorPower);
		moveClaw(motorPower);
		wait1Msec(1);
	}
}
