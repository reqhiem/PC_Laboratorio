/*
*  @autor: Joel Perca
*  @problema: Life forms from https://open.kattis.com/problems/lifeforms
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char buf[1024*1024];
char *p[1024*1024];
char cnt[1024];
char *prev;

int i,j,k,n,c,z,best,done;

int comp (char **a, char **b){
   return strcmp(*a,*b);
}

int common (char *a, char *b){
   int i;
   for (i=0;a[i] && a[i] == b[i];i++);
   return i;
}

int main(int argc, char **argv){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    while (cin >> n) {
        if (done++) printf("\n");
        for (i=k=0;i<n;i++) {
            cin >> buf+i*1024;
            for (j=0;buf[i*1024+j];j++) {
                p[k++] = buf+i*1024+j;
            }
        }
        qsort(p,k,sizeof(char *), comp);
        memset(cnt,0,sizeof(cnt));
        best = 0;
        for (i=j=c=0;i<k;) {
            while (c <= n/2 && i<k) {
                if (!cnt[(p[i++]-buf)/1024]++) c++;
            }
            while (c > n/2) {
                if (!--cnt[(p[j++]-buf)/1024]) c--;
            }
            if (j && common(p[j-1],p[i-1]) > best) {
                best = common(p[j-1],p[i-1]); 
            }
        }
        if (!best) {
            cout << "?\n";
            continue;
        
        }
        memset(cnt,0,sizeof(cnt));
        prev = "";
        for (i=j=c=0;i<k;) {
            while (c <= n/2 && i<k) {
                if (!cnt[(p[i++]-buf)/1024]++) c++;
            }
            while (c > n/2) {
                if (!--cnt[(p[j++]-buf)/1024]) c--;
            }
            if (j && common(p[j-1],p[i-1]) == best) {
                if (strncmp(prev,p[j-1],best)) {
                    prev = p[j-1];
                    for (z=0;z<best;z++)
                        cout << p[j-1][z];
                    cout << endl;
                }
            }
        }
    }
}