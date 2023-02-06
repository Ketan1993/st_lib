#include "st_io.h"
#include <assert.h>

int io_write(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len)
{
	assert(io_descr && buf);
	return io_descr->write(io_descr, buf, len);
}

int io_read(struct io_descriptor *const io_descr, const unsigned char *buf, unsigned int len)
{
	assert(io_descr && buf);
	return io_descr->read(io_descr, buf, len);
}
