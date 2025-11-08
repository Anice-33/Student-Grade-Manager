//
// Created by Anis Jallali on 11/7/2025.
//

#define UTILS_H

#pragma once
#include <string>
#include <optional>

namespace utils {

    std::string trim(const std::string& s);

    // Parses whole int (no trailing garbage). Returns nullopt on failure.
    std::optional<int> toInt(const std::string& s);

    // Prompt helpers (STDIN/STDOUT). Keep I/O at the edges.
    std::string readLine(const std::string& prompt);

    // Reads an int with prompt; reprompts until valid.
    int promptInt(const std::string& prompt, int minInclusive, int maxInclusive);

} // namespace utils
