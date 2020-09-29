#include <iostream>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

#if 0
int solution(int *A, int N) {
    int result =1;
    int node_index = 0;
    for(int i =0; i < N; i++){
        if(A[node_index] == -1){
            break;
        }else{
            node_index = A[node_index];
            result++;
        }
    }
    return result;
}

#endif

using namespace std;

#if 0
void solution(int N) {
    int enable_print = N % 10;
    while (N > 0) {
        if (enable_print == 0 || N / 10 != 0) {
            enable_print = 1;
        }
        if (enable_print == 1) {
            printf("%d", N % 10);
        }
        N = N / 10;
    }
}

#endif

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N){

	//Min Distance
	int Result = 0;

	//Print Adjacent Pairs
	for(int q=1; q < N; q++){
		for(int p=0; p < q ; p++){
			    if(A[p] != A[q]){
			        int valuefound = 0;
			    	int diff = abs(A[p] - A[q]);
			    	for(int x = 0; x  < N ; x++)
			    	{
			    	    if(x == p || x == q)
			    	        continue;
			    	    else if (A[x] == diff){
			    	        valuefound = 1;
			    	        break;
			    	    }
			    	}
			    	if(valuefound == 0){
			    	    cout << p << q  << endl;
			    	}

			    }
		}
	}

	//Minimun Disatance between Adjacent Pairs

	//Smallest Minimun Distance

	return Result;
}

int main()
{
   int A[] = {0,3,3,7,5,3,11,1};
   cout << solution(A, sizeof(A)/sizeof(int));
   return 0;

}
