/*
 * st_bus.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Admin
 */

#ifndef BUS_ST_BUS_H_
#define BUS_ST_BUS_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
 extern "C" {
#endif

#define MASTER_WRITE_CALL                    0
#define MASTER_READ_CALL                     1

//forward declaration of the structure.

typedef struct st_bus st_bus;

//function pointer to hold the array of the function.
typedef void (*function_table)(void);

//forward declaration
typedef unsigned int st_xferlength;
//main driver structure.
//this is driver instance structure, used for the driver library
struct st_bus {
	//constant part
	struct {
		//this will hold the table of the function
		//it's just pointer array to hold the array address
		//we use array of function and @table will hold those array address
		//each entry will be defined.. run-time modification not allowed.
		//too access the particular function driver call from the master function.
		const function_table *table;
		st_xferlength m_max_length;
	} m_const;

	//initialization driver status
	bool m_initilized;
};

//forward declaration for the master write call
typedef st_xferlength (st_bus_master_write_Func)(st_bus *pBus, const unsigned char *buf, st_xferlength len);
st_bus_master_write_Func st_bus_master_write;

//forward declaration for master read
typedef st_xferlength (st_bus_master_read_Func)(st_bus *pBus, const unsigned char *buf, st_xferlength len);
st_bus_master_read_Func st_bus_master_read;


#ifdef __cplusplus
}
#endif

#endif /* BUS_ST_BUS_H_ */
