// Copyright 2018 Gilenkov Alexandr

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "include/MassConverter_app.h"

int main(int argc, const char** argv) {
    MassConverter_app app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
