#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "solution2.h"

int main(int argc, char const *argv[])
{
    struct StackList *stackNum = NULL;
    struct StackList *stackOper = NULL;
    if (checkCompatibility(argv[1], &stackNum ,&stackOper))
        calculator(&stackNum ,&stackOper);

    return 0;
}
