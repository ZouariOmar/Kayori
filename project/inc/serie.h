/* -----------------------------------------------
* @team:   by_kayori_Nova_Grp
* @author: zouari_omar
* @update: 04/06/24
? @file:   serial.h
----------------------------------------------- */

#ifndef __SERIAL_H__
#define __SERIAL_H__

//? -------------------- FUNCTIONS PROTOTYPE DECLARATION PART --------------------
int serialport_init(const char*, int);
int serialport_close(int);
int serialport_writebyte(int, uint8_t);
int serialport_read_until(int, char*, char, int, int);
int serialport_flush(int);

#endif