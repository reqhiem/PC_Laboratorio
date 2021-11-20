#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


void coastLength(vvi &mmap, int n, int m){
    
    static vvi offsets = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    vector<pair<int, int>> unvisited;
    unvisited.push_back(make_pair(0, 0));
    
    int sccount = 0;
    
    while(!unvisited.empty()){
        
        int posY = unvisited.back().first;
        int posX = unvisited.back().second;
        unvisited.pop_back();

        mmap[posY][posX] = 2;

        for(auto &offset : offsets){
            pair<int,int> tloc = make_pair(posY + offset[0], posX + offset[1]);

            if(tloc.first < 0 || tloc.first >= n || tloc.second < 0 || tloc.second >= m) continue;
            else{
                if (mmap[tloc.first][tloc.second] == 0 && (find(unvisited.begin(), unvisited.end(), tloc) == unvisited.end())){
                    unvisited.push_back(tloc);
                }else if(mmap[tloc.first][tloc.second] == 1){
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
    
    int n, m;
    string strLine;

    cin >> n >> m;
    vvi mmap(n+2, vi(m+2, 0));
    for(int i=1; i<=n; i++){
        cin >> strLine;
        int j=1;
        for(auto car : strLine)
            mmap[i][j++] = (car == '0') ? 0 : 1;
    }

    coastLength(mmap, n + 2, m + 2);

    return 0;
}
