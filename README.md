# Intro2CS Arduino Library

Compiled Arduino library and student documentation for Introduction to Computer Science (89110), Bar-Ilan University.

## Documentation

The complete guide is published with GitHub Pages:

**https://intro2cs-biu.github.io/intro2cs-arduino-lib/**

## Download

Download the archive that matches the computer used to run the simulator:

- [Windows](https://intro2cs-biu.github.io/intro2cs-arduino-lib/intro2cs-lib-windows.zip?v=64bit-serial-1)
- [Linux](https://intro2cs-biu.github.io/intro2cs-arduino-lib/intro2cs-lib-linux.zip?v=64bit-serial-1)
- [macOS — Apple Silicon (M-series)](https://intro2cs-biu.github.io/intro2cs-arduino-lib/intro2cs-lib-macos.zip?v=64bit-serial-1)

- [macOS — Intel (macOS 10.13 or later)](https://intro2cs-biu.github.io/intro2cs-arduino-lib/intro2cs-lib-macos-intel.zip?v=64bit-serial-1)

On a Mac, open **Apple menu → About This Mac**: choose the Apple Silicon ZIP if it lists an Apple M-series chip, or the Intel ZIP if it lists an Intel processor.

For compilation on the departmental Linux server, download the Linux ZIP separately and copy its complete `intro2cs-lib` folder to the server, including headers and both archives. Keep the package for your own computer for local use.

Extracting any archive creates one `intro2cs-lib` folder containing shared headers and two source-compatible variants:

- `intro2cs-lib/intro2cs-arduino-lib.a` for an Arduino Uno.
- `intro2cs-lib/intro2cs-arduino-simulator-lib.a` for a computer terminal.

Both variants include `serial.h` and support `serialBegin()` with standard C input and output. The simulator archive inside each ZIP is compiled for the named operating system.

The simulator reports `delay(ms)` as `[delay] N ms` and
`delayMicroseconds(us)` as `[delay] N us`, where `N` is the requested duration.
It does not actually pause the computer program.

The matrix simulator uses exactly one terminal character per pixel: `#` for a
lit pixel and a space for an unlit pixel. Each row contains eight characters
between `|` delimiters.

The digit simulator renders recognized seven-segment patterns as decimal
digits, appends `.` when the decimal point is active, and uses `_` for a
cleared position. An unrecognized pattern includes its full hexadecimal value,
for example `[digits] ? (0x41)`.

This repository intentionally distributes compiled library files and public documentation only. Library implementation source files are not included.

## 64-bit serial numbers

All four packages include `serialReadUnsignedLongLong(&value, base)` and
`serialPrintUnsignedLongLong(value, base)` for unsigned 64-bit input and output.
Use base 16 for hexadecimal or base 10 for decimal. The Uno's `scanf` and
`printf` do not support `long long` conversions.

See the [64-bit serial example and API reference](https://intro2cs-biu.github.io/intro2cs-arduino-lib/#serial-64-bit).
