#include <type_traits>
#include <stdio.h>
#include "IdType.h"

////////////////////////////////////////////////////////////////////////

template <typename T, typename = decltype(T().id) >
struct has_id : std::true_type {};
//struct has_id<T, decltype(std::declval<T>().id)> : std::true_type {};

template <typename T, typename = decltype(T().parent_id)>
struct has_parent_id : std::true_type {};

////////////////////////////////////////////////////////////////////////

constexpr IdType which_id(...) { return NO_ID; }

template<typename T> constexpr 
typename std::enable_if<has_id<T>::value, IdType>::type
which_id(T const& t)
{ 
    return ID;
}

template<typename T> constexpr 
typename std::enable_if<has_parent_id<T>::value, IdType>::type
which_id(T const& t)
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
void handle_id(T t, long new_id)
{
    IdHandler<T>::set_id(t, new_id);
    long id = IdHandler<T>::get_id(t);
    fprintf( stderr, " id %ld\n", id );
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "C++17 for void_t C++11 for decltype and declval\n" );

    NOS nos;
    HB  hb;
    Replace  rep;
    
    handle_id(nos, 17);
    handle_id(hb,  29);
    handle_id(rep, 37);
}
