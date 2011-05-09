#include "thermocouples.h"

double test_potentials[15] = {
    0.397,
    0.798,
    1.203,
    1.612,
    2.023,
    2.436,
    2.851,
    3.267,
    3.682,
    4.096,
    4.509,
    4.920,
    5.328,
    5.735,
    6.138
};

int main(void)
{
    unsigned char i;
    double sum_t = 0;
    double sum_p = 0;

    printf("%s %5s %5s\n", "T", "E(T)", "T(E(T))");
    printf("----------------\n");
    
    for (i = 10; i < 31; i++) {
        sum_p = reference_function(i);
        sum_t = inverse_function(sum_p);

        printf("%2d %2.3lf %2.3lf\n", i, sum_p, sum_t);
    }

    printf("\n%s %8s %5s\n", "E", "T(E)", "E(T(E))");
    printf("-------------------\n");

    for (i = 0; i < 15; i++) {
        sum_t = inverse_function(test_potentials[i]);
        sum_p = reference_function(sum_t);

        printf("%1.3lf %2.3lf %3.3lf\n", test_potentials[i], sum_t, sum_p);
    }

    return 0;
}
