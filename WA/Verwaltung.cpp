#include "stdafx.h"
#include "Verwaltung.h"

#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


Verwaltung::Verwaltung() {
}

Verwaltung::~Verwaltung() {
}


void Verwaltung::generatelists()
{

	if (listof50.size() != 50) {
		for (int i = 0; i < 50; i++) {
			int fill = rand() % 5 + 5; //returns a value between 5 and 9
			newname = "";
			for (int j = 0; j < fill; j++) {
				int letterget = rand() % 26; //returns a value between 0 and 25
				newname = newname + letterlist.at(letterget);
			}

			Kunde newKunde(newname, i);

			listof50.push_back(newKunde);
		}
		cout << "Generated List of 50 Elements!" << endl << endl;
	}



	//generate 500
	if (listof500.size() != 500) {
		for (int i = 0; i < 500; i++) {
			int fill = rand() % 5 + 5;
			newname = "";
			for (int j = 0; j < fill; j++) {
				int letterget = rand() % 26;
				newname = newname + letterlist.at(letterget);
			}

			Kunde newKunde(newname, i);
			listof500.push_back(newKunde);
		}
		cout << "Generated List of 500 Elements!" << endl << endl;
	}


	//generate 5000
	if (listof5000.size() != 5000) {
		for (int i = 0; i < 5000; i++) {
			int fill = rand() % 5 + 5;
			newname = "";
			for (int j = 0; j < fill; j++) {
				int letterget = rand() % 26;
				newname = newname + letterlist.at(letterget);
			}

			Kunde newKunde(newname, i);
			listof5000.push_back(newKunde);
		}
		cout << "Generated List of 5000 Elements!" << endl << endl;
	}

	menu();
}

void Verwaltung::ausgeben50() {

	for (int i = 0; i < listof50.size(); i++) {
		listof50[i].info();
		cout << endl;
	}
	system("pause");
	system("cls");
	menu();
}

void Verwaltung::ausgeben500() {
	for (int i = 0; i < listof500.size(); i++) {
		listof500[i].info();
		cout << endl;
	}
	system("pause");
	system("cls");
	menu();
}

void Verwaltung::ausgeben5000() {
	for (int i = 0; i < listof5000.size(); i++) {
		listof5000[i].info();
		cout << endl;
	}
	system("pause");
	system("cls");
	menu();
}

void Verwaltung::speichern() {
	/*
	speichert alle Listen in einem eigenen txt File. Vor dem speichern wird sämtlicher Inhalt
	aus dem File gelöscht damit nur die neusten Daten enthalten sind. 
	Eine Ladefunktion ergibt keinen Sinn in diesem Szenario.
	*/

	system("cls");
	//50er speichern
	ofstream list50 ("list50.txt");
	if (list50.is_open()) {
		for (int i = 0; i < listof50.size(); i++) {
			list50 << listof50[i].getname() << "  " << listof50[i].getnumber() << endl;
		}
		list50.close();
		cout << "50er Liste gespeichert!" << endl;
	}

	//500er speichern
	ofstream list500;
	list500.open("list500.txt");
	for (int i = 0; i < listof500.size(); i++) {
		list500 << listof500[i].getname() << "  " << listof500[i].getnumber() << endl;
	}
	list500.close();
	cout << "500er Liste gespeichert!" << endl;

	//5000er speichern
	ofstream list5000;
	list5000.open("list5000.txt");
	for (int i = 0; i < listof5000.size(); i++) {
		list5000 << listof5000[i].getname() << "  " << listof5000[i].getnumber() << endl;
	}
	cout << "5000er Liste gespeichert!" << endl;

	menu();
}

void Verwaltung::deletelist() {
	system("cls");
	listof50.clear();
	listof500.clear();
	listof5000.clear();
	cout << "Alle Listen wurden erfolgreich geloescht!" << endl;
	menu();
}

