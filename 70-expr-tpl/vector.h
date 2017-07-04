#pragma once

#include <vector>

template <typename E1, typename E2>
struct vector_sum;

template <typename E1, typename E2>
vector_sum<E1, E2> operator+(E1 && e1, E2 && e2);

template <typename E1, typename E2>
struct vector_dot_product;

template <typename E1, typename E2>
vector_dot_product<E1, E2> operator*(E1 && e1, E2 && e2);

