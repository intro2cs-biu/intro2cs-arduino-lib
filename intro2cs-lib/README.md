# Intro2CS library package

This folder contains the public headers and two compiled versions of the course library. Students do not need the implementation source files. The simulator archive is platform-specific, so download the ZIP for the operating system on which you will run it.

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

On the Arduino Uno, `serialBegin` waits briefly after configuring the serial
connection. Opening a serial monitor resets the board, and this pause gives the
monitor time to reconnect before the program transmits its first message.

## Simulator input and output

The simulator is suitable for comparing a program with automatic-test output.
Initialization functions such as `serialBegin`, `pinMode`, `lcdBegin`,
`matrixBegin`, `digitsBegin`, `keypadBegin`, and `joystickBegin` do not print
anything. Calls to `delay(ms)` print `[delay] N ms`, and calls to
`delayMicroseconds(us)` print `[delay] N us`, where `N` is the requested
duration. Simulated delays report the duration but do not pause the computer
program. Other operations that produce visible output—such as `printf`,
`digitalWrite`, or updating a display—are also printed.

Input functions read directly from standard input without displaying prompts.
This makes interactive input possible while also allowing redirected test data:

```sh
./program < input.txt
```

Use `0` or `1` for `digitalRead`, an integer from 0 to 1023 for `analogRead`,
`0`–`9` or `a`–`f` for `keypadGetKey`, and `w`, `a`, `s`, `d`, `c`, or `x` for
joystick operations.

## Millisecond timestamps

Include `arduino.h` and call `millis()` to get the number of milliseconds elapsed since the program started:

```c
unsigned long started = millis();

if (millis() - started >= 1000UL) {
    /* At least one second has elapsed. */
}
```

The value wraps to zero after about 49.7 days. Subtract timestamps as shown above so elapsed-time comparisons continue to work across the wrap. On Arduino, `millis()` uses Timer0. PWM on pins 5 and 6 remains available, but `digitsBegin()` reconfigures Timer0 for display refresh and therefore cannot be combined reliably with `millis()`.
