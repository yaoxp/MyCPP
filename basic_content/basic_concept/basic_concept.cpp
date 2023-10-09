//
// Created by yaoxp on 2023/9/8.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int globalVariable1 = 200;
int globalVariable2 = 200;
static int staticVariable1 = 300;

const int constVariable1 = 100;
const string constString1 = "asfdfasfsfasfasfwgvdvsfadsfasfewfsadafasfsdfsdfasfewfewgfgbdsfbytbt";

class Test {
public:
    int m;
    int n;
    Test(int i, int j): m(i), n(j) {}
    void address() {
        cout << "Test.m address: " << &m << endl;
        cout << "Test.n address: " << &n << endl;
    }
};

void test() {
    int j = 100;
    int k = 200;
    cout << "test() j is in stack area: " << &j << endl;
    cout << "test() k is in stack area: " << &k << endl;
    cout << "##########################\n" << endl;

    cout << "动态分配的内存在堆区" << endl;
    Test *t1 = new Test(100, 101);
    Test *t2 = new Test(1, 2);
    cout << "t1 address: " << t1 << endl;
    t1->address();
    cout << "t2 address: " << t2 << endl;
    t2->address();
    cout << "##########################\n" << endl;

    cout << "全局变量和静态变量在全局区" << endl;
    cout << "globalVariable1 address: " << &globalVariable1 << endl;
    cout << "globalVariable2 address: " << &globalVariable2 << endl;
    cout << "staticVariable1 address: " << &staticVariable1 << endl;
    cout << "##########################\n" << endl;

    const static int constStaticVariable = 9;
    cout << "常量区" << endl;
    cout << "constVariable1 address: " << &constVariable1 << endl;
    cout << "constString1 address: " << &constString1 << endl;
    cout << "constStaticVariable address: " << &constStaticVariable << endl;
    cout << "##########################\n" << endl;
}

int main() {
    int i = 10;         // stack
    char s[] = "abc";   // stack
    const int j = 20;   // stack
    cout << "栈内存从高地址到低地址" << endl;
    cout << "main() int i = 0 is in stack area: " << &i << endl;
    cout << "main() char s[] = \"abc\" is in stack area: " << (void *)s << endl;
    cout << "main() const int j = 20 is in stack area: " << (void *)(&j) << endl;
    test();

    cout << "函数在代码区" << endl;
    cout << "test() address: " << (void *)test << endl;
    cout << "##########################\n" << endl;
    return 0;
}