#include <string>
#include <stdio.h>

template<typename TValue=std::string, typename TKey=std::string>
struct couple
{
    TKey   key;
    TValue value;
};

template<typename TValue>
struct couple<TValue>
//struct couple<TValue, std::string> // either of these work as std::string is the default behaviour
{
    std::string index;
    TValue   element;
};

template<>
struct couple<>
//struct couple<std::string, std::string>
{
    std::string i;
    std::string e;
};

template<>
struct couple<int, int>
{
    int x;
    int y;
};

////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    fprintf(stderr, "couple - an example of class specialization\n" );

    couple<int, float> cif;
    cif.key = 3.14;
    cif.value = 3;

    couple<long> cl;
    cl.index = "neville";
    cl.element = 58;

    couple<> c;
    c.i = "one";
    c.e = "two";

    couple<int,int> cii;
    cii.x = 3;
    cii.y = 4;

    fprintf( stderr, "cif (%f, %d)\n", cif.key, cif.value);
    fprintf( stderr, "cl (%s, %ld)\n", cl.index.c_str(), cl.element);
    fprintf( stderr, "c (%s, %s)\n", c.i.c_str(), c.e.c_str() );
    fprintf( stderr, "cii (%d, %d)\n", cii.x, cii.y );
}
