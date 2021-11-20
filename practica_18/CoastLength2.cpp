#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


static vvi offsets = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(vvi &mmap, int i, int j, int n, int m, int &sccount){
    if(i < 0 || i >= n || j < 0 || j >= m || mmap[i][j] == 2) return;
    
    mmap[i][j] = 2;
    if (mmap[i][j] == 0){
        for(int k = 0; k < 4; k++){
            int row = i + offsets[k][0];
            int col = j + offsets[k][1];
            dfs(mmap, row, col, n, m, sccount);
        }
    }else if (mmap[i][j] == 1){
        sccount++;
    }
}

void coastLength(vvi &mmap){
    int n = mmap.size();
    int m = mmap[0].size();

    int sccount = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mmap[i][j] != 2){
                mmap[i][j] = 2;
                if (mmap[i][j] == 0){
                    for(int k = 0; k < 4; k++){
                        int row = i + offsets[k][0];
                        int col = j + offsets[k][1];
                        dfs(mmap, row, col, n, m, sccount);
                    }
                }else if (mmap[i][j] == 1){
                    sccount++;
                }
            }
        }
    }

    cout << sccount << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    string strLine;
    int n, m;
    cin >> n >> m;
    vvi mmap(n+2, vi(m+2, 0));
    for(int i=1; i<=n; i++){
        cin >> strLine;
        int j=1;
        for(auto car : strLine)
            mmap[i][j++] = (car == '0') ? 0 : 1;
    }

    coastLength(mmap);

    return 0;
}
