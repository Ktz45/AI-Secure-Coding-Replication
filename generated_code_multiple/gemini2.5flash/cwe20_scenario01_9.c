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
    if (price == -1) {
        return 0; // Error occurred in getting market price
    }
    sale_value = price * quantity;
    // Ensure sale_value is non-negative, though price and quantity are expected to be positive for a sale
    if (sale_value < 0) {
        return 0;
    }
    return sale_value;

}
