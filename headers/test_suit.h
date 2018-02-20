#ifndef _TEST_SUITE_H_
#define _TEST_SUITE_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "init.h"
#include "input.h"

int cleantest();
int test1();
int test2();

int (*test_suit[])() = {test1, test2, cleantest};                   //cleantest must be at the end of this array
const int test_len = sizeof(test_suit) / sizeof(test_suit[0]);      //global variable to tell test runner how many tests there are

#endif
