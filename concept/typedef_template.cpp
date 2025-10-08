#include <vector>

// In C++98 there is no using statement,
// and typedef can not be used to make a type alias for a template type
// eg typedef std::vector<int> IntVector; produces an error.
// This is the work around.  Typedef inside a template struct see below.

template <typename T>
struct MyVector 
{
    typedef std::vector<T> Type;
};

int main() 
{
    // Use the typedef
    MyVector<int>::Type myVec; // Equivalent to std::vector<int>
    myVec.push_back(42);

    return 0;
}

