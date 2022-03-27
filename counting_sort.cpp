
void counting_sort(int *A, int k, int n) {

    int a[k+1], // counter array
    temp[n]; // temp array to hold output
    int i;

    for(i=0; i<k+1; i++){ //set acum arr to 0
        a[i] = 0;
    }

    for (i=0; i<n; i++){//acum values in A
        ++a[A[i]];
    }

    for(i=1; i<k+1; i++) {//add up acum arr
        a[i] = a[i] + a[i-1];
    }
 
    for (i=n-1; i>-1; i--){//insert into ouput array
        temp[a[A[i]]-1] = A[i];
        --a[A[i]] ;
    }
 
    // setting A to output
    for(i=0; i<n; i++){
        A[i] = temp[i];
    }
}
