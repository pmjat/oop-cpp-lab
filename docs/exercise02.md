### Exercise 1. Explain what do you learn from following code.

```c++
#include <iostream>
#include <string>

std::string to_string1(double x) {
    char buffer[30];
    sprintf( buffer, "x = %6.2lf", x);
    return buffer;
}

char* to_string2(double x) {
    char buffer[30];
    sprintf( buffer, "x = %6.2lf", x);
    return buffer;
}

char* to_string3(double x) {
    char* buffer = (char *) malloc(  30 * sizeof (char) );
    sprintf( buffer, "x = %6.2lf", x);
    return buffer;
}

int main() {
    std::string str1 = to_string1(34.56);
    printf( "str1: %s\n", str1.c_str());
    char* str2;
    str2 = to_string2(34.56);
    printf( "str2: %s\n", str2);
    char* str3;
    str3 = to_string3(34.56);
    printf( "str3: %s\n", str3);
    return 0;
}

```
