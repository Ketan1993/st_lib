/*
 * st_io.h
 *
 *  Created on: Jan 26, 2023
 *      Author: Admin
 */

#ifndef DRIVER_ST_IO_H_
#define DRIVER_ST_IO_H_

#ifdef __cplusplus
 extern "C" {
#endif

struct io_descriptor;

typedef int (*io_write_t)(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len);
typedef int (*io_read_t)(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len);

struct io_descriptor
{
	io_write_t write;
	io_read_t  read;
};

int io_write(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len);
int io_read(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len);

#ifdef __cplusplus
}
#endif


#endif /* DRIVER_ST_IO_H_ */
