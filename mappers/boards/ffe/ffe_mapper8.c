#include "mappers/mapperinc.h"

static u8 reg;

static void sync()
{
	mem_setprg32(8,(reg >> 3) & 7);
	mem_setvram8(0,reg & 7);
}

static void write(u32 addr,u8 data)
{
	reg = data;
	sync();
}

static void reset(int hard)
{
	int i;

	for(i=8;i<0x10;i++)
		mem_setwrite(i,write);
	nes_setsramsize(2);
	mem_setsram8(6,0);
	reg = 0;
	sync();
}

static void state(int mode,u8 *data)
{
	STATE_U8(reg);
	sync();
}

MAPPER(B_FFE_MAPPER8,reset,0,0,state);
