#ifndef HEADERS_IMPORTED
#include "main.h"
#include "commonFunctions.h"
#endif

//** this function shows the information of the user and history of goods
void doView(char* input, struct user* users, int loggedinUserId, struct buyerCart* buyerCart, int buyerCartCount, struct good* goods, int numberOfGoods)
{

    if (strtok(NULL, " ") != NULL)
    {
        printf("too much input arguments!");
        free(input);
        return;
    }

    printf("Displaying user Information:\n");
    printf("username: %s\t", users[loggedinUserId].username);
    printf("userType: %s\t", users[loggedinUserId].userType);
    printf("Deposit: %d\n", users[loggedinUserId].deposit);

    if (!strcmp(users[loggedinUserId].userType, "buyer"))
    {
        int thisUserBasket = 0;
        for (int i = 0; i < buyerCartCount; i++)
        {
            if (buyerCart[i].buyerId == loggedinUserId)
            {
                thisUserBasket++;
                printf("----\n");
                printf("Good Name:\t\t%s\n", goods[buyerCart[i].goodId].goodName);
                printf("Good Price:\t\t%d\n", goods[buyerCart[i].goodId].goodPrice);
                printf("Bought Count:\t\t%d\n", buyerCart[i].boughtCount);
                printf("Seller Username:\t%s\n", users[goods[buyerCart[i].goodId].sellerId].username);
            }
        }
        if (thisUserBasket == 0)
        {
            printf("you have no purchases!");
        }
    }
    else if (!strcmp(users[loggedinUserId].userType, "seller"))
    {
        int thisUserGoods = 0;
        for (int i = 0; i < numberOfGoods; i++)
        {
            if (goods[i].sellerId == loggedinUserId)
            {
                thisUserGoods++;
                printf("----\n");
                printf("Good Name:\t\t%s\n", goods[i].goodName);
                printf("Good Price:\t\t%d\n", goods[i].goodPrice);
                printf("Good Count:\t\t%d\n", goods[i].goodCount);
            }
        }
        if (thisUserGoods == 0)
        {
            printf("you have no goods!");
        }
    }

    free(input);
}