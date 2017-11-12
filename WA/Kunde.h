#ifndef KUNDE_H
#define KUNDE_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class Kunde
{
public:
	Kunde(string newname, int newnumber);
	virtual ~Kunde();
	string getname();
	void setname(string a);
	int getnumber();
	void setnumber(int b);
	void info();
private:
	string name;
	int number;
};

#endif 