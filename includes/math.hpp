#ifndef MATH_HPP_
#define MATH_HPP_

#include <string>
#include <type_traits>


template <typename T , typename U , typename ... Ts> /* parameter packing */

auto sum (const T& a , const U& b , const Ts& ... values){

    /* programming by contract */
    /* to make sure that the arguments are arithmetic */
    static_assert(std::is_arithmetic_v<T> && std::is_arithmetic_v<U> , "T&U must be arth. data-type. ");
    
    /* 1. Tail recursion */
    if constexpr(sizeof ...(Ts) > 0){
        auto result = a + b;
        return sum(result , values ...); /* parameters unpack */
    } 
    else
    {
        return a + b;
    }

    /* 2. Folding expression */
}


/* function template specialization.                                   * 
 * this function is made in case that the passed argument is only one. */
template< typename T>
T sum( const T& a){
    
    /* programming by contract. */
    static_assert(std::is_arithmetic_v<T>, "T must be arth. data-type");

    return a;
}

/* function overloading to implement a sum function that *
 * concatenates two strings.                             */
template <>
auto sum<std::string , std::string> (const std::string& a , const std::string& b){
    
    /* Concatination */
    return a+b;

    /* returning the total length of the passed strings. */
    // return a.length() + b.length(); 
}

/* function overloading to handle the case of no passed arguments. */
int sum(){
    return 0;
}

#endif /* MATH_HPP_ */