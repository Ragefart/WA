#include "stdafx.h"
#include "Kunde.h"


Kunde::Kunde(string newname, int newnumber)
{
	name = newname;
	number = newnumber;
}


Kunde::~Kunde()
{
}

string Kunde::getname()
{
	return name;
}

void Kunde::setname(string a)
{
	name = a;
}

int Kunde::getnumber()
{
	return number;
}

void Kunde::setnumber(int b)
{
	number = b;
}

void Kunde::info() {
	cout << number << ", " << name;
}
