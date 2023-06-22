/*
You are given two arrays 𝑎
 and 𝑏
, each consisting of 𝑛
 positive integers, and an integer 𝑥
. Please determine if one can rearrange the elements of 𝑏
 so that 𝑎𝑖+𝑏𝑖≤𝑥
 holds for each 𝑖
 (1≤𝑖≤𝑛
).

Input
The first line of input contains one integer 𝑡
 (1≤𝑡≤100
) — the number of test cases. 𝑡
 blocks follow, each describing an individual test case.

The first line of each test case contains two integers 𝑛
 and 𝑥
 (1≤𝑛≤50
; 1≤𝑥≤1000
) — the length of arrays 𝑎
 and 𝑏
, and the parameter 𝑥
, described in the problem statement.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎1≤𝑎2≤⋯≤𝑎𝑛≤𝑥
) — the elements of array 𝑎
 in non-descending order.

The third line of each test case contains 𝑛
 integers 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏1≤𝑏2≤⋯≤𝑏𝑛≤𝑥
) — the elements of array 𝑏
 in non-descending order.

Test cases are separated by a blank line.

Output
For each test case print Yes if one can rearrange the corresponding array 𝑏
 so that 𝑎𝑖+𝑏𝑖≤𝑥
 holds for each 𝑖
 (1≤𝑖≤𝑛
) or No otherwise.

Each character can be printed in any case.

Example
input
4
3 4
1 2 3
1 1 2

2 6
1 4
2 5

4 4
1 2 3 4
1 2 3 4

1 5
5
5
output
Yes
Yes
No
No
*/

#include<iostream>
using namespace std;

void sort_array(int A[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        if(A[i]>A[min]){
            int temp=A[min];
            A[min]=A[i];
            A[i]=temp;
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int p=0;p<t;p++){
        int n;
    cin>>n;
    int x1;
    cin>>x1;
    
    int M[n];
    int D[n];
    for(int i=0;i<n;i++){
        cin>>M[i];
    }
    for(int i=0;i<n;i++){
        cin>>D[i];
    }
    sort_array(M,n);
    sort_array(D,n);
    

    int flag=0;
    int j=n-1;
    for(int i=0;i<n;i++){
        if((M[i]+D[j])>x1){
            flag=1;
        }
        j--;
    }
    if(flag==0){
        cout<<"Yes"<<"\n";
    }
    else{
        cout<<"No"<<"\n";
    }
    }

}