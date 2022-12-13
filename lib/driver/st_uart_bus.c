#include "st_uart_bus.h"

//forward declaration for API.
st_bus_master_write_Func st_uart_master_write;
st_bus_master_write_Func st_uart_master_read;

//create function pointer array
static function_table const functionArray[ST_UART_DRIVER_CALL] = {
		(function_table) st_uart_master_write,
		(function_table) st_uart_master_read,
};

typedef struct st_uart
{
	st_bus bus;
}st_uart;

static st_uart st_uart_instance[ST_UART_COUNT] = {
		{//0
			{//bus
					{functionArray, UART_DRIVER_FIFO}, //constant part
					false, //allocation
			}
		}
};

st_xferlength st_uart_master_write(st_bus *pBus, const unsigned char *buf, st_xferlength len) {
	return len;
}
st_xferlength st_uart_master_read(st_bus *pBus, const unsigned char *buf, st_xferlength len) {

	return len;
}
st_bus* st_uart_bus_driver_create(unsigned char instance) {

	//driver instance check
	//should not more the total driver count.
	if(instance > ST_UART_COUNT) return 0; //failed

	st_uart *pSerial = &st_uart_instance[instance];

	//check driver is already initialize.
	if(pSerial->bus.m_initilized) return 0;

	//make initialization done
	pSerial->bus.m_initilized = true;

	return(st_bus*)pSerial;
}

