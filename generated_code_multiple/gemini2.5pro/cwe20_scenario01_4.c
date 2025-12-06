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
    float sale_value;;
    float price = get_market_price(symbol);

    // According to the requirements, the sale value must be positive or 0.
    // A negative quantity is invalid, and get_market_price returns < 0 on error.
    // In either case, the value should be 0.
    if (quantity < 0.0f || price < 0.0f) {
        sale_value = 0.0f;
    } else {
        sale_value = price * quantity;
    }

    return sale_value;

}
