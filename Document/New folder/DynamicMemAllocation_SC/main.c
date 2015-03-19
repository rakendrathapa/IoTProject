

#include "sralloc.h"


void TestFill(unsigned char * fAddr, unsigned char fCnt, unsigned char fChar);

void main(void)
{
	
	unsigned char * pTest1;
	unsigned char * pTest2;
	unsigned char * pTest3;
	unsigned char * pTest4;
	unsigned char * pTest5;
	unsigned char * pTest6;
	unsigned char * pTest7;
	
	SRAMInitHeap();
	
	while (1)
	{
		pTest1 = SRAMalloc(1); TestFill(pTest1, 1, 0xFF);
		pTest2 = SRAMalloc(126); TestFill(pTest2, 126, 0xFF);
		
		SRAMfree(pTest2); TestFill(pTest2, 126, 0x00);
		SRAMfree(pTest1); TestFill(pTest1, 1, 0x00);
		
		
		pTest1 = SRAMalloc(8); TestFill(pTest1, 8, 0xFF);
		pTest2 = SRAMalloc(40); TestFill(pTest2, 40, 0xFF);
		pTest3 = SRAMalloc(8); TestFill(pTest3, 8, 0xFF);
		pTest4 = SRAMalloc(20); TestFill(pTest4, 20, 0xFF);
		pTest5 = SRAMalloc(12); TestFill(pTest5, 12, 0xFF);
		pTest6 = SRAMalloc(56); TestFill(pTest6, 56, 0xFF);
		pTest7 = SRAMalloc(92); TestFill(pTest7, 92, 0xFF);
	
		SRAMfree(pTest2); TestFill(pTest2, 40, 0x00);
		SRAMfree(pTest1); TestFill(pTest1, 8, 0x00);
		
		pTest1 = SRAMalloc(30); TestFill(pTest1, 30, 0xFF);
		pTest2 = SRAMalloc(120); TestFill(pTest2, 120, 0xFF);
		
		SRAMfree(pTest1); TestFill(pTest1, 30, 0x00);
		SRAMfree(pTest4); TestFill(pTest4, 20, 0x00);
		SRAMfree(pTest3); TestFill(pTest3, 8, 0x00);
		SRAMfree(pTest7); TestFill(pTest7, 92, 0x00);
		SRAMfree(pTest6); TestFill(pTest6, 56, 0x00);
		SRAMfree(pTest5); TestFill(pTest5, 12, 0x00);
		SRAMfree(pTest2); TestFill(pTest2, 120, 0x00);
	}
	
}



void TestFill(unsigned char * fAddr, unsigned char fCnt, unsigned char fChar)
{
	while(fCnt)
	{
		*fAddr = fChar;
		fAddr++;
		fCnt--;
	}	
}
