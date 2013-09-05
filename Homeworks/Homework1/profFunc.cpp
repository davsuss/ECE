#include "profFunc.h"
#include <QDebug>
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    if(sourceString == 0 || destString == 0 || sourceStringLen == 0 || destStringLen == 0)
        return 0;
    int result = 0;
    for(int x = 0; x < sourceStringLen; x++)
    {
        if((x) >= destStringLen)
            break;
      *(destString+x) = *(sourceString+x);
      result++;

    }
    return result;
}
