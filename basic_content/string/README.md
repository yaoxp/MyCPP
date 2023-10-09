# string

[参考1](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/)

## Use `std::getline()` to input text

use `std::cin`
```c++
    cout << "Enter your full name: ";
    string name{};
    cin >> name; // this won't work as expected since std::cin breaks on whitespace

    cout << "Enter your favorite color: ";
    string color{};
    cin >> color;

    cout << "Your name is " << name << " and your favorite color is " << color << endl;
```

Here's the result from a sample run of this program:
```c++
Enter your full name: yao xinpan
Enter your favorite color: Your name is yao and your favorite color is xinpan
```

It turns out that when using `operator>>` to extract a string from `std::cin`,
`operator>>` only returns characters up to the first whitespace it encounters.
Any other characters are left inside `std::cin`, waiting for the next extraction.
```c++
void testGetLine() {
    cout << "Enter your full name: ";
    string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    cout << "Enter your favourite color: ";
    string color{};
    std::getline(std::cin >> std::ws, color);

    cout << "Your name is " << name << " and your favorite color is " << color << endl;
}
```

**坑**
```c++
    cout << "pick 1 or 2: ";
    int choice{};
    cin >> choice;

    cout << "Now enter your name: ";
    string name{};
    std::getline(cin, name);
    cout << "Hello, " << name << ", you picked " << choice << endl;
```
输出：
```c++
pick 1 or 2: 2
Now enter your name: Hello, , you picked 2
```


