/*
--------------------------------------------------
Name    : Mobile Shop
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 10/Mar/2021
--------------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;
string lower(string s)
{
    string newString = s;
    for (int i = 0; i < s.length(); i++)
    {
        newString[i] = tolower(s[i]);
    }
    return newString;
}
class Phone
{
public:
    Phone(string model,
          string brand,
          int price,
          int cameraResolution,
          string color);
    string getModel(void);
    string getBrand(void);
    int getPrice(void);
    int getResolution(void);
    string getColor(void);
    void printInfo(void);

private:
    string model;
    string brand;
    int price;
    int cameraResolution;
    string color;
};
Phone::Phone(string _model,
             string _brand,
             int _price,
             int _cameraResolution,
             string _color)
{
    model = _model;
    brand = _brand;
    price = _price;
    cameraResolution = _cameraResolution;
    color = _color;
}
inline string Phone::getModel(void)
{
    return model;
}
inline string Phone::getBrand(void)
{
    return brand;
}
inline int Phone::getPrice(void)
{
    return price;
}
inline int Phone::getResolution(void)
{
    return cameraResolution;
}
inline string Phone::getColor(void)
{
    return color;
}
void Phone::printInfo(void)
{
    cout << "Model: " << model << endl
         << "Brand: " << brand << endl
         << "Price: " << price << endl
         << "Camera Resolution: " << cameraResolution << endl
         << "Color: " << color << endl
         << "------------------------" << endl;
}
class PhoneShop
{
public:
    void addPhone(Phone newPhone);
    void search(string type, vector<string> q);
    void search(string type, int q);

private:
    vector<Phone> phones;
    void searchByBrand(string brand);
    void searchByPrice(int price);
    void searchByCameraResolution(int resolution);
    void searchByColor(string color);
};
void PhoneShop::addPhone(Phone newPhone)
{
    phones.push_back(newPhone);
    cout << "Phone addeed successfully." << endl;
}
void PhoneShop::searchByBrand(string brand)
{
    brand = lower(brand);
    for (int i = 0; i < phones.size(); i++)
    {
        if (lower(phones[i].getBrand()) == brand)
        {
            phones[i].printInfo();
        }
    }
}
void PhoneShop::searchByPrice(int price)
{
    for (int i = 0; i < phones.size(); i++)
    {
        if (phones[i].getPrice() <= price)
        {
            phones[i].printInfo();
        }
    }
}
void PhoneShop::searchByCameraResolution(int resolution)
{
    for (int i = 0; i < phones.size(); i++)
    {
        if (phones[i].getResolution() == resolution)
        {
            phones[i].printInfo();
        }
    }
}
void PhoneShop::searchByColor(string color)
{
    color = lower(color);
    for (int i = 0; i < phones.size(); i++)
    {
        if (lower(phones[i].getColor()) == color)
        {
            phones[i].printInfo();
        }
    }
}
void PhoneShop::search(string type, vector<string> q)
{
    if (lower(type) == "color")
    {
        for (int i = 0; i < q.size(); i++)
        {
            searchByColor(q[i]);
        }
    }
    else if (lower(type) == "brand")
    {
        for (int i = 0; i < q.size(); i++)
        {
            searchByBrand(q[i]);
        }
    }
}
void PhoneShop::search(string type, int q)
{
    if (lower(type) == "price")
    {
        searchByPrice(q);
    }
    else if (lower(type) == "resolution")
    {
        searchByCameraResolution(q);
    }
}
int main(void)
{
    PhoneShop ABMobile;
    ABMobile.addPhone(Phone("Galaxy Note 10", "Samsung", 12000, 48, "Blue"));
    ABMobile.addPhone(Phone("Pocophone F1", "Xiaomi", 5000, 12, "Black"));
    ABMobile.addPhone(Phone("Iphone 12", "Apple", 20000, 16, "Gold"));
    ABMobile.addPhone(Phone("Xperia ZX", "Sony", 10000, 15, "Purple"));
    vector<string> brands;
    brands.push_back("APPLE");
    brands.push_back("samsung");
    ABMobile.search("brand", brands);
    ABMobile.search("Price", 11000);
    return 0;
}