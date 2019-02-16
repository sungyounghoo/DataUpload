#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <math.h>
#include <time.h>



int ut_L11DoubleToHex(double dVal)
{
	int L11n = 0;
	int L11y = 0;
	int iResult = 0;
	bool bSign = false;
	double dArgVal = dVal;
	if((int)dVal < 0)
	{
		bSign = true;
		dArgVal = fabs(dVal);
	}
	for(L11n = 0 ; L11n < 0xF ; L11n++)
	{
		if(int(dArgVal/pow(2, L11n*-1)) > 0x3FF)
		{
			L11n=L11n-1;
			break;
		}
		if(fmod(dArgVal, pow(2, L11n*-1)) < 0.0001)
		{
			if(int(dArgVal / pow(2, L11n*-1)) > 0x3FF)
			{
				L11n=L11n-1;
				break;
			}
			break;
		}
	}

	L11y=(dArgVal / pow(2, L11n*-1));
	if(bSign==1) L11y=((L11y^0x3FF)+1)|0x400;
	L11n=((L11n^0x1F)+1) & 0x1F;
	iResult=(L11n<<11)|L11y;

	  printf("\n[SDH] L11y : %X, L11n : %X, iResult : %x, (func : %s)\n", L11y, L11n, iResult, __func__);
	return iResult;
}
										


int main()
{
//	const int iSensorQty = 24;
//	int iHalf = iSensorQty/2;
//	for(int i = 0, j = 0 ; i < iSensorQty ; i++, j++)
//	{
//		if(i == iHalf) j = 0;
//		if(i == iHalf) printf("\n");
//		if(i < iHalf )
//		{
//			printf(" %d ", i+j);
//		}
//		else
//		{
//			printf(" %d ", ++j);
//		}
//	}


		struct timespec ts, endtime;
//	for(int j = 0 ; j < 10 ; j++)
	{
		clock_gettime(CLOCK_MONOTONIC, &ts);

		for(int i = 0 ; i < 100 ; i++)
		{
			clock_gettime(CLOCK_MONOTONIC, &ts);
			usleep(1);
			clock_gettime(CLOCK_MONOTONIC, &endtime);
			long long diff = ((endtime.tv_sec - ts.tv_sec) * 1000000) + ((endtime.tv_nsec - ts.tv_nsec) / 1000);
			printf("[SDH] diff : %ld\n", diff);
		}
//		clock_gettime(CLOCK_MONOTONIC, &endtime);
//		long long diff = ((endtime.tv_sec - ts.tv_sec) * 1000) + ((endtime.tv_nsec - ts.tv_nsec) / 1000000);
//		printf("[SDH] diff[%d] : %ld\n", j, diff);
//		printf("[SDH] diff : %ld\n", diff);
	}



	return 1;
}

