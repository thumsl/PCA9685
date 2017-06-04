#include "i2c.h"
#define MODE1 0x00
#define MODE2 0x01
#define LED0_ON_L 0x06
#define ADDRESS 0x40
#define ALLCALL 0x01
#define SLEEP 0x10
#define AI 0x20
#define OUTDRV 0x04
#define PRE_SCALE 0xFE
#define MAX_DUTY_CICLE 4095
#define REGISTERS_PER_CHANNEL 4
int PCA9685_init(i2c bus);
int PCA9685_setDutyCicle(i2c bus, char channel, unsigned short value);
int PCA9685_setFreq(i2c bus, unsigned short freq);
int PCA9685_stop(i2c bus);
