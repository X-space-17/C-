// C语言没有像MATLAB一样的元胞数组,每个数组的所有元素类型必须完全一致

// 找出所有输入的数中比这些数的平均数大的值
// #include <stdio.h>
// int main() {
//     int input[100];   // 预分配给一个空数组100个int类型的位置,数组的大小一旦创建无法改变大小，故输入数据量不可超过100
//     int sum=0;
//     int count=0;
//     int x;
//     do {
//         scanf("%d",&x);
//         input[count]=x;
//         count+=1;
//         sum+=x;
//     } while (count<5);
//     if (count!=0) {
//         printf("%lf\n",(double)(sum/count));
//         int i;
//         for (i=0;i<count;i+=1) {
//             if (input[i]>(double)(sum/count)) {
//                 printf("%d\n",input[i]);
//             }
//         }
//     }
//     return 0;
// }


// example:统计个数(用数组统计出现次数(输入数字只有10种结果)而非所有输入的数字！)
// #include <stdio.h>
// int main() {
//     int result[10];
//     int n;
//     for (n=0;n<=9;n+=1) {
//         result[n]=0;     // 对于数组进行初始化
//     }
//     int x;
//     scanf("%d",&x);
//     while (x!=-1) {
//         int i;
//         for (i=0;i<=9;i+=1) {
//             if (x<0 || x>9) {
//                 printf("请输入从0到9之间的数字\n");
//                 break;
//             }
//             else {
//                 if (x==i) {
//                     result[i]+=1;
//                 }
//             }
//         }
//         scanf("%d",&x);
//     } 
//     int m;
//     for (m=0;m<=9;m+=1) {
//         printf("数值为%d的数有%d个\n",m,result[m]);
//     }
// }


//   数组操作:
// 以下这些初始化均为对数组的集成初始化(直接用{}包裹给出数组中的全部/部分元素)： 
//完全初始化：int a[] = {2, 4, 6, 8}; 编译器会自动计算数组大小为4。
//部分初始化：int a[10] = {2}; 只有 a[0] 是2,其余9个元素被自动初始化为0。
//指定初始化：可以指定初始化某个位置的元素。int a[10] = {[0]=2, [2]=3, 6}; 会初始化 a[0]=2, a[2]=3, a[3]=6，其余为0。

// 集成初始化
// #include <stdio.h>
// int main() {
//     int a[] ={2,4,6,8,23,45,56,67,87,32,1};  // 编译器会自动计算位数
//     int i;
//     for (i=0;i<11;i+=1) {
//         printf("%d\t",a[i]);
//     }
//     printf("\n");
//     //
//     int b[11] ={2,4,1};  // 编译器会默认其余位上均为0
//     int x;
//     for (x=0;x<11;x+=1) {
//         printf("%d\t",b[x]);
//     }
//     printf("\n");
//     //
//     int c[11]={[0]={1},[1]={9},[2]={6}};
//     int y;
//     for (y=0;y<11;y+=1) {
//         printf("%d\t",c[y]);
//     }
//     return 0;
// }

// 我们也可以用到之前判断数值类型大小的sieof来计算数组中元素的数量
// #include <stdio.h>
// int main() {
//     int a[] ={2,4,6,8,23,45,56,67,87,32,1};  // 编译器会自动计算位数
//     int i;
//     for (i=0;i<11;i+=1) {
//         printf("%d\t",a[i]);
//     }
//     printf("\n");
//     printf("%d\n",sizeof(a));  // 44Byte(11*4Byte)
//     //
//     int number;
//     number=sizeof(a)/sizeof(a[0]); // 手动计算数组存储元素数量  
//     printf("%d\n",number);
//     return 0;
// }


// 数组无法直接复制
// int a[]={1,2,3};  int b[]=a; 错！！


//  特别注意：
// 数组作为参数时，若需要调用数组长度，往往必须再用一个参数来传入数组的大小，不可直接用sizeof!
// (因为数组作为函数参数时，会"退化"为指针，此时如果使用sizeof(a)/sizeof(a[0])得到的是数组a的指针的大小/第一个元素的大小,而不是真实的数组a的大小/第一个元素的大小)
// #include <stdio.h>
// void f(int a[],int len) {
//     int i;
//     for (i=0;i<len;i+=1) {
//         printf("%d\t",a[i]);
//     }
//     printf("\n");
// }
// int main() {
//     int a[]={1,2,4,6,7};
//     int size=sizeof(a)/sizeof(a[0]);
//     f(a,size);
//     printf("%d\n",size);
//     return 0;
// }


