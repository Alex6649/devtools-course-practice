// Copyright 2018 Gusev Alexandr

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/area_calculation_app.h"
//#include "include/area_calculation.h"
using ::testing::internal::RE;
using std::vector;
using std::string;

class AreaCalculationAppTest : public ::testing::Test {
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
    AreaCalculationApp app_;
    string output_;
};

TEST_F(AreaCalculationAppTest, No_Arguments_Test) {
    // Arrange
    vector<string> args = {};
    // Act
    Act(args);
    // Assert
    Assert("This is a area calculation application\\..*");
}
TEST_F(AreaCalculationAppTest, Correctly_Arguments_Test) {
	// Arrange
	vector<string> args = { "3", "1", "1", "1", "1", "2", "1"};
	// Act
	Act(args);
	// Assert
	Assert("This is a area calculation application\\..*");
}