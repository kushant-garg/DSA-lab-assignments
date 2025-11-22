#include <iostream>
using namespace std;

class Diagonal {
    int A[3];
public:
    void set(int i, int j, int x) { if (i==j) A[i]=x; }
    int get(int i, int j) { return (i==j)?A[i]:0; }
};

class TriDiagonal {
    int A[7];
public:
    void set(int i, int j, int x) {
        if(i==j) A[i]=x;
        else if(i==j+1) A[3+j]=x;
        else if(i+1==j) A[3+2+i]=x;
    }
    int get(int i, int j) {
        if(i==j) return A[i];
        if(i==j+1) return A[3+j];
        if(i+1==j) return A[3+2+i];
        return 0;
    }
};

class LowerTriangular {
    int A[6];
public:
    void set(int i, int j, int x) { if(i>=j) A[i*(i+1)/2 + j] = x; }
    int get(int i, int j) { return (i>=j)?A[i*(i+1)/2 + j]:0; }
};

class UpperTriangular {
    int A[6];
public:
    void set(int i, int j, int x) { if(i<=j) A[j*(j+1)/2 + i] = x; }
    int get(int i, int j) { return (i<=j)?A[j*(j+1)/2 + i]:0; }
};

class Symmetric {
    int A[6];
public:
    void set(int i, int j, int x) {
        if(i>=j) A[i*(i+1)/2 + j] = x;
        else A[j*(j+1)/2 + i] = x;
    }
    int get(int i, int j) {
        if(i>=j) return A[i*(i+1)/2 + j];
        else return A[j*(j+1)/2 + i];
    }
};

int main() {
    Diagonal d;
    d.set(0,0,1); d.set(1,1,2); d.set(2,2,3);

    TriDiagonal t;
    t.set(0,0,1);  
    t.set(0,1,2);  
    t.set(1,0,3);  
    t.set(1,1,4);  
    t.set(2,1,5);  

    LowerTriangular l;
    l.set(0,0,1);
    l.set(1,0,2); l.set(1,1,3);
    l.set(2,0,4); l.set(2,1,5); l.set(2,2,6);

    UpperTriangular u;
    u.set(0,0,1); u.set(0,1,2); u.set(0,2,3);
    u.set(1,1,4); u.set(1,2,5);
    u.set(2,2,6);

    Symmetric s;
    s.set(0,0,1);
    s.set(1,0,2); s.set(1,1,3);
    s.set(2,0,4); s.set(2,1,5); s.set(2,2,6);

    return 0;
}
