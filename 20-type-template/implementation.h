#pragma once
#include <boost/optional.hpp>

template<typename T>
struct size_trait
{
    static std::size_t size(const T& t)
    {
        return !!t;
    }
};

template<typename T>
struct size_trait<boost::optional<T>>
{
    static std::size_t size(const boost::optional<T> & t)
    {
        return !!t;
    }
};

template<typename T>
class container_wrapper
{
public:
    container_wrapper() = default;

    container_wrapper(const T t) : container_{std::move(t)}
    {
    }

    std::size_t size() const
    {
        return size_trait<T>::size(container_);
    }

private:
    T container_;
};


/*
template<typename T>
class container_wrapper<boost::optional<T>>
{
public:
    container_wrapper() = default;

    container_wrapper(boost::optional<T> t) : container_{std::move(t)}
    {
    }

    std::size_t size() const
    {
        return !!container_;
    }
private:
    boost::optional<T> container_;
};
*/

