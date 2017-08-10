#pragma once

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

