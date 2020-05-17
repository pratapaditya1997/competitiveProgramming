/* 
 * Author: aps
 * Time: 2020-05-17 18:51:38
**/
#include<bits/stdc++.h>

#define fi first
#define se second
#define all(x) x.begin(), x.end()

using namespace std;

template<class T>
class sparse_matrix {
    vector<pair<pair<int,int>, T>> data;

public:
    sparse_matrix() {}
    sparse_matrix(vector<vector<T>> A) {
        int n = A.size();
        int m = A[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(A[i][j]) data.push_back({{i,j},A[i][j]});
            }
        }
        sort(all(data));
    }

    sparse_matrix transpose() {
        sparse_matrix ret;
        for(auto p: data) ret.data.push_back({{p.fi.se, p.fi.fi},p.se});
        sort(all(ret.data));
        return ret;
    }

    sparse_matrix multiply(sparse_matrix b) {
        sparse_matrix ret;
        map<pair<int,int>, T> val;
        b = b.transpose();

        for(auto i: data) {
            int r = i.fi.fi;
            for(auto j: b.data) {
                int c = j.fi.fi;
                if(i.fi.se == j.fi.se) {
                    if(val.find({r,c}) == val.end()) val[{r,c}] = 0;
                    val[{r,c}] += i.se * j.se;
                }
            }
        }

        for(auto x: val) ret.data.push_back({x.fi, x.se});
        sort(all(ret.data));
        return ret;
    }

    void print() {
        for(auto p: data) cout << "(" << p.fi.fi << "," << p.fi.se << ") " << p.se << "\n";
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<int>> A = {{1,2,0},{0,0,6},{7,0,0}};
    vector<vector<int>> B = {{0,2,0},{4,0,6},{0,8,0}};

    sparse_matrix<int> a(A);
    sparse_matrix<int> b(B);
    sparse_matrix<int> ans = a.multiply(b);

    ans.print();
    return 0;
}
