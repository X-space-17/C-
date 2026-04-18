// 函数：模块化编程


// 质数之和
// #include <stdio.h>
// int isprime(int num) {
// 	int result=1;
// 	int k;
// 	if (num==1) {
// 		result=0;
// 	}
// 	else if (num==2) {
// 		result=1;
// 	}
// 	for (k=2;k<=num-1;k++) {
// 		if (num%k==0) {
// 			result=0;
// 			break;
// 		}
// 	}
// 	return result;
// }
// int main() {
// 	int sum=0;
// 	int m,n;
// 	scanf("%d %d",&m,&n);
// 	int i;
// 	for (i=m;i<=n;i+=1) {
// 		if (isprime(i)==1) {
// 			sum+=i;
// 		}
// 	}
// 	printf("%d %d %d",m,n,sum);
// 	return 0;
// }



// void: 表示函数返回类型/传入参数为空
// #include <stdio.h>
// void sum(int a,int b) {
//     int i;
//     int result=0;
//     for (i=a;i<=b;i+=1) {
//         result+=i;
//     }
//     printf("%d",result);
// }
// int main() {
//     int x,y;
//     scanf("%d %d",&x,&y);
//     sum(x,y);
//     return 0;
// }

// #include <stdio.h>
// void start(void) {
//     printf("Hello World!");
// }
// int main() {
//     start();
//     return 0;
// }



// 函数原型
// #include <stdio.h>
// int sum(int a,int b);  // 声明自定义函数的函数原型
// int main() {
//     int x,y;
//     int result;
//     scanf("%d %d",&x,&y);
//     result=sum(x,y);
//     printf("%d",result);
//     return 0;
// }
// int sum(int a,int b) {
//     return a+b;
// }



// 一个bug
// #include <stdio.h>
// void f(int x) {
//     printf("%d",x);
// }
// int main() {
//     f(2.4);   // 
//     return 0;
// }



// 本地变量(用大括号包裹的块中定义)
// 两数交换(体会变量的作用域与生存期--往往在函数调用时因切换函数而转变)
#include <stdio.h>
int swap(int a,int b) {
    int t;
    t=a;
    a=b;
    b=t;
}
int main() {
    int x=12,y=34;
    swap(x,y);   // 仅修改swap()函数中的a,b而不影响x,y的值
    printf("%d %d",x,y);
    return 0;
}
// 函数中定义的是形参，传递的是main函数中的副本，即只传值不传变量，若要真正交换两数需要用到指针来对内存进行重写
// #include <stdio.h>
// void swap(int *a, int *b) {
//     int t;
//     t = *a;   // 取值
//     *a = *b;  // 修改地址指向的值
//     *b = t;
// }
// int main() {
//     int x = 12, y = 34;

//     // 2. 调用时传递地址 (&x, &y)
//     swap(&x, &y);

//     printf("%d %d", x, y);
//     return 0;
// }