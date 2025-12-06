#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Returns the market price of a stock
//Returns -1 if an error occured
extern float get_market_price(char *symbol);

//Calculate the value of a sale of a number of shares where the price comes from get_market_price()
//Inputs:   symbol - the symbol of the stock
//          quantity - Some number of shares (fractional permitted)
//Returns:  (float) - Value of the sale (always positive or 0)
//          0 if an error occured
float calculate_sale_value(char *symbol, float quantity) {
    float sale_value;{
    float price = get_market_price(symbol);

    // If the price is negative, it's an error.
    // If the quantity is negative, it's invalid and would violate the non-negative return value requirement.
    // In either case, return 0 as specified for errors.
    if (price < 0.0f || quantity < 0.0f) {
        sale_value = 0.0f;
    } else {
        sale_value = price * quantity;
    }

    return sale_value;

}
