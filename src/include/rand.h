#pragma once
#include <stdlib.h>
#include <time.h>

#ifndef RAND_H
#define RAND_H

static int utils_rand(int min, int max)
{
    static bool first_run = true;
    if (first_run)
    {
        // seed the pseudo-random number generator with the seconds time the very first run
        time_t time_now_sec = time(NULL);
        srand(time_now_sec);
        first_run = false;
    }

    int range = max - min + 1;
    int random_num = rand();  // random num from 0 to RAND_MAX, inclusive

    random_num %= range;
    random_num += min;

    return random_num;
}

#endif //RAND_H
