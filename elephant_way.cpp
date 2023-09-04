#include<iostream>
using namespace std;
int elephyantways(int i,int j){
	//base case
	if(i==0&& j==0){
		return 1;
	}
	//recursive case
	int ans=0;
	//for col sum
	for(int k=0;k<i;k++){
		ans+=elephyantways(k,j);
	}//for row sum
	for(int k=0;k<j;k++){
		ans+=elephyantways(i,k);
	}
	return ans;
}

int topdown_e(int i,int j,int dp[][100]){
	//base case
	if(i==0&&j==0){
		return dp[i][j]=1;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	//recursive case
	int ans=0;
	//for col sum
	for(int k=0;k<i;k++){
		ans+=topdown_e(k,j,dp);
	}//for row sum
	for(int k=0;k<j;k++){
		ans+=topdown_e(i,k,dp);
	}
	return dp[i][j]=ans;
}

int bottom_uo_e(int n,int m){
	int dp[100][100]={0};
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 &&j==0){
				dp[i][j]=1;
			}
			else{
				int ans=0;
				for(int k=0;k<n;k++){
					ans+=dp[k][j];
				}
				for(int k=0;k<m;k++){
					ans+=dp[i][k];
				}
				dp[i][j]=ans;
			}
		}
	}
	return dp[n][m];
}
int main(){
	int i,j;
	cin>>i>>j;
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	cout<<elephyantways(i,j)<<endl;
	cout<<topdown_e(i,j,dp)<<endl;
	for(int l=0;l<=i;l++){
		for(int m=0;m<=j;m++){
			cout<<dp[l][m]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}