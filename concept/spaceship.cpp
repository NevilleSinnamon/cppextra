#include <stdio.h>
#include <compare>

const char* to_string(std::strong_ordering ordering) 
{
    if (ordering == std::strong_ordering::less) 
    {
        return "less";
    } else if (ordering == std::strong_ordering::equal) 
    {
        return "equal";
    } else if (ordering == std::strong_ordering::greater) 
    {
        return "greater";
    }
    return "unknown";
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "spaceship \n" );

    int a = 3;
    int b = 6;

    auto rc = a <=> b;
    if(rc == 0)
    {
        fprintf(stderr, "a <%d> == b<%d> rc<%s>\n", a, b, to_string(rc) );
    }
    else if(rc > 0)
    {
        fprintf(stderr, "a <%d> > b<%d> rc<%s>\n", a, b, to_string(rc) );
    }
    else if(rc < 0)
    {
        fprintf(stderr, "a <%d> < b<%d> rc<%s>\n", a, b, to_string(rc) );
    }
}



