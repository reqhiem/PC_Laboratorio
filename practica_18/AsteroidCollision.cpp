#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> q;
    for(int i=0; i<asteroids.size(); i++){
        int aux = asteroids[i];
        if(q.empty()){
            q.push_back(aux);
            continue;
        }
        while(true){
            if(q.size() != 0 && aux < 0 && q.back() > 0){
                if(q.back() + aux == 0){
                    q.pop_back();
                    break;
                }
                else if (q.back() + aux > 0){
                    break;
                }else if(q.back() + aux < 0){
                    q.pop_back();
                    
                }
            }else{
                q.push_back(aux);
                break;
            }
        }
    }
    return q;
}

int main(int argc, char const *argv[]){
    //vector<int> asteroids = {5, 10, -5};
    vector<int> asteroids = {-2,-2,1,-2};
    //vector<int> asteroids = {10,2,-5};
    //vector<int> asteroids = {-2, -1, 1, 2};
    vector<int> result = asteroidCollision(asteroids);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
