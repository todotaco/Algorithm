/*
 * swea_4613.cpp
 *           #4613. 러시아 국기 같은 깃발
 *
 * Author: todotacocom@gmail.com
 * Date  : 2019-08-06
 * URL   : https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
 *
 */

//4613. 러시아 국기 같은 깃발
#include <iostream>
#include <memory.h> //SWEA 컴파일시 필요
using namespace std;

int N, M;
int map[50][3];

int cal(){
    int sum = 2e9;
    int wCnt = 0;
    int bCnt = 0;
    int rCnt = 0;

    for (int i = 0; i < N-2; i++) {
        wCnt += (M - map[i][0]);

        for (int j = i+1; j < N-1; j++) {
            bCnt += (M - map[j][1]);

            for (int k = j+1; k < N; k++) {
                rCnt += (M - map[k][2]);

                if (k == N-1) {
                    int min = wCnt+bCnt+rCnt;

                    if (sum > min)
                        sum = min;
                }
            }
            rCnt = 0;
        }
        bCnt = 0;
    }

    return sum;
}

void question(int t){
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char color;
            //scanf("%c", &color); //'\n' 때문에 안됨
            cin >> color;

            if (color == 'W')
                map[i][0]++;
            else if (color == 'B')
                map[i][1]++;
            else if (color == 'R')
                map[i][2]++;
        }
    }

    int ans = cal();
    printf("#%d %d\n", t,ans);

    memset(map, 0, sizeof(map));
}
int main(){
    int test_case;
    cin >> test_case;
    for (int t = 1; t <= test_case; t++) {
        question(t);
    }

    return 0;
}