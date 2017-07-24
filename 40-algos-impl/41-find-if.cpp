#include <catch.hpp>

#include "find_if.h"

TEST_CASE("successful find_if", "[algorithm]")
{
    std::vector<int> data{ 1, 2, 3, 4 };
    CHECK(training::find_if(data.end(), data.end(), [](auto && ){ return false; }) == data.end());
    CHECK(training::find_if(data.begin(), data.end(), [](auto && elem){ return elem == 4; }) == data.begin() + 3);
    CHECK(training::find_if(data.begin(), data.end(), [](auto && elem){ return elem == 1; }) == data.begin());
    CHECK(training::find_if(data.begin(), data.end(), [](auto && elem){ return elem == 5; }) == data.end());
}

TEST_CASE("unsuccessful find_if", "[algorithm]")
{
    std::vector<int> other_data{ 1, 2, 2 };
    CHECK(training::find_if(other_data.begin(), other_data.end(), [](auto && elem){ return elem == 2; }) == other_data.begin() + 1);
}

