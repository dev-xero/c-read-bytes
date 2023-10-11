#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);  // gets the data stored at i from the address start
    }

    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(x));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(x));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(x));
}

int main()
{
    /**
     * A Note on Big-Endian and Little Endian
     * ---------------------------------------
     * (1) Big-Endian: 
     *      Bits are ordered left-to-right in memory.
     *      The most significant byte, i.e., the left-most byte, is stored first.
     * 
     * (2) Little-Endian: 
     *      Bits are ordered right-to-left in memory.
     *      The least significant byte, i.e., the right-most byte is stored first.
     * 
     * TCP/IP requires bytes are ordered in Big-Endian which is the network byte ordering standard.
    */

    int ival = 12345;
    int fval = 12345.0;
    int *ip = &ival;     // an int pointer to ival
    const char *m = "mnopqr";

    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;
    
    show_int(ival);
    show_float(fval);
    show_pointer(ip);

    printf("\n");
    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);

    printf("\n");
    show_bytes((byte_pointer) m, strlen(m));
}