// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
    if (value == 2) {
        return true;
    } else {
        uint64_t lim = 0;
        while (lim * lim < value) lim++;
        for (uint64_t i = 2; i < lim+1; i++) {
            if (value % i == 0) {
                return false;
            }
        }
        return true;
    }
}

uint64_t nPrime(uint64_t n) {
    uint64_t i = 0;
    uint64_t iter = 2;
    while (1) {
        i += static_cast<uint64_t>(checkPrime(iter));
        if (i == n) return iter;
        iter++;
    }
}

uint64_t nextPrime(uint64_t value) {
    uint64_t iter = value+1;
    while (iter < UINT64_MAX) {
        if (checkPrime(iter)) return iter;
        iter++;
    }
    return 0;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i))sum += i;
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t count = 0;
    for (; lbound < hbound - 2; lbound++) {
        if (checkPrime(lbound) && checkPrime(lbound + 2)) {
            count++;
        }
    }
    return count;
}
