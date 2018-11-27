// Copyright 2018 Gilenkov Alexandr

#include "include/mass-converter.h"

bool MassConverter::isCorrect(const double& value) const {
    const double eps = 0.01;
    if ((value < 0) || (value < eps && value > -eps))
        return false;
    return true;
}

//double MassConverter::tonnToKilogramm(const double & tonn) const {
//    if (!isCorrect(tonn)) {
//        throw "Error! Invalid argument";
//    }
//    return tonn*1000;
//}
//
//double MassConverter::kilogrammToTonn(const double & kilogramm) const {
//    if (!isCorrect(kilogramm)) {
//        throw "Error! Invalid argument";
//    }
//    return kilogramm/1000;
//}
//
//double MassConverter::tonnToGramm(const double & tonn) const {
//    if (!isCorrect(tonn)) {
//        throw "Error! Invalid argument";
//    }
//    return tonn*1000000;
//}
//
//double MassConverter::grammToTonn(const double & gramm) const {
//    if (!isCorrect(gramm)) {
//         throw "Error! Invalid argument";
//    }
//    return gramm/1000000;
//}
//
//double MassConverter::tonnToStoun(const double & tonn) const {
//    if (!isCorrect(tonn)) {
//        throw "Error! Invalid argument";
//    }
//    return tonn*157.473;
//}
//
//double MassConverter::stounToTonn(const double & stoun) const {
//    if (!isCorrect(stoun)) {
//        throw "Error! Invalid argument";
//    }
//    return stoun/157.473;
//}
//
//double MassConverter::tonnToFunt(const double & tonn) const {
//    if (!isCorrect(tonn)) {
//        throw "Error! Invalid argument";
//    }
//    return tonn*2204.62;
//}
//
//double MassConverter::funtToTonn(const double & funt) const {
//    if (!isCorrect(funt)) {
//        throw "Error! Invalid argument";
//    }
//    return funt/2204.62;
//}
//
//double MassConverter::tonnToUncia(const double & tonn) const {
//    if (!isCorrect(tonn)) {
//        throw "Error! Invalid argument";
//    }
//    return tonn*35274;
//}
//
//double MassConverter::unciaToTonn(const double & uncia) const {
//    if (!isCorrect(uncia)) {
//        throw "Error! Invalid argument";
//    }
//    return uncia/35274;
//}
//
//double MassConverter::kilogrammToGramm(const double & kilogramm) const {
//    if (!isCorrect(kilogramm)) {
//        throw "Error! Invalid argument";
//    }
//    return kilogramm*1000;
//}
//
//double MassConverter::grammToKilogramm(const double & gramm) const {
//    if (!isCorrect(gramm)) {
//        throw "Error! Invalid argument";
//    }
//    return gramm/1000;
//}
//
//double MassConverter::kilogrammToStoun(const double & kilogramm) const {
//    if (!isCorrect(kilogramm)) {
//        throw "Error! Invalid argument";
//    }
//    return kilogramm/6.35;
//}
//
//double MassConverter::stounToKilogramm(const double & stoun) const {
//    if (!isCorrect(stoun)) {
//        throw "Error! Invalid argument";
//    }
//    return stoun*6.35;
//}
//
//double MassConverter::kilogrammToFunt(const double & kilogramm) const {
//    if (!isCorrect(kilogramm)) {
//         throw "Error! Invalid argument";
//    }
//    return kilogramm*2.205;
//}
//
//double MassConverter::funtToKilogramm(const double & funt) const {
//    if (!isCorrect(funt)) {
//        throw "Error! Invalid argument";
//    }
//    return funt/2.205;
//}
//
//double MassConverter::kilogrammToUncia(const double & kilogramm) const {
//    if (!isCorrect(kilogramm)) {
//        throw "Error! Invalid argument";
//    }
//    return kilogramm*35.274;
//}
//
//double MassConverter::unciaToKilogramm(const double & uncia) const {
//    if (!isCorrect(uncia)) {
//        throw "Error! Invalid argument";
//    }
//    return uncia/35.274;
//}
//
//double MassConverter::grammToStoun(const double & gramm) const {
//    if (!isCorrect(gramm)) {
//        throw "Error! Invalid argument";
//    }
//    return gramm/6350.293;
//}
//
//double MassConverter::stounToGramm(const double & stoun) const {
//    if (!isCorrect(stoun)) {
//        throw "Error! Invalid argument";
//    }
//    return stoun*6350.293;
//}
//
//double MassConverter::grammToFunt(const double & gramm) const {
//    if (!isCorrect(gramm)) {
//        throw "Error! Invalid argument";
//    }
//    return gramm/453.592;
//}
//
//double MassConverter::funtToGramm(const double & funt) const {
//    if (!isCorrect(funt)) {
//        throw "Error! Invalid argument";
//    }
//    return funt*453.592;
//}
//
//double MassConverter::grammToUncia(const double & gramm) const {
//    if (!isCorrect(gramm)) {
//        throw "Error! Invalid argument";
//    }
//    return gramm/28.35;
//}
//
//double MassConverter::unciaToGramm(const double & uncia) const {
//    if (!isCorrect(uncia)) {
//        throw "Error! Invalid argument";
//    }
//    return uncia*28.35;
//}
//
//double MassConverter::stounToFunt(const double & stoun) const {
//    if (!isCorrect(stoun)) {
//        throw "Error! Invalid argument";
//    }
//    return stoun*14;
//}
//
//double MassConverter::funtToStoun(const double & funt) const {
//    if (!isCorrect(funt)) {
//        throw "Error! Invalid argument";
//    }
//    return funt/14;
//}
//
//double MassConverter::stounToUncia(const double & stoun) const {
//    if (!isCorrect(stoun)) {
//        throw "Error! Invalid argument";
//    }
//    return stoun*224;
//}
//
//double MassConverter::unciaToStoun(const double & uncia) const {
//    if (!isCorrect(uncia)) {
//        throw "Error! Invalid argument";
//    }
//    return uncia/224;
//}
//
//double MassConverter::funtToUncia(const double & funt) const {
//    if (!isCorrect(funt)) {
//        throw "Error! Invalid argument";
//    }
//    return funt*16;
//}
//
//double MassConverter::unciaToFunt(const double & uncia) const {
//    if (!isCorrect(uncia)) {
//        throw "Error! Invalid argument";
//    }
//    return uncia/16;
//}

