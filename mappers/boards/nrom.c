#include "mappers/mapperinc.h"

static void reset(int hard)
{
	mem_setprg16(0x8,0);
	mem_setprg16(0xC,-1);
	if(nes->rom->chrsize)
		mem_setchr8(0,0);
	else
		mem_setvram8(0,0);
}

MAPPER(B_NROM,reset,0,0,0);
