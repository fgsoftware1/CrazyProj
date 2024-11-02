#include "pch.hpp"
#include "Crazy.hpp"

DTOR_IMPL(Crazy)
DTOR_END

CTOR_IMPL_NO_PARAMS(Crazy)
CTOR_END

FUNC_IMPL(Crazy, int, add, int a, int b)
    return a + b;
FUNC_END

int main() {
    Crazy obj;
    std::cout << "Sum: " << obj.add(3, 4) << std::endl;

    return 0;
}