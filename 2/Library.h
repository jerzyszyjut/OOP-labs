#pragma once
#include "Book.h"
#include <initializer_list>

class Library
{
private:
	int size;
	Book* books;

	friend std::ostream& operator<<(std::ostream& os, const Library& library);
public:
	Library();
	Library(const std::initializer_list<Book>& books);
	Library(std::size_t size);
	Library(const Library& orig);
	Library(Library&& orig);
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
	Book& operator[](std::size_t index);
	const Book& operator[](std::size_t index) const;
	std::size_t GetSize() const;
	~Library();
};

void demonstrate_library();
