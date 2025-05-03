#include <stdio.h>

int main(){
    const char *item_name[] = {"pizza", "chips", "coca cola"};

    //Item prices
    int pizza_price = 10;
    int chips_price = 5;
    int coca_price = 7;

    //item stock
    int pizza_qty = 10;
    int chips_qty = 7;
    int coca_qty = 10;

    int choice;
    int buy_qty;

    int total;

    //Menu
    printf("Hi, Welcome to Benga Shop \n");
    printf("What do you want to buy?\n");
    printf("Sl --- Item --- Price -- Qyty \n");
    printf("1.     %s --     %d -- %d \n", item_name[0], pizza_price, pizza_qty);
    printf("2.     %s --     %d -- %d \n", item_name[1], chips_price, chips_qty);
    printf("3.     %s --     %d -- %d \n", item_name[2], coca_price, coca_qty);
    printf("Enter you choice: ");
    scanf(" %d", &choice);
    printf("Enter your qty: ");
    scanf(" %d", &buy_qty);


    // Price Calculation
    if (choice == 1){
        total = pizza_price * buy_qty;
        printf("The total price is %d$ \n", total);
    }
    else if (choice == 2){
        total = chips_price * buy_qty;
        printf("The total price is %d$ \n", total);
    }
    else if (choice == 3){
        total = coca_price * buy_qty;
        printf("The total price is %d$ \n", total);
    }
    else{
        printf("Please enter correct value");
    }
    return 0;
}