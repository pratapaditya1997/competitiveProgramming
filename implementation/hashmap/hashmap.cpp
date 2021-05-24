/* 
 * Author: aps
 * Time: 2021-02-19 18:11:48
**/
#include<bits/stdc++.h>
 
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
 
const ll inf = 1e18;
const ll mod = 1e9+7;
 
inline ll add(ll x, ll y) { x += y; if (x >= mod) x -= mod; return x;}
inline ll sub(ll x, ll y) { x -= y; if (x < 0) x += mod; return x;}
inline ll mul(ll x, ll y) { return ((x % mod) * (y % mod)) % mod;}
inline ll gcd(ll x, ll y) { return x == 0 ? y : gcd(y % x, x); }
inline ll power(ll a, ll b) {
    ll x = 1;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline ll inv(ll a) { return power(a, mod - 2);}

// HashNode represents a bucket node in the table
template <typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value) : _key(key), _value(value), _next(NULL){}
    
    K getKey() const {
        return _key;
    }

    V getValue() const {
        return _value;
    }

    void setValue(V value) {
        _value = value;
    }

    HashNode *getNext() const {
        return _next;
    }

    void setNext(HashNode *next) {
        _next = next;
    }

private:
    // key-value pair
    K _key;
    V _value;

    // next bucket with the same key
    HashNode *_next;

    // disallow copy and assignment
    HashNode(const HashNode &);
    HashNode & operator=(const HashNode &);
};

// Default hash function class
template<typename K, size_t tableSize>
struct KeyHash {
    unsigned long operator()(const K &key) const {
        return reinterpret_cast<unsigned long>(key) % tableSize;
    }
};

// Hash map class template
template <typename K, typename V, size_t tableSize, typename F = KeyHash<K, tableSize> >
class HashMap {
public:
    HashMap() : table(), hashFunc() {}

    ~HashMap() {
        // destroy all buckets one by one
        for (size_t i = 0; i < tableSize; ++i) {
            HashNode<K, V> *entry = table[i];
            while (entry != NULL) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
            table[i] = NULL;
        }
    }

    bool get(const K &key, V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];

        while(entry != NULL) {
            if (entry -> getKey() == key) {
                value = entry->getValue();
                return true;
            }
            entry = entry->getNext();
        }
        return false;
    }

    void put(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while(entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            entry = new HashNode<K, V>(key, value);
            if (prev == NULL) {
                // insert as first bucket
                table[hashValue] = entry;
            } else {
                prev->setNext(entry);
            }
        } else {
            // just update the value
            entry->setValue(value);
        }
    }

    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while(entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            // key not found
            return;
        } else {
            if (prev == NULL) {
                // remove first bucket of the list
                table[hashValue] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            delete entry;
        }
    }

private:
    HashMap(const HashMap & other);
    const HashMap & operator=(const HashMap & other);

    // hash table
    HashNode<K, V> *table[tableSize];
    F hashFunc;
};

// ---- client side code from here ----
struct MyKeyHash {
    unsigned long operator()(const int& k) const {
        return k % 10;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    HashMap<int, string, 10, MyKeyHash> hmap;
    
    hmap.put(1, "1");
    hmap.put(2, "2");
    hmap.put(3, "3");
    
    string value;
    bool res = hmap.get(2, value);
    assert(res);
    assert(value == "2");
    cout << value << endl;
    
    res = hmap.get(3, value);
    assert(res);
    assert(value == "3");
    cout << value << endl;

    hmap.remove(3);
    res = hmap.get(3, value);
    assert(!res);
    if (!res) cout << "key 3 not found in the hashmap" << endl;

    return 0;
}
