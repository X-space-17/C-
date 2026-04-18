// 运算符&：取得变量的地址

// #include <stdio.h>
// int main() {
//     int x;
//     scanf("%d",&x);
//     printf("%p",&x);  // %p格式化占位符：以十六进制格式输出指针变量存储的内存地址
//     return 0;
// }


// #include <stdio.h>
// int main() {
//     int a=0;
//     int b=1;
//     printf("%p\n",&a);
//     printf("%p\n",&b);
//     return 0;
// }
// 观察a,b地址可以发现地址相差4(a比b大4)，即4个Byte; 而a比b先定义，所以可猜测到C语言中数据存储时为在堆栈(stack)中从上到下进行存储


// 我们可以进一步通过运算符&取地址来观察数组在C语言中存储的方式
// #include <stdio.h>
// int main() {
//     int array[10];
//     printf("%p\n",&array);
//     printf("%p\n",&array[0]);  // 可以看到 &array[0]与 &array相同,故间接表明array被调用的时候是一个指针; 因此直接写作&array[0]=array也可以，因为array本身就是指针，无需再进行取地址操作
//     printf("%p\n",&array[1]);
//     return 0;
// }


// 找出数组中的最大值与最小值
// #include <stdio.h>
// int minmax(int array[],int len,int *min,int *max) {  // 当数组作为参数传递给函数时,该数组会退化为一个指针,此时千万不要用sizeof来计算数组的大小
//     int i;
//     for (i=0;i<len;i+=1) {
//         if (array[i]> *max) {
//             *max=array[i];
//         }
//         if (array[i]< *min) {
//             *min=array[i];
//         }
//     }
// }
// int main() {
//     int shuzu[10]={1,12,43,65,2,45,54,21,8,5};
//     int min=shuzu[0];
//     int max=shuzu[0];
//     minmax(shuzu,sizeof(shuzu)/sizeof(shuzu[0]),&min,&max);
//     printf("array中最大数为%d\n最小数为%d\n",min,max);
//     return 0;
// }


// 数组局部翻转
// #include <stdio.h>
//     // int i;
//     // for (i=*start;i<=*end;i+=1) {
//     //     array[i]=array[(*start+*end)-i];
//     // }      // 这样会丢失信息！
//     //
//     // void reverse_sub_array(int array[],int len,int *start,int *end) {
//     //   while (*start<=*end) {
//     //     int i=array[*start];
//     //     array[*start]=array[*end];
//     //     array[*end]=i;
//     //     *start+=1;
//     //     *end-=1;
//     //   }
//     // }      // 这样写其实还是在用下标思维！
//     // 
// void reverse_sub_array(int *start,int *end) {
//     while (start<end) {  // 直接比较地址
//         int i=*start;
//         *start=*end;
//         *end=i;
//         start+=1;
//         end-=1;
//     }
// }
// int main() {
//     int shuzu[10]={1,2,3,42,31,72,21,12,35,29};
//     int start;
//     int end;
//     scanf("%d %d",&start,&end);
//     if (start>=0 && end<10 && start<=end) {
//         reverse_sub_array(&shuzu[start],&shuzu[end]);
//         int i;
//         for (i=0;i<10;i+=1) {
//             printf("%d ",shuzu[i]);
//         }
//     }
//     else {
//         printf("error");
//     }
//     return 0;
// }


// 指针与const
// #include <stdio.h>
// int main() {
// // 此处const：不变的是指针变量的值，即所存储的变量的地址不可更改，因此不可以修改该指针去指向其他变量(p=&i_1:❌️)
//     int i=26;
//     int *const p=&i;
//     printf("%p\n",p);
// // 此处const：不变的是该地址处存放的数值(例如*p_1=48就不可行),本质含义是限制通过该指针修改内存的能力。
//     int i_1=37;
//     const int *p_1=&i_1;   // int const *p_1=&i_1与其等价
//     printf("%p\n",p_1);
//     // i_1 = 245 是直接通过变量名修改内存,这是完全合法的。
//     // 这里否定的是以指针来修改内存这种方式, 本质上是剥夺了指针的写入权限
//     printf("%d\n",i_1);
//     i_1=245;
//     printf("%d\n",i_1);
//     return 0;
// }


// const数组：数组本身地址就不可修改,对其加上const之后(const int array[3]={1,2,3};)数组中存储的数据就也会变为常量
    // 普通数组 int a[3]： “脚”（地址）是固定的，但“脸”（数据）可以随便整容。
    // const数组 const int a[3]： “脚”（地址）固定，“脸”（数据）也打了封条，禁止动刀。
// 为了保证数组在函数中不被其中操作修改，可以设置其类型为const: int sum(const int array[],int len)
// #include <stdio.h>
// int main() {
//     int i=123;
//     int *array_simple=&i;
//     const int *array_const=&i;
//     printf("%d\n",*array_simple);
//     printf("%d\n",*array_const);
//     *array_simple=456;      // 普通数组还可以通过指针修改内存
//     printf("%d\n",*array_simple);
//     printf("%d\n",*array_const);
//     return 0;
// }


