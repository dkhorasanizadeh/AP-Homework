/*
--------------------------------------------------
Name    : DateTime
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#include "../include/Utility.hpp"
std::vector<std::string> split(std::string s, std::string delimiter) {
  int pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;
  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }
  res.push_back(s.substr(pos_start));
  return res;
}
std::string makeTwoDigit(int number) {
  if (number >= 0 && number <= 9) {
    return "0" + std::to_string(number);
  } else if (number > 9) {
    return std::to_string(number);
  }
  return "";
}