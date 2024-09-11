/*************************************************************************
	> File Name: 332.买票.cpp
	> Author: ZhangYang
	> Mail: 2023140902018@std.uestc.edu.cn 
	> Created Time: 2024年09月11日 星期三 22时24分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 200000
int c[2000005],a[2000005],b[2000005],ans[2000005];

inline int lowbit(int x) {return x & (-x);}

void add(int pos,int val,int n){
	while(pos<=n){
		c[pos]+=val;
		pos+=lowbit(pos);
	}
	return;
}

int query(int pos,int n){
	int sum=0;
	while(pos){
		sum+=c[pos];	
		pos-=lowbit(pos);
	}
	return sum;
}

int binary_search(int val,int n){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(query(mid,n)<val)l=mid+1;
		else r=mid;
	}
	return l;
}

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",a+i,b+i);
	}
	for(int i=1;i<=n;i++){
		add(i,1,n);
	}
	for(int i=n;i>=1;i--){
		int pos=binary_search(a[i]+1,n);
		ans[pos]=b[i];
		add(pos,-1,n);
	}
	for(int i=1;i<=n;i++){
		if(i!=1)cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
