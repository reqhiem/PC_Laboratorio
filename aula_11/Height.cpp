#include <iostream>
#include <queue>

using namespace std;

int CN, N, n, x;

int main(int argc, char const *argv[]){
    priority_queue<int, vector<int>, greater<int>> pq;

    scanf("%d", &CN);
    while(CN--){
        
        scanf("%d", &N);
        n = 0;
        while(n++ < N){
            scanf("%d", &x);
            pq.push(x);
        }

        while (!pq.empty()) {
            if(pq.size() == 1){
                printf("%d\n", pq.top());
            }else{
                printf("%d ", pq.top());
            }
            pq.pop();
        }
    }

    return 0;
}
