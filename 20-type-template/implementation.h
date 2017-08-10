#pragma once
#include <boost/optional.hpp>

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
        return container_.size();
    }

private:
    T container_;
};

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
