#include <math.h>
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("input_data.txt", "r");
    if (f == NULL)
    {
        printf("File error");
        return 0;
    }

    double first, current;
    int greater = 0, less = 0;

    if (fscanf(f, "%lf", &first) != 1)
    {
        printf("File is empty");
        return 0;
    }

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (current > first)
        {
            greater += 1;
        }
        else if (current < first)
        {
            less += 1;
        }
    }

    if (greater > less)
        printf("Greater: %d > %d", greater, less);
    else if (less > greater)
        printf("Less: %d > %d", less, greater);
    else
        printf("Equal: %d = %d", greater, less);

    return 0;
}
