#include "../include/CD.hpp"
namespace CDShop
{
    void Movie::setData(void)
    {
        std::cin >> Name >> Director >> Duration >> ReleaseYear >> Language >> Rented;
    }
    void Movie::showData(void)
    {
        std::cout << Name << " "
                  << Director << " "
                  << Duration << " "
                  << ReleaseYear << " "
                  << Language << " "
                  << Rented << std::endl;
    }
    std::string Movie::rentMovie(void)
    {
        if (Rented)
        {
            return "Not Returned Yet";
        }
        Rented = true;
        return "Rented Successfully";
    }
    std::string Movie::returnMovie(void)
    {
        if (!Rented)
        {
            return "Not Rented Yet";
        }
        Rented = false;
        return "Returned Successfully";
    }
} // namespace CDShop