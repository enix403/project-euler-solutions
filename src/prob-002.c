#include <stdio.h>
#include <time.h>

int sol1()
{
    int sum = 0;
    int prev = 0;
    int current = 1;
    int next = 1;

    while (next <= 4e6)
    {
        prev = current;
        current = next;
        next = current + prev;

        if (current % 2 == 0)
            sum += current;
    }

    return sum;
}
 

int sol2()
{
    int prev = 0;
    int next = 1;

    while (next < 4e6)
    {
        next = prev + next;
        prev = next - prev;
    }

    if (next % 2 == 0)
        next += next + prev;
    else if (prev % 2 == 0)
        next += prev;

    return (next - 1) / 2;
}

void Benchmark(int (*func)(), int num_loops, int sol_number)
{
    float start_time = (float)clock() / CLOCKS_PER_SEC;

    for (int i = 0; i < num_loops; i++)
    {
        func();
    }

    float end_time = (float)clock() / CLOCKS_PER_SEC;
    float time = (end_time - start_time) / num_loops;

    printf("Solution %d ==> %d Loops: avg %.5f ns per loop\n", sol_number, num_loops, time * 1e9);
}

int main()
{

    printf("Solution 1: answer = %d\n", sol1());
    printf("Solution 2: answer = %d\n", sol2());
    printf("\n========================================================\n\n");
    Benchmark(sol1, 50000, 1);
    Benchmark(sol2, 50000, 2);
}