// rdtsc.cpp
// processor: x86, x64  
#include <stdio.h>  
#include "stdafx.h"
#include <intrin.h>  
#include<windows.h>

#pragma intrinsic(__rdtsc) 

int main()
{
	LARGE_INTEGER fr, li, oli;
	if (!QueryPerformanceFrequency(&fr))
		printf_s("QueryPerformanceFrequency failed!\n");
	double usec = 0.0, freq = 0.0, qpc = 0.0, dfr, diff;
	unsigned __int64 i, oi, del, ldel, ddel,lfr;
//	freq = 2500000;
	lfr= fr.QuadPart;
	lfr = lfr * 1024;
//	freq = dfr;
	oi = 0;
	oli.QuadPart = 0;
	for (int j = 1; j < 100; j++) {
		Sleep(500);
//		QueryPerformanceCounter(&li);
		i = __rdtsc();
		del = i - oi;
		//		del = del / 1024;
//		ldel = li.QuadPart - oli.QuadPart;
//		ldel = ldel * 1024;
//		qpc = (double(ldel) / lfr);
//		qpc = qpc / 1024;
		usec = (double)del / lfr;
//		diff = (usec - qpc) * 1000000;
//		ddel = del - ldel;
//		printf_s("%I64d rdtscticks usec= %12.8f qpccount %I64d qpc[msec] %12.8f delt-time[usec] %+6.5f deltic= %I64d \n", del, usec, ldel, qpc, diff, ddel);
		printf_s("%I64d rdtscticks usec= %12.8f \n", del, usec);
		//	printf_s("%I64d query performance = %f\n",ldel, qpc);
		oi = i;
//		oli.QuadPart = li.QuadPart;
	}
	getchar();
}