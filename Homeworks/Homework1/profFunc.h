#ifndef PROFFUNC_H
#define PROFFUNC_H
// Copy the smaller of (sourceStringLen,destStringLen) characters from sourceString to destString
//   If either sourceString or destString is NULL, then copy 0 bytes.
// Arguments:
//   sourceStringLen: number of characters in sourceString
//   sourceString: pointer to an array of characters (contains the string that will be copied)
//   destStringLen: maximum number of characters that may be copied into destString
//   destString: pointer to an array of characters into which sourceString will be copied
//
// Returns:
//   The number of bytes that was actually copied from sourceString into destString
//
int profFunc(int sourceStringLen, const char *sourceString,int destStringLen, char *destString);
#endif // PROFFUNC_H
