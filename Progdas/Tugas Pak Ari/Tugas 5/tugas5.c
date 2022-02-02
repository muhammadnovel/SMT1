#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matchString(char token[], char obj[])
{
    int lengthObj = strlen(obj);
    int lengthToken = strlen(token);
    int cekString = 0;
    int cekChar = 0;

    if (lengthToken == 1)
    {
        for (int i = 0; i < lengthToken; i++)
        {
            for (int j = 0; j < lengthObj; j++)
            {
                if (obj[j] == token[i])
                {
                    cekChar++;
                }
            }
        }
    }
    else
    {
        char *tokens;
        tokens = strtok(obj, " ");

        while (tokens != NULL)
        {
            if (strcmp(tokens, token) == 0)
            {
                cekString++;
            }

            tokens = strtok(NULL, " ");
        }
    }

    if (cekChar > 0)
    {
        printf(">> Ditemukan %d karakter %s", cekChar, token);
    }
    else if (cekString > 0)
    {
        printf(">> Ditemukan %d kata %s", cekString, token);
    }
    else
    {
        printf(">> Tidak ditemukan karakter / kata %s", token);
    }

    printf("\n");
}

int search(char obj[], char src[])
{

    char *token;
    token = strtok(src, ",");

    printf("==============\n");

    while (token != NULL)
    {
        printf("[?] Search %s\n", token);
        matchString(token, obj);
        token = strtok(NULL, ",");
    }
}

int main(void)
{
    char obj[100];
    char src[100];

    printf("Masukan Kata : ");
    scanf("%[^\n]s", obj);

    printf("Masukan karakter yang ingin di cari (pisahkan dengan koma tanpa spasi): ");
    scanf("%s", src);

    search(obj, src);
}