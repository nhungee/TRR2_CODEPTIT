#include <bits/stdc++.h>
using namespace std;

int n, m, u;
int ke[1005][1005];
int deg[1005];
bool chuaxet[1005];

void DFS(int u){
    stack<int> st;
    st.push(u);
    chuaxet[u] = false;
    while(!st.empty()){
        int s = st.top();
        st.pop();
        for(int i = 1; i <= deg[s]; i++){
            int v = ke[s][i];
            if(chuaxet[v]){
                chuaxet[v] = false;
                st.push(s);
                st.push(v);
                break;
            }
        }
    }
}

bool lienthong(){
    memset(chuaxet, true, sizeof(chuaxet));
    int start = -1;
    for(int i = 1; i <= n; i++){
        if(deg[i] > 0){
            start = i;
            break;
        }
    }
    if(start == -1) return true;
    DFS(start);
    for(int i = 1; i <= n; i++){
        if(deg[i] > 0 && chuaxet[i]) return false;
    }
    return true;
}

void euler(int u){
    int ce[1005], top = 0;
    stack<int> st;
    st.push(u);
    
    while(!st.empty()){
        int s = st.top();
        int i;
        for(i = 1; i <= deg[s]; i++){
            if(ke[s][i] != 0) break;
        }
        if(i <= deg[s]){
            int v = ke[s][i];
            st.push(v);
            ke[s][i] = 0;
            for(int j = 1; j <= deg[v]; j++){
                if(ke[v][j] == s){
                    ke[v][j] = 0;
                    break;
                }
            }
        }else{
            st.pop();
            ce[++top] = s;
        }
    }
    for(int i = top; i >= 1; i--){
        cout << ce[i] << " ";
    }
}

int main(){
//    //  đúng tên file theo đề
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int t;
    cin >> t;

    memset(deg, 0, sizeof(deg));
    memset(ke, 0, sizeof(ke));

    if(t == 1){
        cin >> n >> m;
    } else {
        cin >> n >> m >> u;
    }

    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ke[x][++deg[x]] = y;
        ke[y][++deg[y]] = x;
    }

    if(t == 1){
        if(!lienthong()){
            cout << 0;
            return 0;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(deg[i] % 2 != 0) cnt++;
        }
        if(cnt == 0) cout << 1;
        else if(cnt == 2) cout << 2;
        else cout << 0;
    }
    else{
        euler(u);
    }
}