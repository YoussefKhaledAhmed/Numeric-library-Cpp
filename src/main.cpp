#include <iostream>
#include <string>

#include "math.hpp"
#include "numeric_operations.hpp"

/* declaration of test functions */
void max_test();
void min_test();
void sub_test();
void custom_class_test();

/* tmp class to test passing an argunment of user-defined type */
class tmp{

};

int main ()
{   
    /* 1. testing max operations */
    std::cout<<"max:\n";
    max_test();
    std::cout<<std::endl;

    /* 2. testing min operations */
    std::cout<<"min:\n";
    min_test();
    std::cout<<std::endl;

    /* 3. testing sub operations */
    std::cout<<"sub:\n";
    sub_test();
    std::cout<<std::endl;


    /* 4. testing the custom class */
    std::cout<<"testing the custom class:\n";
    custom_class_test();
    std::cout<<std::endl;

    return 0;
}



/* testing max function template*/
void max_test(){
    /* creating an object of the tmp class */
    tmp t;

    /* printing the numbers that we will test with */
    std::cout<<"numbers: 100, 200, 500.2 , 500.1\n";

    /* testing passing more than two arguments with different *
     * types.                                                 */
    std::cout << custom_lib::max(100, 200, 500.2 , 500.1)  << "\n";

    /* testing passing one argument. */
    std::cout << custom_lib::max(100)  << "\n";

    /* testing with passing no arguments. */
    std::cout << int(custom_lib::max())  << "\n";

    /* testing passing element with user-defined type */
    // std::cout << custom_lib::max(100, 200, 500.2 , 500.1 , t)  << "\n";
}


/* testing min function template*/
void min_test(){
    /* creating an object of the tmp class */
    tmp t;

    /* printing the numbers that we will test with */
    std::cout<<"numbers: 100, 200, 500.2 , 500.1\n";

    /* testing passing more than two arguments with different *
     * types.                                                 */
    std::cout << custom_lib::min(100, 200, 500.2 , 500.1)  << "\n";

    /* testing passing one argument. */
    std::cout << custom_lib::min(100)  << "\n";

    /* testing with passing no arguments. */
    std::cout << int(custom_lib::min())  << "\n";

    /* testing passing element with user-defined type */
    // std::cout << custom_lib::min(100, 200, 500.2 , 500.1 , t)  << "\n";
}


/* testing sub function template*/
void sub_test(){
    /* creating an object of the tmp class */
    tmp t;

    /* printing the numbers that we will test with */
    std::cout<<"numbers: 100, 200, 500.2 , 500.1\n";

    /* testing passing more than two arguments with different *
     * types.                                                 */
    std::cout << custom_lib::sub(100, 200, 500.2 , 500.1)  << "\n";

    /* testing passing one argument. */
    std::cout << custom_lib::sub(100)  << "\n";

    /* testing with passing no arguments. */
    std::cout << int(custom_lib::sub())  << "\n";

    /* testing passing element with user-defined type */
    // std::cout << custom_lib::sub(100, 200, 500.2 , 500.1 , t)  << "\n";
}



void custom_class_test(){
    /* creating object of custom class and initializing it with string: * 
     * "Youssef".                                                       */
    custom <std::string> str("Youssef");

    /* creating object of custom class and initializing it with string: * 
     * "zaied".                                                         */
    custom <std::string> str2("zaied");

    /* using print_string() method */
    str.print_string();
    str2.print_string();

    /* testing the overloading of the [] operator */
    std::cout << "str[2] -> "<<str[2]<<"\n";

    /* testing the overloading of the - operator */
    std::cout << "str - str2: " << str - str2<<"\n";
}
