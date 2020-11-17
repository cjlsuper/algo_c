//
// Created by 崔继霖 on 2020/10/27.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef union {
    float flt;
    uint32_t bits;
} lens_t;

uint32_t f2i(float x) {
    return ((lens_t) {.flt = x}).bits;
}

void function();

void function(int x, int n) {
    //  Set nth bit
    //  1000000  10000001
    //  10000001
    printf("Set nth bit:\n");
    printf("%d\n", (x | (1 << n)));

    // Unset nth bit
    printf("Unset nth bit:\n");
    printf("%d\n", (x & ~(1 << n)));

    // Toggle nth bit
    printf("Toggle nth bit:\n");
    printf("%d\n", (x ^ (1 << n)));

    // Round up to the next power of two
    //only works if v is 32 bit
    printf("Round up to the next power of two:\n");
    unsigned int v = 7;
    // 01110000 00000000 00000000 00000000  1
    // 01111000 00000000 00000000 00000000  2
    // 01111111 10000000 00000000 00000000  4
    // 01110000 00000000 00000000 00000000  8
    // 01110000 00000000 00000000 00000000  16

    v--;                //  6
    v |= v >> 1;        //  --- 00000110  ｜ ---00000011  = --- 00000111
    v |= v >> 2;        //  --- 00000111  ｜ ---00000001  = --- 00001111
    v |= v >> 4;        //  --- 00001111  ｜ ---00000000  = --- 00001111
    v |= v >> 8;        //  --- 00001111  ｜ ---00000000  =     8421
    v |= v >> 16;
    v++;
    printf("%d", v);

    // Get the maximum integer
    int maxInt = ~(1 << 31);
    int maxInt2 = (1 << 31) - 1;
    int maxInt3 = (1 << -1) - 1;
    int maxInt4 = -1u >> 1;
    printf("Get the maximum integer\n");
    printf("%d,%d,%d,%d\n", maxInt, maxInt2, maxInt3, maxInt4);

    // Exchange (swap) two values
    int a = 1, b = 9;
    //version 1
//    a ^= b;
//    b ^= a;
//    a ^= b;

    //version 2
//    a = a ^ b ^ (b = a);
    printf("a=%d,b=%d\n", a, b);

    // Get the max of two values
    int max = b & ((a - b) >> 31) | a & (~(a - b) >> 31);
    printf("max=%d\n", max);

    //Get the min of two values
    int min = a & ((a - b) >> 31) | b & (~(a - b) >> 31);
    printf("min=%d\n", min);

    //Check whether both numbers have the same sign
    printf("heck whether both numbers have the same sign:%d\n", (2 ^ -3) >= 0);

    //Flip the sign
    int i = 9;
    //    i = ~i + 1; // or
    i = (i ^ -1) + 1; // i = -i
    printf("Flip the sign:%d\n", i);
    //Whether a number is power of 2
    n > 0 && (n & (n - 1)) == 0;

    // Modulo 2n against m
    int m = 2;
    printf("Modulo 2n against m : %d\n", m & ((1 << 3) - 1));

    //Get the mth bit of n (from low to high)
    printf("Get the mth bit of n (from low to high):%d\n", (n >> (m - 1)) & 1);

    //Isolate (extract) the right-most 1 bit
    printf("Isolate (extract) the right-most 1 bit:%d\n", x & (-x));
    // Isolate (extract) the right-most 0 bit
    printf("Isolate (extract) the right-most 0 bit:%d\n", ~x & (x + 1));
    //Set the right-most 0 bit to 1
    x | (x + 1);

    //Set the right-most 1 bit to 0
    x & (x - 1);

    printf("Turn a float into a bit-array :%d\n",f2i(3.0));

    //Get letter's position in alphabet (for Uppercase letters only):
    // ? : 00111111  @ : 01000000
    // AND by ? => (x & '?') or XOR by @ => (x ^ '@')
    // eg. ('C' & '?') => 3 ; ('Z' ^ '@') => 26

    // Get letter's position in alphabet (for lowercase letters only):
    // ' : 00100111  01100000
    // XOR by backtick/chr(96)/binary('1100000')/hex('60') => (x ^ '`')
    // eg. ('d' ^ '`') => 4 ; ('x' ^ '`') => 24
    printf("Get letter's position in alphabet : %d\n",('d' ^ '`'));

    //Letter's position in alphabet:
    //AND by chr(31)/binary('11111')/(hex('1F') => (x & "\x1F")
    //Result is in 1..26 range, letter case is not important
    //eg. ('a' & "\x1F") => 1 ; ('B' & "\x1F") => 2
    printf("Letter's position in alphabet:%d\n",('C' & '\x1f'));

}


int main() {

    function(9, 3);

    return 0;
}

