# constexpr

- 参考

  https://www.learncpp.com/cpp-tutorial/compile-time-constants-constant-expressions-and-constexpr/

  https://www.learncpp.com/cpp-tutorial/constexpr-and-consteval-functions/

  https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/

A `constexpr` variable can only be a compile-time constant.

`Best practice`

`Any variable that should not be modifiable after initialization and whose initializer is known at compile-time should be declared as constexpr.` 

`Any variable that should not be modifiable after initialization and whose initialize is not known at compile-time should be declared as const.`

some types that are not compatible with `constexpr` (including `std::string`, `std::vector`, and other types that use dynamic memory allocation) 