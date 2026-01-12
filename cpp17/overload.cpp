#include <string.h>
#include <stdio.h>

template<typename T>
void fn(T t, long l=10)
{
    fprintf( stderr, "fn (typename, long) %ld\n", l);
}

void fn(int i)
{
    fprintf( stderr, "fn (int) %d\n", i);
}

////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    fprintf(stderr, "overload \n" );

    fn(10);
    fn(20l);
    fn(20, 30);

}
