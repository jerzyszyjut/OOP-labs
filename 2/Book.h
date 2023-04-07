#pragma once
#include <string>
#include <iostream>

class Book
{
private:
	std::string author, title;
	friend std::ostream& operator<<(std::ostream& os, const Book& book);
public:
	Book();
	Book(const std::string& author, const std::string& title);
	Book(std::string&& author, std::string&& title);
	Book(const Book& book);
	Book(Book&& book);
	Book& operator=(const Book& book);
	Book& operator=(Book&& book);
	std::string GetAuthor() const;
	std::string GetTitle() const;
	void SetAuthor(const std::string& author);
	void SetAuthor(std::string&& author);
	void SetTitle(const std::string& title);
	void SetTitle(std::string&& title);
};

void demonstrate_book();