double MassConverter::convert(double input, const char* from,const char* to) {
    if (!isCorrect(input))
        throw "Error! Invalid Argument!";
    MassUnit MUfrom = ParseMassUnit(from);
    MassUnit MUto = ParseMassUnit(to);
    double res = 0;
    if ((MUfrom < 6) && (MUfrom >= 0) && (MUto >= 0) && (MUto < 6)) {
        if (MUfrom == 1) {
            res = input*ConvMatrix[MUto];
        }
        else {
            res = input / ConvMatrix[MUfrom] * ConvMatrix[MUto];
        }
        return res;
    }
    else
        throw "Error! Invalid Argument!";
}

MassUnit ParseMassUnit(const char* arg) {
    MassUnit massUnit;
    if (strcmp(arg, "Tonn") == 0) {
        massUnit = Tonn;
    }
    else if (strcmp(arg, "Kilogramm") == 0) {
        massUnit = Kilogramm;
    }
    else if (strcmp(arg, "Gramm") == 0) {
        massUnit = Gramm;
    }
    else if (strcmp(arg, "Stone") == 0) {
        massUnit = Stone;
    }
    else if (strcmp(arg, "Pound") == 0) {
        massUnit = Pound;
    }
    else if (strcmp(arg, "Ounce") == 0) {
        massUnit = Ounce;
    }
    else {
        throw "Wrong mass unit format!";
    }
    return massUnit;
}
