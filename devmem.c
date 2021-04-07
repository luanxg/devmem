#include <rthw.h>
#include <rtthread.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void devmem(int argc, char **argv)
{
	rt_uint64_t tmp;
	rt_uint32_t addr, value;
    int access_type = 'w';

	/* check args */
	if (argc < 2) 
    {
		rt_kprintf("\nUsage:\t%s address [type [data]]\n"
                   "\taddress : memory address to act upon\n"
                   "\ttype    : access operation type : [b]yte, [h]alfword, [w]ord\n"
                   "\tdata    : data to be written\n\n", argv[0]);
		return;
	}

	/* get address */
	tmp = strtoll(argv[1], RT_NULL, 16);
	addr = (rt_uint32_t)tmp;

    /* get access_type */
	if (argc >= 3) 
    {
		access_type = tolower(argv[2][0]);
	}

	if (argc >= 4) 
    {
		/* write value */
		tmp = strtoll(argv[3], RT_NULL, 16);
		value = (rt_uint32_t)tmp;

		switch (access_type) 
        {
		case 'b':
			*(volatile rt_uint8_t*)addr = (rt_uint8_t)value;
			break;
		case 'h':
			*(volatile rt_uint16_t*)addr = (rt_uint16_t)value;
			break;
		case 'w':
			*(volatile rt_uint32_t*)addr = (rt_uint32_t)value;
			break;
		default:
			*(volatile rt_uint32_t*)addr = (rt_uint32_t)value;
			break;
		}
	} 
    else 
    {
		/* read value */
		switch (access_type) 
        {
		case 'b':
			rt_kprintf("0x%02x\n", *(volatile rt_uint8_t*)addr);
			break;
		case 'h':
			rt_kprintf("0x%04x\n", *(volatile rt_uint16_t*)addr);
			break;
		case 'w':
			rt_kprintf("0x%08x\n", *(volatile rt_uint32_t*)addr);
			break;
		default:
			rt_kprintf("0x%08x\n", *(volatile rt_uint32_t*)addr);
			break;
		}
	}
}
MSH_CMD_EXPORT(devmem, devmem address [type [data]]);
