#include "pca9685.h"

int PCA9685_init(i2c bus) {
	return i2cRegWrite(bus, PCA9685_ADDRESS, PCA9685_MODE1, PCA9685_ALLCALL | PCA9685_AI)
		+ i2cRegWrite(bus, PCA9685_ADDRESS, PCA9685_MODE2, PCA9685_OUTDRV);
}

int PCA9685_setDutyCicle(i2c bus, char channel, unsigned short value) {
	value = (PCA9685_MAX_DUTY_CICLE * value) / 100;

	unsigned char buf[5];
	buf[0] = PCA9685_LED0_ON_L + (PCA9685_REGISTERS_PER_CHANNEL * channel);
	buf[1] = buf[2] = 0x00;
	buf[3] = value & 0xFF; buf[4] = (value >> 8) & 0xF;

	return i2cWrite(bus, PCA9685_ADDRESS, buf, 5);
}

int PCA9685_setFreq(i2c bus, unsigned short freq) {
	freq = 25000000 / (4096 * freq);
	return i2cRegWrite(bus, PCA9685_ADDRESS, PCA9685_PRE_SCALE, freq);
}

int PCA9685_stop(i2c bus) {
	return i2cRegWrite(bus, PCA9685_ADDRESS, PCA9685_MODE1, PCA9685_SLEEP);
}
