//casos de prueba
/*

    list<int> a = {3,1,5};
    list<int> b = {5,9,2};

    list<int> a = {4,2,9};
    list<int> b = {5,7,8};

    list<int> a = {2,3,5};
    list<int> b = {9,9,9,1};

*/


#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int> suma(list<int> &a, list<int> &b){
    list<int> res;
    int lleva = 0;

    int maxSize = (a.size() > b.size()) ? a.size() : b.size();
    auto it1 = a.begin();
    auto it2 = b.begin();

    for(int i=0; i<maxSize; i++){
        if(it1 != a.end() && it2 != b.end() && ( (*it1) + (*it2) + lleva < 10)){
            res.push_back((*it1) + (*it2) + lleva); 
            it1++; it2++;
            lleva = 0;
        }
        if(it1 != a.end() && it2 != b.end() && ( (*it1) + (*it2) + lleva >= 10)){
            res.push_back((*it1) + (*it2) + lleva - 10); 
            it1++; it2++;
            lleva = 1;
        }
        if(it1 == a.end() && it2 != b.end()){
            if(*it2 + lleva < 10){
                res.push_back(lleva + (*it2));
                it2++;
                lleva = 0;

            }else{
                res.push_back(10 - (*it2) + lleva);
                it2++;
                lleva = 1;
            }
        }
        if(it1 != a.end() && it2 == b.end()){
            if(*it1 + lleva < 10){
                res.push_back(lleva + (*it1));
                it1++;
                lleva = 0;

            }else{
                res.push_back(10 - (*it1) + lleva);
                it1++;
                lleva = 1;
            }
        }
    }
    if(lleva != 0) res.push_back(lleva);

    for(auto elem : res) cout << elem << " ";
    cout << endl;
    return res;

}

int main(int argc, char const *argv[])
{
    list<int> a = {2,3,5};
    list<int> b = {9,9,9,1};

    list<int> res = suma(a,b);


    return 0;
}
