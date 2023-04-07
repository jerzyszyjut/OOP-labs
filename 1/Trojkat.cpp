#include "Trojkat.h"
#include <iostream>

using namespace std;

Trojkat::Trojkat(double a, double b, double c): a(a), b(b), c(c) {
	cout << "Konstruktor Trojkata(" << a << "," << b << ',' << c << ")" << endl;
	sumaObwodow += Obwod();
	cout << "sumaObwodow: " << sumaObwodow << endl;
}

double Trojkat::GetA() const {
	return a;
}

void Trojkat::SetA(double a) {
	sumaObwodow -= Obwod();
	this->a = a;
	sumaObwodow += Obwod();
}

double Trojkat::GetB() const {
	return b;
}

void Trojkat::SetB(double b) {
	sumaObwodow -= Obwod();
	this->b = b;
	sumaObwodow += Obwod();
}

double Trojkat::GetC() const {
	return c;
}

void Trojkat::SetC(double c) {
	sumaObwodow -= Obwod();
	this->c = c;
	sumaObwodow += Obwod();
}

double Trojkat::Obwod() {
	return this->a + this->b + this->c;
}

double Trojkat::Pole() {
	double p = Obwod() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Trojkat::Wypisz(std::ostream& out) const {
	out << "Trojkat(" << a << "," << b << "," << c << ")";
}

Trojkat::~Trojkat() {
	cout << "Destruktor Trojkata(" << a << "," << b << ',' << c << ")" << endl;
	sumaObwodow -= Obwod();
	cout << "sumaObwodow: " << sumaObwodow << endl;
}
