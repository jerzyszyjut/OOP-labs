#include "Prostokat.h"
#include <iostream>

using namespace std;

Prostokat::Prostokat(double a, double b)
	: a(a), b(b)
{
	cout << "Konstruktor Prostokata(" << a << "," << b << ")" << endl;
	sumaObwodow += Obwod();
	cout << "sumaObwodow: " << sumaObwodow << endl;
}
double Prostokat::GetA() const {
	return a;
}
double Prostokat::GetB() const {
	return b;
}
void Prostokat::SetA(double a) {
	sumaObwodow -= Obwod();
	this->a = a;
	sumaObwodow += Obwod();
}
void Prostokat::SetB(double b) {
	sumaObwodow -= Obwod();
	this->b = b;
	sumaObwodow += Obwod();
}
double Prostokat::Obwod() {
	return this->a * 2 + this->b * 2;
}
double Prostokat::Pole() {
	return this->a * this->b;
}
void Prostokat::Wypisz(std::ostream& out) const {
	out << "Prostokat(" << a << ", " << b << ")";
}
Prostokat::~Prostokat() {
	cout << "Destruktor Prostokata(" << a << "," << b << ")" << endl;
	sumaObwodow -= Obwod();
	cout << "sumaObwodow: " << sumaObwodow << endl;
}
