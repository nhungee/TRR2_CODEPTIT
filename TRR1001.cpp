#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
	int t; cin >> t;
	int res = 0;
	if(t == 1){
		int n; cin >> n ; 
		int a[n][n];
		int deg;
		for(int i = 0; i < n ;i++){
			for(int j = 0; j < n ; j++){
				cin >> a[i][j];	
			}
		}
		for(int i = 0; i< n ; i++){
		    deg = 0;
			for(int j = 0; j < n ; j++){
				if(a[i][j]) deg++;
			}
			cout << deg << " ";
			res += deg;
		}
		cout << endl;
	}
	if(t == 2){
		int n; cin >> n;
		int a[n][n];
		for(int i = 0; i < n ; i++){
			for(int j =0; j < n ;j++){
				cin >> a[i][j];
			}
		}
		int m = res/2;
		cout << n <<  " " << m << endl;
		for(int  i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(a[i][j]) cout << i <<" " << j << endl;
			}
		}
	}
}
