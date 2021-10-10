
/**
 *  @descripcion: Este programa fue admitido por el jurado como una solución
*/

#include <iostream>
#include <vector>
using namespace std;

const int ns = 2e05 + 10;

int N, i=0, x;

int main(int argc, char const *argv[])
{
    cin >> N;
    vector<pair<int,int>> arr;
    arr.push_back(make_pair(0,0));

    while(i++ < N){
        cin >> x;
        while(!arr.empty() && arr.back().first >= x)
            arr.pop_back();
        cout << arr.back().second << " ";
        arr.push_back(make_pair(x,i));
    }
    cout << endl;

    return 0;
}
