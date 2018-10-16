// Copyright 2018 Gilenkov Alexandr

#ifndef MODULES_MASS_CONVERTER_INCLUDE_MASSCONVERTER_APP_H_
#define MODULES_MASS_CONVERTER_INCLUDE_MASSCONVERTER_APP_H_

#include <string>

enum MassUnit {
    Gramm, Kilogramm, Tonn, Stoun, Funt, Uncia
};

class MassConverter_app {
 public:
    MassConverter_app();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double originalValue;
        MassUnit originalMassUnit;
        MassUnit targetMassUnit;
    } Arguments;
};

#endif  // MODULES_MASS_CONVERTER_INCLUDE_MASSCONVERTER_APP_H_
