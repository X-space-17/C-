// 判断一个数的位数(较大位数时不再使用区间判断)--从左到右逐位整除10消去！
//#include <stdio.h>
//int main() {
//	int num;
//	scanf("%d",&num);
//	int counter;
//	num/=10;
//	counter+=1;  // 处理num=0的情况
//	while (num>0) {
//		num/=10;
//		counter+=1;
//		printf("num=%d,counter=%d\n",num,counter);
//	}
//	printf("%d",counter);
//	return 0;
//}
//
// do-while的使用--比较优雅(在必须要对输入数据执行一次之后再进行判断的时候十分必要,如果是先判断再执行的 while则需将循环体中的内容在外复制一遍,导致代码冗余)
//#include <stdio.h>
//int main() {
//	int num,counter;
//	do {
//		num/10;
//		counter+=1;
//	}
//	while (num>0);  // 若满足条件则返回do继续执行其中内容,简化了代码结构
// 	return 0;
//}


// 猜数游戏   // C语言中随机数的生成往往涉及 time(),srand(),rand()这三个函数
// 由于每次我们想让计算机生成不同的随机数，但是不同的随机数的生成需要依靠不同的随机种子，而不同的随机种子产生的较好的方式就是利用每秒都在变化的时间
// rand()之中无需传入参数,它可以直接调用并修改C语言中的隐藏全局变量 global_seed,它根据当前的 global_seed算出一个新数字,然后更新 global_seed为下一个值,最后返回算出的那个数字.
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int main() {
//	srand(time(NULL));
//	int x=rand();
//	x=x%100+1;
//	printf("已生成从1到100的随机数字，请猜数：\n");
//	int counter;
//	int input_num;
//	do {
//		scanf("%d",&input_num);
//		if (input_num<x) {
//			printf("太小了\n");
//		}
//		else if (input_num>x) {
//			printf("太大了\n");
//		}
//		counter+=1;	
//	} while (input_num!=x);
//	printf("你使用了%d次猜到了正确答案为%d",counter,x);
//	return 0;
//}


//// 算平均数
//#include <stdio.h>
//int main() {
//	int sum=0;
//	int input_num;
//	int x;
//	int counter=0;
//	printf("请输入要读入数据的个数:\n");
//	scanf("%d",&x);
//	while (counter<x) {
//		counter+=1;
//		scanf("%d",&input_num);
//		sum+=input_num;
//		if (counter!=x)
//			printf("请再次输入数值:\n");
//	}
//	double avg_num;
//	avg_num=(double)(sum/x);
//	printf("输入的%d个数值的平均数为%lf",x,avg_num);
//	return 0;
//}


// 逆序数处理
//#include <stdio.h>
//#include <math.h>
//int main() {
//	int num;
//	scanf("%d",&num);
//	int num_cpy=num;
//	int revs_num=0;
//	int counter;
//	while (num!=0) {
//		num/=10;
//		counter+=1;
//	}
//	printf("该数的位数为%d\n",counter);
//	int i=1;
//	while (i<=counter) {
//		revs_num+=(pow(10,counter-i))*(num_cpy%10);  // 注意C语言中没有像python中一样的 ^幂指运算，需调用头文件<math.h>中的函数pow()
//		num_cpy/=10;
//		i+=1;
//	}
//	printf("该数的逆序数为%d",revs_num);
//	return 0;
//}



// for循环
//#include <stdio.h>
//int main() {
//	int n;
//	scanf("%d",&n);
//	int result=1;
//	int i;
//	for (i=1;i<n+1;i++) {   // 注意n需要大于等于1! // for循环之中传入的三个参数:初始条件，循环持续条件，循环每一轮的动作
//		result*=i;
//	}
//	printf("%d",result);
//	return 0;
//}

// 或者可以……
//#include <stdio.h>
//int main() {
//	int n;
//	scanf("%d",&n);
//	int result=1;
//	for (;n>=2;n-=1) {   // 此处可省略n=n;结束循环时 n的值为1!
//		result*=n;
//	}
//	printf("%d",result);
//	return 0;
//}


// 素数判断
// #include <stdio.h>
// int main() {
// 	int x;
// 	scanf("%d",&x);
// 	int i;
// 	int result=1;
// 	if (x<=1) {
// 		result=0;
// 	}
// 	else if (x==2) {
// 		result=1;
// 	}
// 	for (i=2;i<=x-1;i++) {
// 		if (x%i==0) {
// 			result=0;
// 			break;  // 及时跳出！
// 		}
// 	}
// 	if (result==0) {
// 		printf("不是素数");
// 	}
// 	else if (result==1) {
// 		printf("是素数");
// 	}
// 	return 0;
// }

//#include <stdio.h>
//int main() {
//	int i;
//	int i_inner;
//	printf("下面输出100以内的素数:\n");
//	for (i=2;i<=99;i+=1) {
//		int result=1;
//		if (i==2) {
//			result=1;
//		}
//		for (i_inner=2;i_inner<=i-1;i_inner+=1) {
//			if (i%i_inner==0) {
//				result=0;
//				break;
//			}
//		}
//		if (result==1) {
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}


