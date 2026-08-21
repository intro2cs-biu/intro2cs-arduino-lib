#ifndef JOYSTICK_H
#define JOYSTICK_H

void joystickBegin(
    unsigned char xPin,
    unsigned char yPin,
    unsigned char buttonPin
);

int joystickReadX(void);
int joystickReadY(void);
int joystickPressed(void);

int joystickLeft(void);
int joystickRight(void);
int joystickUp(void);
int joystickDown(void);
int joystickClicked(void);

#endif