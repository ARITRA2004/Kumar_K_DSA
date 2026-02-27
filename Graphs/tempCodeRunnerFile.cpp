for(int i=0;i<m;i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }