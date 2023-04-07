#include "Book.h"
#include <string>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.author << " " << book.title;
	return os;
}

Book::Book(): author(""), title("")
{
}

Book::Book(const std::string& author, const std::string& title): author(author), title(title)
{
}

Book::Book(std::string&& author, std::string&& title) : author(author), title(title)
{
}

Book::Book(const Book& book): author(book.author), title(book.title)
{
}

Book::Book(Book&& book): author(std::move(book.author)), title(std::move(book.title))
{
}

Book& Book::operator=(const Book& book)
{
	Book tmp = book;
	std::swap(author, tmp.author);
	std::swap(title, tmp.title);
	return *this;
}

Book& Book::operator=(Book&& book)
{
	author = std::move(book.author);
	title = std::move(book.title);
	return *this;
}

std::string Book::GetAuthor() const
{
	return author;
}

std::string Book::GetTitle() const
{
	return title;
}

void Book::SetAuthor(const std::string& author)
{
	this->author = author;
}

void Book::SetAuthor(std::string&& author)
{
	this->author = author;
}

void Book::SetTitle(const std::string& title)
{
	this->title = title;
}

void Book::SetTitle(std::string&& title)
{
	this->title = title;
}

void demonstrate_book() {
	std::string a = "A", t = "B";
	Book e;
	std::cout << "e: " << e << std::endl;
	Book b1 = { a, t };
	std::cout << "b1: " << b1 << std::endl;
	Book b2 = { "C","D" };
	std::cout << "b2: " << b2 << std::endl;
	Book b3 = b1;
	std::cout << "b3: " << b3 << " b1: " << b1 << std::endl;
	e = std::move(b2);
	std::cout << "e: " << e << " b2:" << b2 << std::endl;
	e.SetAuthor("E");
	std::cout << "e: " << e << std::endl;
	e.SetTitle("F");
	std::cout << "e: " << e << std::endl;
}
