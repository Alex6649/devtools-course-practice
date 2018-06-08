// Copyright 2018 Razumova Maria

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/two-lines-options.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TwoLinesOptionsTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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
    TwoLinesOptions app_;
    string output_;
};

TEST_F(TwoLinesOptionsTest, Do_Print_Help) {
    vector<string> args = {""};

    Act(args);

    Assert("This is a two-lines application\\..*");
}

TEST_F(TwoLinesOptionsTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"-l", "1", "2"};

    Act(args);

    Assert("ERROR: Should be 8 arguments\\..*");
}

TEST_F(TwoLinesOptionsTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"f", "0.0", "1", "1", "0", "1", "1", "0"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(TwoLinesOptionsTest, Can_Detect_Intersect) {
    vector<string> args = {"1", "0", "6", "5", "1", "0", "1", "0"};

    Act(args);

    Assert("lines are intersect");
}

TEST_F(TwoLinesOptionsTest, Can_Detect_not_Intersect) {
    vector<string> args = {"0.0", "0.0", "0", "1", "2", "0", "3", "1"};

    Act(args);

    Assert("lines are not intersect");
}
