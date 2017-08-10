#include <boost/optional.hpp>

#include <catch.hpp>

#include "implementation.h"

TEST_CASE("size of optional", "[container_wrapper]")
{
    container_wrapper<boost::optional<int>> c1;
    REQUIRE(c1.size() == 0);

    container_wrapper<boost::optional<int>> c2 = boost::make_optional<int>(1);
    REQUIRE(c2.size() == 1);
}

