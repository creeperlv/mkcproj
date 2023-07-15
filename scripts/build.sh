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
find ./src/ -name "*.c" | xargs gcc -DVERSION='"1.2.3.0"' -o "bin/$EXE"
