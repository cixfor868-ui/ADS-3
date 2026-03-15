// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;

    while (num > 1) {
        if (num % 2 == 0) {
            num /=  2;
        } else {
            num = 3 * num + 1;
        }
        if (maxVal<num) {
            maxVal = num;
        }
    }
    return maxVal;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num > 1) {
        if (num % 2 == 0) {
            num /=  2;
        } else {
            num = 3 * num + 1;
        }

        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int* maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int bestNum = lbound;
    unsigned int bestLen = collatzLen(lbound);
    for (uint64_t n = lbound + 1; n <= rbound; n++) {
        unsigned int len = collatzLen(n);
        if (len > bestLen) {
            bestLen = len;
            bestNum = n;
        }
    }
    *maxlen = bestLen;
    return bestNum;
}
