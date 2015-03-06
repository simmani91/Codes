//93page 시간 복잡도 분석 예제
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//주어진 배열에서 가장 많이 등장하는 숫자를 반환하기
int majority1(const vector<int> A){
    int N = A.size();
    int majority = -1, majorityCount =0;
    
    for(int i=0;i<N;i++){
        //A에 등장하는 A[i]의 수를 센다.
        int V = A[i], count =0;
        
        for(int j=0;j<N;++j){
            if(A[j] == V) ++count;
        }
        
        if (count > majorityCount){
            majorityCount = count;
            majority = V;
        }
    }
    return majority;
}
int main(){
    
    vector<int> data = {1,2,3,3,3,4};
    data.push_back(1);
    
    cout << majority1(data) << endl;
    return 0;
}