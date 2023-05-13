#include <stdio.h>
int gcd(int i, int j,int *count);
int main() {
    int n1, n2,count=0;
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);
    printf("G.C.D of %d and %d is %d\n.", n1, n2, gcd(n1, n2, &count));
    printf("number of steps: %d ",count);
    return 0;
}

int gcd(int i, int j,int *count) {
	(*count)                                                                                     ++;
 if(j==0)
 {
 	return i;
 }
 else
 {
 	return gcd(j,i%j,count);
 }
}

