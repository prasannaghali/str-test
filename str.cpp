#include "str.h"

Str::Str() : len(0), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	ptr[0] = '\0';
}

Str::Str(char const* rhs) : len(std::strlen(rhs)), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	std::strcpy(ptr, rhs);
}

Str::Str(Str const& rhs) : len(rhs.len), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	std::strcpy(ptr, rhs.ptr);
}

Str::Str(std::initializer_list<char> rhs) : len(rhs.size()), ptr(new value_type [len+1]) {
PRINT_STR_FUNC(std::cout);
	char* tmp_ptr{ptr};
	for(auto elem : rhs) {
		*tmp_ptr++ = elem;
	}
	*tmp_ptr = '\0';
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

Str operator+(Str const& lhs, Str const& rhs) {
	Str sum{lhs};
	return sum+=rhs;
}

Str operator+(Str const& lhs, char const* rhs) {
	Str sum{lhs};
	return sum+=rhs;
}

Str operator+(char const* lhs, Str const& rhs) {
	Str sum{lhs};
	return sum+=rhs;
}
