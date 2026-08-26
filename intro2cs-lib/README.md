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

## Millisecond timestamps

Include `arduino.h` and call `millis()` to get the number of milliseconds elapsed since the program started:

```c
unsigned long started = millis();

if (millis() - started >= 1000UL) {
    /* At least one second has elapsed. */
}
```

The value wraps to zero after about 49.7 days. Subtract timestamps as shown above so elapsed-time comparisons continue to work across the wrap. On Arduino, `millis()` uses Timer0. PWM on pins 5 and 6 remains available, but `digitsBegin()` reconfigures Timer0 for display refresh and therefore cannot be combined reliably with `millis()`.
