#include "st_bus.h"

#ifdef DEBUG
#define CheckInstance(pBus, failed) \
	do { \
		if((!pBus) || (!pBus->m_initilized)) \
		 return (failed); \
		}while(0)
#else
#define CheckInstance(pBus, failed)
#endif //

st_xferlength st_bus_master_write(st_bus *pBus, const unsigned char *buf, st_xferlength len) {

	CheckInstance(pBus, false); //failed..
	if (!pBus)
		return -1;  //failed..

	const st_bus_master_write_Func *func = (const st_bus_master_write_Func*) pBus->m_const.table[MASTER_WRITE_CALL];

	if (!func)
		return -2; //failed...

	return (*func)(pBus, buf, len);
}

st_xferlength st_bus_master_read(st_bus *pBus, const unsigned char *buf, st_xferlength len) {

	CheckInstance(pBus, false); //failed..

	if (!pBus)
		return -1;  //failed..

	const st_bus_master_read_Func *func = (const st_bus_master_read_Func*) pBus->m_const.table[MASTER_READ_CALL];

	if (!func)
		return -2; //failed...

	return (*func)(pBus, buf, len);
}

