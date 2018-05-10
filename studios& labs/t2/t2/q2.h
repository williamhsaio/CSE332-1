#pragma once
#include <iostream>
// actually written for exercise 3

template <typename ITERATOR> 
size_t exercise2(ITERATOR i, ITERATOR j) {
	std::cout << "Exercise 3 version of size function called" << std::endl;
	size_t size = 0;
	for (ITERATOR k = i; k != j; ++k) {
		++size;
	}
	return size;
}

template <typename ITERATOR>
size_t exercise2(ITERATOR  *i, ITERATOR  *j) {
	std::cout << "Exercise 2 version of size function called" << std::endl;
	
	
	return j-i;
}

template <> size_t exercise2(int * i, int * j) {
	std::cout << "Exercise 4 version of size function called" << std::endl;
	for (int * k = i; k != j; ++k) {
		std::cout << *k << " ";

	}
	std::cout << std::endl;
	return size_t(j - i);
}

template <> size_t exercise2(char * i, char * j) {
	std::cout << "Exercise 4 version of size function called" << std::endl;
	for (char * k = i; k != j; ++k) {
		std::cout << *k << " ";

	}
	std::cout << std::endl;
	return size_t(j - i);
}
