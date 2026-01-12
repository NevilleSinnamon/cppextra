#include <stdio.h>
#include "odr.h"

int main(int argc, char* argv[])
{
    char data[Odr::N];
    fprintf( stderr, "Odr::N %d\n", Odr::N);
    fprintf( stderr, "Odr::M %d\n", Odr::M);

    Odr o;
    o.f();
}

