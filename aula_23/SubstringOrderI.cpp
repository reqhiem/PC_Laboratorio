#include <iostream>
#include <vector>
using namespace std;

//CP-Algorithms implementation for SUfix Array
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;

    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string s, vector<int> sorted_shifts) {
    int n = s.size();
    vector<int> lcp(n);
    lcp[0] = 0;
    for (int i = 1; i < n; i++) {
        string s1 = s.substr(sorted_shifts[i-1]);
        string s2 = s.substr(sorted_shifts[i]);
        int j = 0;
        while ((j < s1.size() || j < s2.size()) && s1[j] == s2[j])
            j++;
        lcp[i] = j;
    }
    return lcp;
}

int unique_substrings(string s, vector<int> lcp){
    int n = s.size();
    int dup = 0;
    for(auto i: lcp) dup += i;

    return (n*(n+1)/2 - dup);
}

int main(int argc, char const *argv[])
{
    /* code */
    //string s = "ababbab";
    string s;
    int k;

    cin >> s;
    cin >> k;
    
    vector<string> aux;
    
    vector<int> suffix_array = suffix_array_construction(s);
    vector<int> lcp = lcp_construction(s, suffix_array);
    for (int i = 0; i < suffix_array.size(); i++)
        cout << suffix_array[i] << " " << lcp[i] << " " << s.substr(suffix_array[i]) << endl;

    for(int i=0; i<lcp.size(); i++){
        ;
    }
    
    

    return 0;
}
