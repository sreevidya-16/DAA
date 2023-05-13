#include <stdio.h>
 int longestIncreasingSubsequence(int arr[], int n) { 
 int i,j;
 int dp[n]; 
 for ( i = 0; i < n; i++) 
 { dp[i] = 1; 
   for ( j = 0; j < i; j++)
  { if (arr[j] < arr[i]) 
    { dp[i] = (dp[i] > dp[j] + 1) ? dp[i] : dp[j] + 1; 
	} } } 
	int max_len = 0; 
	for ( i = 0; i < n; i++) { 
	if (dp[i] > max_len) 
	{ max_len = dp[i]; 
	} } 
	return max_len; }
int main() { 
   int n,i,arr[100];
   printf("enter size of array: ");
   scanf("%d",&n);
   printf("enter array: ");
   for(i=0;i<n;i++)
   {
   	scanf("%d",&arr[i]);
   }
 printf("Length of longest increasing subsequence is %d", longestIncreasingSubsequence(arr, n));
  return 0; }
