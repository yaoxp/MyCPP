//
// Created by yaoxp on 2023/9/13.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person {
public:
    enum class SexType {
      Boy,
      GIRL
    };
    Person(const char *name, int age, SexType sex) : age(age), sex(sex) {
        this->name = new char[std::strlen(name) + 1];
        std::strcpy(this->name, name);
    }

    int getAge() const {
        return this->age;
    }

    Person &addAge(int a) {
        age += a;
        return *this;
    }

    ~Person() {
        delete[] name;
    }

private:
    int age;
    char *name;
    SexType sex;
};


int main() {
    Person p("zhangsan", 20, Person::SexType::Boy);
    cout << p.getAge() << endl;
    cout << p.addAge(10).getAge() << endl;
    return 0;
}