#include "CPlatformDifference.h"

void PRINTFLog(const char *pLog, int nLen)
{
#ifdef WRAPPER_WINDOWS
	FILE *pFile = fopen("UnityLog.log", "a+");
	if (pFile)
	{
		fwrite(pLog, 1, nLen, pFile);
		fclose(pFile);
	}
#else
#ifdef WRAPPER_ANDROID
	PRINTF(pLog);
#else
#ifdef WRAPPER_IOS
	PRINTF(pLog);
#endif
#endif
#endif
}
