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
    /* 1. Объявляем все переменные в начале функции (требование C90) */
    FILE *f;
    int greater;

    /* 2. Открываем файл */
    f = fopen("input_data.txt", "r");
    
    /* 3. Проверяем, успешно ли открылся файл */
    if (f == NULL)
    {
        printf("File error\n");
        return 1;
    }

    /* 4. Вызываем функцию, передавая ей уже открытый файл */
    greater = count_with_condition(f);

    /* 5. Выводим результат */
    if (greater > 0)
        printf("Greater: %d\n", greater);
    else if (greater < 0)
        printf("Less: %d\n", -greater);
    else
        printf("Equal\n");

    return 0;
}
