#include <stdio.h>
int main() {
    int arr4[3][3] = {1,3,5,7,9,11,13,15,17};
    int (*pArr)[3] = arr4;
    // 2차원 배열의 포인터 연산을 위해서는 각 일차원 배열을 가리키는 포인터배열을 만들어줘서 접근 가능
    for(int i=0; i<3; i++){
        // 1. 배열 직접 접근
		printf("1st. Idx[%d][%d] = %d\n", i, i%3, *(arr4[i]));
		printf("1st. Idx[%d][%d] = %d\n", i, i%3, *(arr4[i]+1));
		printf("1st. Idx[%d][%d] = %d\n", i, i%3, *(arr4[i]+2));
        
        // 2. 포인터를 통한 배열 요소 접근 i%3,
        printf("2nd. Idx[%d][%d] = %d\n", i, i%3, *(pArr[i]));
		printf("2nd. Idx[%d][%d] = %d\n", i, i%3, *(pArr[i]+1));
		printf("2nd. Idx[%d][%d] = %d\n", i, i%3, *(pArr[i]+2));
    }
    return 0;
}