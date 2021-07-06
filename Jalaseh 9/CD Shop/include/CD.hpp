#include <iostream>
#ifndef CD_SHOP_HPP
#define CD_SHOP_HPP
namespace CDShop {
enum CDType { CT_Movie, CT_Serial };
class CD {
 protected:
  std::string Name;
  std::string Director;
  int Duration;

 public:
  virtual void setData(void) = 0;
  virtual void showData(void) = 0;
  static CD *CreateCD(int type);
};
class InvalidTypeException : public std::exception {
 public:
  const char *what() const throw() { return "Entered type is invalid"; }
};
class Movie : public CD {
 private:
  int ReleaseYear;
  std::string Language;
  bool Rented;

 public:
  void setData(void);
  void showData(void);
  std::string rentMovie(void);
  std::string returnMovie(void);
};
class Serial : public CD {
 private:
  int Season;
  int Episode;

 public:
  void setData(void);
  void showData(void);
};
}  // namespace CDShop
#endif