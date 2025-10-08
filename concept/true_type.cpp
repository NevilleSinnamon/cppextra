#include <type_traits>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////

template <typename T, typename = long>
struct has_id : std::false_type {};

template <typename T>
struct has_id<T, decltype(T().id)> : std::true_type {};
//struct has_id<T, decltype(std::declval<T>().id)> : std::true_type {};

////////////////////////////////////////////////////////////////////////

template<typename, bool>
struct IdHandlerWithId;

template<typename T>
struct IdHandlerWithId<T, false>
{
    static long get_id(T const &) {return 0; }
    static void set_id(T&, long) {}
};

template<typename T>
struct IdHandlerWithId<T, true>
{
    static long get_id(T const & t) {return t.id; }
    static void set_id(T& t, long l) { t.id = l; }
};

template<typename T>
using IdHandler = IdHandlerWithId<T, has_id<T>::value>;

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
    fprintf(stderr, "C++11 for decltype and declval use C++17 if void_t needed \n" );

    NOS nos;
    HB  hb;
    Replace  rep;
    
    handle_id(nos, 17);
    handle_id(hb,  29);
    handle_id(rep, 37);
}
