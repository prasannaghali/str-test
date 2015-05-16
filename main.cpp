#include <iostream>
#include "str.h"

int main() {
	Str s1{"abc"}, s2{"xyz"}, s3;
	s3 = s1+s2;
	std::cout << s3 << std::endl;
	
	s1 += s3;
	std::cout << s1 << std::endl;
	
	Str s4{'m','n','o','p'};
	std::cout << s4 << std::endl;
}
