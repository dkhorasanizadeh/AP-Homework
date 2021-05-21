#include "../include/CD.hpp"
namespace CDShop
{
    CD *CD::CreateCD(int type)
    {
        try
        {
            switch (type)
            {
            case 1:
                return new Movie();
            case 2:
                return new Serial();
            default:
                throw InvalidTypeException();
                break;
            }
        }
        catch (InvalidTypeException &e)
        {
            std::cout << e.what();
            std::exit(1);
        }
    }
} // namespace CDShop