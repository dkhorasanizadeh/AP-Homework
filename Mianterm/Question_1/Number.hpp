#include <iostream>
#include <vector>
class Number {
 private:
  std::vector<int> number;
  bool negative;

 public:
  Number(void);
  Number(int n);
  Number(std::string n);
  Number(const Number &n);
  bool operator==(const Number &n) const;
  bool operator<=(const Number &n) const;
  bool operator<(const Number &n) const;
  bool operator>(const Number &n) const;
  friend std::istream &operator>>(std::istream &in, Number &n);
  friend std::ostream &operator<<(std::ostream &out, Number &n);
};