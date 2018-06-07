// Copyright 2018 Ioanu Daniel

#include "include/rpn.h"
#include "include/rpn_app.h"

#include <string>

RPN::RPN(void)
    : message_("") {
}

void RPN::help(const char *appname, const char *message) {
    message_ =
        std::string(message) +
        "This is reverse polish notation application\n" +
        "In order to use this application,\n" +
        "provide the arguments like this\n\n    " +

        appname + " <expression_to_calculate>\n\n" +

        "    ---------------------------------------\n\n" +
        "    Allowed operators: +, -, *, (, ), ^ /.\n\n" +
        "    ---------------------------------------\n\n" +
        "    Examples of expressions to calculate" +
        "    1) 1 + 2; 3 - 1; 2 * 2; 12 / 6" +
        "    2) 3 + ( 1 - 2 )" +
        "    3) 4 ^ 2; 2 + ( 3 + 1) ^ 2";
}

bool RPN::validateNumberOfArguments(int argc, const char *argv[]) {
    if (argc == 1) {
        return false;
    } else {
        return true;
    }
}

std::string RPN::operator ()(int argc, const char *argv[]) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    std::string expression("");
    for (int i = 1; i < argc; i++)
        expression += argv[i];

    int answer;
    try {
        std::string tmpAns = rpn::convertToRpn(expression);
        answer = rpn::calculateRpn(tmpAns);
    }
    catch (int catchError) {
        help(argv[0]);
        switch (catchError) {
        case 1100: return "INVALID_SYMBOL";
        case 1200: return "UNDEFINED_OPERATION";
        case 1201: return "DIVISION_BY_ZERO";
        }
    }

    message_ += "Result: " + std::to_string(answer) + "\n" +
        "---------------------------------------" +
        "---------------------------------------";

    return message_;
}
