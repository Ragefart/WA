#ifndef VERWALTUNG_H
#define VERWALTUNG_H

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <chrono>

#include "Kunde.h"

using namespace std;

class Verwaltung {
public:
	Verwaltung();
	virtual ~Verwaltung();
	void generatelists();
	void ausgeben50();
	void menu();
	void ausgeben500();
	void ausgeben5000();
	void ausgeben50000();
	void speichern();
	void deletelist();
	void sortmenu();
	void quickmenu();
	void bubblemenu();
	void selectionmenu();
	void insertionmenu();
	void bubblesort(vector<Kunde>&);
	void selectionsort(vector<Kunde>&);
	void insertionsort(vector<Kunde>&);
	void startqs(vector<Kunde>& a);
	void quicksort(vector<Kunde>&, int low, int high);
	int Partition(vector<Kunde>& a, int low, int high);
private:
	vector<int> length = { 5, 6, 7, 8, 9 };
	vector<string> letterlist = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
	vector<Kunde> listof50;
	vector<Kunde> listof500;
	vector<Kunde> listof5000;
	vector<Kunde> listof50000;
	string newname;
	char eingabe;

};

#endif /* VERWALTUNG_H */