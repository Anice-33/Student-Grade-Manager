#include <iostream>
#include <string>
#include "database.h"
#include "utils.h"

static void showMenu() {
    std::cout << "\n=== Student Manager ===\n"
              << "1. Add student\n"
              << "2. Add grade to a student\n"
              << "3. Show all students\n"
              << "4. Show class average\n"
              << "5. Exit\n";
}

static void handleAddStudent(Database& db) {
    std::string name = utils::trim(utils::readLine("Enter name: "));
    if (name.empty()) {
        std::cout << "Name cannot be empty.\n";
        return;
    }
    db.addStudent(Student{name});
    std::cout << "Student added: " << name << "\n";
}

static void handleAddGrade(Database& db) {
    std::string name = utils::trim(utils::readLine("Student name: "));
    auto s = db.findByName(name);
    if (!s) { std::cout << "Not found.\n"; return; }

    Student& st = s->get();  // unwrap the reference
    int g = utils::promptInt("Enter grade [0..100]: ", 0, 100);
    if (st.addGrade(g)) std::cout << "Grade added.\n";
    else std::cout << "Invalid grade.\n";
}

static void handleShowAll(const Database& db) {
    const auto& v = db.all();
    if (v.empty()) {
        std::cout << "No students yet.\n";
        return;
    }
    std::cout << "\n--- Students ---\n";
    for (const auto& s : v) {
        std::cout << s.name() << " | grades: ";
        const auto& gs = s.grades();
        if (gs.empty()) {
            std::cout << "(none)";
        } else {
            for (size_t i = 0; i < gs.size(); ++i) {
                std::cout << gs[i];
                if (i + 1 < gs.size()) std::cout << ", ";
            }
        }
        std::cout << " | avg: " << s.average() << "\n";
    }
}

static void handleClassAverage(const Database& db) {
    std::cout << "Class average: " << db.classAverage() << "\n";
}

int main() {
    Database db;
    while (true) {
        showMenu();
        int choice = utils::promptInt("Choose [1-5]: ", 1, 5);
        switch (choice) {
            case 1: handleAddStudent(db); break;
            case 2: handleAddGrade(db); break;
            case 3: handleShowAll(db); break;
            case 4: handleClassAverage(db); break;
            case 5: std::cout << "Bye.\n"; return 0;
        }
    }
}
