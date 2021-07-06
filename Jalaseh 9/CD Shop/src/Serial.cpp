#include "../include/CD.hpp"
namespace CDShop {
void Serial::setData(void) {
  std::cin >> Name >> Director >> Duration >> Season >> Episode;
}
void Serial::showData(void) {
  std::cout << Name << " " << Director << " " << Duration << " " << Season
            << " " << Episode << std::endl;
}
}  // namespace CDShop