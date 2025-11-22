#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

// transpose of sparse mat
void transpos(Term A[], Term T[]) {
    int k = 1;
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].val = A[0].val;

    for(int i=0;i<A[0].col;i++){
        for(int j=1; j<=A[0].val; j++){
            if(A[j].col == i){
                T[k].row = A[j].col;
                T[k].col = A[j].row;
                T[k].val = A[j].val;
                k++;
            }
        }
    }
}

// add two sparse matrixes
void addSparse(Term A[], Term B[], Term C[]){
    if(A[0].row != B[0].row || A[0].col!=B[0].col){
        return;  // dims mismatch
    }

    C[0].row = A[0].row;
    C[0].col = A[0].col;

    int i=1,j=1,k=1;

    while(i<=A[0].val && j<=B[0].val){
        if(A[i].row==B[j].row && A[i].col==B[j].col){
            C[k].row = A[i].row;
            C[k].col = A[i].col;
            C[k].val = A[i].val + B[j].val;
            i++; j++; k++;
        }
        else if( (A[i].row < B[j].row) ||
                 (A[i].row==B[j].row && A[i].col < B[j].col) ) {
            C[k++] = A[i++];
        } else {
            C[k++] = B[j++];
        }
    }

    while(i<=A[0].val) C[k++] = A[i++];
    while(j<=B[0].val) C[k++] = B[j++];

    C[0].val = k-1;
}

// multiplication (simple method)
void multiSparse(Term A[], Term B[], Term C[]){
    if(A[0].col != B[0].row) return;  // matrx not multipliable

    Term BT[100];
    transpos(B, BT);   // use transpose of B

    int k = 1;
    C[0].row = A[0].row;
    C[0].col = B[0].col;

    for(int i=1;i<=A[0].row;i++){
        for(int j=1;j<=B[0].col;j++){
            int sum = 0;

            for(int x=1; x<=A[0].val; x++){
                if(A[x].row == i){
                    for(int y=1; y<=BT[0].val; y++){
                        if(BT[y].row==j && BT[y].col==A[x].col){
                            sum += A[x].val * BT[y].val;
                        }
                    }
                }
            }

            if(sum!=0){
                C[k].row = i;
                C[k].col = j;
                C[k].val = sum;
                k++;
            }
        }
    }

    C[0].val = k-1;
}

int main() {
    // sample sparse mat A (3 non-zero valus)
    Term A[100] = {
        {3,3,3},
        {0,0,1},
        {0,2,2},
        {2,1,3}
    };

    // sample B
    Term B[100] = {
        {3,3,3},
        {0,1,4},
        {1,2,5},
        {2,0,6}
    };

    Term T[100], S[100], M[100];

    transpos(A, T);
    addSparse(A, B, S);
    multiSparse(A, B, M);

    return 0;
}
