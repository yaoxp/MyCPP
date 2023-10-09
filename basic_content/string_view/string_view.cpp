//
// Created by yaoxp on 2023/8/17.
//
#include <iostream>

using std::cout;
using std::endl;

std::string_view getView() {
    std::string s = "abcd";
    return std::string_view{s};
}

void printString(std::string str) {
    cout << str << endl;
    cout << "printString: str address: " << (void *)(str.data()) << endl;
}

void testPrintString() {
    std::string_view sv{"hello world!"};
    //printString(sv); // compile error: won't implicitly convert string_view to string
    cout << "testPrintString: sv address: " << (void *)(sv.data()) << endl;
    std::string s{sv};
    cout << "testPrintString: s address: " << (void *)(s.data()) << endl;
    printString(s);
    std::string s1 = static_cast<std::string>(sv);
    cout << "testPrintString: s1 address: " << (void *)(s1.data()) << endl;
    printString(s1);
}

int main() {
    testPrintString();

    const char *c1 = "hello world";
    std::string_view sv_c1 = c1;
    std::string s_c1 = c1;
    cout << "const char *c1: " << c1 << endl;
    cout << "c1 address: " << static_cast<const void *>(c1) << endl;
    cout << "sv_c1 address: " << static_cast<const void *>(sv_c1.data()) << endl;
    cout << "s_c1 address: " << static_cast<const void *>(s_c1.data()) << endl;
    cout << endl;

    std::string s1 = "just test";
    std::string s2 = s1;
    std::string_view sv_s1 = s1;
    cout << "std::string s1: " << s1 << endl;
    cout << "s1 address: " << static_cast<const void *>(s1.data()) << endl;
    cout << "s2 address: " << static_cast<const void *>(s2.data()) << endl;
    cout << "sv_s1 address: " << static_cast<const void *>(sv_s1.data()) << endl;
    cout << "std::string_view sv_s1 length: " << sv_s1.length() << endl;
    cout << endl;

    std::string s3 = "hello world";
    std::string_view sv_s3(s3.data() + 3, 5);
    cout << "std::string s3: " << s3 << endl;
    cout << "std::string s3 address: " << static_cast<const void *>(s3.data()) << endl;
    cout << "std::string_view sv_s3: " << sv_s3 << endl;
    cout << "std::string_view sv_s3 address: " << static_cast<const void *>(sv_s3.data()) << endl;
    sv_s3.remove_prefix(1);
    cout << "sv_s3.remove_prefix(1)" << endl;
    cout << "std::string s3: " << s3 << endl;
    cout << "std::string_view sv_s3: " << sv_s3 << endl;

    auto tmp_sv = getView();
    cout << "getView: " << tmp_sv << endl;
}