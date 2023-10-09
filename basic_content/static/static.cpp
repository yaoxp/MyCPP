//
// Created by yaoxp on 2023/9/4.
//
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Singleton {
public:
    static Singleton &sharedInstance() {
        static Singleton Instance("test");
        return Instance;
    };

    explicit Singleton(std::string name): name(name) {
        std::cout << "construct: " << name << std::endl;
    }
    ~Singleton() {
        std::cout << "destruct: " << name << std::endl;
    };


    std::string name;
    //static int age = 0;
    static int age;
};

Singleton s1("s1");
Singleton s2("s2");

int main() {
    Singleton::age = 0;

    cout << "in main" << endl;
    {
        cout << "first time to use static: " << endl;
        Singleton::sharedInstance();
        cout << "end first use ......" << endl;
    }

    {
        cout << "second time to use static: " << endl;
        Singleton::sharedInstance();
        cout << "end second use ......" << endl;
    }

    {
        cout << "create a static variable a: ";
        static Singleton a("a");
        cout << "out of static variable a scope" << endl;
    }
    cout << "out main" << endl;
}