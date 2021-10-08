#include <iostream>
#include <vector>
using namespace std;

class BTree{
private:
    struct  Node{
        int data;
        Node* left, *right;
    };
    
};

void minAltura(BTree bt, vector<int> &v, int p, int q){
    if(p == q){
        bt.insert(v[p]);
        return;
    }
    
    int mid = floor((p+q)/2);
    minAltura(bt, p, mid-1);
    minAltura(bt, mid+1, q);

}


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5,6,7};
    minAltura(v, 0, 6);

    return 0;
}
