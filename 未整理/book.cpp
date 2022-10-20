//����һ�����ֵmid������Էֳ�k�Ρ�
//���mid�����������<=k
//
//���k<m����˵��mid̫���ˣ���Сһ��
//���k>m����˵��mid̫С�ˣ��ڴ�һ��
//���k==m���򻹿��Գ��Խ�mid��Сһ�� 
//
//1,��3�����ϲ��������м�ֵ 
//while(l<r){
//	mid = (l+r)>>1;
//	if(chk(mid) <= m) r = mid;
//	else l = mid+1;
//} 
//
//x y
//l r
//mid 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,mx,sm,ans,a[100005];
int jud(int x){
	int sum = 0, cnt = 1;///ע������ط�Ϊʲô��1	
	for(int i = 1; i <= n; i++){
		if(sum + a[i] > x){
			cnt++;
			sum = a[i];
		}
		else
			sum += a[i];
	}
	return cnt;
}
int main()
{
	freopen("test.in", "r", stdin);
    freopen("ab.out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		sm+=a[i];
	}
	int l = mx, r = sm;
	while(l < r){
		int mid = (l+r)/2;
		if(jud(mid) <= m) r = mid;
		else l = mid + 1;
	}
	cout<<l<<endl;
	return 0;
}
