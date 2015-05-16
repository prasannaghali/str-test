/*
An encapsulation of (null-terminated) C-strings ...
Requires C++11 ...
Implemented to understand the work-flow of GitHub ...
*/
#ifndef STR_H
#define STR_H

#include <iostream>	// for std::cout
#include <cstring>	// for strlen, strcpy, strcat
#include <cstdlib> // for size_t
#include <initializer_list>
#include <algorithm> // for std::swap

#if defined(STR_DEBUG)

#if defined(_MSC_VER)
#define PRINT_STR_FUNC(os) (os << __FUNCSIG__ << std::endl)
#elif defined(__GNUC__)
#define PRINT_STR_FUNC(os) (os << __PRETTY_FUNCTION__ << std::endl)
#endif

#else
	
#define PRINT_STR_FUNC(os)

#endif

class Str {
public:
	using size_type = std::size_t;
	using value_type = char;
	using pointer = char*;
	using const_pointer = const char*;
	using reference = char&;
	using const_reference = const char&;
	using iterator = char*;
	using const_iterator = const char*;
	
public:
	Str();
	Str(char const*);
	Str(char const*, size_type n); // copies the first n character from buffer
	Str(Str const&);
	Str(std::initializer_list<char>);
	Str(Str&&);
	~Str();
	
	Str& operator=(char const*);
	Str& operator=(Str const&);
	Str& operator=(Str&&);
	
	Str& operator+=(char const*);
	Str& operator+=(Str const&);
	Str& operator+=(std::initializer_list<char>);
	
	const_reference operator[](size_type) const;
	reference operator[](size_type);
	
	const_pointer c_str() const { return ptr; }
	
	iterator begin() { return ptr; }
	const_iterator begin() const { return ptr; }
	const_iterator cbegin() const { return ptr; }
	
	iterator end() { return ptr+len; }
	const_iterator end() const { return ptr+len; }
	const_iterator cend() const { return ptr+len; }
	
	size_type size() const { return len; }
	size_type length() const { return len; }
	bool empty() const { return len == 0; }
	
private:
	size_type len;
	pointer ptr;
};

std::ostream& operator<<(std::ostream&, Str const&);

#if 0
Str operator+(Str const&, Str const&);
Str operator+(Str const&, Str&&);
Str operator+(Str&&, Str const&);
Str operator+(Str&&, Str&&);
Str operator+(Str const&, char const*);
Str operator+(char const*, Str const&);
Str operator+(Str&&, char const*);
Str operator+(char const*, Str&&);
#else
Str operator+(Str, Str const&);
Str operator+(Str, char const*);
Str operator+(char const*, Str const&);
#endif




#endif
