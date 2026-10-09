#include <stdio.h>

int count_with_condition(FILE *f);
int count_with_condition(FILE *f)
{
    double first = 0., current = 0.;
    int count = 0;

    if (fscanf(f, "%lf", &first) != 1)
    {
        printf("File is empty\n");
        return 0;
    }

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (current > first)
            count++;
        else if (current < first)
            count--;
    }
    return count;
}

int main(void)
{
    FILE *f;
    int greater;
    
    f = fopen("input_data.txt", "r");
    
    if (f == NULL)
    {
        printf("File error\n");
        return 1;
    }

    greater = count_with_condition(f);

    if (greater > 0)
        printf("Greater: %d\n", greater);
    else if (greater < 0)
        printf("Less: %d\n", -greater);
    else
        printf("Equal\n");

    return 0;
}
