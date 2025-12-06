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
    float sale_value;float price = get_market_price(symbol);

    // An error is indicated by a negative price. A negative quantity is also invalid
    // as the sale value must be non-negative. In case of an error, return 0.
    if (price < 0.0f || quantity < 0.0f) {
        sale_value = 0.0f;
    } else {
        // Otherwise, calculate the value.
        sale_value = price * quantity;
    }

    return sale_value;

}
