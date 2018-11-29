// Copyright 2018 Gilenkov Alexandr

#ifndef MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
#define MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

enum MassUnit {
    Tonn, Kilogramm, Gramm, Stone, Pound, Ounce
};
const double ConvMatrix[] = { 0.001, 1, 1000, 0.157473, 2.205, 35.274 };

class MassConverter {
 public:
    // MassConverter() { }

    bool isCorrect(const double &value) const;
    double convert(double input, const char* from, const char* to);
    MassUnit ParseMassUnit(const char* arg);
};

#endif  // MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
