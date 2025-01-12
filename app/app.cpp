#include "app.h"
#include <algorithm>
#include <iostream>

namespace vsite::oop::v3
{
	results::results(int velicina) {
		this->velicina = velicina;
		prviSlobodni = 0;
		studenti = new student[velicina];
	}

	void results::add(student s) {
		(this->studenti)[prviSlobodni] = s;
		prviSlobodni++;
	}

	results::~results() {
		delete[] studenti;
	}

	unsigned int results::has_grade(int grade) {
		unsigned int koliko = 0;
		for (int i = 0; i < prviSlobodni; ++i) {
			if (studenti[i].grade == grade) {
				koliko++;
			}
		}
		return koliko;
	}

	unsigned int results::starts_with_letter(char name) {
		unsigned int count = 0;
		
		for (int i = 0; i < prviSlobodni; i++) {
			if (tolower(studenti[i].name[0]) == tolower(name)) {
				count++;
			}
		}
		return count;
	}

	array::array() {
		_array = nullptr;
		prviSlobodni = 0;
	}

	array::array(uint32_t size, double value) {
		_array = new double[size];
		for (uint32_t i = 0; i < size; ++i) {
			_array[i] = value;
		}
		prviSlobodni = size;
	}

	array::array(const array& other) {
		_array = new double[other.prviSlobodni];
		for (uint32_t i = 0; i < other.prviSlobodni; ++i) {
			_array[i] = other._array[i];
		}
		prviSlobodni = other.prviSlobodni;
	}

	array::array(array&& other) {
		_array = other._array;
		other._array = nullptr;
		prviSlobodni = other.prviSlobodni;
		other.prviSlobodni = 0;
	}

	array::~array() {
		delete[] _array;
	}


	double array::at(uint32_t index) {
		if (index >= prviSlobodni) {
			return 0;
		}
		return _array[index];
	}

	double array::push_back(double value) {
		//postaviti value na kraj arrayja
		double *_newArray = new double[prviSlobodni+1];
		for (uint32_t i = 0; i < prviSlobodni; i++) {
			_newArray[i] = _array[i];
		}
		delete[] _array;
		_array = _newArray;
		_array[prviSlobodni] = value;
		prviSlobodni++;
		return value;
	}

	uint32_t array::size() {
		return prviSlobodni;
	}

}