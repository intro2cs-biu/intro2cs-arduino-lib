#ifndef ARDUINO_H
#define ARDUINO_H

#define INPUT         0
#define OUTPUT        1
#define INPUT_PULLUP  2

#define LOW  0
#define HIGH 1

#define FOREVER -1

#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19

#define SDA A4
#define SCL A5

void pinMode(char pin, char mode);

void digitalWrite(char pin, unsigned char value);
char digitalRead(char pin);

void analogWrite(char pin, unsigned char value);
int analogRead(char pin);

void delay(unsigned long ms);
void delayMicroseconds(unsigned long us);

void tone(unsigned char pin, unsigned int frequency, long duration);
void noTone(unsigned char pin);



#endif