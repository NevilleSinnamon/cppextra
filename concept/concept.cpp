#include <concepts>
#include <type_traits>
#include <stdio.h>

template <typename T>
concept has_id = requires(T t) { t.id; };

template <typename T>
concept has_parent_id = requires(T t) { t.parent_id; };

////////////////////////////////////////////////////////////////////////

typedef enum { NO_ID, PARENT_ID, ID } IdType;

template<typename T>
constexpr IdType which_id(T const& t)
{ 
    return NO_ID;
}

template<has_id T>
constexpr IdType which_id(T const& t)
{ 
    return ID;
}

template<has_parent_id T>
constexpr IdType which_id(T const& t)
{ 
    return PARENT_ID;
}

////////////////////////////////////////////////////////////////////////

template<typename, IdType>
struct IdHandlerType;

template<typename T>
struct IdHandlerType<T, NO_ID>
{
    static long get_id(T const &) {return 0; }
    static void set_id(T&, long) {}
};

template<typename T>
struct IdHandlerType<T, ID>
{
    static long get_id(T const & t) {return t.id; }
    static void set_id(T& t, long l) { t.id = l; }
};

template<typename T>
struct IdHandlerType<T, PARENT_ID>
{
    static long get_id(T const & t) {return t.parent_id; }
    static void set_id(T& t, long l) { t.parent_id = l; }
};

template<typename T>
using IdHandler = IdHandlerType<T, which_id(T())>;

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
void handle_id(T t, int new_id)
{
    IdHandler<T>::set_id(t, new_id);
    long id = IdHandler<T>::get_id(t);
    fprintf( stderr, " id %ld\n", id );
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "C++20 with concepts\n" );

    NOS nos;
    HB  hb;
    Replace  rep;
    
    handle_id(nos, 17);
    handle_id(hb,  29);
    handle_id(rep, 37);
}
