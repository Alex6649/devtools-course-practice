// Copyright 2018 Gilenkov Alexandr

#include "include/MassConverter_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <string>
#include <sstream>
#include <iomanip>
#include "include/mass-converter.h"

MassConverter_app::MassConverter_app() : message_("") {}

void MassConverter_app::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a mass converter application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <originalValue> <originalMassUnit> " +
        "<targetMassUnit>\n\n" +
        "Where the first argument is positive double-precision number, " +
        "and mass units are one of Tonn, Kilogramm, Gramm, " +
        "Stoun, Funt, Uncia.\n";
}

bool MassConverter_app::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
    help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

MassUnit ParseMassUnit(const char* arg) {
    MassUnit massUnit;
    if (strcmp(arg, "Tonn") == 0) {
        massUnit = Tonn;
    } else if (strcmp(arg, "Kilogramm") == 0) {
        massUnit = Kilogramm;
    } else if (strcmp(arg, "Gramm") == 0) {
        massUnit = Gramm;
    } else if (strcmp(arg, "Stoun") == 0) {
        massUnit = Stoun;
    } else if (strcmp(arg, "Funt") == 0) {
        massUnit = Funt;
    } else if (strcmp(arg, "Uncia") == 0) {
        massUnit = Uncia;
    } else {
        throw std::string("Wrong mass unit format!");
    }
    return massUnit;
}

std::string MassConverter_app::operator()(int argc, const char** argv) {
    Arguments args;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.originalValue = ParseDouble(argv[1]);
        args.originalMassUnit = ParseMassUnit(argv[2]);
        args.targetMassUnit = ParseMassUnit(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }
    MassConverter massConv;
    std::ostringstream stream;
    try {
        double res;
        switch (args.originalMassUnit) {
        case Tonn:
            switch (args.targetMassUnit) {
            case Kilogramm:
                res = massConv.tonnToKilogramm(args.originalValue);
                stream << args.originalValue << " tonns is "
                    << res << " kilogramms";
                break;
            case Stoun:
                res = massConv.tonnToStoun(args.originalValue);
                stream << args.originalValue << " tonns is "
                    << res << " stouns";
                break;
            case Funt:
                res = massConv.tonnToFunt(args.originalValue);
                stream << args.originalValue << " tonns is "
                    << res << " funts";
                break;
            case Uncia:
                res = massConv.tonnToUncia(args.originalValue);
                stream << args.originalValue << " tonns is "
                    << res << " uncia";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Kilogramm:
            switch (args.targetMassUnit) {
            case Tonn:
                res = massConv.kilogrammToTonn(args.originalValue);
                stream << args.originalValue << " kilogramms is "
                    << res << " tonns";
                break;
            case Gramm:
                res = massConv.kilogrammToGramm(args.originalValue);
                stream << args.originalValue << " kilogramms is "
                    << res << " gramms";
                break;
            case Stoun:
                res = massConv.kilogrammToStoun(args.originalValue);
                stream << args.originalValue << " kilogramms is "
                    << res << " stouns";
                break;
            case Funt:
                res = massConv.kilogrammToFunt(args.originalValue);
                stream << args.originalValue << " kilogramms is "
                    << res << " funts";
                break;
            case Uncia:
                res = massConv.kilogrammToUncia(args.originalValue);
                stream << args.originalValue << " kilogramms is "
                    << res << " uncia";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Gramm:
            switch (args.targetMassUnit) {
            case Tonn:
                res = massConv.grammToTonn(args.originalValue);
                stream << args.originalValue << " gramms is "
                    << res << " tonns";
                break;
            case Kilogramm:
                res = massConv.grammToKilogramm(args.originalValue);
                stream << args.originalValue << " gramms is "
                    << res << " kilogramms";
                break;
            case Stoun:
                res = massConv.grammToStoun(args.originalValue);
                stream << args.originalValue << " gramms is "
                    << res << " stouns";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Stoun:
            switch (args.targetMassUnit) {
            case Tonn:
                res = massConv.stounToTonn(args.originalValue);
                stream << args.originalValue << " stouns is "
                    << res << " tonns";
                break;
            case Kilogramm:
                res = massConv.stounToKilogramm(args.originalValue);
                stream << args.originalValue << " stouns is "
                    << res << " kilogramms";
                break;
            case Funt:
                res = massConv.stounToFunt(args.originalValue);
                stream << args.originalValue << " stouns is "
                    << res << " funts";
                break;
            case Uncia:
                res = massConv.stounToUncia(args.originalValue);
                stream << args.originalValue << " stouns is "
                    << res << " uncia";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Funt:
            switch (args.targetMassUnit) {
            case Tonn:
                res = massConv.funtToTonn(args.originalValue);
                stream << args.originalValue << " funts is "
                    << res << " tonns";
                break;
            case Kilogramm:
                res = massConv.funtToKilogramm(args.originalValue);
                stream << args.originalValue << " funts is "
                    << res << " kilogramms";
                break;
            case Gramm:
                res = massConv.funtToGramm(args.originalValue);
                stream << args.originalValue << " funts is "
                    << res << " gramms";
                break;
            case Stoun:
                res = massConv.funtToStoun(args.originalValue);
                stream << args.originalValue << " funts is "
                    << res << " stouns";
                break;
            case Uncia:
                res = massConv.funtToUncia(args.originalValue);
                stream << args.originalValue << " funts is "
                    << res << " uncia";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        case Uncia:
            switch (args.targetMassUnit) {
            case Tonn:
                res = massConv.unciaToTonn(args.originalValue);
                stream << args.originalValue << " uncia is "
                    << res << " tonns";
                break;
            case Kilogramm:
                res = massConv.unciaToKilogramm(args.originalValue);
                stream << args.originalValue << " uncia is "
                    << res << " kilogramms";
                break;
            case Gramm:
                res = massConv.unciaToGramm(args.originalValue);
                stream << args.originalValue << " uncia is "
                    << res << " gramms";
                break;
            case Stoun:
                res = massConv.unciaToStoun(args.originalValue);
                stream << args.originalValue << " uncia is "
                    << res << " stouns";
                break;
            case Funt:
                res = massConv.unciaToFunt(args.originalValue);
                stream << args.originalValue << " uncia is "
                    << res << " funts";
                break;
            default:
                throw std::string("Error! Unknown conversion");
                break;
            }
            break;
        }
    }
    catch (std::string& str) {
         return str;
    }
    catch (const char* str) {
        return std::string(str);
    }
    message_ = stream.str();
    return message_;
}
