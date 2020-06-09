#include<bits/stdc++.h>
#define ll long long int 

using namespace std;

int weight(string s){
	int res = 0, l = s.length();
	for (int i = 0; i < l; ++i)
	{
		if(s[i]=='1')
			res++;
	}
	return res;
}

int mu(string tstr, vector<vector<int>>& supAg, int m){
	int bitwise_OR[m] = {0};
	for (int i = 0; i < tstr.length(); ++i)
	{
		if(tstr[i]=='1'){
			for(int j=0;j<m;++j)
				if(supAg[i][j])
					bitwise_OR[j]++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		if(bitwise_OR[i]>0)
			cnt++;
	}
	return cnt;
}


void traverse(string str, unordered_map<string, ll>& mp, int& p, int& m, vector<vector<int>>& supAg){
	int l = str.length();
	string prev = str;
	for (int i = l; i < p; ++i)
	{
		string tstr = prev + "1";
		if( mu(tstr, supAg, m) < m){
			int wt = weight(tstr);

			if( mp.find(tstr) == mp.end()){
				mp[tstr] = pow(-2, wt);
			}
			else{
				mp[tstr] += pow(-2, wt);
			}

			if(tstr.length() < p)
				traverse(tstr, mp, p, m, supAg);
		}
		prev = prev + "0";
	}
}

int psi(string a, vector<int> b){
	int l = min(a.length(), b.size());

	int cnt = 0;
	for (int i = 0; i < l; ++i)
	{
		if(a[i]=='1' && b[i])
			cnt++;
	}
	return cnt;
}

int main(){

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int p, m;cin>>p>>m;
	vector<vector<int>> supAg(p, vector<int>(m));

	for(int i=0;i<p;++i){
		for (int j = 0; j < m; ++j)
		{
			cin>>supAg[i][j];
		}
	}

	vector<int> v(m);
	int v_weight = 0;
	for (int i = 0; i < m; ++i)
	{
		cin>>v[i];
		if(v[i])
			v_weight++;
	}

	unordered_map<string,ll> mp;

	traverse("", mp, p, m, supAg);

	vector<ll> B(m,0);
	ll bb = 0;

	for(auto pair: mp){
		int wt = weight(pair.first);
		B[wt] = B[wt] + pair.second;
		
		if(psi(pair.first, v) ==0 )
			bb = bb + pair.second / pow(2, wt);
	}

	int cv = pow(-1,p) -1;
	
	for (int i = 0; i < m; ++i){
		cv -= B[i];
	}

	cv = cv/pow(2,m) + bb;
	cv = pow(-1,v_weight)*cv;

	cout<<cv;

	return 0;
}