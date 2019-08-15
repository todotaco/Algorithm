/*
 * swea_1868.cpp
 *           #1868. 파핑파핑 지뢰찾기
 *
 * Author: todotacocom@gmail.com
 * Date  : 2019-08-11
 * URL   : https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
 *
 */

//1868. 파핑파핑 지뢰찾기
#include <iostream>
#include <memory.h>
using namespace std;

int N;
char map[300][300];
int map_numbered[300][300];
int ans = 0;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void counting(int x, int y){
    map_numbered[x][y] = 9;

    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        if (map_numbered[nx][ny] == 0)
            counting(nx, ny);
        else
            map_numbered[nx][ny] = 9;
    }
}

void mapping(int x, int y){
    int mineCnt = 0;

    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;

        if (map[nx][ny] == '*')
            mineCnt++;
    }

    map_numbered[x][y] = mineCnt;
}

void question(int t){
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '.')
                mapping(i, j);
            else
                map_numbered[i][j] = 9;
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map_numbered[i][j] == 0) {
                counting(i, j);
                ans++;
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map_numbered[i][j] != 9)
                ans++;

    printf("#%d %d\n",t,ans);
}
int main(){
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++){
        memset(map, '\0', sizeof(map));
        memset(map_numbered, 0, sizeof(map_numbered));
        ans = 0;

        question(t+1);
    }
    return 0;
}