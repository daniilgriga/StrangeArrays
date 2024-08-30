#include <stdio.h>
#include <stdlib.h>

struct array_view
{
    int* mem;
    size_t digits;
};

void communicate (void);

int input(size_t* a);

int enter_coeff(size_t* a);

void clean_buffer(void);

int main (void)
{
    communicate();
}


void communicate (void)
{
    size_t n_rows = 0;

    printf("Enter the desired number of rows: ");
    enter_coeff(&n_rows);

    char* buffer = (char*)calloc(n_rows, sizeof(struct array_view));
    struct array_view* arrays = (struct array_view*)buffer;

    int* data_beginning = (int*)(arrays + n_rows);
    size_t nabeg_summ1 = 0;
    size_t addr = 0;
    for (size_t i = 0; i < n_rows; i++)
    {
        printf("\nEnter the desired number of digits in %zu row: ", i);
        scanf("%zu", &(arrays[i]).digits);

        nabeg_summ1 += arrays[i].digits;
    }
    addr = (size_t)data_beginning + nabeg_summ1;

    buffer = (char*)realloc(buffer, (size_t)(n_rows * sizeof(struct array_view*) + addr * sizeof(int)));
    arrays = (struct array_view*)buffer;

    data_beginning = (int*)(arrays + n_rows);

    size_t nabeg_summ2 = 0;
    for (size_t i = 0; i < n_rows; i++)
    {

        nabeg_summ2 += arrays[i].digits;
        arrays[i].mem = data_beginning + nabeg_summ2;
        for (size_t j = 0; j < arrays[i].digits; j++)
        {
            printf("\nEnter the desired numbers in %zu row: ", i);
            scanf("%d", &arrays[i].mem[j]);
        }
    }


    for (size_t y = 0; y < n_rows; y++)
    {
        for (size_t x = 0; x < arrays[y].digits ; x++)
        {
            printf("data[%zu][%zu] = %d   ", y, x, arrays[y].mem[x]);
        }
        // printf("\n");
        putchar('\n');
    }

    free(buffer);
}


int input(size_t* a)
{
    int n = 0;
    if(scanf("%zu", a) == 1)
    {
        if(((n = getchar()) == '\n') || (n == EOF))
            return 0;

        clean_buffer();
        return 1;
    }
    else
    {
        clean_buffer();
        return 1;
    }
}


int enter_coeff(size_t* a)
{
    for(int i = 0; i < 5; i++)
    {
        if(input(a) == 0)
            return 0;

        printf("You didn't enter a number!\n");
    }

    printf("Goodbye! Don't come in this programm anymore :D\n");
    return 1;
}


void clean_buffer(void)
{
    while((getchar()) != '\n') {;}
}
