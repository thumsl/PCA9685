#include "pca9685.h"
#include <stdio.h>

int main() {
	i2c bus = i2cOpen("/dev/i2c-1");
	PCA9685_init(bus);

	PCA9685_setFreq(bus, 1000);
	PCA9685_setDutyCicle(bus, 15, 99);

	printf("Press enter to quit.");
	getchar();

	PCA9685_stop(bus);
}
