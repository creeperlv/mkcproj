#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
typedef char *cstr;
typedef FILE *File;

#ifndef __cplusplus
typedef char bool;
#define false 0
#define true 1
#endif
#define null NULL
#define FG 0
#define BG 10
#define Red 1
#define Green 2
#define Yellow 3
#define Bright 90
#define Normal 30
#ifndef VERSION
#define VERSION "1.0.1.0"
#endif
void MakeDir(cstr name, int mode);
void FileWriteLine(File F, cstr str);
void FileWrite(File F, cstr str);
void SetColor(int Base, int Color, int Tint);
void ResetColor();

bool CStrIsEqual(cstr L, cstr R);
