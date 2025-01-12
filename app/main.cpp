#include "app.h"
#include <iostream>
// read number of results
// read all student data
// read grade and output grade statistics
// read letter and output letter statistics

using namespace std;
using namespace vsite::oop::v3;

int main()
{
	vsite::oop::v3::array a;
	a.push_back(1.5);
	a.push_back(2.5);
	a.push_back(3.5);
	//Assert::AreEqual(2.5, a.at(1));



	int brojRezultata;
	cout << "Upisite broj rezultata: ";
	cin >> brojRezultata;
	results r = results(brojRezultata);

	for (int i = 1; i <= brojRezultata; ++i) {
		string name;
		int grade;
		// ucitaj podatke za hednog studenta
		cout << "Upisite ocjenu: ";
		cin >> grade;
		cout << "Upisite ime studenta: ";
		cin >> name;
		student s;
		s.name = name;
		s.grade = grade;
		r.add(s);
	}
	int grade;
	cout << "Upisite ocjenu za koju vas zanima statistika: ";
	cin >> grade;
	int koliko  = r.has_grade(grade);
	cout << "Ovoliko studenata ima ocjenu 3: " << koliko;
	char prvoSlovo;
	cout << "\nUpisite prvo slovo imena studenta: ";
	cin >> prvoSlovo;
	int kolikoSlova = r.starts_with_letter(prvoSlovo);
	cout << "Ovoliko studenata ima prvo slovo '" << prvoSlovo << "': " << kolikoSlova;
}
