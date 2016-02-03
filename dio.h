/*
 * dio.h
 *
 *  Created on: Feb 3, 2016
 *      Author: Jason
 */

#ifndef DIO_H_
#define DIO_H_

void DIO_makeOutput(int port, int pin);
void DIO_makeInput(int port, int pin);
void DIO_enableInterrupt(int port, int pin, void (*functPtr)());
void DIO_disableInterrupt(int port, int pin);

#endif /* DIO_H_ */
