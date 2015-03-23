#ifndef __SRALLOC_H__
#define __SRALLOC_H__

extern unsigned char * SRAMalloc(unsigned char nBytes);
extern void SRAMfree(void * pSRAM);
extern void SRAMInitHeap(void);

#endif