#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//
// Created by zhangshuai on 2020/12/9. 
// Contact by zhangshuai@dushu.io
// 内存管理

//序号	函数和描述
//1	void *calloc(int num, int size);
//在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。
//所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是0。
//2	void free(void *address);
//该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
//3	void *malloc(int num);
//在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
//4	void *realloc(void *address, int newsize);
//该函数重新分配内存，把内存扩展到 newsize。


//动态分配内存
void DynamicallyAllocateMemory(void) {
    char name[100];
    char *description;
    //Zara Ali赋值给name数组
    strcpy(name, "Zara Ali");

    //动态分配内存
    description = (char *) malloc(200 * sizeof(char));
//    description = (char *) calloc(200, sizeof(char));
    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcpy(description, "Zara ali a DPS student in class 10th.");
    }
    printf("Name：%s\n", name);
    printf("Description：%s\n", description);

    //假设您想要存储更大的描述信息
    description = (char *) realloc(description, 100 * sizeof(char));
    if (description == NULL) {
        fprintf(stderr, "Error - unable to allocate required memory\n");
    } else {
        strcat(description, "\tShe is in class 10th.");
    }
    printf("Name：%s\n", name);
    printf("Description：%s\n", description);

    free(description);
}

void CacheManagerMain(void) {
    DynamicallyAllocateMemory();
}