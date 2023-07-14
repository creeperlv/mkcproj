#include "func.h"
void MakeDir(cstr name, int mode) {
#ifdef __WIN32
  mkdir(name);
#else
  mkdir(name, mode);
#endif
}
void FileWriteLine(File F, cstr str) {
  fputs(str, F);
  fputs("\n", F);
}
void FileWrite(File F, cstr str) { fputs(str, F); }

void SetColor(int Base, int Color, int Tint) {
  printf("\x1b[%dm", Base + Color + Tint);
}
void ResetColor() { printf("\x1b[0m"); }

bool CStrIsEqual(cstr L, cstr R) {
  if (L == null || R == null) {
    if (L == R)
      return true;
    return false;
  }
  int lenL = strlen(L);
  int lenR = strlen(R);
  if (lenL != lenR)
    return false;
  for (int i = 0; i < lenL; i++) {
    if (L[i] != R[i])
      return false;
  }
  return true;
}