void Verwaltung::sortmenu() {
	system("cls");
	cout << "Welcher Algorithmus soll verwendet werden?" << endl;
	cout << "(Q) Quicksort" << endl;
	cout << "(S) Selection Sort" << endl;
	cout << "(B) Bubble Sort" << endl;
	cout << "(I) Insertion Sort" << endl;
	cout << "(X) Zurueck" << endl;
	cin >> eingabe;
	switch (eingabe) {
	case'q':
	case'Q':
		quickmenu();
		break;
	case's':
	case'S':
		selectionmenu();
		break;
	case'b':
	case'B':
		bubblemenu();
		break;
	case'i':
	case'I':
		insertionmenu();
		break;
	case'x':
	case'X':
		system("cls");
		menu();
	default:
		sortmenu();
		break;
	}
}

void Verwaltung::quickmenu() {
	system("cls");
	cout << "Willkommen im Quicksort-Menue, welche Liste wollen Sie sortieren?" << endl;
	cout << "(A) 50er Liste (" << listof50.size() << " Elemente)" << endl;
	cout << "(B) 500er Liste (" << listof500.size() << " Elemente)" << endl;
	cout << "(C) 5000er Liste (" << listof5000.size() << " Elemente)" << endl;
	cout << "(Y) Zurueck" << endl;
	cout << "(X) Hauptmenue" << endl;
	cin >> eingabe;
	switch (eingabe) {
	case'a':
	case'A':
		quicksort(listof50);
		break;
	case'b':
	case'B':
		quicksort(listof500);
		break;
	case'c':
	case'C':
		quicksort(listof5000);
		break;
	case'y':
	case'Y':
		sortmenu();
		break;
	case'x':
	case'X':
		system("cls");
		menu();
		break;
	default:
		quickmenu();
		break;
	}

}

void Verwaltung::bubblemenu() {
	system("cls");
	cout << "Willkommen im Bubblesort-Menue, welche Liste wollen Sie sortieren?" << endl;
	cout << "(A) 50er Liste (" << listof50.size() << " Elemente)" << endl;
	cout << "(B) 500er Liste (" << listof500.size() << " Elemente)" << endl;
	cout << "(C) 5000er Liste (" << listof5000.size() << " Elemente)" << endl;
	cout << "(Y) Zurueck" << endl;
	cout << "(X) Hauptmenue" << endl;
	cin >> eingabe;
	switch (eingabe) {
	case'a':
	case'A':
		bubblesort(listof50);
		break;
	case'b':
	case'B':
		bubblesort(listof500);
		break;
	case'c':
	case'C':
		bubblesort(listof5000);
		break;
	case'y':
	case'Y':
		sortmenu();
		break;
	case'x':
	case'X':
		system("cls");
		menu();
		break;
	default:
		bubblemenu();
		break;
	}
}

void Verwaltung::insertionmenu() {
	system("cls");
	cout << "Willkommen im Insertionsort-Menue, welche Liste wollen Sie sortieren?" << endl;
	cout << "(A) 50er Liste (" << listof50.size() << " Elemente)" << endl;
	cout << "(B) 500er Liste (" << listof500.size() << " Elemente)" << endl;
	cout << "(C) 5000er Liste (" << listof5000.size() << " Elemente)" << endl;
	cout << "(Y) Zurueck" << endl;
	cout << "(X) Hauptmenue" << endl;
	cin >> eingabe;
	switch (eingabe) {
	case'a':
	case'A':
		insertionsort(listof50);
		break;
	case'b':
	case'B':
		insertionsort(listof500);
		break;
	case'c':
	case'C':
		insertionsort(listof5000);
		break;
	case'y':
	case'Y':
		sortmenu();
		break;
	case'x':
	case'X':
		system("cls");
		menu();
		break;
	default:
		insertionmenu();
		break;
	}
}


