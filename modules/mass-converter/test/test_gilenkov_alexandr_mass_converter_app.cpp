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
    vector<string> args = { "2", "Kilogrmm", "Gramm" };
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
    vector<string> args = { "2", "Stone", "Stone" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_5) {
    vector<string> args = { "2", "Pound", "Pound" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Detect_Unknown_Conversion_6) {
    vector<string> args = { "2", "Ounce", "Ounce" };
    Act(args);
    Assert("Error! Unknown conversion");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Kilogramm) {
    vector<string> args = { "1", "Tonn", "Kilogramm" };
    Act(args);
    Assert("1 Tonn is 1000 Kilogramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Stone) {
    vector<string> args = { "1", "Tonn", "Stone" };
    Act(args);
    Assert("1 Tonn is 157.473 Stone");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Pound) {
    vector<string> args = { "1", "Tonn", "Pound" };
    Act(args);
    Assert("1 Tonn is 2205 Pound");
}

TEST_F(MassConverterAppTest, Can_Convert_Tonn_To_Ounce) {
    vector<string> args = { "1", "Tonn", "Ounce" };
    Act(args);
    Assert("1 Tonn is 35274 Ounce");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Tonn) {
    vector<string> args = { "1", "Kilogramm", "Tonn" };
    Act(args);
    Assert("1 Kilogramm is 0.001 Tonn");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Gramm) {
    vector<string> args = { "1", "Kilogramm", "Gramm" };
    Act(args);
    Assert("1 Kilogramm is 1000 Gramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Stone) {
    vector<string> args = { "1", "Kilogramm", "Stone" };
    Act(args);
    Assert("1 Kilogramm is 0.157473 Stone");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Pound) {
    vector<string> args = { "1", "Kilogramm", "Pound" };
    Act(args);
    Assert("1 Kilogramm is 2.205 Pound");
}

TEST_F(MassConverterAppTest, Can_Convert_Kilogramm_To_Ounce) {
    vector<string> args = { "1", "Kilogramm", "Ounce" };
    Act(args);
    Assert("1 Kilogramm is 35.274 Ounce");
}

TEST_F(MassConverterAppTest, Can_Convert_Gramm_To_Tonn) {
    vector<string> args = { "1500", "Gramm", "Tonn" };
    Act(args);
    Assert("1500 Gramm is 0.0015 Tonn");
}

TEST_F(MassConverterAppTest, Can_Convert_Gramm_To_Kilogramm) {
    vector<string> args = { "1000", "Gramm", "Kilogramm" };
    Act(args);
    Assert("1000 Gramm is 1 Kilogramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Gramm_To_Stone) {
    vector<string> args = { "1000", "Gramm", "Stone" };
    Act(args);
    Assert("1000 Gramm is 0.157473 Stone");
}

TEST_F(MassConverterAppTest, Can_Convert_Stone_To_Tonn) {
    vector<string> args = { "1500", "Stone", "Tonn" };
    Act(args);
    Assert("1500 Stone is 9.52544 Tonn");
}

TEST_F(MassConverterAppTest, Can_Convert_Stone_To_Kilogramm) {
    vector<string> args = { "0.157473", "Stone", "Kilogramm" };
    Act(args);
    Assert("0.157473 Stone is 1 Kilogramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Stone_To_Pound) {
    vector<string> args = { "0.157473", "Stone", "Pound" };
    Act(args);
    Assert("0.157473 Stone is 2.205 Pound");
}

TEST_F(MassConverterAppTest, Can_Convert_Stone_To_Ounce) {
    vector<string> args = { "1500", "Stone", "Ounce" };
    Act(args);
    Assert("1500 Stone is 336000 Ounce");
}

TEST_F(MassConverterAppTest, Can_Convert_Pound_To_Tonn) {
    vector<string> args = { "2205", "Pound", "Tonn" };
    Act(args);
    Assert("2205 Pound is 1 Tonn");
}

TEST_F(MassConverterAppTest, Can_Convert_Pound_To_Kilogramm) {
    vector<string> args = { "1500", "Pound", "Kilogramm" };
    Act(args);
    Assert("1500 Pound is 680.272 Kilogramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Pound_To_Gramm) {
    vector<string> args = { "2.205", "Pound", "Gramm" };
    Act(args);
    Assert("2.205 Pound is 1000 Gramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Pound_To_Stone) {
    vector<string> args = { "2.205", "Pound", "Stone" };
    Act(args);
    Assert("2.205 Pound is 0.157473 Stone");
}

TEST_F(MassConverterAppTest, Can_Convert_Pound_To_Ounce) {
    vector<string> args = { "2.205", "Pound", "Ounce" };
    Act(args);
    Assert("2.205 Pound is 35.274 Ounce");
}

TEST_F(MassConverterAppTest, Can_Convert_Ounce_To_Tonn) {
    vector<string> args = { "1500", "Ounce", "Tonn" };
    Act(args);
    Assert("1500 Ounce is 0.0425242 Tonn");
}

TEST_F(MassConverterAppTest, Can_Convert_Ounce_To_Kilogramm) {
    vector<string> args = { "1500", "Ounce", "Kilogramm" };
    Act(args);
    Assert("1500 Ounce is 42.5242 Kilogramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Ounce_To_Gramm) {
    vector<string> args = { "35.274", "Ounce", "Gramm" };
    Act(args);
    Assert("35.274 Ounce is 1000 Gramm");
}

TEST_F(MassConverterAppTest, Can_Convert_Ounce_To_Stone) {
    vector<string> args = { "35.274", "Ounce", "Stone" };
    Act(args);
    Assert("35.274 Ounce is 0.157473 Stone");
}

TEST_F(MassConverterAppTest, Can_Convert_Ounce_To_Pound) {
    vector<string> args = { "35.274", "Ounce", "Pound" };
    Act(args);
    Assert("35.274 Ounce is 2.205 Pound");
}
