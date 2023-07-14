#! /bin/sh
EXE=mkcproj
Sys=$(uname)
if [ -z "${Sys##*"Win"*}" ]
then
EXE="$EXE.exe"
fi
if [ -z "${Sys##*"DOS"*}" ]
then
EXE="$EXE.exe"
fi
echo "Output:bin/$EXE"
gcc ./src/**/*.c -DVERSION='"1.1.2.0"' -o "bin/$EXE"
