#include "Library.h"
#include <string>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Library& library)
{
    os << "Library size: " << library.size << std::endl;
    for (int i = 0; i < library.size; i++)
    {
		os << library.books[i] << std::endl;
	}
    return os;
}

void demonstrate_library()
{
    Library e;
    std::cout << "e: " << e << std::endl;
    Library l1 = { {"A", "B"},
    {"C", "D"},
    {"E", "F"} };
    std::cout << "l1: " << l1 << std::endl;
    Library l2(2);
    std::cout << "l2: " << l2 << std::endl;
    l2[0] = { "G", "H" };
    l2[1] = { "I", "J" };
    std::cout << "l2: " << l2 << std::endl;
    e = std::move(l2);
    std::cout << "e: " << e << " l2: " << l2 << std::endl;
    l1[0] = std::move(e[1]);
    std::cout << "l1: " << l1 << " e: " << e << std::endl;
}

Library::Library(): size(0), books(nullptr)
{
}

Library::Library(const std::initializer_list<Book>& books): size(books.size()), books(new Book[books.size()])
{
    size_t i = 0;
    for (Book book : books)
    {
		this->books[i] = book;
        i++;
	}
}

Library::Library(std::size_t size)
{
    this->size = size;
	books = new Book[size];
    for (int i = 0; i < size; i++) books[i] = Book();
}

Library::Library(const Library& orig) : size(orig.size), books(new Book[orig.size])
{
	for (int i = 0; i < orig.size; i++)
    { 
		books[i] = orig.books[i];
	}
}

Library::Library(Library&& orig)
{
    size = orig.size;
    books = orig.books;
    orig.size = 0;
    orig.books = nullptr;
}

Library& Library::operator=(Library&& right)
{
    std::swap(books, right.books);
    std::swap(size, right.size);
    return *this;
}

Library& Library::operator=(const Library& right)
{
    Library tmp = right;
    std::swap(size, tmp.size);
    std::swap(books, tmp.books);
    return *this;
}

Book& Library::operator[](std::size_t index)
{
    return books[index];
}

const Book& Library::operator[](std::size_t index) const
{
    return books[index];
}

std::size_t Library::GetSize() const
{
    return size;
}

Library::~Library()
{
    if (books != nullptr)
    {
		delete[] books;
	}
}