void Verwaltung::selectionmenu() {
	system("cls");
	cout << "Willkommen im Selectionsort-Menue, welche Liste wollen Sie sortieren?" << endl;
	cout << "(A) 50er Liste (" << listof50.size() << " Elemente)" << endl;
	cout << "(B) 500er Liste (" << listof500.size() << " Elemente)" << endl;
	cout << "(C) 5000er Liste (" << listof5000.size() << " Elemente)" << endl;
	cout << "(Y) Zurueck" << endl;
	cout << "(X) Hauptmenue" << endl;
	cin >> eingabe;
	switch (eingabe) {
	case'a':
	case'A':
		selectionsort(listof50);
		break;
	case'b':
	case'B':
		selectionsort(listof500);
		break;
	case'c':
	case'C':
		selectionsort(listof5000);
		break;
	case'y':
	case'Y':
		sortmenu();
		break;
	case'x':
	case'X':
		system("cls");
		menu();
		break;
	default:
		selectionmenu();
		break;
	}
}

//TODO   ist doof...
void Verwaltung::bubblesort(vector<Kunde> a) {
	system("cls");
	cout << "Bubblesort mit " << a.size() << " Elementen begonnen!" << endl;
	for (int i = 0; i < a.size()-1; i++){
		for (int j = 0; j < a.size()-1; j++) {
			string b = a[j].getname();
			string c = a[j + 1].getname();
			int bint = a[j].getnumber();
			int cint = a[j + 1].getnumber();
			if (b > c)
			{
				/*a[j].setname(c);
				a[j].setnumber(cint);
				a[j + 1].setname(b);
				a[j + 1].setnumber(bint);*/
				swap(a[j], a[j + 1]);
			}
		}
	}

	
	cout << "Liste mit " << a.size() << " Elementen wurde sortiert!" << endl;
	menu();
}


//TODO alles
void Verwaltung::selectionsort(vector<Kunde> a) {
	system("cls");
	cout << "Selectionsort mit " << a.size() << " Elementen begonnen!" << endl;


	cout << "Liste mit " << a.size() << " Elementen wurde sortiert!" << endl;
	menu();
}


//TODO alles
void Verwaltung::quicksort(vector<Kunde> a) {
	system("cls");
	cout << "Quicksort mit " << a.size() << " Elementen begonnen!" << endl;


	cout << "Liste mit " << a.size() << " Elementen wurde sortiert!" << endl;
	menu();
}


//TODO alles
void Verwaltung::insertionsort(vector<Kunde> a) {
	system("cls");
	cout << "Insertionsort mit " << a.size() << " Elementen begonnen!" << endl;


	cout << "Liste mit " << a.size() << " Elementen wurde sortiert!" << endl;
	menu();
}


void Verwaltung::menu() {
	cout << "Willkommen im Hauptmenue, bitte entscheiden Sie wie Sie fortfahren moechten" << endl << endl;
	cout << "(N) Neue Liste(n) generieren." << endl;
	cout << "(A) 50er Liste ausgeben" << endl;
	cout << "(B) 500er Liste ausgeben" << endl;
	cout << "(C) 5000er Liste ausgeben" << endl;
	cout << "(S) Listen Speichern" << endl;
	cout << "(D) Listen loeschen" << endl;
	cout << "(Q) Listen sortieren" << endl;
	cout << "(X) Programm beeenden" << endl;
	cin >> eingabe;
	switch (eingabe) 
	{
	case'n':
	case'N': 
		system("cls");
		generatelists();
		break;
	case'a':
	case'A': ausgeben50();
		break;
	case'b':
	case'B':
		ausgeben500();
		break;
	case'c':
	case'C':
		ausgeben5000();
		break;
	case's':
	case'S':
		speichern();
		break;
	case'd':
	case'D':
		deletelist();
		break;
	case'q':
	case'Q':
		sortmenu();
		break;
	case'x':
	case'X':
		cout << "Programm beendet" << endl;
		break;
	default: 
		system("cls");
		menu();
		break;
	}
}