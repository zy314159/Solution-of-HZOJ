/*************************************************************************
	> File Name: 第二种解法330.加强的整数问题.cpp
	> Author: ZhangYang
	> Mail: 2023140902018@std.uestc.edu.cn 
	> Created Time: 2024年09月10日 星期二 09时16分59秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
long long a[100005],c[2][100005];

inline int lowbit(int x) {return x &(-x);}

void add(int k,int i,int v){
	while(i<=n)c[k][i]+=v,i+=lowbit(i);
	return;
}

long long query(int k,int i){
	long long sum=0;
	while(i){
		sum+=c[k][i];
		i-=lowbit(i);
	}
	return sum;
}

long long Q(int k){
	long long a1=query(0,k);
	long long a2=query(1,k);
	return (k+1)*a1-a2;

}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		add(0,i,a[i]-a[i-1]);
		add(1,i,i*(a[i]-a[i-1]));
	}
	for(int i=1,a,b;i<=m;i++){
		char ch;
		cin>>ch;
		if(ch=='C'){
			long long c;
			cin>>a>>b>>c;
			add(0,a,c);
			add(0,b+1,-c);
			add(1,a,a*c);
			add(1,b,-(b+1)*c);
		}else{
			cin>>a>>b;
			cout<<Q(b)-Q(a-1)<<endl;
		}
	}
	return 0;
}
