/*
 * swea_4615.cpp
 *           #4615. 재미있는 오셀로 게임
 *
 * Author: todotacocom@gmail.com
 * Date  : 2019-08-05
 * URL   : https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
 *
 */

//4615. 재미있는 오셀로 게임
#include <iostream>
#include <memory.h> //SWEA 컴파일시 필요
using namespace std;

int N, M;
int map[10][10]; // 흑돌 1, 백돌 2

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void coloring(int x, int y, int dol, int dir){
    int cx = x + dx[dir];
    int cy = y + dy[dir];
    
    int cnt = 0;
    int check = false;
    
    while (cx >= 0 && cy >= 0 && cx < N && cy < N && map[cx][cy] != 0) {
        cnt++;
        
        if (map[cx][cy] == dol) {
            check = true;
            break;
        }
        
        cx += dx[dir];
        cy += dy[dir];
    }
    
    if (check == false)
        cnt = 0;
    
    for (int c = 0; c < cnt; c++) {
        map[x][y] = dol;
        
        x += dx[dir];
        y += dy[dir];
    }
}

void finding(int x, int y, int dol){
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || map[nx][ny] == 0)
            continue;
        
        if (map[nx][ny] != dol)
            coloring(nx, ny, dol, k);
    }
}

int main(){
    int test_case;
    cin >> test_case;
    
    for (int t = 0; t < test_case; t++) {
        cin >> N >> M;
        
        map[N/2 - 1][N/2 - 1] = 2;
        map[N/2][N/2] = 2;
        map[N/2 - 1][N/2] = 1;
        map[N/2][N/2 - 1] = 1;
        
        for (int m = 0; m < M; m++) {
            int x, y, dol;
            scanf("%d %d %d", &x, &y, &dol);
            map[x-1][y-1] = dol;
            
            finding(x-1, y-1, dol);
        }
        
        int black = 0;
        int white = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1)
                    black++;
                else if (map[i][j] == 2)
                    white++;
            }
        }
        
        printf("#%d %d %d\n", t+1, black, white);
        memset(map, 0, sizeof(map));
    }
    
    return 0;
}