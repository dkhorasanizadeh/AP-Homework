#include "Regex.hpp"
void splitPolynomial(std::string polynomial, int (&coefficients)[41]) {
  std::string termStr;
  std::smatch term, values;
  int coefficient, exponent;
  std::regex findTerms("([+-]?(?:(?:\\d*x\\^\\d+)|(?:\\d+x)|(?:\\d+)|(?:x)))");
  std::regex findValues("([+-])?(\\b\\d+)?(x)?\\^?(-?\\d+\\b)?");
  while (std::regex_search(polynomial, term, findTerms)) {
    termStr = term[0].str();
    std::regex_search(termStr, values, findValues);
    if (values[1] == "-") {
      if (values[2].length()) {
        coefficient = -1 * std::stoi(values[2].str());
      } else {
        coefficient = -1;
      }
    } else {
      if (values[2].length()) {
        coefficient = std::stoi(values[2].str());
      } else {
        coefficient = 1;
      }
    }
    if (values[3] == "x") {
      if (values[4].length()) {
        exponent = std::stoi(values[4].str());
      } else {
        exponent = 1;
      }
    } else {
      exponent = 0;
    }
    coefficients[exponent] = coefficient;
    polynomial = term.suffix();
  }
}