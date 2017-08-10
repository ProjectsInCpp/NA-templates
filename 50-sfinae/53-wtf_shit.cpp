template<typename T>
struct has_foo
{
private:
    template<typename U, typename = decltype(std::declval<U>().foo())>
    static void test(int);
    template<typename U>
    static char test(long);

public:
    static constexpr bool value = std::is_void<decltype(test<T>(0))>::value;
};
