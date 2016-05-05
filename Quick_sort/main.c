//
//  main.c
//  Quick_sort
//
//  Created by 王亓泰 on 16/4/16.
//  Copyright © 2016年 WangQitai. All rights reserved.
//

#include <stdio.h>

void quickSort(int * a, int numSize)
{
    int i = 0, j = numSize - 1;
    int val = a[0];
    if (numSize < 2) {
        return;
    }
    
    while (i < j) {
        for (; j > i; j--) {
            if (a[j] < val) {
                a[i++] = a[j];
                break;
            }
        }
        
        for (; i < j; i++) {
            if (a[i] > val) {
                a[j--] = a[i];
                break;
            }
        }
    }
    
    // 将val放到分界线出
    a[i] = val;
    quickSort(a, i);
    quickSort(a + i + 1, numSize - i - 1);
    //  0 9   numSize = 10
    // 0---4 5 6---9   n - i -1 + 1 = numSize - 1 - i
}


int main(int argc, const char * argv[]) {
    
    int a[10] = {5,1,3,9,7,6,4,2,0,8};
    
    for (int i = 0; i<10; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    quickSort(a, 10);
    
    for (int i = 0; i<10; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    return 0;
}
