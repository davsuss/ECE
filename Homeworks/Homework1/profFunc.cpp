#include <stddef.h>
// Change the #define below to use different versions of profFunc()
// 0 -- only good version, should pass all tests
// 8 -- really bad version that does nothing except return -1
// 1 -- does not work properly when sourceString is NULL && sourceStringLen > 0
// 2 -- does not work properly when destString is NULL && destStringLen > 0
// 3 -- does not copy the correct string
// 4 -- copies one less character than it should (if it should copy more than 0 bytes)
// 5 -- if sourceStringLen > destStringLen, then it returns the wrong number of bytes copied
// 6 -- if sourceStringLen < destStringLen, then it returns the wrong number of bytes copied
// 7 -- copies only the first character correctly
//
// Note: I did not include any versions that did the "wrong" thing when a negative number of bytes was
//       passed because the specification for profFunc() did not say what *should* happen when either or
//       both sourceStringLen or destStringLen is negative.  My good version does a reasonable behavior, which
//       is to treat it as a length of 0.  It would also be reasonable to use a Q_ASSERT() to check to make sure
//       that the arguments received by profFunc() are non-negative.  Essentially,  you cannot test for
//       an expected behavior if there is no expected behavior specified.  It doesn't mean you shouldn't
//       test with those arguments, but the test would only be able to see if the routine doesn't fail
//       (e.g., crash).
//
#define VERSION 2
//
// Grading:
//   To receive a score > 0, your code must:
//     (1) Use the filename, classname, and include line as specified in the assignment description, *and*
//     (2) Uses data-driven unit testing as per Tutorial 2 rather than separate test cases as in Tutorial 1, *and*
//     (3) Is able to pass the correct version (Version 0) on all of your tests, *and*
//     (4) Is able to fail at least one incorrect version (any of Versions 1 to 8) on at least one of your test cases.
//
//   If all of the above is not satisfied, then do not schedule a validation time with the TA.  You can, of course, meet with the TA to discuss
//     your program, but please do not schedule that in a validation time slot.
//
//   If all of the above is satisfied, then you have a base score of 16 out of the total possible 40 points.  The remainder of the points
//     are allocated as:
//     (1) 2 points for each bad version (versions 1 to 8) that you fail on a test case
//     (2) 4 points for using descriptive variable names *everywhere* as required in the style guidelines (i.e., for anything other than loop counters)
//     (3) 4 points for using descriptive test case names (e.g., *not* "Test 1" or "Case 1" but describing what is actually being tested for that case
//
//
// Specification for the function profFunc()
// Copy the smaller of (sourceStringLen,destStringLen) characters from sourceString to destString
//   If sourceString or destString are NULL, then copy 0 bytes.
// Arguments:
//   sourceStringLen: number of characters in sourceString
//   sourceString: pointer to an array of characters (contains the string that will be copied)
//   destStringLen: number of characters that may be copied into destString
//   destString: pointer to an array of characters into which sourceString will be copied
//
// Returns:
//   The number of bytes that was actually copied from sourceString into destString
//
// End of the specification
//
//
// This is a good version of the function that is used in multiple variants below, both in the good version
//   and in the bad versions of the functions
int goodProfFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    if ((sourceString == NULL) || (destString == NULL)) {
        return(0);
    }
    if (destStringLen < sourceStringLen) {
        sourceStringLen = destStringLen;
    }
    int copyCount = 0;
    for (copyCount=0;copyCount<sourceStringLen;copyCount++) {
        destString[copyCount] = sourceString[copyCount];
    }
    return(copyCount);
}
#if VERSION==0
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    return(goodProfFunc(sourceStringLen,sourceString,destStringLen,destString));
}
#elif VERSION == 1
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    if (sourceString == NULL) {
        if (sourceStringLen > 0) {
            char *tempSourceString = new char[sourceStringLen];
            for (int i=0;i<sourceStringLen;i++) {
                tempSourceString[i] = ' ';
            }
            int retVal = goodProfFunc(sourceStringLen,tempSourceString,destStringLen,destString);
            delete [] tempSourceString;
            return(retVal);
        }
    }
    return(goodProfFunc(sourceStringLen,sourceString,destStringLen,destString));
}
#elif VERSION == 2
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    if (destString == NULL) {
        if (destStringLen > 0) {
            destString = new char[destStringLen];
            int retVal = goodProfFunc(sourceStringLen,sourceString,destStringLen,destString);
            delete [] destString;
            return(retVal);
        }
    }
    return(goodProfFunc(sourceStringLen,sourceString,destStringLen,destString));
}
#elif VERSION == 3
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    if ((sourceString != NULL) && (sourceStringLen > 0)) {
        char *tempSourceString = new char[sourceStringLen];
        for (int i=0;i<sourceStringLen;i++) {
            tempSourceString[i] = 'y';
        }
        int retVal = goodProfFunc(sourceStringLen,tempSourceString,destStringLen,destString);
        delete [] tempSourceString;
        return(retVal);
    } else {
        return(goodProfFunc(sourceStringLen,sourceString,destStringLen,destString));
    }
}
#elif VERSION == 4
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    if ((sourceStringLen > 0) && (destStringLen > 0)) {
        if (sourceStringLen > destStringLen) {
            destStringLen--;
        } else {
            sourceStringLen--;
        }
    }
    return(goodProfFunc(sourceStringLen,sourceString,destStringLen,destString));
}
#elif VERSION == 5
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    int retVal = goodProfFunc(sourceStringLen,sourceString,destStringLen,destString);
    if (retVal > 0) {
        if (sourceStringLen > retVal) {
            retVal = sourceStringLen;
        }
    }
    return(retVal);
}
#elif VERSION == 6
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    int retVal = goodProfFunc(sourceStringLen,sourceString,destStringLen,destString);
    if (retVal > 0) {
        if (destStringLen > retVal) {
            retVal = destStringLen;
        }
    }
    return(retVal);
}
#elif VERSION == 7
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    int retVal = goodProfFunc(sourceStringLen,sourceString,destStringLen,destString);
    if (retVal > 1) {
        for (int i=1;i<retVal;i++) {
            destString[i] = '@';
        }
    }
    return(retVal);
}
#elif VERSION == 8
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString)
{
    return(-1);
}
#endif
