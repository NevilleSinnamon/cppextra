#include <type_traits>
#include <iostream>

template <typename T, typename = void>
struct has_id : std::false_type {};

template <typename T>
struct has_id<T, std::void_t<decltype(std::declval<T>().id)>> : std::true_type {};

template <typename T>
typename std::enable_if<has_id<T>::value, void>::type
print_id(const T& obj) 
{
    std::cout << "id: " << obj.id << std::endl;
}

template <typename T>
typename std::enable_if<!has_id<T>::value, void>::type
print_id(const T&) 
{
    std::cout << "No 'id' member found!" << std::endl;
}

// Example classes
struct WithId 
{
    int id = 42;
};

struct WithoutId {};

int main() 
{
    fprintf( stderr, "print C++17 needed for void_t\n" );
    WithId obj1;
    WithoutId obj2;

    print_id(obj1); // Output: id: 42
    print_id(obj2); // Output: No 'id' member found!

    return 0;
}

