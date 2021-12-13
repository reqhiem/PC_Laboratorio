/**
 *  problema: Dvaoutput from https://open.kattis.com/problems/dvaput
*/

#include <iostream>
#include <cstring>

#define MAXLEN  200000
#define MAXHASH 200003

typedef struct {
   int hash, key, next;
} node;

int L;
static char str[MAXLEN+1];
int nnodes = 0;
node nodes[MAXLEN];
int hashtable[MAXHASH];

int processSubstrings( const char *str, int len ){
    unsigned hash, sub;
    int i;

    if ( len == 0 ) return 1;

    while ( nnodes > 0 ) {
        hashtable[ nodes[--nnodes].hash ] = -1;
    }

    // hashing technique from CP-Algorithms
    hash = 0; sub = 1;
    for ( i=0; i<len; ++i ) {
        sub = (26*sub) % MAXHASH;
        hash = (26*hash + str[i]) % MAXHASH;
    }

    sub = MAXHASH - sub;
    for ( i=len-1; str[i]!='\0'; ++i ) {
        int p;
        for ( p=hashtable[hash]; p!=-1; p=nodes[p].next ) {
            int isti = 1, j;
            for ( j=0; j<len; ++j )
            if ( str[ nodes[p].key+j ] != str[ i-len+1+j ] ) {
                isti = 0;
                break;
            }
            if ( isti )
            return 1;
        }

        nodes[nnodes].hash = hash;
        nodes[nnodes].key  = i-len+1;
        nodes[nnodes].next = hashtable[hash];
        hashtable[hash] = nnodes++;

        hash = (26*hash + sub*str[i-len+1] + str[i+1]) % MAXHASH;
    }

    return 0;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int i, left, right;
    std::cin >> L >> str;

    for ( i=0; i<MAXHASH; ++i ) hashtable[i] = -1;

    //generating all substrings length
    left = 0; right = L-1;
    while ( left < right ) {
        int mid = (left+right+1) / 2;

        if ( processSubstrings(str, mid) ) left = mid;
        else right = mid-1;
    }

    std::cout << left << std::endl;
    return 0;
}
