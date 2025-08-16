#include <stdio.h>
#include <stdlib.h>

void findZigZagSequence(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    
    int mid = (n - 1) / 2;       
    

    int temp = a[mid];
    a[mid] = a[n - 1];
    a[n - 1] = temp;
    
    int left = mid + 1;
    int right = n - 2;         

    while (left < right) {
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;             
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int* a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        findZigZagSequence(a, n);
        
        for (int i = 0; i < n; i++) {
            printf("%d", a[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
        
        free(a);
    }
    
    return 0;
}
