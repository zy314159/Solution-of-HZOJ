/*************************************************************************
	> File Name: 331.Lost_cows.cpp
	> Author: ZhangYang
	> Mail: 2023140902018@std.uestc.edu.cn 
	> Created Time: 2024年09月11日 星期三 09时49分02秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 80000

inline int lowbit(int x) {return x & (-x);}
int c[80005],a[80005];

void add(int i,int v,int n){
	while(i<=n)c[i]+=v,i+=lowbit(i);
	return;
}

int query(int pos){
	int sum=0;
	while(pos){
		sum+=c[pos];
		pos-=lowbit(pos);
	}
	return sum;
}

int binary_search(int x,int n){
	int l=1,r=n,mid;
	while(l<r){
		int mid=(l+r)>>1;
		if(query(mid)<x)l=mid+1;
		else r=mid;
	}
	return l;
}

int main(){
	int n;
	cin>>n;
	a[1]=0;
	for(int i=2;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		add(i,1,n);
	}

	for(int i=n;i>=1;i--){
		a[i]=binary_search(a[i]+1,n);
		add(a[i],-1,n);
	}

	for(int i=1;i<=n;i++)printf("%d\n",a[i]);
	return 0;
}
