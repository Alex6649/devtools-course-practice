// Copyright 2018 Razumova Maria

#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

#include "include/two-lines-options.h"
#include "include/two_lines.h"

int main(int argc, const char** argv) {
    TwoLinesOptions app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    // printf("%s\n", output.c_str());
    return 0;
}
