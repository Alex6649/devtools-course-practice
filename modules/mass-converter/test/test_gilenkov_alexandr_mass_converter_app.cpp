// Copyright 2018 Gilenkov Alexandr

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include "include/MassConverter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class MassConverterAppTest : public ::testing::Test {
protected:

    void Act(vector<string> args_) {
        vector<const char*> options;
        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }
        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;
        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
         EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

private:
    MassConverter_app app_;
    string output_;
};

TEST_F(MassConverterAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};
    Act(args);
    Assert("This is a mass converter application\\..*");
}

TEST_F(MassConverterAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "Gramm", "Kilogramm" };
    Act(args);
    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(MassConverterAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "odin", "Kilogramm", "Gramm" };
    Act(args);
    Assert("Wrong number format!");
}

TEST_F(MassConverterAppTest, Can_Detect_Negative_Mass) {
    vector<string> args = { "-1", "Kilogramm", "Gramm" };
    Act(args);
    Assert("Error! Invalid argument");
}

TEST_F(MassConverterAppTest, Can_Detect_Wrong_Mass_Unit_Format) {
    vector<string> args = { "2", "Kilogramms", "Gramm" };
    Act(args);
    Assert("Wrong mass unit format!");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_1) {
    vector<string> args = { "2", "Tonn", "Tonn" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_2) {
    vector<string> args = { "2", "Kilogramm", "Kilogramm" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_3) {
    vector<string> args = { "2", "Gramm", "Gramm" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_4) {
    vector<string> args = { "2", "Stoun", "Stoun" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_5) {
    vector<string> args = { "2", "Funt", "Funt" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_6) {
    vector<string> args = { "2", "Uncia", "Uncia" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Kilogramm) {
    vector<string> args = { "1", "Tonn", "Kilogramm" };
    Act(args);
    Assert("1 tonns is 1000 kilogramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Stoun) {
    vector<string> args = { "1", "Tonn", "Stoun" };
    Act(args);
    Assert("1 tonns is 157.473 stouns");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Funt) {
    vector<string> args = { "1", "Tonn", "Funt" };
    Act(args);
    Assert("1 tonns is 2204.62 funts");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Uncia) {
    vector<string> args = { "1", "Tonn", "Uncia" };
    Act(args);
    Assert("1 tonns is 35274 uncia");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Tonn) {
    vector<string> args = { "1", "Kilogramm", "Tonn" };
    Act(args);
    Assert("1 kilogramms is 0.001 tonns");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Gramm) {
    vector<string> args = { "1", "Kilogramm", "Gramm" };
    Act(args);
    Assert("1 kilogramms is 1000 gramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Stoun) {
    vector<string> args = { "1", "Kilogramm", "Stoun" };
    Act(args);
    Assert("1 kilogramms is 0.15748 stouns");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Funt) {
    vector<string> args = { "1", "Kilogramm", "Funt" };
    Act(args);
    Assert("1 kilogramms is 2.205 funts");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Uncia) {
    vector<string> args = { "1", "Kilogramm", "Uncia" };
    Act(args);
    Assert("1 kilogramms is 35.274 uncia");
}

TEST_F(MassConverterAppTest, Can_Convert_Gramm_To_Tonn) {
    vector<string> args = { "1500", "Gramm", "Tonn" };
    Act(args);
    Assert("1500 gramms is 0.0015 tonns");
}

TEST_F(MassConverterAppTest, Can_Convert_Gramm_To_Kilogramm) {
    vector<string> args = { "1500", "Gramm", "Kilogramm" };
    Act(args);
    Assert("1500 gramms is 1.5 kilogramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Gramm_To_Stoun) {
    vector<string> args = { "1500", "Gramm", "Stoun" };
    Act(args);
    Assert("1500 gramms is 0.23621 stouns");
}

TEST_F(MassConverterAppTest, Can_Convert_Stoun_To_Tonn) {
    vector<string> args = { "1500", "Stoun", "Tonn" };
    Act(args);
    Assert("1500 stouns is 9.52544 tonns");
}

TEST_F(MassConverterAppTest, Can_Convert_Stoun_To_Kilogramm) {
    vector<string> args = { "1500", "Stoun", "Kilogramm" };
    Act(args);
    Assert("1500 stouns is 9525 kilogramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Stoun_To_Funt) {
    vector<string> args = { "1500", "Stoun", "Funt" };
    Act(args);
    Assert("1500 stouns is 21000 funts");
}

TEST_F(MassConverterAppTest, Can_Convert_Stoun_To_Uncia) {
    vector<string> args = { "1500", "Stoun", "Uncia" };
    Act(args);
    Assert("1500 stouns is 336000 uncia");
}

TEST_F(MassConverterAppTest, Can_Convert_Funt_To_Tonn) {
    vector<string> args = { "1500", "Funt", "Tonn" };
    Act(args);
    Assert("1500 funts is 0.680389 tonns");
}

TEST_F(MassConverterAppTest, Can_Convert_Funt_To_Kilogramm) {
    vector<string> args = { "1500", "Funt", "Kilogramm" };
    Act(args);
    Assert("1500 funts is 680.272 kilogramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Funt_To_Gramm) {
    vector<string> args = { "1500", "Funt", "Gramm" };
    Act(args);
    Assert("1500 funts is 680388 gramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Funt_To_Stoun) {
    vector<string> args = { "1500", "Funt", "Stoun" };
    Act(args);
    Assert("1500 funts is 107.143 stouns");
}

TEST_F(MassConverterAppTest, Can_Convert_Funt_To_Uncia) {
    vector<string> args = { "1500", "Funt", "Uncia" };
    Act(args);
    Assert("1500 funts is 24000 uncia");
}

TEST_F(MassConverterAppTest, Can_Convert_Uncia_To_Tonn) {
    vector<string> args = { "1500", "Uncia", "Tonn" };
    Act(args);
    Assert("1500 uncia is 0.0425242 tonns");
}

TEST_F(MassConverterAppTest, Can_Convert_Uncia_To_Kilogramm) {
    vector<string> args = { "1500", "Uncia", "Kilogramm" };
    Act(args);
    Assert("1500 uncia is 42.5242 kilogramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Uncia_To_Gramm) {
    vector<string> args = { "1500", "Uncia", "Gramm" };
    Act(args);
    Assert("1500 uncia is 42525 gramms");
}

TEST_F(MassConverterAppTest, Can_Convert_Uncia_To_Stoun) {
    vector<string> args = { "1500", "Uncia", "Stoun" };
    Act(args);
    Assert("1500 uncia is 6.69643 stouns");
}

TEST_F(MassConverterAppTest, Can_Convert_Uncia_To_Funt) {
    vector<string> args = { "1500", "Uncia", "Funt" };
    Act(args);
    Assert("1500 uncia is 93.75 funts");
}
