//
// Created by Anis Jallali on 11/7/2025.
//

#include "student.h"
#include "student.h"
#include <numeric>

Student::Student(std::string name) : name_(std::move(name)) {}

bool Student::addGrade(int g) {
    if (g < 0 || g > 100) return false;
    grades_.push_back(g);
    return true;
}

double Student::average() const {
    if (grades_.empty()) return 0.0;
    double sum = std::accumulate(grades_.begin(), grades_.end(), 0.0);
    return sum / grades_.size();
}

