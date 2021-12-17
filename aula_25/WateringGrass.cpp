#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<double, double> dd;

double N, L, W, x, r;

void process_distances(vector<dd> &lis, double &L){
    double c = 0, i = 0, aux = 0;
    double n = lis.size();

    while(true){
        double tmp = -1;
        while(i < n &&  lis[i].first <= aux){
            tmp = max(tmp, lis[i].second);
            i++;
        }
        if(tmp == -1){
            cout << -1 << endl;
            return;
        }
        c++;
        aux = tmp;
        if (aux >= L){
            cout << c << endl;
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    while(cin >> N >> L >> W){
        vector<dd> lis;
        while(N--){
            cin >> x >> r;
            if (2*r > W){
                double d = sqrt(pow(r, 2) - pow(W/2, 2));
                lis.push_back(dd(x - d, x + d));
            }
        }
        sort(lis.begin(), lis.end());
        process_distances(lis, L);
    }

    return 0;
}
