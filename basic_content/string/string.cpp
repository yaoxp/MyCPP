//
// Created by yaoxp on 2023/9/15.
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void testString() {
    auto c1 = "01234567890123456789";
    string s1 = c1;
    int i = 10;
    cout << "c1 address: " << (void *)(&c1) << endl;
    cout << "c1 string address: " << (void *)c1 << endl;
    cout << "s1 address: " << (void *)(&s1) << endl;
    cout << "s1.data address: " << (void *)(s1.data()) << endl;
    cout << "i address: " << (void *)(&i) << endl;
    cout << "c1 len: " << std::strlen(c1) << endl;
    cout << "data len: " << std::strlen(s1.data()) << endl;
}

void testCin() {
    cout << "Enter your full name: ";
    string name{};
    cin >> name; // this won't work as expected since std::cin breaks on whitespace

    cout << "Enter your favorite color: ";
    string color{};
    cin >> color;

    cout << "Your name is " << name << " and your favorite color is " << color << endl;
}

void testGetLine() {
    cout << "Enter your full name: ";
    string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    cout << "Enter your favourite color: ";
    string color{};
    std::getline(std::cin >> std::ws, color);

    cout << "Your name is " << name << " and your favorite color is " << color << endl;
}

void testGetLine2() {
    cout << "pick 1 or 2: ";
    int choice{};
    cin >> choice;

    cout << "Now enter your name: ";
    string name{};
    std::getline(cin, name);
    cout << "Hello, " << name << ", you picked " << choice << endl;
}

int main() {
    //testCin();
    //testGetLine();
    testGetLine2();
    return 0;
}