#include "Number.hpp"
Number::Number(void) {
  number.push_back(0);
  negative = false;
}
Number::Number(int n) {
  if (n < 0) {
    negative = true;
    n = -n;
  } else {
    negative = false;
  }
  while (n) {
    number.push_back(n % 10);
    n /= 10;
  }
}
Number::Number(std::string n) {
  if (n[0] == '-') {
    negative = true;
    for (int i = n.length() - 1; i > 0; i--) {
      number.push_back(n[i] - '0');
    }
  } else {
    negative = false;
    for (int i = n.length() - 1; i >= 0; i--) {
      number.push_back(n[i] - '0');
    }
  }
}
Number::Number(const Number &n) { number = n.number; }
bool Number::operator==(const Number &n) const {
  if (number.size() != n.number.size()) {
    return false;
  }
  for (int i = 0; i < number.size(); i++) {
    if (n.number[i] != number[i]) {
      return false;
    }
  }
  return true;
}
bool Number::operator<=(const Number &n) const {
  if (this->operator==(n)) {
    return true;
  }
  if (negative && !n.negative) {
    return true;
  } else if (!negative && n.negative) {
    return false;
  }
  if (negative && n.negative) {
    if (number.size() < n.number.size()) {
      return false;
    } else if (number.size() > n.number.size()) {
      return true;
    } else {
      for (int i = 0; i < number.size(); i++) {
        if (number[i] < n.number[i]) {
          return false;
        }
      }
      return true;
    }
  }
  if (!negative && !n.negative) {
    if (number.size() > n.number.size()) {
      return false;
    } else if (number.size() < n.number.size()) {
      return true;
    } else {
      for (int i = 0; i < number.size(); i++) {
        if (number[i] > n.number[i]) {
          return false;
        }
      }
      return true;
    }
  }
}
bool Number::operator<(const Number &n) const {
  if (negative && !n.negative) {
    return true;
  } else if (!negative && n.negative) {
    return false;
  }
  if (negative && n.negative) {
    if (number.size() < n.number.size()) {
      return false;
    } else if (number.size() > n.number.size()) {
      return true;
    } else {
      for (int i = 0; i < number.size(); i++) {
        if (number[i] < n.number[i]) {
          return false;
        }
      }
      return true;
    }
  }
  if (!negative && !n.negative) {
    if (number.size() > n.number.size()) {
      return false;
    } else if (number.size() < n.number.size()) {
      return true;
    } else {
      for (int i = 0; i < number.size(); i++) {
        if (number[i] > n.number[i]) {
          return false;
        }
      }
      return true;
    }
  }
}
bool Number::operator>(const Number &n) const {
  if (negative && !n.negative) {
    return false;
  } else if (!negative && n.negative) {
    return true;
  }
  if (negative && n.negative) {
    if (number.size() < n.number.size()) {
      return true;
    } else if (number.size() > n.number.size()) {
      return false;
    } else {
      for (int i = 0; i < number.size(); i++) {
        if (number[i] > n.number[i]) {
          return false;
        }
      }
      return true;
    }
  }
  if (!negative && !n.negative) {
    if (number.size() > n.number.size()) {
      return true;
    } else if (number.size() < n.number.size()) {
      return false;
    } else {
      for (int i = 0; i < number.size(); i++) {
        if (number[i] < n.number[i]) {
          return false;
        }
      }
      return true;
    }
  }
}
std::istream &operator>>(std::istream &in, Number &nIn) {
  std::string n;
  in >> n;
  nIn.number.clear();
  if (n[0] == '-') {
    nIn.negative = true;
    for (int i = n.length() - 1; i > 0; i--) {
      nIn.number.push_back(n[i] - '0');
    }
  } else {
    nIn.negative = false;
    for (int i = n.length() - 1; i >= 0; i--) {
      nIn.number.push_back(n[i] - '0');
    }
  }
  return in;
}
std::ostream &operator<<(std::ostream &out, Number &nOut) {
  if (nOut.negative) {
    out << "-";
  }
  for (int i = nOut.number.size() - 1; i >= 0; i--) {
    out << nOut.number[i];
  }
  out << std::endl;
  return out;
}