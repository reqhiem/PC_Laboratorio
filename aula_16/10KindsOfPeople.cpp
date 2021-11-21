#include <iostream>
#include <string>
using namespace std;

string line;
int mat[1000][1000], R, C, N, r1, r2, c1, c2;

void process(string &line, int i){
    int j=0;
    for(auto let : line){
        mat[i][j++] = (let == '0') ? 0 : 1;
    }
}

void query(int r1, int c1, int r2, int c2){
    cout << "binary" << endl;
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for(int i=0; i<R; i++){
        cin >> line;
        int j = 0;
        for(auto car : line) mat[i][j++] = (car == '0') ? 0 : 1;
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        query(r1, c1, r2, c2);
    }

    return 0;
}
