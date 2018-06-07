// Copyright 2018 Ioanu Daniel

#include <gtest/gtest.h>

#include <string>
#include <sstream>
#include <vector>

#include "include/rpn_app.h"
#include "include/messages.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RpnTest : public ::testing::Test {
 protected:
    void Act(string args_) {
        vector<const char*> options;

        options.push_back("appname");

        string arg;
        vector<string> argsV;
        std::istringstream ss(args_);
        while (ss >> arg) {
            argsV.push_back(arg);
        }

        for (size_t i = 0; i < argsV.size(); ++i) {
            options.push_back(argsV[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(options.size());

        output_ = app_(argc, argv);
    }

    void Assert(string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

    void Assert_Any_Throw(string expected) {
        EXPECT_ANY_THROW(RE::PartialMatch(output_, expected));
    }

 private:
    RPN app_;
    string output_;
};

TEST_F (RpnTest, Can_Parse_Number) {
    string args("12");

    Act(args);

    Assert("Result: 12");
}

TEST_F(RpnTest, Can_Add) {
    string args("5 + 8");

    Act(args);

    Assert("Result: 13");
}

TEST_F(RpnTest, Can_Substract) {
    string args("5 - 8");

    Act(args);

    Assert("Result: -3");
}

TEST_F(RpnTest, Can_Multiply) {
    string args("3 * 4");

    Act(args);

    Assert("Result: 12");
}

TEST_F(RpnTest, Can_Divide) {
    string args("12 / 6");

    Act(args);

    Assert("Result: 2");
}

TEST_F(RpnTest, Exception_on_Division_by_Zero) {
    string args("12 / 0");

    Act(args);

    Assert("DIVISION_BY_ZERO");
}

TEST_F(RpnTest, Can_Exponent) {
    string args("2 ^ 3");

    Act(args);

    Assert("Result: 8");
}

TEST_F(RpnTest, Exponent_Undefined) {
    string args("0 ^ 0");

    Act(args);

    Assert("UNDEFINED_OPERATION");
}

TEST_F(RpnTest, Exponent_Base_Zero_Negative) {
    string args("0 ^ ( 0 - 1 )");

    Act(args);

    Assert("DIVISION_BY_ZERO");
}

TEST_F(RpnTest, Exponent_Base_One_Negative) {
    string args("1 ^ ( 0 - 1 )");

    Act(args);

    Assert("Result: 1");
}

TEST_F(RpnTest, Exponent_Negative) {
    string args("2 ^ ( 0 - 1 )");

    Act(args);

    Assert("Result: 0");
}

TEST_F(RpnTest, Throw_On_Invalid_Symbols) {
    string args("2 + f");

    Act(args);

    Assert("INVALID_SYMBOL");
}

TEST_F(RpnTest, Skip_Multiple_Spaces) {
    string args("  2  +  3  ");

    Act(args);

    Assert("Result: 5");
}

TEST_F(RpnTest, Serial_Calculations) {
    string args("(1 + 2) * 4 + 3");

    Act(args);

    Assert("Result: 15");
}

TEST_F(RpnTest, Serial_Calculations_2) {
    string args("4 + 6 * 2 / (1 - 3)^2");

    Act(args);

    Assert("Result: 7");
}
