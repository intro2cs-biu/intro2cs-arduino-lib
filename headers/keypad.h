#ifndef KEYPAD_H
#define KEYPAD_H

#define KEYPAD_SIZE 4

void keypadBegin(
    const unsigned char rows[KEYPAD_SIZE],
    const unsigned char cols[KEYPAD_SIZE]
);

int keypadGetKey(void);

#endif