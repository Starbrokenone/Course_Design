#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
map<int,int> con;
vector<int> *mp;
stack<int> st;
bool marked[10001][10001];
int id[10001];
int N,M,COU;
// ��·��ѹ����quick-union 
int _find(int p) {
	if(p==id[p]) {
		return p;
	}
	return (id[p]=_find(id[p]));
}
bool _union(int p,int q) {
	p=_find(p);
	q=_find(q);
	if(p==q) {
		return false;
	}
	id[p]=q;
	return true;
}
// ����������� 
void dfs(int s) {
	int len=mp[s].size();
	for(int i=0; i<len; i++) {
		int e=mp[s][i];
		if(!marked[s][e]){
			marked[s][e]=marked[e][s]=true;
			dfs(e);
		}
	}
	st.push(s);
}
int main(void) {
	int s,e;
	cin>>N>>M;
	mp=new vector<int>[N+1];
	for(int i=1; i<=N; i++) {
		id[i]=i;
	}
	for(int i=0; i<M; i++) {
		cin>>s>>e;
		_union(s,e);
		mp[s].push_back(e);
		mp[e].push_back(s);
	}
	// union-find�ж���ͨ�� 
	bool ok=true;
	int fa=_find(1);
	for(int i=2; i<=N; i++) {
		if(_find(i)!=fa) {
			ok=false;
			break;
		}
	}
	
	if(ok) {	// �����ͨ 
		// �������� 
		for(int i=1; i<=N; i++) {
			sort(mp[i].begin(),mp[i].end());
		}
		COU=0;
		for(int i=1; i<=N; i++) {
			con[i]=mp[i].size();
			if(con[i]%2) {
				COU++;
			}
		}
		// ����ŷ��ͨ·�������������ѣ��õ������� 
		if(COU==0||COU==2&&con[1]%2) {
			dfs(1);
			int t;
			// ������м�Ϊ����������ͨ· 
			while(!st.empty()){
				t=st.top();
				cout<<t<<' ';
				st.pop();
			}
			cout<<endl;
		} else {	// ������ŷ����·���� 
			cout<<-1<<endl;
		}
	} else {	// �������ͨ 
		cout<<-1<<endl;
	}
	delete mp;
	return 0;
}

