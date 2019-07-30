/*
 * swea_2805.cpp
 *           #2805. 농작물 수확하기
 *
 * Author: todotacocom@gmail.com
 * Date  : 2019-07-30
 * URL   : https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
 *
 */

//2805. 농작물 수확하기
#include <iostream>
#include <memory.h> //SWEA 컴파일시 필요
using namespace std;

int map[50][50];
int temp[50][50];
int N; // 1 ≤ N ≤ 49
int middle = 0;

void pMap(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void pTemp(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void color(){
    int cnt = 1;
    int start = middle;
    
    //    for (int i = 0; i < N; i++) {
    //        int K = cnt;
    //
    //        if (i < middle) {
    //            for (int j = 0; j < K; j++) {
    //                int s = start;
    //
    //                temp[i][s+j] = 1;
    //            }
    //            cnt += 2;
    //            start -= 1;
    //        }
    //        else {
    //            for (int j = 0; j < K; j++) {
    //                int s = start;
    //
    //                temp[i][s+j] = 1;
    //            }
    //            cnt -= 2;
    //            start += 1;
    //        }
    //
    //        pMap();
    //    }
    
    for (int i = 0; i < N; i++) {
        if (i < middle) {
            for (int j = 0; j < cnt; j++)
                temp[i][start+j] = 1;
            cnt += 2;
            start -= 1;
        }
        else {
            for (int j = 0; j < cnt; j++)
                temp[i][start+j] = 1;
            cnt -= 2;
            start += 1;
        }
        //        pMap();
    }
    
}
int sum(){
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j]) {
                ans += map[i][j];
            }
        }
    }
    return ans;
}

void question(int test_case){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    //    N = 7;
    middle = N/2;
    
    color();
    
    //    pMap();
    //    pTemp();
    
    cout << "#" << test_case << " " << sum() << endl;
    
    memset(map, 0, sizeof(map));
    memset(temp, 0, sizeof(temp));
}
int main(){
    int testCase = 0;
    cin >> testCase;
    for (int t = 1; t <= testCase; t++) {
        question(t);
    }
    
    return 0;
}