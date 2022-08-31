#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    srand(0);
    n=rand()%1000000000000000000+1;
    long long int m1,m2;
    m1=rand()%10;
    m2=rand()%10;
    for(long long int i=0; i<m1; i++){
        long long int r,c,v;
        r=rand()%n+1;
        c=rand()%n+1;
        v=rand();
        cout<<"1 "<<r<<" "<<c<<" "<<v<<endl;
    }
    for(long long int i=0; i<m2; i++){
        long long int r,c,v;
        r=rand()%n+1;
        c=rand()%n+1;
        v=rand();
        cout<<"2 "<<r<<" "<<c<<" "<<v<<endl;
    }
    cout<<0;

    return 0;
}