/*
 * st_ll_uart.h
 *
 *  Created on: Jan 26, 2023
 *      Author: Admin
 */

#ifndef DRIVER_ST_LL_UART_H_
#define DRIVER_ST_LL_UART_H_

#ifdef __cplusplus
 extern "C" {
#endif

 struct _usart_async_device;

 struct _usart_async_callback
 {
	 void (*tx_byte_set)(struct _usart_async_device *device);
 };

 struct _usart_async_device
 {
	 struct _usart_async_callback uart_cb;
	 void *						  hw;
 };

 int _usart_async_int(struct _usart_async_device *const device, void *const hw);


#ifdef __cplusplus
}
#endif


#endif /* DRIVER_ST_LL_UART_H_ */
