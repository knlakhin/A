#include <stdio.h>

int main(void)
{
    FILE *f = fopen("input_data.txt", "r");
    if (f == NULL)
    {
        printf("File error\n");
        return 1;
    }

    double first, current;
    int greater = 0;

    if (fscanf(f, "%lf", &first) != 1)
    {
        printf("File is empty\n");
        fclose(f);
        return 1;
    }

    while (fscanf(f, "%lf", &current) == 1)
    {
        if (current > first)
            greater++;
        else if (current < first)
            greater--;
    }

    fclose(f);

    if (greater > 0)
        printf("Greater: %d\n", greater);
    else if (greater < 0)
        printf("Less: %d\n", -greater);
    else
        printf("Equal\n");

    return 0;
}
