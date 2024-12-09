#pragma once
#include <string>
using namespace std;
namespace vsite::oop::v3 
{
	class student {
		public:
			string name;
			int grade;
	};

	class results {

		private:
			int velicina;
			student *studenti;
			int prviSlobodni;
		
		public:

			results(int velicina);
			void add(student);
			unsigned int has_grade(int grade);
			unsigned int starts_with_letter(char name);
			~results();
	};

	class array {
		
		double *_array;
		int prviSlobodni;
		public:
			array(); //defaultni konstruktor
			array(uint32_t size, double value); //konstruktor
			array(const array &other); // copy konstruktor
			array(array&& other);
			uint32_t size(); //vraca duljinu arraya
			double at(uint32_t index); // vrati double koji se nalazi na tom indexu
			double push_back(double value); // stavlja value na kraj arraya
			~array();
	};
}