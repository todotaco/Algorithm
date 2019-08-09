/*
 * swea_2819.cpp
 *           #2819. 격자판의 숫자 이어 붙이기
 *
 * Author: todotacocom@gmail.com
 * Date  : 2019-08-09
 * URL   : https://swexpertacademy.com/main/learn/course/lectureProblemViewer.do
 *
 */

//2819. 격자판의 숫자 이어 붙이기
#include <iostream>
#include <memory.h> //SWEA 컴파일시 필요
#include <string>
#include <set>
using namespace std;

int dart[4][4];
int visit[4][4];

int dx[4] = {0,0,1,-1}; //동서남북
int dy[4] = {1,-1,0,0};

string str;
set<string> strArr;

void dfs(int x, int y, int depth){
    depth++;
    str.append(to_string(dart[x][y]));
    
    if (depth == 7) {
        depth--;
        strArr.insert(str);
        
        return;
    }
    
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)
            continue;
        
        dfs(nx, ny, depth);
        
        str.pop_back();
    }
}

void question(int t){
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> dart[i][j];
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            str.clear();
            memset(visit, 0, sizeof(visit));
            
            dfs(i, j, 0);
        }
    }
    
    cout << "#" << t << " " << strArr.size() << endl;
    strArr.clear();
}
int main(){
    int test_case;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
        question(t+1);
    
    return 0;
}