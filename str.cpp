#include "str.h"

Str::Str() : len(0), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	ptr[0] = '\0';
}

Str::Str(char const* rhs) : len(std::strlen(rhs)), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	std::copy(rhs, rhs+len+1, ptr);
}

// copies the first n characters from buffer
Str::Str(char const* rhs, size_type n) : len(n), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	std::copy(rhs, rhs+n, ptr);
	ptr[n] = '\0';
}

Str::Str(Str const& rhs) : len(rhs.len), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	std::copy(rhs.ptr, rhs.ptr+len+1, ptr);
}

Str::Str(std::initializer_list<char> rhs) : len(rhs.size()), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
#if 1
	std::copy(rhs.begin(), rhs.end(), ptr);
	ptr[len] = '\0';
#else
	char* tmp_ptr{ptr};
	for(auto elem : rhs) {
		*tmp_ptr++ = elem;
	}
	*tmp_ptr = '\0';
#endif
}

Str::Str(Str&& rhs) : len(rhs.len), ptr(rhs.ptr) {
PRINT_STR_FUNC(std::cout);
	rhs.ptr = nullptr;
}

Str::~Str() {
PRINT_STR_FUNC(std::cout);
	delete [] ptr;
}

Str& Str::operator=(Str const& rhs) {
PRINT_STR_FUNC(std::cout);
	size_type tmp_len{rhs.len};
	pointer tmp_ptr{new value_type [tmp_len+1]};
	std::strcpy(tmp_ptr, rhs.ptr);
	
	len = tmp_len;
	delete [] ptr;
	ptr = tmp_ptr;
	
	return *this;
}

Str& Str::operator=(char const* rhs) {
PRINT_STR_FUNC(std::cout);
	size_type tmp_len{std::strlen(rhs)};
	pointer tmp_ptr{new value_type [tmp_len+1]};
	std::strcpy(tmp_ptr, rhs);
	
	len = tmp_len;
	delete [] ptr;
	ptr = tmp_ptr;
	
	return *this;
}

Str& Str::operator=(Str&& rhs) {
PRINT_STR_FUNC(std::cout);
	std::swap(len, rhs.len);
	std::swap(ptr, rhs.ptr);
	return *this;
}

Str& Str::operator+=(Str const& rhs) {
PRINT_STR_FUNC(std::cout);
	size_type tmp_len{len+rhs.len};
	pointer tmp_ptr{new value_type [tmp_len+1]};
	std::strcpy(tmp_ptr, ptr);
	std::strcat(tmp_ptr, rhs.ptr);
	
	len = tmp_len;
	delete [] ptr;
	ptr = tmp_ptr;
	
	return *this;
}

Str& Str::operator+=(char const* rhs) {
PRINT_STR_FUNC(std::cout);
	size_type tmp_len{len+std::strlen(rhs)};
	pointer tmp_ptr{new value_type [tmp_len+1]};
	std::strcpy(tmp_ptr, ptr);
	std::strcat(tmp_ptr, rhs);
	
	len = tmp_len;
	delete [] ptr;
	ptr = tmp_ptr;
	
	return *this;
}

Str& Str::operator+=(std::initializer_list<char> rhs) {
	size_type tmp_len{len+rhs.size()};
	pointer tmp_ptr{new value_type [tmp_len+1]};
	
	std::strcpy(tmp_ptr, ptr);
	pointer tmp_ptr2{tmp_ptr};
	for(auto elem : rhs) *tmp_ptr2++ = elem;
	*tmp_ptr2 = '\0';
	
	len = tmp_len;
	delete [] ptr;
	ptr = tmp_ptr;
	
	return *this;
}

Str::const_reference Str::operator[](Str::size_type idx) const {
	return ptr[idx];
}

Str::reference Str::operator[](Str::size_type idx) {
	return const_cast<reference>(static_cast<Str const&>(*this)[idx]);
}

std::ostream& operator<<(std::ostream& os, Str const& rhs) {
	os << rhs.c_str();
	return os;
}

/*
Str concatenation is non-commutative and requires the allocation of
memory to hold the concatenated string. Therefore, there are no
optimizations available when the right operand is rvalue reference.
*/
Str operator+(Str lhs, Str const& rhs) {
PRINT_STR_FUNC(std::cout);
	return std::move(lhs+=rhs);
}

/*
Similarly, the following two overloads will take care of both lvalue
and rvalue reference parameters
*/
Str operator+(Str lhs, char const* rhs) {
PRINT_STR_FUNC(std::cout);
	return std::move(lhs+=rhs);
}

Str operator+(char const* lhs, Str const& rhs) {
PRINT_STR_FUNC(std::cout);
	return std::move(Str(lhs)+=rhs);
}
