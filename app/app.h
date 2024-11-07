#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <cctype>
#include <algorithm> // Dodano za std::count_if

namespace vsite::oop::v3
{
    // Struktura koja predstavlja studenta
    struct student {
        std::string name;
        int grade;

        student(const std::string& n, int g) : name(n), grade(g) {}
    };

    // Klasa koja čuva rezultate
    class results {
    private:
        std::vector<student> students;
        std::size_t max_size;

    public:
        results(std::size_t size) : max_size(size) {}

        void add(const student& s) {
            if (students.size() < max_size) {
                students.push_back(s);
            }
        }

        unsigned int has_grade(int grade) const {
            return static_cast<unsigned int>(std::count_if(students.begin(), students.end(), [grade](const student& s) {
                return s.grade == grade;
                }));
        }

        unsigned int starts_with_letter(char letter) const {
            letter = std::tolower(letter);
            return static_cast<unsigned int>(std::count_if(students.begin(), students.end(), [letter](const student& s) {
                return std::tolower(s.name[0]) == letter;
                }));
        }
    };

    // Klasa za dinamički niz
    class array {
    private:
        std::vector<double> elements;

    public:
        array() = default;

        array(std::size_t size, double value) : elements(size, value) {}

        array(const array& other) : elements(other.elements) {}

        array(array&& other) noexcept : elements(std::move(other.elements)) {}

        uint32_t size() const {
            return static_cast<uint32_t>(elements.size());
        }

        double at(int index) const {
            if (index < 0 || static_cast<std::size_t>(index) >= elements.size()) {
                return 0.0;
            }
            return elements[index];
        }

        void push_back(double value) {
            elements.push_back(value);
        }
    };
}

