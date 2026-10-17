#ifndef SERIAL_H
#define SERIAL_H

void serialBegin(unsigned long baud);

/* Read one whitespace-delimited unsigned 64-bit integer (base 2 through 16).
 * Hexadecimal input may start with 0x; an optional leading + is accepted.
 * Returns 1 on success, 0 for invalid input/overflow, or EOF before a token.
 * Invalid tokens are consumed; *value is unchanged on failure.
 */
int serialReadUnsignedLongLong(unsigned long long *value, unsigned char base);

/* Print an unsigned 64-bit integer in base 2 through 16, without a newline.
 * Returns the number of characters written, or EOF on invalid base/I/O error.
 */
int serialPrintUnsignedLongLong(unsigned long long value, unsigned char base);

#endif