// 指针运算
// 指针的+1或-1,不是加减1个字节，而是加减1个指向类型的单位大小
// #include <stdio.h>
// int main() {
//     int i=5;
//     int *p1=&i;
//     printf("%p\n",p1);
//     p1+=1;
//     printf("%p\n",p1);   // 前后地址相差4Byte
//     //
//     char i_1=5;
//     char *p2=&i_1;
//     printf("%p\n",p2);
//     p2+=1;
//     printf("%p\n",p2);   // 前后地址相差1Byte
//     return 0;
// }

// 指针能做的四种运算:
    // 1.指针 ± 整数;
    // 2.指针 - 指针（同类型）
    // 3.指针与整数的比较
    // 4.指针赋值
// #include <stdio.h>
// int main() {
//     int arr[5] = {10, 20, 30, 40, 50};
//     int *p = arr; // arr数组自身即是指针,p初始指向arr[0]

//     // 1. 指针 ± 整数 (移动地址)
//     int *p3 = p + 2; 
//     printf("p3 指向的值: %d\n", *p3); 

//     // 2. 指针 - 指针 (算指针之间相差的“距离”,必须为同类型指针进行运算，表示含有多少个指针所指向类型的单位大小,而不是仅仅进行地址加减)
//     long diff = p3 - p; 
//     printf("p3 与 p 之间的距离: %ld 个元素\n", diff);

//     // 3. 指针与指针的比较 (定界)
//     int *end = &arr[5];    // 指向数组最后一个元素之后的“哨兵”位置
//     int *temp;
//     for (temp = arr; temp < end; temp+=1) { 
//         printf("%d ", *temp);
//     }
//     printf("\n");

//     // 4. 指针赋值 (共享/重定向)
//     int *q = NULL;
//     q = p3; 
//     printf("q 现在指向: %d\n", *q);

//     return 0;
// }


// 指针类型转换
// #include <stdio.h>
// int main() {
//     int num=6;
//     void *p_1=&num;    // 任意类型的指针都可以隐式转换为void*,即可以充当"通用接口"; 但随之而来的代价是无法进行指针计算与解引用，因为编译器不知道指针类型，故不知道按几个字节来解析 
//     printf("%p\n",p_1);
//     int *p_2=p_1;      // 在C语言中，将void*转为int*无需进行强制类型转换(但是C++需要：int *p_2=(int*)p_1;)
//     printf("%p\n",p_2);
//     //
//     int n=7;
//     int *p_3=&n;
//     printf("%p\n",p_3);
//     char *p_4=(char*)p_3;
//     printf("%p\n",p_4);      // 可以发现强制类型转换之后指针对应的地址没有发生改变，说明强制转换只改变解引用的逻辑与指针计算的步长
//     // 
//     char m=52;
//     char*p_5=&m;
//     printf("%p\n",p_5);
//     long *p_6=(long*)p_5;    
//     printf("%p\n",p_6);
//     printf("%d\n",*p_5);
//     long k=*p_6;
//     printf("%ld\n",k);      // // 给char类型的p_5指针强行声明是long类型的指针,导致后续解指针时出现问题,发生解引用溢出(在此处是以int类型去解char类型的指针，读完char类型的1个字节再去读int类型剩余的3个字节--混入胡乱内容)
//     return 0;
// }


// 动态内存分配(利用malloc实现数组内存的动态调整，即可以在程序运行时再去确定数组的具体大小)
// 为那些不愿意提前存入数组中的元素但是同时还不愿意提前设定数组大小的人所准备
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int number;
//     scanf("%d",&number);
//     int* a;
//     a=(int*)malloc(number*sizeof(int));   // malloc本质上是一个"堆内存", 堆内存的设计初衷是能够跨函数、跨时间长期保存数据, 故使用完需要free释放内存; 此外，malloc返回的是void*类型的地址，故需强制类型转换为所需指针类型 
//     // 而平时直接定义数组时：int arr[10]--你使用的是栈内存(Stack),系统会自动回收内存
//     int i;
//     for (i=0;i<number;i++) {
//         scanf("%d",&a[i]);
//     }
//     for (i=number-1;i>=0;i-=1) {
//         printf("%d ",a[i]);
//     }
//     free(a);
//     return 0;
// }
// 此外还有realloc: p=realloc(p,20*sizeof(int));  // 扩容到20个位

// 可申请内存极限压力测试
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int count=0;
//     int *p;
//     while (p=malloc(100*1024*1024)) {   // 每次申请100MB内存直至返回NULL中断循环，从而得出最大可申请内存的容量
//         // 但是这导致一个严重的问题：指针丢失，无法在程序运行结束后释放申请的全部内存(这就像你不停地开新房间,但手里永远只拿最后一把钥匙,之前的钥匙全扔了,你当然没法“退房”)
//         count+=1;
//     }
//     int sum=count*100;
//     printf("系统共分配了%dMB的内存",sum);
//     // free(p);  -->这样无法释放所有内存！因为指针已经丢失（NULL）,找不到内存所在地址
//     return 0;
// }

// 可以改为：
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     int count=0;
//     int *p;
//     int safe=0;
//     while ((p=malloc(100*1024*1024))!=NULL && count<100) {  // 注意!=的优先级比赋值运算符=要高
//         count+=1;
//         safe+=1;
//         free(p);
//         safe-=1;
//     }
//     int sum=count*100;
//     printf("系统共分配了%dMB的内存\n",sum);
//     printf("%d",safe);
//     return 0;
// }