/*
 * Name: Youssef Khaled Ahmed 
 * Description: this is a hpp file that holds operations
 *              that should be accessed when dealing with 
 *              numeric values and creating a class template
 *              that holds strings and subtract method using 
 *              operator overloading(-).
 * Date: 17/9/2024 : dd/mm/yyyy
 * */

#ifndef NUMERIC_OPERATIONS_HPP
#define NUMERIC_OPERATIONS_HPP

/* to test the types passed to the functions */
#include <type_traits>



/* creating namespace for this lib to prevent
 * naming --- */
namespace custom_lib
{
/* 1. max operation: getting the maximum number between *
 *                   the passed arguments.              */
    template < typename T , typename U , typename ... Ts>

    /* creating the max function using tail recursion. */
    auto max( const T & a , const U & b , const Ts & ... values)
    {
        /* checking if the passed arguments are arithmetic or not */
        static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> , " T & U must be arithmetic ");

        /* checking if there is more than one element is passed. */
        if constexpr( sizeof ... (Ts) > 0){

            /* checking which one is max and *
             * saving it in a temp variable. */
            auto max_element = (a>b)?  a: b;

            /* calling the max function again with unpacking the *
             * parameters.                                       */
            return max(max_element , values ...);

        } else{

            /* Comparing the two elements and saving the max one * 
             * in a temp variable.                               */
            auto max_element = (a>b)?  a: b;

            /* returning the max variable */
            return max_element;
        }
    }

    /* handling the case of passing one argument */
    template <typename T>
    T max(const T & a){
        /* checking if the passed argument is arithmetic or not */
        static_assert( std::is_arithmetic_v<T>, " T must be arithmetic ");

        return a;
    }

    /* handling the case of not passing any argument */
    char max(){
        return 0;
    }

/* 2. min operation: getting the minimum number between *
 *                   the passed arguments.              */
    template < typename T , typename U , typename ... Ts>

    /* creating the min function using tail recursion. */
    auto min( const T & a , const U & b , const Ts & ... values)
    {
        /* checking if the passed arguments are arithmetic or not */
        static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> , " T & U must be arithmetic ");

        /* checking if there is more than one element is passed. */
        if constexpr( sizeof ... (Ts) > 0){

            /* checking which one is min and *
             * saving it in a temp variable. */
            auto min_element = (a<b)?  a: b;

            /* calling the min function again with unpacking the *
             * parameters.                                       */
            return min(min_element , values ...);

        } else{

            /* Comparing the two elements and saving the min one * 
             * in a temp variable.                               */
            auto min_element = (a<b)?  a: b;

            /* returning the min variable */
            return min_element;
        }
    }

    /* handling the case of passing one argument */
    template <typename T>
    T min(const T & a){
        /* checking if the passed argument is arithmetic or not */
        static_assert( std::is_arithmetic_v<T>, " T must be arithmetic ");

        return a;
    }

    /* handling the case of not passing any argument */
    char min(){
        return 0;
    }


/* 3. sub operation: subtracting the passed arguments */
    template < typename T , typename U , typename ... Ts>

    /* creating the sub function using tail recursion. */
    auto sub( const T & a , const U & b , const Ts & ... values)
    {
        /* checking if the passed arguments are arithmetic or not */
        static_assert( std::is_arithmetic_v<T> && std::is_arithmetic_v<U> , " T & U must be arithmetic ");

        /* checking if there is more than one element is passed. */
        if constexpr( sizeof ... (Ts) > 0){

            /* checking which one is sub and *
             * saving it in a temp variable. */
            auto sub_element = a-b;

            /* calling the sub function again with unpacking the *
             * parameters.                                       */
            return sub(sub_element , values ...);

        } else{

            /* Comparing the two elements and saving the sub one * 
             * in a temp variable.                               */
            auto sub_element = a-b;

            /* returning the sub variable */
            return sub_element;
        }
    }

    /* handling the case of passing one argument */
    template <typename T>
    T sub(const T & a){
        /* checking if the passed argument is arithmetic or not */
        static_assert( std::is_arithmetic_v<T>, " T must be arithmetic ");

        return a;
    }

    /* handling the case of not passing any argument */
    char sub(){
        return 0;
    }

}



/* custom class */
template <typename T>
class custom
{

};


/* Full class template specialization */
template <>
class custom < std::string >
{
private:
    /* internal buffer to hold the chars */
    std::string buffer_;
public:
    /* saving passed string in the internal buffer */
    explicit custom( std::string a ) : buffer_{a}{}

    /* operator [] overloading where this accesses *
     * the intended index of the internal buffer.  */
    char & operator[](size_t i){
        return (this->buffer_)[i];
    }
    
    /* operator - overloading where this subtracts the *
     * length of the 2 strings.                        */
    size_t operator -(custom & str){
        return ((this->buffer_).length() - str.custom_length());
    }

    /* printing the internal buffer(i.e., buffer_) */
    void print_string(){
        std::cout << this->buffer_ <<"\n";
    }

    /* getting the length of the internal buffer(i.e., buffer_)*/
    int custom_length(){
        return (this->buffer_).length();
    }
};




#endif /* NUMERIC_OPERATIONS_HPP */