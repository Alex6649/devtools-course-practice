// Copyright 2018 Ioanu Daniel

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/rpn_app.h"

int main(int argc, const char** argv) {
    RPN app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
