//
//  main.cpp
//  ggg
//
//  Created by Михаил Козлов on 07.10.2021.
//

#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int M[20][20];
    int N;
    printf("введи размерность");
    scanf("%d", &N);
    while (N < 1 || N>20)
    {
        printf("ошибка\n");
        scanf("%d", &N);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("M[%d][%d]= ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }
    int  max =-100000000, min = 100000000;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (M[i][j] < min)
                min = M[i][j];
            else
                if (M[i][j] > max)
                    max = M[i][j];
    }
    printf("Max=%d, min=%d\n", max, min);
    int average = (min + max) / 2;
    printf("(min+max)/2=%d\n", (min + max) / 2);
        if (average >= 0)
        {
            for (int i = 0; i < N; i++){
                int x;
                x=M[i][i];
                M[i][i]=M[i][N-1-i];
                M[i][N-1-i]=x;
            }
            
        }
    if (average < 0)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                M[i][j] = -1 * M[i][j];
    }
        for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }

      return 0;
}

