#pragma once

#include <stdio.h>

class Odr 
{
public:
    static const int N = 10;
    static const int M = N;

    void f() { fprintf( stderr, "calling inline f()\n"); }

};

//Odr global;

