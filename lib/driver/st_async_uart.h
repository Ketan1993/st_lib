/*
 * st_async_uart.h
 *
 *  Created on: Jan 26, 2023
 *      Author: Admin
 */

#ifndef DRIVER_ST_ASYNC_UART_H_
#define DRIVER_ST_ASYNC_UART_H_

#include "st_io.h"
#include "st_ll_uart.h"

#ifdef __cplusplus
 extern "C" {
#endif

 struct usart_async_descriptor;

 struct usart_async_descriptor
 {
	 struct io_descriptor io;
	 struct _usart_async_device device;
 };

 //async uart initialization
int st_async_uart_init(struct usart_async_descriptor *const descr, void *const hw);

#ifdef __cplusplus
}
#endif

#endif /* DRIVER_ST_ASYNC_UART_H_ */
