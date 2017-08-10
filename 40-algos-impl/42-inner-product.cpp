#include <catch.hpp>

#include "inner_product.h"

TEST_CASE("inner_product", "[numeric]")
{                              // 2+ 4+ 9+ 12 = 6 + 21 = 27
    std::vector<int> data_lhs = { 1, 2, 3, 4 };
    std::vector<int> data_rhs = { 2, 2, 3, 3 };

    REQUIRE(training::inner_product(data_lhs.begin(), data_lhs.end(), data_rhs.begin(),
        0,
        std::plus<>(),
        std::multiplies<>()
    ) == 27);
}

