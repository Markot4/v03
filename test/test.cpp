#include "CppUnitTest.h"
#include "../app/app.h"

using namespace std::string_literals;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v3;

namespace all_tests
{
	TEST_CLASS(test_v03_students)
	{
	public:
		TEST_METHOD(struct_student)
		{
			student s{ "pero", 2 };
			Assert::AreEqual("pero"s, s.name);
			Assert::AreEqual(2, s.grade);
		}

		TEST_METHOD(results_test_set_1)
		{
			results r(5);
			r.add({ "pero", 2 });
			r.add({ "marko", 3 });
			r.add({ "petra", 3 });
			r.add({ "ivo",	1 });
			r.add({ "drazen", 5 });
			Assert::AreEqual(2u, r.has_grade(3));
			Assert::AreEqual(2u, r.starts_with_letter('P'));
		}

		TEST_METHOD(results_test_set_2)
		{
			results r(4);
			r.add({ "Iva", 2 });
			r.add({ "ivan", 3 });
			r.add({ "ivica", 3 });
			r.add({ "ivo", 1 });
			Assert::AreEqual(0u, r.has_grade(5));
			Assert::AreEqual(4u, r.starts_with_letter('I'));
		}

		TEST_METHOD(results_test_set_3)
		{
			results r(4);
			r.add({ "ivan", 3 });
			r.add({ "karlo", 3 });
			r.add({ "marko", 3 });
			r.add({ "filip", 3 });
			Assert::AreEqual(4u, r.has_grade(3));
			Assert::AreEqual(0u, r.starts_with_letter('d'));
		}

		TEST_METHOD(results_test_set_4)
		{
			results r(50);
			r.add({ "Marko",	1 });
			r.add({ "Ivan",		1 });
			r.add({ "Antonio",	1 });
			r.add({ "Ante",		2 });
			r.add({ "Ivan",		2 });
			r.add({ "Karlo",	2 });
			r.add({ "Mario",	2 });
			r.add({ "Filip",	2 });
			r.add({ "Nikola",	2 });
			r.add({ "Lidija",	2 });
			r.add({ "Edin",		3 });
			r.add({ "Filip",	3 });
			r.add({ "Josip",	3 });
			r.add({ "Hrvoje",	3 });
			r.add({ "Lucija",	3 });
			r.add({ "Antonio",	4 });
			r.add({ "Deni",		4 });
			r.add({ "Anton",	4 });
			r.add({ "David",	4 });
			r.add({ "Mario",	4 });
			r.add({ "Sead",		5 });
			r.add({ "Matija",	5 });
			r.add({ "Marko",	5 });
			r.add({ "Igor",		5 });
			r.add({ "Anamarija",	5 });
			r.add({ "Vinko",	1 });
			r.add({ "Zoran",	1 });
			r.add({ "Filip",	1 });
			r.add({ "Matko",	1 });
			r.add({ "Luka",		1 });
			r.add({ "Kristijan",	2 });
			r.add({ "Denis",	2 });
			r.add({ "Bojan",	2 });
			r.add({ "Marko",	2 });
			r.add({ "Ivan",		2 });
			r.add({ "Maja",		3 });
			r.add({ "Krunoslav",	3 });
			r.add({ "Jakub",	3 });
			r.add({ "Bozidar",	3 });
			r.add({ "Ervin",	3 });
			r.add({ "Luka",		4 });
			r.add({ "Marko",	4 });
			r.add({ "Domagoj",	4 });
			r.add({ "Sandro",	4 });
			r.add({ "Matija",	4 });
			r.add({ "Ante",		5 });
			r.add({ "Tihomir",	5 });
			r.add({ "Masa",		5 });
			r.add({ "Dervis",	5 });
			r.add({ "Lovro",	5 });

			Assert::AreEqual(8u, r.has_grade(1));
			Assert::AreEqual(12u, r.has_grade(2));
			Assert::AreEqual(10u, r.has_grade(5));
			Assert::AreEqual(11u, r.starts_with_letter('m'));
			Assert::AreEqual(2u, r.starts_with_letter('e'));
			Assert::AreEqual(6u, r.starts_with_letter('A'));
		}

	};

	TEST_CLASS(test_v03_array)
	{
		const uint32_t size = 10;
		const double value = 1.5;

	public:
		TEST_METHOD(array_default_constructor)
		{
			array a;
			Assert::AreEqual(0u, a.size());
		}

		TEST_METHOD(array_constructor)
		{
			array a(size, value);
			Assert::AreEqual(size, a.size());
			for(uint32_t i=0; i<a.size(); ++i)
				Assert::AreEqual(value, a.at(i));
		}

		TEST_METHOD(array_index_invalid_large)
		{
			array a(size, value);
			Assert::AreEqual(0., a.at(100));
		}

		TEST_METHOD(array_index_invalid_negative)
		{
			array a(size, value);
			Assert::AreEqual(0., a.at(-1));
		}

		TEST_METHOD(array_copy_constructor)
		{
			array a(size, value);
			array b(a);
			Assert::AreEqual(size, b.size());
			for (uint32_t i = 0; i < b.size(); ++i)
				Assert::AreEqual(value, b.at(i));
		}

		TEST_METHOD(array_move_constructor)
		{
			array a(size, value);
			array b(std::move(a));
			Assert::AreEqual(0u, a.size());
			Assert::AreEqual(size, b.size());
			for (uint32_t i = 0; i < b.size(); ++i)
				Assert::AreEqual(value, b.at(i));
		}

		TEST_METHOD(array_grow_from_empty)
		{
			array a;
			Assert::AreEqual(0u, a.size());
			a.push_back(1.5);
			Assert::AreEqual(1u, a.size());
			a.push_back(2.5);
			Assert::AreEqual(2u, a.size());
			a.push_back(3.5);
			Assert::AreEqual(3u, a.size());
			Assert::AreEqual(1.5, a.at(0));
			Assert::AreEqual(2.5, a.at(1));
			Assert::AreEqual(3.5, a.at(2));
		}

		TEST_METHOD(array_grow)
		{
			array a(size, value);
			Assert::AreEqual(size, a.size());
			a.push_back(100);
			a.push_back(200);
			a.push_back(300);
			a.push_back(400);
			a.push_back(500);
			Assert::AreEqual(size + 5, a.size());
			Assert::AreEqual(value, a.at(0));
			Assert::AreEqual(value, a.at(size - 1));
			Assert::AreEqual(100., a.at(size));
			Assert::AreEqual(500., a.at(size + 4));
		}
	};
}
