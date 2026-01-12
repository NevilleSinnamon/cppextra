#include <stdio.h>
#include <tuple>

std::tuple<int,int> divide_t(int divident, int divisor)
{
    return std::make_tuple(divident/divisor, divident%divisor);
}

std::pair<int,int> divide_p(int divident, int divisor)
{
    return std::pair(divident/divisor, divident%divisor);
}

struct Result
{
    int res1;
    int res2;
};

Result divide_r(int divident, int divisor)
{
    return Result{divident/divisor, divident%divisor};
}

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;

    std::tie(a,b) = divide_t(14, 3);
    fprintf( stderr, "tuple (14, 3) using tie result a=<%d> b=<%d>\n", a, b);

    //a,b = divide_t(14, 3); error
    //[a,b] = divide_t(14, 3); error needs to be a declaration like line 40 auto[c,d] =
    //fprintf( stderr, "one a=<%d> b=<%d>\n", a, b);
    fprintf( stderr, "multi returns can be assigned only in a declaration\n");

//    int c = 0;
//   int d = 0;
    auto [c,d] = divide_t(19, 4);
    fprintf( stderr, "tuple (19, 4) using auto declaration result c=<%d> d=<%d>\n", c, d);

    auto [e,f] = divide_p(13, 5);
    fprintf( stderr, "pair (13, 5) with auto declaration e=<%d> f=<%d>\n", e, f);

    std::pair<int,int> p;
    p = divide_p(16, 5);
    fprintf( stderr, "pair(16, 5) assign to pair p.first=<%d> p.second=<%d>\n", p.first, p.second);

    Result r = divide_r(9, 2);
    fprintf( stderr, "struct (9,2) r.res1=<%d> r.res2=<%d>\n", r.res1, r.res2);

    auto[g,h] = divide_r(11, 2);
    fprintf( stderr, "struct (11,2) g=<%d> h=<%d>\n", g, h);

}
