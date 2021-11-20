#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void Gregory(int R, int C, int Gr, int Gc, int Lr, int Lc){
    //Ya se encuentra en la hoja
    if(Lr == Gr && Lc == Gc) {
        cout << "0\n";
        return;
    }

    //Buscar en la hoja
    vvi steps = {{-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1}};

    


    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R,C,Gr,Gc,Lr,Lc;
    while(cin >> R >> C >> Gr >> Gc >> Lr >> Lc){
        Gregory(R,C,Gr,Gc,Lr,Lc);
    }
    return 0;
}
