#pragma once

// define vector_erase here
#include <algorithm>
#include <vector>

template<typename T>
void vector_erase(T& vec, typename T::const_reference val)
{
    vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
}
