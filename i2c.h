#ifndef I2C_h
#define I2C_h

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct i2c_t;
typedef struct i2c_t * i2c;

i2c i2cOpen(const char *filename);
int i2cWrite(i2c bus, int addr, unsigned char *buffer, int buffersize);
int i2cRegWrite(i2c bus, int addr, int reg, int data);
int i2cRead(i2c bus, int addr, unsigned char *buffer, int buffersize);
int i2cClose(i2c bus);

#endif
