2-3pm tue hill center 246 TA hours

-Wall -Werr -fsanatize=address
Show all warnings, make all warnings errors, -fsanitize

#### Enums
`enums` are basically aliases for constants to make using them more clear:
```c
enum days = {mon, tue, wed, thu, fri, dat, sun};
enum myDay = mon;
```
You can assign values to the `enum` types manually and ones not assigned a value will take the previous value +1. `enums` can share values (i.e. multiple aliases).

#### Adresses
The address of a variable is denoted by prepending an `&`. For example:
```c
int x = 5;
printf("The address of x is: %d", &x);
```

Note that addresses are `long` integers that are the maximum word size of the computer. For modern computers this is 64 bits or 8 bytes.

#### Boolean values
In C, 0 is considered false and anything else is considered true. Logical expressions take this into account. For example, the following sets `y` to 0:

```c
int x = 50;
int y = !x;
```

#### Function Prototype
If a function is declared without a body (i.e. just a null statement `;`), it is called a *function prototype*. We can refer to it in other expressions and define it later.

#### Basic I/O
Included in `<stdio.h>` is the `printf` function and the `scanf` function.
- `printf("This is an integer: %d, x");`
- `scanf("%d", &y");`

The `scanf` function reads a variable via the instructions given in the string into some given address (denoted with the `&`).

#### Output
`%d` is an integer type, `%f` is a float, `%f.n` is a float to the nth decimal place.
