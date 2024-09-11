/*************************************************************************
	> File Name: 330.加强的整数问题.cpp
	> Author: ZhangYang
	> Mail: 2023140902018@std.uestc.edu.cn 
	> Created Time: 2024年09月10日 星期二 00时52分04秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_M 100000
#define MAX_N 100000
#define root 1

int n,m,flag[4*MAX_N+5];
long long arr[MAX_N+5];
long long tree[4*MAX_N+5];
void update(int i){
	tree[i]=tree[i<<1]+tree[i<<1|1];
	return;
}

void build_tree(int i,int l,int r){
	if(l==r){
		tree[i]=arr[l];
		return;
	}
	int mid=(l+r)>>1;
	build_tree(i<<1,l,mid);
	build_tree(i<<1|1,mid+1,r);
	update(i);
	return;
}

void down(int i,int l1,int r1,int l2,int r2){
	int val=flag[i];
	flag[i<<1]+=val;
	tree[i<<1]+=(r1-l1+1)*val;
	flag[i<<1|1]+=val;
	tree[i<<1|1]+=(r2-l2+1)*val;
	flag[i]=0;
	return;
}

void modify(int i,int l,int r,int x,int y,long long val){
	if(x<=l&&r<=y){
		tree[i]+=(r-l+1)*val;
		flag[i]+=val;
		return;
	}
	int mid=(l+r)>>1;
	down(i,l,mid,mid+1,r);
	if(x<=mid)modify(i<<1,l,mid,x,y,val);
	if(y>mid)modify(i<<1|1,mid+1,r,x,y,val);
	update(i);
	return;
}

long long query(int i,int l,int r,int x,int y){
	if(x<=l&&r<=y)return tree[i];
	int mid=(l+r)>>1;
	down(i,l,mid,mid+1,r);
	long long sum=0;
	if(x<=mid)sum+=query(i<<1,l,mid,x,y);
	if(y>mid)sum+=query(i<<1|1,mid+1,r,x,y);
	return sum;
}

int main(int argc, char *argv[])
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",arr+i);
	build_tree(root,1,n);
	for(int i=1,a,b;i<=m;i++){
		char c;
		cin>>c>>a>>b;
		if(c=='C'){
			long long val;
			cin>>val;
			modify(root,1,n,a,b,val);
		}else{
			cout<<query(root,1,n,a,b)<<endl;
		}
	}
	return 0;
}
