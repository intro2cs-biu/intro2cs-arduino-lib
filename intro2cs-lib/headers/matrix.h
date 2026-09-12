#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

#define MATRIX_SIZE 8

void matrixBegin(
    const unsigned char rows[MATRIX_SIZE],
    const unsigned char cols[MATRIX_SIZE]
);

void matrixSetFromByteArray(
    const unsigned char frame[MATRIX_SIZE]
);

/*
 * Set all eight rows from one 64-bit value.
 * Bits 63..56 are row 0 (top); bits 7..0 are row 7 (bottom).
 * Within each row, bit 7 is the leftmost pixel.
 */
void matrixSetFrom64Bits(unsigned long long frame);

void matrixSetFromPixelArray(
    const unsigned char frame[MATRIX_SIZE][MATRIX_SIZE]
);

void matrixSetRowFromPixelArray(
    unsigned char row,
    const unsigned char content[MATRIX_SIZE]
);

void matrixSetRowFromByte(
    unsigned char row,
    unsigned char content
);

void matrixSetPixel(
    unsigned char row,
    unsigned char col,
    unsigned char value
);

void matrixClear(void);

void matrixStop(void);

/* Previous names retained for source compatibility. */
void matrixSet(const unsigned char frame[MATRIX_SIZE]);
void matrixSet64(unsigned long long frame);
void matrixSet2D(const unsigned char frame[MATRIX_SIZE][MATRIX_SIZE]);
void matrixSetRow(unsigned char row, const unsigned char content[MATRIX_SIZE]);
void matrixSetRowByte(unsigned char row, unsigned char content);

#endif
