//
// Created by Anis Jallali on 11/7/2025.
//

#pragma once
#include <vector>
#include <string>
#include <optional>
#include <functional>
#include "student.h"

class Database {
public:
    void addStudent(Student s);

    // returns reference to existing student
    std::optional<std::reference_wrapper<Student>> findByName(const std::string& name);

    const std::vector<Student>& all() const { return students_; }

    // NOTE: const here
    double classAverage() const;

private:
    std::vector<Student> students_;
};

