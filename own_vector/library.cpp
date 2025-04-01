#include "library.hpp"
#include <iostream>

//namespace template_library {
    // Здесь ничего не нужно писать
//}
int main() {

    //Test PushBackAndAccess
    std::cout << "PushBackAndAccess" << "\n";
    Vector<int> vec1;

    if (vec1.size() == 0) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    if (vec1.size() == 3) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }
    std::cout << vec1[0] << "\n" << vec1[1] << "\n" << vec1[2] << "\n";

    //Test InitializerList
    std::cout << "InitializerList" << "\n";
    Vector<int> vec2 = { 1, 2, 3, 4, 5 };

    if (vec2.size() == 5) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }

    int test = 1;
    for (size_t i = 0; i < vec2.size(); ++i) {
        if (vec2[i] != static_cast<int>(i + 1)) {
            test = 0;
        }
    }
    if (test == 1) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }

    //Test AtMethodThrowsOutOfRange
    std::cout << "AtMethodThrowsOutOfRange" << "\n";
    Vector<int> vec3 = { 1, 2, 3 };


    // Проверка, что при корректном индексе исключение НЕ бросается
    try {
        vec3.at(2);
        std::cout << "True\n";
    }
    catch (const std::out_of_range&) {
        std::cout << "False\n";
        return 1;
    }
    catch (...) {
        std::cout << "False\n";
        return 1;
    }

    // Проверка, что при выходе за границы бросается std::out_of_range
    try {
        vec3.at(3);
        std::cout << "False\n";
        return 1;
    }
    catch (const std::out_of_range&) {
        std::cout << "True\n";
    }
    catch (...) {
        std::cerr << "False\n";
        return 1;
    }

    //Test ResizeReserveClear
    std::cout << "ResizeReserveClear" << "\n";
    Vector<int> vec4;

    vec4.resize(5, 42);
    if (vec4.size() == 5) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }
    int test4 = 1;
    for (size_t i = 0; i < vec4.size(); ++i) {
        if (vec4[i] != 42) {
            test4 = 0;
        }
    }
    if (test4 == 1) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }
    size_t oldCapacity = vec4.capacity();
    vec4.reserve(oldCapacity + 10);
    if (vec4.capacity() < oldCapacity + 10) {
        std::cout << "False" << "\n";
    }
    else {
        std::cout << "True" << "\n";
    }
    vec4.clear();
    if (vec4.size() == 0) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << " False" << "\n";
    }

    //Test CopyConstructorAndAssignment
    std::cout << "CopyConstructorAndAssignment" << "\n";
    Vector<int> vec5 = { 100, 200, 300 };
    Vector<int> copy(vec5);
    if (copy.size() == vec5.size()) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }
    int test51 = 1;
    for (size_t i = 0; i < vec5.size(); ++i) {
        if (copy[i] != vec5[i]) {
            test51 = 0;
        }
    }
    if (test51 == 0) {
        std::cout << "False" << "\n";
    }
    else {
        std::cout << "True" << "\n";
    }
    Vector<int> assign;
    assign = vec5;
    if (assign.size() == vec5.size()) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << "False" << "\n";
    }
    int test52 = 1;
    for (size_t i = 0; i < vec5.size(); ++i) {
        if (assign[i] != vec5[i]) {
            test52 = 0;
        }
    }
    if (test52 == 0) {
        std::cout << "False" << "\n";
    }
    else {
        std::cout << "True" << "\n";
    }

    //Test PopBack
    std::cout << "PopBack" << "\n";
    Vector<int> vec6 = { 10, 20, 30 };
    if (vec6.size() == 3) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << " False" << "\n";
    }
    vec6.pop_back();
    if (vec6.size() == 2) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << " False" << "\n";
    }
    if (vec6[1] == 20) {
        std::cout << "True" << "\n";
    }
    else {
        std::cout << " False" << "\n";
    }
    vec6.clear();
    try {
        vec6.pop_back();
        std::cout << "False\n";
        return 1;
    }
    catch (const std::out_of_range&) {
        std::cout << "True\n";
    }
    catch (...) {
        std::cerr << "False\n";
        return 1;
    }
}
