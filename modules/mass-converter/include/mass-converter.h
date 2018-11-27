// Copyright 2018 Gilenkov Alexandr

#ifndef MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
#define MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

enum MassUnit {
    Tonn, Kilogramm, Gramm, Stone, Pound, Ounce
};
double ConvMatrix[] = { 0.001,1,1000,0.157473,2.205,35.274 };

class MassConverter {
 public:
    MassConverter() { }
    ~MassConverter() { }

    bool isCorrect(const double &value) const;
    double convert(double input, const char* from, const char* to);
	MassUnit ParseMassUnit(const char* arg);
    /*double tonnToKilogramm(const double &tonn) const;
    double kilogrammToTonn(const double &kilogramm) const;

    double tonnToGramm(const double &tonn) const;
    double grammToTonn(const double &gramm) const;

    double tonnToStoun(const double &tonn) const;
    double stounToTonn(const double &stoun) const;

    double tonnToFunt(const double &tonn) const;
    double funtToTonn(const double &funt) const;

    double tonnToUncia(const double &tonn) const;
    double unciaToTonn(const double &uncia) const;

    double kilogrammToGramm(const double &kilogramm) const;
    double grammToKilogramm(const double &gramm) const;

    double kilogrammToStoun(const double &kilogramm) const;
    double stounToKilogramm(const double &stoun) const;

    double kilogrammToFunt(const double &kilogramm) const;
    double funtToKilogramm(const double &funt) const;

    double kilogrammToUncia(const double &kilogramm) const;
    double unciaToKilogramm(const double &uncia) const;

    double grammToStoun(const double &gramm) const;
    double stounToGramm(const double &stoun) const;

    double grammToFunt(const double &gramm) const;
    double funtToGramm(const double &funt) const;

    double grammToUncia(const double &gramm) const;
    double unciaToGramm(const double &uncia) const;

    double stounToFunt(const double &stoun) const;
    double funtToStoun(const double &funt) const;

    double stounToUncia(const double &stoun) const;
    double unciaToStoun(const double &uncia) const;

    double funtToUncia(const double &funt) const;
    double unciaToFunt(const double &uncia) const;*/
};

#endif  // MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
