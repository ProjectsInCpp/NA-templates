#include <catch.hpp>

#include "vector.h"

template<typename T>
class checked_vector : std::vector<T>
{
public:
    using std::vector<T>::vector;

    auto at(std::size_t) = delete;

    auto operator[](std::size_t idx) const
    {
        ++_accesses;
        return std::vector<T>::at(idx);
    }

    auto access_count() const
    {
        return _accesses;
    }

private:
    mutable std::size_t _accesses = 0;
};

TEST_CASE("add-multiply", "[vector]")
{
    checked_vector<double> v1{ 1.0, 2.0, 4.0 };
    checked_vector<double> v2{ 1.0, 0.5, 0.25 };
    checked_vector<int> v3{ 9, 9, 9 };

    auto result = v1 * v2 + v3;

    CHECK(result[0] == 10);
    CHECK(result[1] == 10);
    CHECK(result[2] == 10);

    CHECK(v1.access_count() == 3);
    CHECK(v2.access_count() == 3);
    CHECK(v3.access_count() == 3);
}