// goto方法(适合于多层嵌套函数从内层快速跳至外层函数)--"传送焚诀"
//#include <stdio.h>
//int main() {
//	int money;
//	scanf("%d",&money);
//	int one,two,five;
//	for (one=1;one<=money*10;one+=1) {
//		for (two=1;two<=money*5;two+=1) {
//			for (five=1;five<=money*2;five+=1) {
//				if (one*1+two*2+five*5==money*10) {
//					printf("%d个一角硬币+%d个两角硬币+%d个五角硬币可以凑成%d元\n",one,two,five,money);
//					goto out;   // (goto out)与(out:)相配合完成执行语句的快速跳跃！
//				}
//			}
//		}
//	}
//	out:
//	return 0;
//}


// 前 n项(1/i)的和
//#include <stdio.h>
//#include <math.h>
//int main() {
//	int num;
//	scanf("%d",&num);
//	int i;
//	double result;
//	for (i=1;i<=num;i+=1) {
//		result+=pow(-1,i+1)*(double)(1.0/i);
//	}
//	printf("result=%lf",result);
//	return 0;
//}


// (正序!)分解整数
//#include <stdio.h>
//int main() {
//	int num;
//	scanf("%d",&num);
//	int revs_num=0;  
//	int i;
//	do {
//		i=num%10;
//		revs_num=revs_num*10+i;
//		num/=10;
//	} while (num>0);
//	printf("逆序之后的数为%d\n ",revs_num);
//	int x;
//	do {
//		x=revs_num%10;
//		if (revs_num>=10) {
//			printf("%d\n",x);
//		}
//		else if (0<=revs_num<=9) {
//			printf("%d",x);
//		}
//		revs_num/=10;
//	} while (revs_num>0);
//	return 0;
//}

// 先将数字逆序过来,为之后逆序输出做准备,但是这样会使结尾为 0的数逆序后 0无法显示
// 因此可以修改为：
//#include <stdio.h>
//#include <math.h>
//int main() {
//	// 先计算输入数据的位数
//	int num;
//	scanf("%d",&num);
//	int num_cpy=num;
//	int counter=0;
//	while (num>0) {
//		num/=10;
//		counter+=1;
//	}
//	printf("数字位数为%d\n",counter);
//	int i;
//	do {
//		i=num_cpy/(int)(pow(10,counter-1));
//		if (num_cpy>=10) {
//			printf("%d\n",i);
//		}
//		else if (num_cpy<=9) {
//			printf("%d",i);
//		}
//		num_cpy=num_cpy % (int)(pow(10,counter-1));
//		counter-=1;
//	} while (counter>=1);
//	return 0;
//}


// #include <stdio.h>  // 利用辗转相除法求两个正整数的最大公约数
// int main() {
// 	int a,b;
// 	scanf("%d %d",&a,&b);
// 	int q=1;
// 	int r;
// 	do {
// 		r=a%b;
// 		a=b;
// 		b=r;
// 	} while (r>0);
// 	q=a;
// 	printf("两数公约数为%d",q);
// 	return 0;
// }


// 水仙花数
//#include <stdio.h>
//#include <math.h>
//int main() {
//	int n;
//	scanf("%d",&n);
//	int num;
//	int num_cpy;
//	int sum=0;
//	for (num=(int)(pow(10,n-1));num<(int)(pow(10,n));num+=1) {
//		num_cpy=num;   // 在此处最好设置一个 num_copy以作为临时变量,否则直接用 num来进行计算的话会导致外部变量在内部循环的时候被修改,从而陷入死循环
//		               // (需要区分好循环变量与临时变量)
//		while (num_cpy>0) {
//			sum+=(int)(pow(num_cpy%10,n));
//			num_cpy/=10;
//		}
//		if (num==sum) {
//			printf("%d\n",num);
//		}
//		sum=0;
//	}
//	return 0;
//}


// 打印九九乘法表(主要细节在于同一式子之间空格数量的变化,当相乘结果<10时需要3个空格,>=10时需要2个空格即可)
//#include <stdio.h>
//int main() {
//	int n;
//	scanf("%d",&n);
//	int i,j;
//	i=1;
//	while (i<=n) {
//		j=1;
//		while (j<=i) {
//			printf("%d*%d=%d",j,i,i*j);
//			if (i*j<=9) {
//				printf("   ");
//			}
//			else {
//				printf("  ");
//			}
//			j+=1;
//		}
//		printf("\n");
//		i+=1;
//	}
//	return 0;
//}