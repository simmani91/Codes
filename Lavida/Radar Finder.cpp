//Radar Finder
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int N;

int main(){
    long long t, target;
    cin >> N;
    for(int i=0;i< N;i++){
        long long x1,y1,r1,x2,y2,r2,r,R, dist;
        
        scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&r1,&x2,&y2,&r2);
        
        if (r1 > r2){R = r1;r =r2;}
        else {R =r2;r=r1;}
        
        dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        
        if (dist ==0){
            if (r1==0 && r2 ==0) printf("1\n");
            else if (r1 ==r2) printf("-1\n");
            else printf("0\n");
        }
        
        else if (dist < R + r){
            if (r+ dist ==R)printf("1\n");
            else if (r+ dist > R) printf("2\n");
            else printf("0\n");
        }
        
        else if (dist > R + r){
            if(r+R == dist)printf("1\n");
            else if (r+R < dist) printf("0\n");
            else printf("2\n");
        }
        
        else {
            if (r ==0) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}