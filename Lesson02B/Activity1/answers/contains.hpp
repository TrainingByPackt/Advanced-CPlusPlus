//============================================================================
// Name        : contains.hpp
// Author      : Brian Price
// Version     :
// Copyright   : Your copyright notice
// Description : Activity 1 Lesson 3
//============================================================================
#pragma once
#include <type_traits>
#include <string>
#include <set>
#include <vector>
#include <algorithm>


template <class T>
auto test_npos(int) -> decltype((void)T::npos, std::true_type{});

template <class T>
auto test_npos(long) -> std::false_type;

template <class T>
struct has_npos : decltype(test_npos<T>(0)) {};

template< class T >
inline constexpr bool has_npos_v = has_npos<T>::value;


template <class T, class A0>
auto test_find(int) -> decltype(void(std::declval<T>().find(std::declval<A0>())), std::true_type{});

template <class T, class A0>
auto test_find(long) -> std::false_type;

template <class T, class A0>
struct has_find : decltype(test_find<T,A0>(0)) {};

template< class T, class A0 >
inline constexpr bool has_find_v = has_find<T, A0>::value;

template<class C, class T>
auto contains(const C& c, const T& key) -> decltype(end(c), true)
{
    if constexpr(has_npos_v<C>)
    {
        return C::npos != c.find(key);
    }
    else if constexpr(has_find_v<C, T>)
    {
        return std::end(c) != c.find(key);
    }
    else
    {
        return end(c) != std::find(begin(c), end(c), key);
    }
}
