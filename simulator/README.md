# Intro2CS Arduino Console Simulator

This host-computer version implements the same public API as `intro2cs-arduino-lib` without AVR hardware. It prints output operations and renders LCD, matrix, and seven-segment state in the terminal.

## Build a program

```bash
cc -std=c99 -Iintro2cs-arduino-simulator/headers \
  program.c intro2cs-arduino-simulator/intro2cs-arduino-simulator-lib.a \
  -o program
./program
```

Programs can therefore switch between the physical library and the simulator without changing their `#include` lines or API calls.

Call `serialBegin(baud)` after including `serial.h` to use standard C input and output. In the simulator, `printf`, `putchar`, `getchar`, and `scanf` use the same terminal in which the program runs.

## Console input

- `digitalRead`: enter `0` for LOW or `1` for HIGH.
- `analogRead`: enter an integer from 0 to 1023.
- `keypadGetKey`: enter `0`–`9` or `a`–`f`, representing values 0–15.
- Joystick: `w`=up, `a`=left, `s`=down, `d`=right, `c`=button/click, `x`=center or not pressed.

Each input function consumes one command using `getchar()` (with `analogRead` reading the complete number). Direction helpers should generally be called once per requested input because every helper asks for a new command.

`delay` and `delayMicroseconds` print the requested delay but do not actually pause, keeping simulations fast.
