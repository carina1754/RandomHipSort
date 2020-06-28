#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#pragma warning(disable : 4996)
#define parent(x) (x-1)/2

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int *arr, int here, int size) {
    int left = here * 2 + 1;
    int right = here * 2 + 2;
    int max = here;
    if (left < size && arr[left]>arr[max])
        max = left;
    if (right < size && arr[right]>arr[max])
        max = right;

    if (max != here) {
        swap(&arr[here], &arr[max]);
        heapify(arr, max, size);
    }
}

void buildHeap(int *arr, int size) {
    int i, j;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, i, size);
       // for (j = 0; j < size; j++)
        //    printf("%d ", arr[j]);
       // printf("\n\n");
    }
}

void heapSort(int *arr, int size) {
    int treeSize;
    buildHeap(arr, size);
    for (treeSize = size - 1; treeSize >= 0; treeSize--) {
        swap(&arr[0], &arr[treeSize]);
        heapify(arr, 0, treeSize);
    }
}

void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    FILE* input_file, * output_file;
    input_file = fopen("input.txt", "r");
    int data,*usernum,*rannum, *ran1num, i=0, j,k, size, temp = 0,r,c,a=0,p;
    char str[10], **user,**ranuser;
    printf("반의 가로 책상의 수와 세로 책상의 수를 입력하세요 : ");
    scanf("%d %d", &c, &r);
    
    while (fscanf(input_file, "%d %s", &data, str) > 0) {
        i++;
    }

    usernum = (int*)malloc(sizeof(int) * i);
    
    rannum = (int*)malloc(sizeof(int) * i);
    ran1num = (int*)malloc(sizeof(int) * i);
    user = (char**)malloc(sizeof(char*) * i);
    ranuser = (char**)malloc(sizeof(char*) * i);
    for (j = 0; j < i; j++) {
        user[j] = (char*)malloc(sizeof(char) * 10);
    }

    i = 0;
    
    fclose(input_file);
    
    input_file = fopen("input.txt", "r");

    while (fscanf(input_file, "%d %s", &data, str) > 0) {
        usernum[i] = data;
        strcpy(user[i], str);
        i++;
    }
//
  //  for (k = 0; k < i; k++) {
  //      printf("%d %s \n", usernum[k], user[k]);
 //   }
//
    fclose(input_file);

    srand(time(NULL));

    for (k = 0; k < i; k++) {
        rannum[k] = rand() % i + 1;
        for (j = 0; j < k; j++) {
            if (rannum[k] == rannum[j]) {
                k--;
                break;
            }
        }
    }
    for (k = 0; k < i; k++) {
        ran1num[k] = rannum[k];
    }
    printf("출석번호별 좌석 \n \n");
    for (j = 0; j < r; j++) {
        for (k = 0; k < c; k++) {
            if (a < i) {
                p = rannum[a];
                printf("%6d",p);
                a++;
            }
        }
        printf("\n \n");
    }
    a = 0;
    printf("이름별 좌석 \n \n");
    for (j = 0; j < r; j++) {
        for (k = 0; k < c; k++) {
            if (a < i) {
                p = rannum[a];
                printf("%6s", user[p-1]);
                ranuser[p-1] = user[p - 1];
                a++;
            }
        }
        printf("\n \n"); 
    }
    
    heapSort(rannum, i);
    a = 0;
    for (j = 0; j < r*(c-3); j++) {
        for (k = 0; k < 3; k++) {
            if (a < i) {
                printf("%6s 좌석 번호 : %3d   ", ranuser[a], ran1num[a]);
                a++;
            }
        }
        printf("\n \n");
    }
    free(usernum);
    free(rannum);
    free(user);
    return 0;
}   