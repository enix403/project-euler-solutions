#include <stdio.h>

int sol1() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    return sum;
}

int sol2() {
    int sum = 0;
    for (int i = 3; i < 1000; i += 3) {
        sum += i;
    }
    
    for (int i = 5; i < 1000; i += 5) {
        // since some numbers, like 15 or 30 (both divisible by 3), are already 
        // calculated in the previous loop, we need to skip them
        if (i % 3 == 0) continue;
        sum += i;
    }
    
    return sum;
}


int sol3() {
    // some clever math
    
    // subtract a small amount from 1000 so that if 1000 is divisible by the number, it still does not count the 1000
    // the C language would then drop the fractional part since the datatype is int
    int num3 = (1000 - 0.2) / 3;
    int num5 = (1000 - 0.2) / 5;
    int num15 = (1000 - 0.2) / 15;
    
    // sum = (n * (2a + (n - 1) * d)) / 2
    int sum3 = (num3 * (2 * 3 + (num3 - 1) * 3)) / 2;
    int sum5 = (num5 * (2 * 5 + (num5 - 1) * 5)) / 2;
    int sum15 = (num15 * (2 * 15 + (num15 - 1) * 15)) / 2;
    
    return sum3 + sum5 - sum15;
}


int main() {
    printf("Answer using solution 1 = %d\n", sol1());
    printf("Answer using solution 2 = %d\n", sol2());
    printf("Answer using solution 3 = %d\n", sol3());
}

