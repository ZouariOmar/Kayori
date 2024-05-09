


#include "inc.h"

int serialport_init(const char*, int);
int serialport_close(int);
int serialport_writebyte(int, uint8_t);
int serialport_read_until(int, char*, char, int, int);
int serialport_flush(int);

