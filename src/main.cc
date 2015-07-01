// $Id$

#include <iostream>
#include <fstream>

#include "driver.h"

int main(int argc, char *argv[]) {
  query_rewriter::query_parser::Driver driver;

  for (int ai = 1; ai < argc; ++ai) {
    std::fstream infile(argv[ai]);
    if (!infile.good()) {
      std::cerr << "Could not open file: " << argv[ai] << std::endl;
      return 0;
    }

    bool result = driver.parse_stream(infile, argv[ai]);
    //if (result) {
    //  std::cout << "Expressions:" << std::endl;
    //  for (unsigned int ei = 0; ei < calc.expressions.size(); ++ei) {
    //    std::cout << "[" << ei << "]:" << std::endl;
    //    std::cout << "tree:" << std::endl;
    //    calc.expressions[ei]->print(std::cout);
    //    std::cout << "evaluated: "
    //    << calc.expressions[ei]->evaluate()
    //    << std::endl;
    //  }
    //}
    if (driver.GetAstNode() == nullptr) {
      std::cout << "failed!" << std::endl;
    } else {
      std::cout << "succeeded!" << std::endl;
      driver.GetAstNode()->Print();
    }
  }

  return 0;
}
