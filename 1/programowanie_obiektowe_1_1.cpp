#include <iostream>
#include "Prostokat.h"
#include "Kolo.h"
#include "Trojkat.h"

using namespace std;

class Zwierzak {
public:
	virtual void dajGlos() {
		cout << "Zwierzak daje glos" << endl;
	}
};

class Pies : public Zwierzak {
public:
	void dajGlos() {
		cout << "Hau" << endl;
	}
	void dajGlos(int ile_razy) {
		for (int i = 0; i < ile_razy; i++) {
			cout << "Hau ";
		}
		cout << endl;
	}
};

int main()
{
	Prostokat p1(2, 3);
	cout << "a: " << p1.GetA() << endl;
	cout << "b: " << p1.GetB() << endl;
	cout << "Obwod: " << p1.Obwod() << endl;
	cout << "Pole: " << p1.Pole() << endl;
	cout << p1 << endl;
	p1.SetA(4);
	p1.SetB(5);
	cout << "a: " << p1.GetA() << endl;
	cout << "b: " << p1.GetB() << endl;
	cout << "Obwod: " << p1.Obwod() << endl;
	cout << "Pole: " << p1.Pole() << endl;
	cout << p1 << endl;
	
	Prostokat* p2;
	p2 = new Prostokat(6, 7);
	cout << "a: " << p2->GetA() << endl;
	cout << "b: " << p2->GetB() << endl;
	cout << "Obwod: " << p2->Obwod() << endl;
	cout << "Pole: " << p2->Pole() << endl;
	cout << *p2 << endl;
	p2->SetA(8);
	p2->SetB(9);
	cout << "a: " << p2->GetA() << endl;
	cout << "b: " << p2->GetB() << endl;
	cout << "Obwod: " << p2->Obwod() << endl;
	cout << "Pole: " << p2->Pole() << endl;
	cout << *p2 << endl;
	delete p2;
	
	Kolo k1(2);
	cout << "r: " << k1.GetR() << endl;
	cout << "Obwod: " << k1.Obwod() << endl;
	cout << "Pole: " << k1.Pole() << endl;
	cout << k1 << endl;
	k1.SetR(3);
	cout << "r: " << k1.GetR() << endl;
	cout << "Obwod: " << k1.Obwod() << endl;
	cout << "Pole: " << k1.Pole() << endl;
	cout << k1 << endl;

	Kolo* k2;
	k2 = new Kolo(4);
	cout << "r: " << k2->GetR() << endl;
	cout << "Obwod: " << k2->Obwod() << endl;
	cout << "Pole: " << k2->Pole() << endl;
	cout << *k2 << endl;
	k2->SetR(5);
	cout << "r: " << k2->GetR() << endl;
	cout << "Obwod: " << k2->Obwod() << endl;
	cout << "Pole: " << k2->Pole() << endl;
	cout << *k2 << endl;
	delete k2;
	
	Trojkat t1(2, 3, 4);
	cout << "a: " << t1.GetA() << endl;
	cout << "b: " << t1.GetB() << endl;
	cout << "c: " << t1.GetC() << endl;
	cout << "Obwod: " << t1.Obwod() << endl;
	cout << "Pole: " << t1.Pole() << endl;
	cout << t1 << endl;
	t1.SetA(3);
	t1.SetB(4);
	t1.SetC(5);
	cout << "a: " << t1.GetA() << endl;
	cout << "b: " << t1.GetB() << endl;
	cout << "c: " << t1.GetC() << endl;
	cout << "Obwod: " << t1.Obwod() << endl;
	cout << "Pole: " << t1.Pole() << endl;
	cout << t1 << endl;
	
	Trojkat* t2;
	t2 = new Trojkat(6, 7, 8);
	cout << "a: " << t2->GetA() << endl;
	cout << "b: " << t2->GetB() << endl;
	cout << "c: " << t2->GetC() << endl;
	cout << "Obwod: " << t2->Obwod() << endl;
	cout << "Pole: " << t2->Pole() << endl;
	cout << *t2 << endl;
	t2->SetA(7);
	t2->SetB(8);
	t2->SetC(9);
	cout << "a: " << t2->GetA() << endl;
	cout << "b: " << t2->GetB() << endl;
	cout << "c: " << t2->GetC() << endl;
	cout << "Obwod: " << t2->Obwod() << endl;
	cout << "Pole: " << t2->Pole() << endl;
	cout << *t2 << endl;
	delete t2;

	FiguraPlaska* tab[3];
	tab[0] = new Prostokat(2, 3);
	tab[1] = new Kolo(4);
	tab[2] = new Trojkat(5, 6, 7);
	for (int i = 0; i < 3; i++)
	{
		cout << tab[i]->Obwod() << endl;
		cout << tab[i]->Pole() << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete tab[i];
	}

	Zwierzak z1;
	z1.dajGlos();
	
	Pies z2;
	z2.dajGlos();
	z2.dajGlos(3);
}
