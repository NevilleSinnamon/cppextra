#include <string>
#include <stdio.h>

template<typename TValue=std::string, typename TKey=std::string>
//template<typename TValue, typename TKey>
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
//struct couple<std::string, std::string>
struct couple<>
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
    fprintf( stderr, "cif (%f, %d)\n", cif.key, cif.value);

    // equivalent to
    //couple<long, std::string> cl;
    couple<long> cl;
    cl.index = "neville";
    cl.element = 58;
    fprintf( stderr, "cl (%s, %ld)\n", cl.index.c_str(), cl.element);

    // equivalent to
    //couple<std::string, std::string> c;
    couple<> c;
    c.i = "one";
    c.e = "two";
    fprintf( stderr, "c (%s, %s)\n",   c.i.c_str(), c.e.c_str() );

    couple<int,int> cii;
    cii.x = 3;
    cii.y = 4;
    fprintf( stderr, "cii (%d, %d)\n", cii.x, cii.y );

}
