//# include <stdio.h>  //* stdio:std(standard)+io(input,output),帮助计算机认识
//int main() {
//	int foot,inch;
//	scanf("%d %d",&foot,&inch);
//	printf("%lf",(foot+inch/12.0)*0.3048); 
//	// 由于inch/12很有可能为小数，而C语言规定整数之间进行的运算返回的数均应为整数，故会自动向下取整,故可以直接将/看作是C语言中整数之间的整除符号
//	// 故可以讲所处的除数变为浮点数，从而整数与浮点数运算返回一个浮点数
//	return 0;
//}


// #include <stdio.h>
// int main() {
// 	int hour1,minute1;
// 	int hour2,minute2;
// 	scanf("%d %d",&hour1,&minute1);
// 	scanf("%d %d",&hour2,&minute2);
// 	int delta_time=(hour1*60+minute1)-(hour2*60+minute2);
// 	printf("两个时间的间隔为%d时%d分",delta_time/60,delta_time%60);
// 	return 0;
// }


// 复合赋值: 例如+=,-=,/=,*=,%=
// 此外还有一种特殊的运算符：++与--,分别表示变量递增1与递减1.但是使用时需特别注意其位置
// 如果是前缀的话，例如++a就是表示原来的a加1后的结果，而a++则表示a加1之前的值
//#include <stdio.h>
//int main() {
//	int a;
//	scanf("%d",&a);
//	// a++
//	printf("a=%d \n",a);
//	printf("a++=%d \n",a++);
//	// ++a
//	printf("a=%d \n",a);
//	printf("++a=%d \n",++a);
//	return 0;
//}


//// Self-Training_1
//#include <stdio.h>
//int main() {
//	int length_cm;
//	scanf("%d",&length_cm);
//	int foot=length_cm/30.48; //在C语言可以进行类型的自动转换(定义变量类型时)
//	int inch=(length_cm/30.48-foot)*12;
//	printf("%d %d",foot,inch);
//	return 0;
//}

//// Self-Training_2
//#include <stdio.h>
//int main() {
//	int o_time;
//	int pass_time;
//	scanf("%d %d",&o_time,&pass_time);
//	int current_time;
//	current_time=(o_time%100+o_time/100*60)+pass_time;
//	int current_hour,current_minute;
//	current_hour=current_time/60;
//	current_minute=current_time%60;
//	current_time=current_hour*100+current_minute;
//	printf("%d",current_time);
//	return 0;
//}

//// Self-Training_3
//#include <stdio.h>
//int main() {
//	int num;
//	scanf("%d",&num);
//	int gw,sw,bw;
//	bw=num/100;
//	gw=(num%100)%10;
//	sw=(num%100-gw)/10;
//	int new_number;
//	new_number=gw*100+sw*10+bw;
//	printf("%d",new_number);
//	return 0;
//}

// Self-Training_4 (BCD数)
//#include <stdio.h>
//int main() {
//	int error_10;
//	scanf("%d",&error_10);
//	int right_10;
//	right_10=error_10/16*10+error_10%16;
//	printf("%d",right_10);
//	return 0;
//}