// Copyright 2018 Mayachkin Arseny

#include "include/heap.hpp"
#include "include/heap_app.hpp"

#include <fstream>
#include <functional>
#include <exception>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>


HeapApp::HeapApp() : message_("") {}

void HeapApp::help(const char* appname, const char* message) {
  message_ =
  std::string(message) +
  "This is a heap application.\n\n" +
  "Please provide arguments in the following format:\n\n" +
  "  $ " + appname + " <dimension of heap> " +
  "<type of heap, '<' or '>' , optional> "+ "<element 1> " +
  "...<element 2>\n\n" + "Where first argument > 0 " +
  "and all arguments are positive integers\n";
}

bool HeapApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  }
  return true;
}

int parseInt(const char* arg) {
  int value = std::stoi(std::string(arg));
  return value;
}

std::string HeapApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    if (strcmp(argv[2], "<") == 0) {
      int dimension = parseInt(argv[1]);
      atal::heap<int, std::less<int>> h;
      h.setDim(dimension);

      for (int i = 3; i < argc; i++) {
        h.push(parseInt(argv[i]));
      }
      std::ostringstream stream;
      stream << "Your heap:\n{ ";
      stream << "size = " << h.size();
      stream << ", dim = " << h.getDim();
      stream << ", top = " << h.top();
      stream << " }\n";
      message_ = stream.str();
      return message_;
    } else if (strcmp(argv[2], ">") == 0) {
      int dimension = parseInt(argv[1]);
      atal::heap<int, std::greater<int>> h;
      h.setDim(dimension);

      for (int i = 3; i < argc; i++) {
        h.push(parseInt(argv[i]));
      }
      std::ostringstream stream;
      stream << "Your heap:\n{ ";
      stream << "size = " << h.size();
      stream << ", dim = " << h.getDim();
      stream << ", top = " << h.top();
      stream << " }\n";
      message_ = stream.str();
      return message_;
    } else {
      int dimension = parseInt(argv[1]);
      atal::heap<int> h;
      h.setDim(dimension);

      for (int i = 2; i < argc; i++) {
        h.push(parseInt(argv[i]));
      }
      std::ostringstream stream;
      stream << "Your heap:\n{ ";
      stream << "size = " << h.size();
      stream << ", dim = " << h.getDim();
      stream << ", top = " << h.top();
      stream << " }\n";
      message_ = stream.str();
      return message_;
    }
  }
  catch(std::exception& exc) {
    return std::string("Wrong format or value is out of range");
  }
}