// 素数判断简化
// #include <stdio.h>
// #include <math.h>
// int isPrime(int x) {
//     int result=1;
//     int i;
//     if ((x%2==0 && x!=2) || (x<=1)) {
//         result=0;
//     }
//     else {
//         int limit=sqrt(x);   // 避免sqrt()被重复调用
//         for (i=3;i<=limit;i+=2) {    // 排除了输入数为偶数的情况，下面对奇数进行筛选：又由于奇数中不可能拆出2这个因数，所以一切大于0的偶数均不可作为因数，所以因数也只需要从奇数中筛选即可
//             if (x%i==0) {
//                 result=0;
//                 break;
//             }
//         }
//     }
//     return result;
// }
// int main() {
//     int num;
//     scanf("%d",&num);
//     if (isPrime(num)==0) {
//         printf("%d不是素数",num);
//     }
//     else {
//         printf("%d是素数",num);
//     }
//     return 0;
// }


// 还有更运算更省时的方法，即检验因数时只去检验比x小的素数，而这样做之所以可行是因为每个合数因数分解至最简形式后每个因数都将是素数，而如果一个数无法整除比其小的所有素数，则证明其一定是素数
// 但是建立素数表前也需判断是否为素数，因此素数存入与素数判断应当同时进行;
// 下面程序的目标:以上面的方式找到前100个素数
// #include <stdio.h>
// int prime(int x,int store[],int count) {  // 先用此函数建立判断逻辑，后续在main()函数中去调用并真正建立起素数库
//     int result=1;
//     int i;
//     for (i=0;i<count;i+=1) {
//         if (x%store[i]==0) {
//             result=0;
//             break;
//         }
//     }
//     return result;
// }
// int main() {
//     int store[100]={2};
//     int count=1;
//     int num=3;
//     while (count<100) {
//         if (prime(num,store,count)==1) {   // 边建立素数库边调用其中素数作为因数进行检验!
//             store[count]=num;
//             count+=1;
//         }
//         num+=1;      // 从3开始逐个筛选直至素数库中存储数量达到100个
//     }
//     int i;
//     for (i=0;i<=99;i+=1) {
//         printf("%d",store[i]);
//         if ((i+1)%5) {
//             printf("\t");
//         }
//         else {
//             printf("\n");
//         }
//     }
//     return 0;
// }



// 二维数组
// #include <stdio.h>
// int main() {
//     int two_dimension[4][3];  // 分配一个4行三列的空二维数组 (但是注意调用时索引从0开始)
//     int i,j;
//     for (i=0;i<4;i+=1) {
//         for (j=0;j<3;j+=1) {
//             two_dimension[i][j]=(i+1)*(j+1);
//             printf("%d\t",two_dimension[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 定义二维数组时，列数不可省略，但行数可以省略
// #include <stdio.h>
// int main() {
//     int two_dimension[][3]={
//         {1,2,3},       // 一个大括号所包裹的数代表一行
//         {4,5,6},
//         {7,8,9}
//     };  
//     int i,j;
//     for (i=0;i<3;i+=1) {
//         for (j=0;j<3;j+=1) {
//             printf("%d\t",two_dimension[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


// tic-tac-toe游戏
// #include <stdio.h>
// int main() {
//     int matrix[3][3];
//     int i,j;
//     for (i=0;i<3;i+=1) {
//         for (j=0;j<3;j+=1) {
//             scanf("%d",&matrix[i][j]);
//         }
//     }
//     //
//     int result=-1;
//     // 首先检查3行
//     for (i=0;i<3;i+=1) {
//         if (matrix[i][0]==0 && matrix[i][1]==0 && matrix[i][2]==0) {
//             result=0;
//             break;
//         } else if (matrix[i][0]==1 && matrix[i][1]==1 && matrix[i][2]==1) {
//             result=1;
//             break;
//         }
//     }
//     // 检查3列
//     for (j=0;j<3;j+=1) {
//         if (matrix[0][j]==0 && matrix[1][j]==0 && matrix[2][j]==0) {
//             result=0;
//             break;
//         } else if (matrix[0][j]==1 && matrix[1][j]==1 && matrix[2][j]==1) {
//             result=1;
//             break;
//         }
//     }
//     // 检查对角线
//     if (matrix[0][0]==0 && matrix[1][1]==0 && matrix[2][2]==0) {
//         result=0;
//     }
//     else if (matrix[0][0]==1 && matrix[1][1]==1 && matrix[2][2]==1) {
//         result=1;
//     }
//     //
//     printf("\n");
//     for (i=0;i<3;i+=1) {
//         for (j=0;j<3;j+=1) {
//             if (result==0 && matrix[i][j]==0) {
//                 printf("%d ",matrix[i][j]);
//             }
//             else if (result==0 && matrix[i][j]!=0) {
//                 printf("  ");
//             }
//         }
//         printf("\n");
//     }
//     for (i=0;i<3;i+=1) {
//         for (j=0;j<3;j+=1) {
//             if (result==1 && matrix[i][j]==1) {
//                 printf("%d ",matrix[i][j]);
//             }
//             else if (result==1 && matrix[i][j]!=1) {
//                 printf("  ");
//             }
//         }
//         printf("\n");
//     }
//     return 0;
// }