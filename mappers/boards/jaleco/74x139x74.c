#include "mappers/mapperinc.h"
#include "mappers/chips/c_latch.h"

static u8 banks[] = {0,2,1,3};

static void sync()
{
	mem_setchr8(0,banks[latch_reg & 3]);
}

static void reset(int hard)
{
	latch_init(sync);
	mem_setwrite(6,latch_write);
	mem_setwrite(7,latch_write);
	mem_setprg16(0x8,0);
	mem_setprg16(0xC,0xFF);
}

MAPPER(B_74x139x74,reset,0,0,latch_state);
