#include <type_traits>
#include <stdio.h>

template<typename T, typename T2 = long >
struct IdHandler
{
    static long get_id(T const &) {return 0; }
    static void set_id(T&, long) {}
};

template<typename T>
struct IdHandler<T, decltype(T().id)>
{
    static long get_id(T const & t) {return t.id; }
    static void set_id(T& t, long l) { t.id = l; }
};

template<typename T>
struct IdHandler<T, decltype(T().parent_id)>
{
    static long get_id(T const & t) {return t.parent_id; }
    static void set_id(T& t, long l) { t.parent_id = l; }
};

////////////////////////////////////////////////////////////////////////

struct NOS
{
    long id=0;
};

struct Replace
{
    long parent_id=0;
};

struct HB
{
    bool no_id=true;
};

////////////////////////////////////////////////////////////////////////

template<typename T>
void handle_id(T t, long new_id)
{
    IdHandler<T>::set_id(t, new_id);
    long id = IdHandler<T>::get_id(t);
    fprintf( stderr, " id %ld\n", id );
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "C++11 with decltype\n" );

    NOS nos;
    HB  hb;
    Replace  rep;
    
    handle_id(nos, 17);
    handle_id(hb,  29);
    handle_id(rep, 37);
}
