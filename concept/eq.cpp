#include <concepts>
#include <type_traits>
#include <string.h>
#include <stdio.h>

template <typename T1, typename T2>
concept EqComparable = requires( T1 a, T2 b ) { a==b; };

template <typename T1, typename T2>
    requires EqComparable<T1, T2>
bool are_eq( T1 a, T2 b)
{
    return a == b;
}

template <typename T>
    requires EqComparable<T, T>
bool eq( T a, T b )
{
    return a == b;
}

template <typename T=char*>
    requires EqComparable<T, T>
bool eq( char* a, char* b )
{
    return strcmp(a, b) == 0;
}

////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    fprintf(stderr, "EQ \n" );

    char a[] = "Nev";
    char b[] = "Nev";
    char c[] = "NeV";

    fprintf( stderr, " eq(3,4) is %d\n", eq(3,4) );
    fprintf( stderr, " eq(3,3) is %d\n", eq(3,3) );
    fprintf( stderr, " eq(\"Nev\",\"Nev\") is %d\n", eq("Nev","Nev") );
    fprintf( stderr, " eq(\"Nev\",\"NeV\") is %d\n", eq("Nev","NeV") );

    fprintf( stderr, " eq(\"Nev\",\"Nev\") is %d\n", eq(a, b) );
    fprintf( stderr, " eq(\"Nev\",\"NeV\") is %d\n", eq(b, c) );

    fprintf( stderr, " are_eq(2.0, 2) is %d\n", are_eq(2.0, 2) );
    
    // constraint error double void* not compatable. 
    // fprintf( stderr, " are_eq(2.0, nullptr) is %d\n", are_eq(2.0, nullptr) );

}
