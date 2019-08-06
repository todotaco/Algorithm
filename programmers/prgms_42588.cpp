/*
 * prgms_42588.cpp
 *           #42588. 탑
 *
 * Author: todotacocom@gmail.com
 * Date  : 2019-08-06
 * URL   : https://programmers.co.kr/learn/courses/30/lessons/42588
 *
 */

//42588. 탑
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    for (int i = 1; i <= heights.size(); i++) {
        bool check = false;
        for (int j = i-1; j > 0; j--) {
            if (heights[i-1] < heights[j-1]) {
                check = true;
                answer.push_back(j);
                break;
            }
        }

        if (!check)
            answer.push_back(0);
    }

    return answer;
}

int main(){
//    vector<int> arr {6,9,5,7,4};
//    vector<int> arr {3,9,9,3,5,7,2};
    vector<int> arr {1,5,3,6,7,6,5};

    solution(arr);

    return 0;
}