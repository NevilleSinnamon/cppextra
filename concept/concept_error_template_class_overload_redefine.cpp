#include <concepts>
#include <type_traits>
#include <stdio.h>

template <typename T>
concept has_id = requires(T t) { t.id; };

template <typename T>
concept no_id = requires(T t) { ! t.id; };

////////////////////////////////////////////////////////////////////////

template<typename T>
struct IdHandler
{
    static long get_id(T const &) {return 0; }
    static void set_id(T&, long) {}
};

template<>
struct IdHandler<has_id T>
{
    static long get_id(T const & t) {return t.id; }
    static void set_id(T& t, long l) { t.id = l; }
};

////////////////////////////////////////////////////////////////////////

struct foo
{
    long id=0;
};

struct bar
{
    bool no_id=true;
};

////////////////////////////////////////////////////////////////////////

template<typename T>
void handle_id(T t, int new_id)
{
    IdHandler<T>::set_id(t, new_id);
    long id = IdHandler<T>::get_id(t);
    fprintf( stderr, " id %ld\n", id );
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "C++20 ERROR can not overload template type defination using concepts\n" );

    foo f;
    bar b;
    
    handle_id(f, 17);
    handle_id(b, 29);
}

