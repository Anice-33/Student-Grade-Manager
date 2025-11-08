//
// Created by Anis Jallali on 11/7/2025.
//

#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include <string>
#include <vector>

class Student {
public:
    explicit Student(std::string name);

    // Adds a grade in [0, 100]. Returns false if out of range.
    bool addGrade(int g);

    double average() const;
    const std::string& name() const { return name_; }
    const std::vector<int>& grades() const { return grades_; }

private:
    std::string name_;
    std::vector<int> grades_;
};



#endif //STUDENT_H
