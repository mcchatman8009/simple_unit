# Simple Unit

## Overview
A simple C unit test library (header only) that enables projects to write quick test executables.


## C Example
```C
#include "simple_unit.h"

int main() {
    describe_suite("Basic test suite", {

        unit_test("Test basic assertions", {
            assert_eq(1, 1);
            assert_not_eq(2, 1);
            assert_true(1);
            assert_true("Some value");
        });

        unit_test("Test float comparisons", {
            assert_float_eq(1.001, 1.001);
            assert_float_not_eq(1.021, 1.001);

            assert_float_eq(1.001f, 1.001f);
            assert_float_not_eq(1.021f, 1.001f);
        });

        unit_test("Test string comparisons", {
            assert_str_eq("Hello, World!", "Hello, World!");
            assert_str_not_eq("Hello World!", "Hello, World!");
        });
    });

    return 0;
}
```


