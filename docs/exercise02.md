### Exercise 1. Explain what do you learn from following code.

```c++
#include <stdio.h>
#include <string.h>

#include <string>

std::string to_string1(double x) {
	char buffer[30];
	sprintf( buffer, "x = %6.2f", x);
	return buffer;
}


char* to_string2(double x) {
	char buffer[30];
	sprintf( buffer, "x = %6.2f", x);
	return buffer;
}

int main() {
    std::string str1 = to_string1(31.56);
	printf( "str1: %s\n", str1.c_str());
    char* str2;
    str2 = to_string2(34.56);
	printf( "str2: %s\n", str2);
    return 0;
}



```
