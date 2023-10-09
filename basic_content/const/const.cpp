//
// Created by yaoxp on 2023/9/12.
//
#include <iostream>

using std::cout;
using std::endl;
using std::string;



class Student {
public:
    string name;
    mutable int age;
    Student(std::string_view name, int age): name(name), age(age) {}
    void test(int n) const {
        age = n; // Cannot assign to non-static data member within const member function 'test'
        cout << "age: " << age << endl;
    }
};

void testConstClassFunction() {
    Student s("Abc", 10);
    s.test(11);
}

void testConstVariable() {
    const double gravity = 9.8; // const variables must be initialized
    // gravity = 9.9; // error: const variables can not be changed
    cout << "gravity: " << gravity << endl;

    int i = 10;
    cout << "input your age: ";
    std::cin >> i;
    // const variable can be initialized from other variable(include non-const ones);
    const int constAge = i;
    cout << "constant age: " << constAge << endl;
}

void testFunctionConstParameter(const int& x) {
    // x++; // error
    cout << "x: " << x << endl;
}

void testConstPointer() {
    int a = 10;
    const int b = 10;

    int *const p1 = &a; // 指针常量
    const int *p2 = &b; // 常量指针
    p2 = &a;
    (*p1)++;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

int main() {
    testConstVariable();
    testFunctionConstParameter(5);
    testConstPointer();
    testConstClassFunction();
}