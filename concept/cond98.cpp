#include <stdio.h>

////////////////////////////////////////////////////////////////////////

struct NOS
{
    long id;
};

struct Replace
{
    long parent_id;
};

struct HB
{
    bool no_id;
};

////////////////////////////////////////////////////////////////////////

typedef enum { NO_ID, PARENT_ID, ID } IdType;

template <typename T>
struct which_id
{
    static const IdType value;
};

template <typename T>
const IdType which_id<T>::value = NO_ID;

template<>
const IdType which_id<NOS>::value = ID;

template<>
const IdType which_id<Replace>::value = PARENT_ID;

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
struct IdHandler
{
    typedef IdHandlerType<T, which_id<T>::value> type;
};

////////////////////////////////////////////////////////////////////////

template<typename T>
void handle_id(T t, long new_id)
{
    IdHandler<T>::type::set_id(t, new_id);
    long id = IdHandler<T>::type::get_id(t);
    fprintf( stderr, " id %ld\n", id );
}

int main(int argc, char* argv[])
{
    fprintf(stderr, "C++98 pre C++11 \n" );

    NOS nos;
    HB  hb;
    Replace  rep;
    
    handle_id(nos, 17);
    handle_id(hb,  29);
    handle_id(rep, 37);
}

