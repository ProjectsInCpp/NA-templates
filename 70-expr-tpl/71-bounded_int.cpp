#include <catch.hpp>

#include "bounded_int.h"

TEST_CASE("construction", "[bounded_int]")
{
    bounded_int<int, 1, 2> one = 1;
    (void)one;

    try
    {
        bounded_int<int, 3, 4> two = 2;
        (void)two;
        REQUIRE(!"exception should've been thrown");
    }
    catch (const invalid_value &)
    {
    }
}

TEST_CASE("arithmetic", "[bounded_int]")
{
    bounded_int<int, 1, 1> one{ 1 };
    CHECK(one.value() == 1);

    bounded_int<int, 3, 7> four{ 4 };
    CHECK(four.value() == 4);

    auto five = one + four;
    CHECK((std::is_same<decltype(five), bounded_int<int, 4, 8>>::value));
    CHECK(five.value() == 5);

    auto minus_one = four - five;
    CHECK((std::is_same<decltype(minus_one), bounded_int<int, -1, -1>>::value));
    CHECK(minus_one.value() == -1);

    auto twenty = four * five;
    CHECK((std::is_same<decltype(twenty), bounded_int<int, 12, 56>>::value));
    CHECK(twenty.value() == 20);
}

TEST_CASE("conversions", "[bounded_int]")
{
    CHECK((std::is_constructible<bounded_int<int, 1, 2>, bounded_int<int, 1, 1>>::value));
    CHECK((std::is_constructible<bounded_int<int, 1, 2>, bounded_int<int, -1, 7>>::value));
    CHECK((!std::is_constructible<bounded_int<int, 3, 4>, bounded_int<int, 1, 2>>::value));
}
