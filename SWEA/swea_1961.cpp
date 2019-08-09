/*
 * swea_1961.cpp
 *           #1961. 숫자 배열 회전
 *
 * Author: todotacocom@gmail.com
 * Date  : 2019-03-06
 * URL   : https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
 *
 */

//1961. 숫자 배열 회전
#include <stdio.h>
#include <memory.h> //SWEA 컴파일시 필요

int map[8][8];

int map_90[8][8];
int map_180[8][8];
int map_270[8][8];

int N;

void pArr(int arr[8][8]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotation_90(int input[8][8], int output[8][8]) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            output[i][j] = input[N - 1 - j][i];
        }
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    for (int t = 1; t <= testcase; t++)
    {
        N = 0;
        memset(map, 0, sizeof(map));
        memset(map_90, 0, sizeof(map_90));
        memset(map_180, 0, sizeof(map_180));
        memset(map_270, 0, sizeof(map_270));

        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }

        rotation_90(map, map_90);
        rotation_90(map_90, map_180);
        rotation_90(map_180, map_270);

        /*pArr(map);
         pArr(map_90);
         pArr(map_180);
         pArr(map_270);*/

        printf("#%d\n", t);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d", map_90[i][j]);
            }
            printf(" ");

            for (int j = 0; j < N; j++)
            {
                printf("%d", map_180[i][j]);
            }
            printf(" ");

            for (int j = 0; j < N; j++)
            {
                printf("%d", map_270[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}