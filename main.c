#include <stdio.h>
#include "makestuff.h"
#include "libgpiojtag.h"
#include <wiringPi.h>
#include "liberror.h"

// Pin assignments on the RPi header (see http://wiringpi.com/pins):
typedef enum {
	TCK = 7,
	TDO = 9,
	TDI = 8,
	TMS = 16
} Pins;

// Callbacks implementing actual GPIO for JTAG lines
void setTCK(unsigned char x) {
	digitalWrite(TCK, x ? HIGH : LOW);
}
void setTDI(unsigned char x) {
	digitalWrite(TDI, x ? HIGH : LOW);
}
void setTMS(unsigned char x) {
	digitalWrite(TMS, x ? HIGH : LOW);
}
bool getTDO(void) {
	return digitalRead(TDO) == HIGH;
}

int main(int argc, const char *argv[]) {
	wiringPiSetup();

	if(argc != 2) {
		fprintf(stderr, "Synopsis: %s <svf-file>\n", argv[0]);
		exit(0);
	}

	// Setup pins
	pinMode(TCK, OUTPUT);
	pinMode(TMS, OUTPUT);
	pinMode(TDI, OUTPUT);
	pinMode(TDO, INPUT);
	digitalWrite(TCK, LOW);
	digitalWrite(TMS, LOW);
	digitalWrite(TDI, LOW);

	// Parse .svf file
	const char *error = NULL;
	const struct ParserCallbacks cb = {setTCK, setTMS, setTDI, getTDO};
	ParserStatus pStatus = parse(argv[1], &cb, &error);

	pinMode(TCK, INPUT);
	pinMode(TMS, INPUT);
	pinMode(TDI, INPUT);
	pinMode(TDO, INPUT);
}
