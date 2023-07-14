#include "func.h"
void WriteLine(cstr str) { printf("%s\n", str); }
void Write(cstr str) { printf("%s", str); }
void RequestInput(const cstr Prompt, cstr *field) {
  WriteLine(Prompt);
  cstr Name = malloc(256 * sizeof(char));
  scanf("%s", Name);
  field[0] = Name;
}
void About() {
  WriteLine("mkcproj - MaKe a C PROJect");
  Write("Copyright (C) 2023 Creeper Lv");
  Write("Version:");
  WriteLine(VERSION);
  WriteLine(
      "This program and its source code are licensed under the MIT License.");
}
void Help() {
  WriteLine("mkcproj <options>");
  WriteLine("Options:");
  WriteLine("-h|--help");
  WriteLine("\tShow this help.");
  WriteLine("-a|--about");
  WriteLine("\tShow about mkcproj.");
  WriteLine("-n|--name <string>");
  WriteLine("\tSpecify the name of the project. As well as the output binary.");
  WriteLine("-v|--version <string>");
  WriteLine("\tSpecify the version of the project as a macro definition with "
            "-DVERSION.");
  WriteLine("-cc|--c-compiler <string>");
  WriteLine("\tSpecify the c compiler to use.");
  WriteLine("\tDefault=\"gcc\"");
  WriteLine("-o|--output <string>");
  WriteLine("\tSpecify the output path.");
  WriteLine("\tDefault=\"bin/\"");
  WriteLine("-i|--install <string>");
  WriteLine("\tSpecify the install path.");
  WriteLine("\tDefault=\"/bin/\"");
}
int main(int argc, cstr *argv) {
  cstr ProjectName = NULL;
  cstr ProjectVersion = NULL;
  cstr CC = NULL;
  cstr OUTPUT = NULL;
  cstr INSTALL = NULL;
  for (int i = 0; i < argc; i++) {
    cstr item = argv[i];
    if (CStrIsEqual(item, "-h") || CStrIsEqual(item, "--help")) {
      Help();
      return 0;
    }
    if (CStrIsEqual(item, "-a") || CStrIsEqual(item, "--about")) {
      About();
      return 0;
    }
    if (CStrIsEqual(item, "-n") || CStrIsEqual(item, "--name")) {
      ProjectName = argv[i + 1];
      i++;
    } else if (CStrIsEqual(item, "-cc") || CStrIsEqual(item, "--c-compiler")) {
      CC = argv[i + 1];
      i++;
    } else if (CStrIsEqual(item, "-o") || CStrIsEqual(item, "--output")) {
      OUTPUT = argv[i + 1];
      i++;
    } else if (CStrIsEqual(item, "-i") || CStrIsEqual(item, "--install")) {
      INSTALL = argv[i + 1];
      i++;
    } else if (CStrIsEqual(item, "-v") || CStrIsEqual(item, "--version")) {
      ProjectVersion = argv[i + 1];
      i++;
    }
  }
  if (ProjectName == NULL) {
    RequestInput("Please specify a executable name:", &ProjectName);
  }
  WriteLine("Project Executable Name:");
  SetColor(FG, Green, Normal);
  WriteLine(ProjectName);
  ResetColor();
  WriteLine("Project Version:");
  if (ProjectVersion == null) {
    SetColor(FG, Yellow, Normal);
    WriteLine("null");
  } else {
    SetColor(FG, Green, Normal);
    WriteLine(ProjectVersion);
  }
  if (CC == null)
    CC = "gcc";
  if (OUTPUT == null)
    OUTPUT = "bin/";
  if (INSTALL == null)
    INSTALL = "/bin/";
  ResetColor();
  MakeDir("src", 0777);
  MakeDir(OUTPUT, 0777);
  MakeDir("scripts", 0777);
  {
    FILE *scriptf = fopen("scripts/build.sh", "wb");
    FileWriteLine(scriptf, "#! /bin/sh");
    FileWrite(scriptf, "EXE=");
    FileWriteLine(scriptf, ProjectName);
    FileWriteLine(scriptf, "Sys=$(uname)");
    FileWriteLine(scriptf, "if [ -z \"${Sys##*\"Win\"*}\" ]");
    FileWriteLine(scriptf, "then");
    FileWriteLine(scriptf, "EXE=\"$EXE.exe\"");
    FileWriteLine(scriptf, "fi");
    FileWriteLine(scriptf, "if [ -z \"${Sys##*\"DOS\"*}\" ]");
    FileWriteLine(scriptf, "then");
    FileWriteLine(scriptf, "EXE=\"$EXE.exe\"");
    FileWriteLine(scriptf, "fi");
    FileWriteLine(scriptf, "echo \"Output:bin/$EXE\"");
    FileWrite(scriptf, CC);
    FileWrite(scriptf, " ./src/**/*.c");
    if (ProjectVersion != null) {
      if (!CStrIsEqual(ProjectVersion, "")) {
        FileWrite(scriptf, " -DVERSION=\'\"");
        FileWrite(scriptf, ProjectVersion);
        FileWrite(scriptf, "\"\'");
      }
    }
    FileWrite(scriptf, " -o \"");
    FileWrite(scriptf, OUTPUT);
    FileWrite(scriptf, "$EXE\"");
    FileWriteLine(scriptf, "");
    fclose(scriptf);
    WriteLine("Created build script.");
  }
  {
    FILE *scriptf = fopen("scripts/install.sh", "wb");
    FileWriteLine(scriptf, "#! /bin/sh");
    FileWrite(scriptf, "EXE=");
    FileWriteLine(scriptf, ProjectName);
    FileWriteLine(scriptf, "Sys=$(uname)");
    FileWriteLine(scriptf, "if [ -z \"${Sys##*\"Win\"*}\" ] ");
    FileWriteLine(scriptf, "then");
    FileWriteLine(scriptf, "EXE=\"$EXE.exe\"");
    FileWriteLine(scriptf, "fi");
    FileWriteLine(scriptf, "if [ -z \"${Sys##*\"DOS\"*}\" ] ");
    FileWriteLine(scriptf, "then");
    FileWriteLine(scriptf, "EXE=\"$EXE.exe\"");
    FileWriteLine(scriptf, "fi");
    FileWriteLine(scriptf, "echo \"Output:/bin/$EXE\"");
    FileWrite(scriptf, "cp \"./bin/$EXE\" \"");
    FileWrite(scriptf, INSTALL);
    FileWrite(scriptf, "$EXE\"");
    FileWriteLine(scriptf, "");
    fclose(scriptf);
    WriteLine("Created install script.");
  }
  return 0;
}
