#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "binary_io.hpp"
#include "book_info.hpp"
using namespace std;

enum CharacterRole {
    MAIN,
    SECONDARY,
    EPIZODIC
};

struct characterInfo {
    vector<string> names;
    map<unsigned /* bookUid */, CharacterRole> books;
};