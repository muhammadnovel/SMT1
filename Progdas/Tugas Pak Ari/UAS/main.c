// Gunakan Code Block Untuk menjalankan Program.
// Code By Muhammad Novel - 202110370311320

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long faktorial(int n)
{
    long t = 1;

    for (int i = 1; i <= n; i++)
    {
        t *= i;
    }

    return t;
}

int n_persegi(int n)
{
    return pow(n, 2);
}

void g_persegi(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int n_persegiPanjang(int n)
{
    return n * (n + 1);
}

void g_persegiPanjang(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int n_segitiga(int n)
{
    int t = 1 * n * (n + 1);
    return t / 2;
}

void g_segitiga(int n)
{
    int l = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = l; j >= 1; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
        l--;
    }
}

int n_pascal(int n)
{
    return pow(2, n - 1);
}

void g_pascal(int n)
{

    int l = n;
    for (int i = 0; i < n; i++)
    {

        for (int k = l; k >= 1; k--)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("%d ", faktorial(i) / (faktorial(j) * faktorial(i - j)));
        }
        printf("\n");
        l--;
    }
}

int main(void)
{
    system("clear");
    char *bentuk[100] = {
        "Persegi",
        "Persegi Panjang",
        "Segitiga",
        "Pacal",
    };
    int menu, min, max;

    printf("1. Pola Bilangan Persegi\n");
    printf("2. Pola Bilangan Persegi Panjang\n");
    printf("3. Pola Bilangan Segitiga\n");
    printf("4. Pola Bilangan Pascal\n\n");

    printf("Pilih Menu : ");
    scanf("%d", &menu);

    printf("Min : ");
    scanf("%d", &min);

    printf("Max : ");
    scanf("%d", &max);

    printf("====================================\n");

    for (int i = min; i <= max; i++)
    {
        if (menu == 1)
        {
            printf("Pola Bilangan %s Dengan N = %i\n", bentuk[menu - 1], n_persegi(i));
            g_persegi(i);
        }
        else if (menu == 2)
        {
            printf("Pola Bilangan %s Dengan N = %i\n", bentuk[menu - 1], n_persegiPanjang(i));
            g_persegiPanjang(i);
        }
        else if (menu == 3)
        {
            printf("Pola Bilangan %s Dengan N = %i\n", bentuk[menu - 1], n_segitiga(i));
            g_segitiga(i);
        }
        else if (menu == 4)
        {
            printf("Pola Bilangan %s Dengan N = %i\n", bentuk[menu - 1], n_pascal(i));
            g_pascal(i);
        }
        printf("\n");
    }
}