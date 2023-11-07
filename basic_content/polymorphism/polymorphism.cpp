//
// Created by yaoxp on 2023/10/20.
//
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Base {
public:
    virtual void print() {
        cout << "Base print" << endl;
    }
};

class Foo: public Base {
public:
    virtual void print() override {
        cout << "Fool1 print" << endl;
    }
};

void test1(Base *b) {
    b->print();
}

void test2(Base b) {
    b.print();
}

void test3(Base &b) {
    b.print();
}

int main() {
    Foo *f1 = new Foo;
    test1(f1);

    Foo f2;
    test2(f2);

    Foo f3;
    test3(f3);
}