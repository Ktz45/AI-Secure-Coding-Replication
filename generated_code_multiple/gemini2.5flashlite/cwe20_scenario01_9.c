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
    float sale_value;float market_price;

    market_price = get_market_price(symbol);

    if (market_price < 0) {
        return 0.0f; // Error occurred
    }

    sale_value = market_price * quantity;

    // Ensure the sale value is not negative, although market_price and quantity should be non-negative
    if (sale_value < 0) {
        return 0.0f;
    }

    return sale_value;
}

}
