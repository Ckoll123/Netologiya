#include <iostream>
#include <assert.h>
#include <exception>
#include <sstream> 

#include "extended_array.h"

    
template <typename T, typename U>
void AssertEq(const T& valueA, const U& valueB) {
    if (valueA != valueB) {
        std::ostringstream err;
        err << "Assertion failed: " << valueA << " != " << valueB;
        throw std::runtime_error(err.str());
    }
}


template <typename TestFunc>
void RunOneTest(TestFunc tfunc, const std::string& test_name) {
    try
    {
        tfunc();
        std::cerr << test_name << " OK" << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << test_name << " FAIL: " << e.what() << std::endl;
    }
    catch (std::invalid_argument& e)
    {
        std::cerr << test_name << " FAIL: " << e.what() << std::endl;
    }
    catch (std::bad_typeid& e)
    {
        std::cerr << test_name << " FAIL: " << e.what() << std::endl;
    }
    catch (std::logic_error& e)
    {
        std::cerr << test_name << " FAIL: " << e.what() << std::endl;
    }
}


void test_mean() {
    ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
    AssertEq(v1.mean(), 1.125);
}

void test_mean_short() {
    ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
    AssertEq(v1.mean(1, 2), 4.0);
}

void test_median() {
    ExtArray<double> v1{ 4.5, 0.7, 10.8, 2.6, -3.5 };
    AssertEq(v1.median(), 2.6);
}

void test_mode() {
    ExtArray<int> v1{ 4, 2, 7, 2, 5, -5, 0, 5, 5 };
    auto mode_result = v1.mode();
    std::ostringstream oss;
    oss << "(" << mode_result.first << ", " << mode_result.second << ")";
    AssertEq(oss.str(), "(5, 3)");
}

void test_checkSum() {
    ExtArray<int> v1{ 1, 1, 1, 0, 0, 0, 0, 1 };
    AssertEq(v1.checkSum(), 4);
}


// Tests for empty arrays
void test_mean_empty() {
    ExtArray<int> v1{}; 
    AssertEq(v1.mean(), 0);
}

void test_median_empty() {
    ExtArray<double> v1{}; 
    AssertEq(v1.median(), 0);
}

void test_mode_empty() {
    ExtArray<int> v1{}; 
    auto mode_result = v1.mode();
    std::ostringstream oss;
    oss << "(" << mode_result.first << ", " << mode_result.second << ")";
    AssertEq(oss.str(), "(0, 0)");
}


void runAllTests(){
    RunOneTest(test_mean, "test_mean");
    RunOneTest(test_mean_short, "test_mean_short");
    RunOneTest(test_median, "test_median");
    RunOneTest(test_mode, "test_mode");
    RunOneTest(test_checkSum, "test_checkSum");

    // Tests for empty arrays
    std::cout << std::endl;
    RunOneTest(test_mean_empty, "test_mean_empty");
    RunOneTest(test_median_empty, "test_median_empty");
    RunOneTest(test_mode_empty, "test_mode_empty");
}

/*
// void test_mean() {
//     ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
//     assert(v1.mean() == 1.125);
//     std::cout << "Mean test OK" << std::endl;
// }

// void test_median() {
//     ExtArray<double> v2{ 4.5, 0.7, 10.8, 2.6, -3.5 };
//     assert(v2.median() == 2.6);
//     std::cout << "Median test OK" << std::endl;
// }

// void test_mode() {
//     ExtArray<int> v1{ 4, 2, 7, 2, 5, -5, 0, 5, 5 };
//     assert(v1.mode() == std::pair(5, 3));
//     std::cout << "Mode test OK" << std::endl;
// }
*/