// Copyright 2018 Gilenkov Alexandr

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <string>

#include "include/mass-converter.h"
#include "../include/mass-converter.h"

bool MassConverter::isCorrect(const double& value) const {
    const double eps = 0.01;
    if ((value < 0) || (value < eps && value > -eps))
        return false;
    return true;
}

double MassConverter::convert(double input, const char* from, const char* to) {
    if (isCorrect(input)) {
        MassUnit MUfrom = ParseMassUnit(from);
        MassUnit MUto = ParseMassUnit(to);
        if ((MUfrom < 6) && (MUfrom >= 0) && (MUto >= 0) && (MUto < 6)) {
            if (MUfrom == 1) {
                return (input*ConvMatrix[MUto]);
            } else {
                return (input / ConvMatrix[MUfrom] * ConvMatrix[MUto]);
            }
            return 0;
        }
    }
    throw "Error! Invalid argument";
}

MassUnit MassConverter::ParseMassUnit(const char* arg) {
    MassUnit mUnit;
    if (strcmp(arg, "Tonn") == 0) {
        mUnit = Tonn;
    } else if (strcmp(arg, "Kilogramm") == 0) {
        mUnit = Kilogramm;
    } else if (strcmp(arg, "Gramm") == 0) {
        mUnit = Gramm;
    } else if (strcmp(arg, "Stone") == 0) {
        mUnit = Stone;
    } else if (strcmp(arg, "Pound") == 0) {
        mUnit = Pound;
    } else if (strcmp(arg, "Ounce") == 0) {
        mUnit = Ounce;
    } else {
        throw "Wrong mass unit format!";
    }
    return mUnit;
}
