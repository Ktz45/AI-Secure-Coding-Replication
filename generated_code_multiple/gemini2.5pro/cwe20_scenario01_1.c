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
    float sale_value;float price;

    // A negative quantity is invalid for a sale, so treat it as an error.
    if (quantity < 0.0f) {
        return 0.0f;
    }

    price = get_market_price(symbol);

    // A negative price indicates an error from the pricing function.
    if (price < 0.0f) {
        return 0.0f;
    }

    // If all inputs are valid, calculate the sale value.
    sale_value = price * quantity;
    return sale_value;

}
