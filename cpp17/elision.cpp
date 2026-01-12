#include <stdio.h>
#include <tuple>

class Elision
{
public:
    Elision(int x){ fprintf(stderr, "Elision int  %d\n", x); y=x;}
    Elision(const Elision& other){  y=other.y; fprintf(stderr, "Elision copy %d\n", y);}
    Elision(Elision&& other){ y=other.y; fprintf(stderr, "Elision move %d\n", y); } 

    Elision operator = (const Elision& other){ y=other.y;  fprintf(stderr, "Elision assignment %d\n", y); return other;}
    Elision operator = (Elision&& other){ y=other.y; fprintf(stderr, "Elision move assignment %d\n", y); return other;}
private:
    int y;
};

Elision f()
{
    Elision rc(50);
    return rc;
}

Elision g(bool cond = false)
{
    Elision one(60);
    Elision two(70);
    return cond ? one : two;
}

void e()
{
    Elision ex(99);
    throw ex;
}

int main(int argc, char* argv[])
{
    Elision e1(42);
    Elision e2 = Elision(45); // copy _ct_ not called

    Elision e3 = f(); // copy _ct_ not called

    Elision e4 = g(); // copy _ct_ called once

    try{ e(); } catch ( const Elision& ex ) { fprintf( stderr, "handle ex\n"); }
    // copy _ct_ called once if move not available, or move called once.
}
