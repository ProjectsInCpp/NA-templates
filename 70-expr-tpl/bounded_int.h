#include <stdexcept>
#include <type_traits>

class invalid_value : public std::domain_error
{
public:
    invalid_value() : std::domain_error{ "bounded_int value not within bounds" }
    {
    }
};

template<typename T, T Min, T Max>
class bounded_int
{
public:
    static constexpr const T min = Min;
    static constexpr const T max = Max;

    bounded_int(T t) : _value{ std::move(t) };

    explicit operator T() const
    {
        return _value;
    }

    T value() const
    {
        return _value;
    }

private:
    T _value;
};

template<typename T, typename U, T MinT, T MaxT, U MinU, U MaxU>
auto operator+(const bounded_int<T, MinT, MaxT> & lhs, const bounded_int<U, MinU, MaxU> & rhs);

template<typename T, typename U, T MinT, T MaxT, U MinU, U MaxU>
auto operator-(const bounded_int<T, MinT, MaxT> & lhs, const bounded_int<U, MinU, MaxU> & rhs);

template<typename T, typename U, T MinT, T MaxT, U MinU, U MaxU>
auto operator*(const bounded_int<T, MinT, MaxT> & lhs, const bounded_int<U, MinU, MaxU> & rhs)
