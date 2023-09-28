#ifndef SDDS_POS_H
#define SDDS_POS_H
namespace sdds
{
    const double TAX = 0.13;
    const int MAX_SKU_LEN = 7;
    const int MIN_YEAR = 2000;
    const int MAX_YEAR = 2030;
    const int MAX_STOCK_NUMBER = 99;
    const int MAX_NO_ITEMS = 2000;
    const int MAX_NAME_LEN = 40;

    const int POS_LIST = 1;
    const int POS_FORM = 2;

    const char* const ERROR_POS_SKU = "SKU too long";
    const char* const ERROR_POS_NAME = "Item name too long";
    const char* const ERROR_POS_PRICE = "Invalid price value";
    const char* const ERROR_POS_TAX = "Invalid tax status";
    const char* const ERROR_POS_QTY = "Invalid quantity value";
    const char* const ERROR_POS_STOCK = "Item out of stock";
    const char* const ERROR_POS_EMPTY = "Invalid Empty Item";
}
#endif