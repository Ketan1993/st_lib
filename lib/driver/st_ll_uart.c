#include "st_ll_uart.h"
#include "st_error_code.h"

static int _usart_init(void *const hw)
{
	//core driver initialization for UART
	//set the UART control register and status register
	return ERROR_NONE;
}

int _usart_async_int(struct _usart_async_device *const device, void *const hw)
{
	int status = ST_FAILED;

	status = _usart_init(hw);

	if(status != ERROR_NONE)
		return status;

	device->hw  = hw;

	//set the interrupt option
	//set the priority of the interrupt
	//enable the UART interrupt

	return status;
}
