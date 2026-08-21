#ifndef DIGITS_H
#define DIGITS_H

#define DIGITS_SEGMENTS 8
#define DIGITS_MAX_DIGITS 4

/*
 * Initialize the display.
 *
 * segmentPins:
 *   Pins for A,B,C,D,E,F,G,DP.
 *   NULL -> use default pins.
 *
 * digitPins:
 *   Digit-select pins.
 *   NULL -> use default pins.
 *
 * digitCount:
 *   Number of digits, usually 1 or 4.
 */
void digitsBegin(
    const unsigned char segmentPins[DIGITS_SEGMENTS],
    const unsigned char digitPins[DIGITS_MAX_DIGITS],
    unsigned char digitCount
);


/*
 * Apply the same 8-bit segment pattern
 * to selected digits.
 *
 * Segment bits:
 *
 * bit 7 -> DP
 * bit 6 -> G
 * bit 5 -> F
 * bit 4 -> E
 * bit 3 -> D
 * bit 2 -> C
 * bit 1 -> B
 * bit 0 -> A
 *
 * Position bits are counted from the right:
 *
 * bit 0 -> rightmost digit
 * bit 1 -> second from right
 * bit 2 -> third from right
 * bit 3 -> leftmost digit
 */
void digitsSetSegments(
    unsigned char segments,
    unsigned char positions
);


/*
 * Set the entire display using packed bytes.
 *
 * Byte 0 -> rightmost digit
 * Byte 1 -> second from right
 * Byte 2 -> third from right
 * Byte 3 -> leftmost digit
 */
void digitsSetDisplay(unsigned long display);


/*
 * Set one segment of one digit.
 *
 * digit:
 *   0 -> rightmost
 *   1 -> second from right
 *   2 -> third from right
 *   3 -> leftmost
 *
 * segment:
 *   0 -> A
 *   1 -> B
 *   2 -> C
 *   3 -> D
 *   4 -> E
 *   5 -> F
 *   6 -> G
 *   7 -> DP
 */
void digitsSetSegment(
    unsigned char digit,
    unsigned char segment,
    unsigned char value
);


/*
 * Clear the entire display.
 */
void digitsClear(void);

#endif