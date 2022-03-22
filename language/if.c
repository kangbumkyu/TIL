#include <stdio.h>

enum {
    FALSE = 0,
    TRUE = 1
};
int main()
{
    int is_true = TRUE;

    if (is_true == TRUE) {
        printf("It's true!");
    }
    else {
        printf("It's false!");
    }

    is_true ? printf("It's true!") : printf("It's false!");

    return 0;
}

