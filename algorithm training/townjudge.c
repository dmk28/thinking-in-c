#include <stdio.h>



int findJudge(int N, int** trust, int trustSize, int* trustColSize) {

    int trusting[1000] = {0}, trusted[1000]={0},i;

    for (i=0; i<trustSize;i++) {
        trusting[trust[i][0]-1]++;
        trusted[trust[i][1]-1]++;
    }

    for (i=0; i<N;i++) {
        if (trusting[i]==0) {
            if(trusted[i]==(N-1))
            return i+1;
        }
    }
    return -1;
}

