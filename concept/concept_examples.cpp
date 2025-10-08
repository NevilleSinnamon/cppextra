#include <concepts>
#include <type_traits>
#include <stdio.h>

//////////////////////////////////////////////////////////////
//  concepts
//////////////////////////////////////////////////////////////

template <typename T>
concept always_satisfied = true;

template <typename T>
concept my_signed = std::is_integral<T>::value && std::is_signed<T>::value;

template <typename T>
concept callable = requires(T f) { f(); };

template <typename T>
concept adder = requires(T x) { x+x; };

//////////////////////////////////////////////////////////////
//  requires
//////////////////////////////////////////////////////////////

template <my_signed T>
void f(T v){ fprintf(stderr, "called f\n"); };

template <callable T>
void k(T f){ f(); };

template <typename T>
  requires my_signed<T>
void g(T v){ fprintf(stderr, "called g\n"); };

//template <typename T>
// requires requires (T x){x+x;}
// T add(T a, T b)
// { int r = a+b; fprintf(stderr, "called add <%d> + <%d> = <%d>\n", a, b, r); return r; };

template <adder T>
T add(T a, T b)
{ int r = a+b; fprintf(stderr, "called add <%d> + <%d> = <%d>\n", a, b, r); return r; };

template <typename T>
void h(T v)
  requires my_signed<T>
   { fprintf(stderr, "called h\n"); };

/*
template <typename T>
void j(T v)
   { fprintf(stderr, "called j\n"); }
  ERROR must be before function body.
  requires my_signed<T>;
*/

class point
{
    int x=0;
    int y=0;
};

void hello()
{
    fprintf(stderr, "hello \n");
}

int goodbye(int i)
{
    fprintf(stderr, "goodbye \n");
    return i;
}

struct foo {
  int foo;
};

struct bar {
  using value = int;
  value data;
};

struct baz {
  using value = int;
  value data;
};

//struct boz; // to test Ref<T>

// Using SFINAE, enable if `T` is a `baz`.
template <typename T, typename = std::enable_if_t<std::is_same_v<T, baz>>>
struct S {};

template <typename T>
using Ref = T&;

template <typename T>
concept C = requires {
                     // Requirements on type `T`:
  typename T::value; // A) has an inner member named `value`
  typename S<T>;     // B) must have a valid class template specialization for `S`
  typename Ref<T>;   // C) must be a valid alias template substitution
};

template <C T>
void m(T a){ fprintf(stderr, "called m\n"); };


template <typename T>
concept C2 = requires(T x) {
  {*x}    -> std::convertible_to<typename T::inner>; // the type of the expression `*x` is convertible to `T::inner`
  {x + 1} -> std::same_as<int>; // the expression `x + 1` satisfies `std::same_as<decltype((x + 1))>`
  {x * 1} -> std::convertible_to<T>; // the type of the expression `x * 1` is convertible to `T`
};

template <typename T>
concept C3 = requires(T x) {
  std::is_convertible_v<decltype(*x), typename T::inner>; // the type of the expression `*x` is convertible to `T::inner`
  std::is_same_v<decltype(x+1), int>; // the expression `x + 1` satisfies `std::same_as<decltype((x + 1))>`
  std::is_convertible_v<decltype(x+1), T>; // the type of the expression `x * 1` is convertible to `T`
};


template <typename T>
concept C4 = requires(T x) {
  std::convertible_to<decltype(*x), typename T::inner>; // the type of the expression `*x` is convertible to `T::inner`
  std::same_as<decltype(x+1), int>; // the expression `x + 1` satisfies `std::same_as<decltype((x + 1))>`
  std::convertible_to<decltype(x+1), T>; // the type of the expression `x * 1` is convertible to `T`
};

int main(int argc, char* argv[])
{
    fprintf(stderr, "concepts \n" );

    int a = 5;
    int b = 4;
    unsigned char c = 6;

    point p1, p2;

    f(a);
    //f(c); produces compilation error with unsigned.
    g(a);
    //g(c); produces compilation error with unsigned.
    h(a);
    //h(c); produces compilation error with unsigned.
    //j(a);
    
    k(hello);
    //k(goodbye); Error, signature of goodbye does not satisfy template k.

    add(a, b);
    //add(p1, p2); // compilation error point not addible

    
    //m(foo{}); // ERROR: Fails requirement A.
    //m(bar{}); // ERROR: Fails requirement B.
    m(baz{}); // PASS.
    //m(boz{}); // FAIL everything.

}
