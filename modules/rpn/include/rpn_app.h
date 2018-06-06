// Copyright 2018 Ioanu Daniel

#ifndef MODULES_RPN_INCLUDE_RPN_APP_H_
#define MODULES_RPN_INCLUDE_RPN_APP_H_

#include <string>

class RPN {
 public:
    RPN();
    std::string operator()(int argc, const char *argv[]);

 private:
    void help(const char *appname, const char *message = "");
    bool validateNumberOfArguments(int argc, const char *argv[]);

    std::string message_;
    std::string arguments;
};

#endif  // MODULES_RPN_INCLUDE_RPN_APP_H_
