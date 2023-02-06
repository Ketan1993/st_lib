#include <assert.h>
#include "st_async_uart.h"
#include "st_error_code.h"

static void uart_process_byte_sent(struct _usart_async_device *device);
static int  uart_async_write(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len);
static int  uart_async_read(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len);

int st_async_uart_init(struct usart_async_descriptor *const descr, void *const hw)
{
	int status = ST_FAILED;

	assert(descr && hw);

	status = _usart_async_int(&descr->device, hw);

	//set the low level driver call.
	//io call will be called from master call
	descr->io.write = uart_async_write;
	descr->io.read  = uart_async_read;

	//set the call back function for low-level driver
	//this call back will report the user-call back function
	descr->device.uart_cb.tx_byte_set = uart_process_byte_sent;
	return status;
}

static int  uart_async_write(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len)
{
	return ERROR_NONE;
}
static int  uart_async_read(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len)
{
	return ERROR_NONE;
}
static void uart_process_byte_sent(struct _usart_async_device *device)
{

}
