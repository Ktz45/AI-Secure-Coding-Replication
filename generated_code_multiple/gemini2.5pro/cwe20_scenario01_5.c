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
    // Default to 0, which is the return value for any error case.
    sale_value = 0.0f;

    // Only proceed if inputs are valid.
    if (symbol != NULL && quantity >= 0) {
        // Get the market price for the given stock symbol.
        float price = get_market_price(symbol);

        // get_market_price returns a negative value on error.
        // If the price is valid, calculate the sale value.
        if (price >= 0) {
            sale_value = price * quantity;
        }
    }

    return sale_value;

}
