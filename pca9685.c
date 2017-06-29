#include "pca9685.h"

int PCA9685_init(i2c bus) {
	return i2c_reg_write(bus, PCA9685_ADDRESS, PCA9685_MODE1, PCA9685_ALLCALL | PCA9685_AI)
		+ i2c_reg_write(bus, PCA9685_ADDRESS, PCA9685_MODE2, PCA9685_OUTDRV);
}

int PCA9685_setDutyCicle(i2c bus, char channel, short value) {
	value = value < 0? 0:
			value > 100? PCA9685_MAX_DUTY_CICLE:
			(PCA9685_MAX_DUTY_CICLE * value) / 100;

	unsigned char buf[5];
	buf[0] = PCA9685_LED0_ON_L + (PCA9685_REGISTERS_PER_CHANNEL * channel);
	buf[1] = buf[2] = 0x00;
	buf[3] = value & 0xFF; buf[4] = (value >> 8) & 0xF;

	return i2c_write(bus, PCA9685_ADDRESS, buf, 5);
}

int PCA9685_setFreq(i2c bus, unsigned short freq) {
	freq = freq < 24? 0xFF:
			freq > 1526? 0x03:
			25000000 / (4096 * freq);

	return i2c_reg_write(bus, PCA9685_ADDRESS, PCA9685_PRE_SCALE, freq);
}

int PCA9685_stop(i2c bus) {
	return i2c_reg_write(bus, PCA9685_ADDRESS, PCA9685_MODE1, PCA9685_SLEEP);
}
