# Intro2CS Arduino Library

Compiled Arduino library and student documentation for Introduction to Computer Science (89110), Bar-Ilan University.

## Documentation

The complete guide is published with GitHub Pages:

**https://intro2cs-biu.github.io/intro2cs-arduino-lib/**

## Download

Download the archive that matches the computer used to run the simulator:

- [Windows](https://intro2cs-biu.github.io/intro2cs-arduino-lib/intro2cs-lib-windows.zip)
- [Linux](https://intro2cs-biu.github.io/intro2cs-arduino-lib/intro2cs-lib-linux.zip)
- [macOS](https://intro2cs-biu.github.io/intro2cs-arduino-lib/intro2cs-lib-macos.zip)

Extracting any archive creates one `intro2cs-lib` folder containing shared headers and two source-compatible variants:

- `intro2cs-lib/intro2cs-arduino-lib.a` for an Arduino Uno.
- `intro2cs-lib/intro2cs-arduino-simulator-lib.a` for a computer terminal.

Both variants include `serial.h` and support `serialBegin()` with standard C input and output. The simulator archive inside each ZIP is compiled for the named operating system.

The simulator reports `delay(ms)` as `[delay] N ms` and
`delayMicroseconds(us)` as `[delay] N us`, where `N` is the requested duration.
It does not actually pause the computer program.

The digit simulator renders recognized seven-segment patterns as decimal
digits, appends `.` when the decimal point is active, and uses `_` for a
cleared position. An unrecognized pattern includes its full hexadecimal value,
for example `[digits] ? (0x41)`.

This repository intentionally distributes compiled library files and public documentation only. Library implementation source files are not included.
