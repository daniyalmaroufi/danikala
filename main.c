#ifndef HEADERS_IMPORTED
#include "main.h"
#include "commonFunctions.c"
#include "commonFunctions.h"
#endif

#include "AddGoods.c"
#include "AddGoods.h"
#include "Buy.c"
#include "Buy.h"
#include "Deposit.c"
#include "Deposit.h"
#include "Login.c"
#include "Login.h"
#include "Logout.c"
#include "Logout.h"
#include "ShowGoods.c"
#include "ShowGoods.h"
#include "Signup.c"
#include "Signup.h"
#include "View.c"
#include "View.h"

int main()
{
    printf("Welcome To DaniKala!");

    struct user *usersHead = (struct user *)malloc(sizeof(struct user));
    usersHead->next = NULL;
    int numberOfGoods = 0;
    struct good *goods = NULL;
    char *command;
    struct user *loggedinUser = NULL;
    int buyerCartCount = 0;
    struct buyerCart *buyerCart = NULL;

    while (TRUE)
    {
        // gettng input from user and checking for the entered command
        printf("\nEnter your Command:");
        char *input = getCommandLine();
        checkMalloc(input);
        command = strtok(input, " ");

        if (!strcmp(command, "signup") && loggedinUser == NULL)
        {
            doSignup(input, usersHead);
        }
        else if (!strcmp(command, "login") && loggedinUser == NULL)
        {
            doLogin(input, usersHead, &loggedinUser);
        }
        else if (!strcmp(command, "logout") && loggedinUser != NULL)
        {
            doLogout(input, &loggedinUser);
        }
        else if (!strcmp(command, "view") && loggedinUser != NULL)
        {
            doView(input, loggedinUser, buyerCart, buyerCartCount, goods, numberOfGoods);
        }
        else if (!strcmp(command, "deposit") && loggedinUser != NULL && !strcmp(loggedinUser->userType, "buyer"))
        {
            doDeposit(input, loggedinUser);
        }
        else if (!strcmp(command, "add_goods") && loggedinUser != NULL && !strcmp(loggedinUser->userType, "seller"))
        {
            doAddGoods(input, loggedinUser, &goods, &numberOfGoods);
        }
        // else if (!strcmp(command, "show_goods") && loggedinUserId != -1)
        // {
        //     doShowGoods(input, goods, numberOfGoods, users);
        // }
        // else if (!strcmp(command, "buy") && loggedinUserId != -1 && !strcmp(users[loggedinUserId].userType, "buyer"))
        // {
        //     doBuy(input, &goods, numberOfGoods, &users, loggedinUserId, &buyerCart, &buyerCartCount);
        // }
        else
        {
            printf("Command Not Found!");
            free(input);
        }
    }

    // clearing all allocated memories
    // for (int i = 0; i < numberOfUsers; i++)
    // {
    //     free(users[i].username);
    //     free(users[i].password);
    //     free(users[i].userType);
    // }
    // free(users);

    for (int i = 0; i < numberOfGoods; i++)
    {
        free(goods[i].goodName);
    }
    free(goods);

    free(buyerCart);
    return 0;
}
