#include "pch.hpp"
#include "Crazy.hpp"

CTOR_IMPL(Crazy)
CTOR_END

FUNC_IMPL(Crazy, int, add, int a, int b)
    return a + b;
FUNC_END

int main() {
    Crazy obj;
    std::cout << "Sum: " << obj.add(3, 4) << std::endl;

    return 0;
}