#include <iostream>
#include "str.h"

Str foo() {
	//return std::move(Str("foo"));
	return Str("foo");
}

Str goo() {
	//return std::move(Str("goo"));
	return Str("goo");
}

int main() {
	Str s1{'s','1'}, s2{'s','2'}, s3;
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;
	std::cout << "--------------test1-------------\n";
	s3 = s1+s2;
	std::cout << "s3: " << s3 << std::endl;
	std::cout << "--------------test2-------------\n";
	s3 = s1+foo();
	std::cout << "s3: " << s3 << std::endl;
	std::cout << "--------------test3-------------\n";
	s3 = foo()+s2;
	std::cout << "s3: " << s3 << std::endl;
	std::cout << "--------------test4-------------\n";
	s3 = foo()+goo();
	std::cout << "s3: " << s3 << std::endl;
	std::cout << "--------------endtest-------------\n";
}
