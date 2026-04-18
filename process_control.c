// 流程控制：顺序结构+选择结构(由条件判断决定)+循环结构

//example_1
// #include <stdio.h>
// int main() {
// 	int hour1,minute1;
// 	int hour2,minute2;
// 	scanf("%d %d",&hour1,&minute1);
// 	scanf("%d %d",&hour2,&minute2);
// 	int delta_hour,delta_minute;
// 	delta_hour=hour2-hour1;
// 	delta_minute=minute2-minute1;
// 	if (delta_minute<0 & delta_hour>0) {
// 		delta_minute=delta_minute+60;
// 		delta_hour-=1;
// 	}
// 	else if (delta_minute>0 & delta_hour<0) {
// 		delta_minute=delta_minute-60;
// 		delta_hour+=1;
// 	}
// 	printf("从1状态到2状态经历了%d时%d分",delta_hour,delta_minute);
// 	return 0;
// }


// 关系运算符：!=,==,>,>=,<,<=，这些关系运算符的运算优先级比数值运算要低，但是比赋值运算符要高
// 其中!=与==比<,>,<=,>=运算符的优先级还要低以便不等式结果的比较
//#include <stdio.h>
//int main() {
//	printf("%d\n",1==5>4);
//	int y=3>0;
//	printf("%d\n",y);
//}


//// 找出三个数中最大的数
//#include <stdio.h>
//int main() {
//	int a,b,c;
//	scanf("%d %d %d",&a,&b,&c);
//	int max_num=a;
//	int sep_max_num;
//	if (b<c) {
//		sep_max_num=c;
//	}
//	else {
//		sep_max_num=b;
//	}
//	if (sep_max_num>max_num) {
//		max_num=sep_max_num;
//	}
//	printf("%d",max_num);
//	return 0;
//}


// switch-case语句(其中控制表达式只能是整数型的结果,case后面所跟的是一个数值型的常数)
// 现在比较if-else if-else与switch-case的运行速度的差距
// 注意break只能在for,while循环中或者switch-case中使用，而不能用于if-else if-else这样的选择结构
//#include <stdio.h>
//#include <stdlib.h> 
//#include <time.h>
//int main() {
//	clock_t start,end;
//	start=clock();
//	int result;
//	int x;
//	scanf("%d",&x);
//	if (x==1) {
//		result=15;
//	}
//	else if (x==2) {
//		result=26;
//	}
//	else if (x==3) {
//		result=37;
//	}
//	else {
//		printf("result is nothing");
//		exit(0);	 // exit()函数定义在标准库头文件<stdlib.h>中,若没有#include <stdlib.h>,编译器会报错;
//	}	
//	end=clock();
//	double cpu_runtime;
//	cpu_runtime=((double)(end-start))/CLOCKS_PER_SEC;
//	printf("result=%d\n",result);
//	printf("程序运行时间为%lfms",cpu_runtime*1000);
//	return 0;
//}
//
//#include <stdio.h>  // switch的优势在于分支非常多(比如 100 个 case)且数值连续时,编译器会生成"跳转表(Jump Table)",实现O(1)复杂度;而在只有3个分支时,这种优势不存在,甚至可能因为指令预取等原因产生微小劣势。
//#include <time.h>
//int main() {
//	clock_t start,end;
//	start=clock();
//	int result;
//	int x;
//	scanf("%d",&x);
//	switch (x) {
//		case 1:
//			result=15;
//			break;
//		case 2:
//			result=26;
//			break;
//		case 3:
//			result=37;
//			break;
//		default :
//			result=0;
//			break;
//	}
//	end=clock();
//	printf("%d\n",result);
//	double cpu_runtime;
//	cpu_runtime=((double)(end-start))/CLOCKS_PER_SEC;
//	printf("程序运行时间为%lfms",cpu_runtime*1000);
//	return 0;
//}

// 此外还应注意：如果某case所对应的分支编号下没有break,即不终止该case分支的语句,此时该case分支将自动跳转至下一个case继续执行
// case只是路牌，不具有划分功能   switch-case相当于先找站点再用break截停
//#include <stdio.h>
//int main() {
//	int x;
//	scanf("%d",&x);
//	int result;
//	switch (x) {
//		case 1:
//		case 2:
//		case 3:
//			result=3;
//			break;
//		case 4:
//			result=4;
//			break;		
//	}
//	printf("result=%d",result);
//	return 0;
//}  // 此时输入的x无论是1,2还是3均会返回3


#include <stdio.h>  // 一定注意区分字符、字符数组和字符串！
// (字符串内容不可变，但是其指针指向位置可变;) (%s) (char *str1 ="hello",一旦定义完成后内容不可再更改，但是指针的指向可以变化) 或者 (char str1[]="hello")
// (字符数组内容可变(但不可用strcpy复制内容！,否则由于无\0,内存极有可能溢出--此方式只适用于字符串类型; 需使用 memcpy来进行复制),但是其数组名不可更改，故不可将指针指向其他地址) (例如char str2[]={'A','B','C'})
// (字符仅含一个字符,char直接定义即可,但是字符为单引号，字符串为双引号！) (%c)
//int main() {    
//	int x;
//	char result;
//	scanf("%d",&x);
//	switch (x>=90) {
//		case 1:
//			result='A';
//			break;
//		case 0:
//			switch (x<90 && x>=80) {
//				case 1:
//					result='B';
//					break;
//				case 0:
//					switch (x<80 && x>=70) {
//						case 1:
//							result='C';
//							break;
//						case 0:
//							switch (x<70 && x>=60) {
//								case 1:
//									result='D';
//									break;
//								case 0:
//									result='E';
//									break;
//							}	
//					}
//			}
//	}
//	printf("%c",result);
//	return 0;
//}
// 此题还可以对输入的成绩整除以10得到十位以此用switch-case来判断;
//#include <stdio.h>
//int main() {
//	char result;
//	int score;
//	scanf("%d",&score);
//	score/=10;
//	switch (score) {
//		case 10:  // 利用级联
//		case 9:
//			result='A';
//			break;
//		case 8:
//			result='B';
//			break;
//		case 7:
//			result='C';
//			break;
//		case 6:
//			result='D';
//			break;
//		default:
//			result='E';
//			break;
//	}
//	printf("%c",result);
//	return 0;
//}

//// training
//#include <stdio.h>
//int main() {  // 将连续的分段函数的区间转化为有限多个离散的常量以使用switch-case表达式
//	int x;
//	scanf("%d",&x);
//	int result;
//	int category;
//	category=(x>0)-(x<0);  // 巧妙利用布尔表达式转化出3个离散常量-1,0,1
//	switch (category) {
//		case 1:
//			result=2*x;
//			break;
//		case 0:
//			result=0;
//			break;
//		case -1:
//			result=-1;
//			break;
//	}
//	printf("%d",result);
//	return 0;
//}