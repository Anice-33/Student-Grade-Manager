//
// Created by Anis Jallali on 11/7/2025.
//

#include "database.h"
#include <utility>

void Database::addStudent(Student s) {
    students_.push_back(std::move(s));
}

std::optional<std::reference_wrapper<Student>>
Database::findByName(const std::string& name) {
    for (auto& s : students_) {
        if (s.name() == name) return s; // wraps a reference
    }
    return std::nullopt;
}

double Database::classAverage() const {
    long count = 0;
    double sum = 0.0;
    for (const auto& s : students_) {
        for (int g : s.grades()) {
            sum += g;
            ++count;
        }
    }
    if (count == 0) return 0.0;
    return sum / static_cast<double>(count);
}