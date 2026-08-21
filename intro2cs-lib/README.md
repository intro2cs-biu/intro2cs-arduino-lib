# Intro2CS library package

This folder contains the public headers and two compiled versions of the course library. Students do not need the implementation source files.

## Arduino Uno

```sh
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -std=c99 \
  -Iintro2cs-lib/headers program.c \
  intro2cs-lib/intro2cs-arduino-lib.a -o program.elf
```

## Computer simulator

```sh
cc -std=c99 -Iintro2cs-lib/headers program.c \
  intro2cs-lib/intro2cs-arduino-simulator-lib.a -o program
./program
```

Both versions expose the same headers and functions. Include the header for every module used by the program. For example, include `serial.h` and call `serialBegin(9600)` before using standard C input or output.
