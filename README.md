# mkcproj

**M**a**K**e a **C** **Proj**ect. A simple tool to make a simple C project structure.

It will generate:

```
\Root
-\bin
-\src
-\scripts
--[sh]build.sh
--[sh]install.sh
```

# Compatibility

The tool it self runs on almost all platform, tested on: Windows 11 (64-bit), Debian 12 (64-bit), Debian 11 (arm64) and MS-DOS with DJGPP.

Generated scripts requires:

- A POSIX compatible shell, such as ash and bash.

- `find` command.

- `xargs`

# Build

## Requirements

- GCC (Author uses `w64devkit`)

- A POSIX compatible shell, such as ash and bash.

- `find`

- `xargs`

## How-To

Use `scripts/build.sh` to build the project.

# Installation

The installation script will copy `mkcproj` by default.

# License

This project is licensed under the MIT Licence.

