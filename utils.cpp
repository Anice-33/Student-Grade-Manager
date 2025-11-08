//
// Created by Anis Jallali on 11/7/2025.
//

#include "utils.h"
#include <cctype>
#include <iostream>
#include <limits>

namespace utils {

    std::string trim(const std::string& s) {
        size_t a = 0, b = s.size();
        while (a < b && std::isspace(static_cast<unsigned char>(s[a]))) ++a;
        while (b > a && std::isspace(static_cast<unsigned char>(s[b-1]))) --b;
        return s.substr(a, b - a);
    }

    std::optional<int> toInt(const std::string& s) {
        std::string t = trim(s);
        if (t.empty()) return std::nullopt;

        // manual parse to detect trailing junk
        int sign = 1;
        size_t i = 0;
        if (t[0] == '+' || t[0] == '-') {
            sign = (t[0] == '-') ? -1 : 1;
            i = 1;
            if (i == t.size()) return std::nullopt;
        }
        long val = 0;
        for (; i < t.size(); ++i) {
            char c = t[i];
            if (!std::isdigit(static_cast<unsigned char>(c))) return std::nullopt;
            val = val * 10 + (c - '0');
            if (val > std::numeric_limits<int>::max()) return std::nullopt;
        }
        return static_cast<int>(sign * val);
    }

    std::string readLine(const std::string& prompt) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

    int promptInt(const std::string& prompt, int minInclusive, int maxInclusive) {
        while (true) {
            std::string line = readLine(prompt);
            auto v = toInt(line);
            if (v && *v >= minInclusive && *v <= maxInclusive) return *v;
            std::cout << "Please enter an integer in [" << minInclusive
                      << ", " << maxInclusive << "].\n";
        }
    }

} // namespace utils
