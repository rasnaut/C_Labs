
#include "massiv.h"


int check(int *num) {
    int val;
    int chk;
    bool state = false;
    while(state == false) {
        chk = scanf("%d", &val);
        if (chk == EOF) {
            return -1;
        }
        if (chk != 1) {
            printf("Incorrect value!\n");
            printf("Try again: ");
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        else {
            state = true;
            break;
        }
    }
    *num = val;
    return 0;
}
