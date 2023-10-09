# const
A variable whose value can not be changed is called constant variable.

## const 的分类
### Compile-time const
is a constant whose value is known at compile-time.

### Runtime const
Any constant variable that is initialized with a non-constant expression is a runtime constant.
`Runtime Constants`  are constants whose value are not knows until runtime.

`编译器决定常量是编译时常量还是运行时常量。`

## const 的用法
### 修饰变量
语法: const 数据类型 常量名 = 常量值
```c++
const int month = 12
```

* const variables must be initialized when you define them,
and then that value can not be changed by assignment

 
```c++
    int i = 10;
    cout << "input your age: ";
    std::cin >> i;
    // const variable can be initialized from other variable(include non-const ones);
    const int constAge = i;
    cout << "constant age: " << constAge << endl;
```

* **<mark>Note</mark>: const variable can be initialized from other variable(including non-const variable)**

## 修饰函数参数(Const function parameter)
```c++
void testFunctionConstParameter(const int& x) {
    // x++; // error
    cout << "x: " << x << endl;
}
```
* **<mark>Note:</mark> Don't use const when passing by value**

When arguments are passed by value, we generally don't care
if the function changes the value of parameter
(since it's just a copy that will be destroyed at the end of the function anyway).


## 修饰指针

- 指针常量：指针指向固定的位置(A const pointer is a pointer whose address can not be changed after initalization)
- 常量指针：指向常量的指针(Pointer to const value)
```c++
void testConstPointer() {
int a = 10;
const int b = 10;

    int *const p1 = &a; // 指针常量
    const int *p2 = &b; // 常量指针
}
```

## 修饰类成员函数：常函数
- 成员函数后加const后称这个函数为常函数
- 常函数内不可以修改成员属性
- 成员属性声明时加关键字mutable后，在常函数中依然可以修改

```c++
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
```

## 修饰类对象：常对象
- 声明对象前加const称该对象为常对象
- 常对象只能调用常函数

```c++
class Person {};
const Person person;
```

## const 和 #define 的区别
1. 编译器处理方式不同
   * define宏是在预处理阶段展开
   * const常量是编译运行阶段使用
2. 类型和安全检查不同
   * define宏没有类型，不做任务类型检查，仅仅是展开。
   * const常量有具体的类型，在编译阶段会执行类型检查。

## 参考
- https://www.learncpp.com/cpp-tutorial/const-variables-and-symbolic-constants/