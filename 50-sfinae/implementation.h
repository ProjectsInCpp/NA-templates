#pragma once

template<typename T>
struct has_type_typedef
{
private:
    template<typename U, typename = typename U::type>
    static void test(int);

    template<typename U>
    static char test(long);

public:
    static const constexpr bool value = std::is_void<decltype(test<T>(0))>::value;
};

template<typename T>
struct has_member_variable
{
private:
    template<typename U, typename = decltype(std::declval<U>().member)>
    static void test(int);

    template<typename U>
    static char test(long);

public:
    static const constexpr bool value = std::is_void<decltype(test<T>(0))>::value;
};

