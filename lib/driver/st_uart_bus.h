/*
 * st_uart_bus.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Admin
 */

#ifndef DRIVER_ST_UART_BUS_H_
#define DRIVER_ST_UART_BUS_H_

#include "st_bus.h"

#ifdef __cplusplus
 extern "C" {
#endif

#define ST_UART_COUNT            2
#define ST_UART_DRIVER_CALL      2

#define UART_DRIVER_FIFO         150 //Bytes

typedef st_bus *(st_uart_bus_driver_create_)(unsigned char instance);
st_uart_bus_driver_create_ st_uart_bus_driver_create;

#ifdef __cplusplus
}
#endif

#endif /* DRIVER_ST_UART_BUS_H_ */
