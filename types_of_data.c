// 整数(含布尔类型 bool)--char, short, int, long, long long;
// 浮点数--float,double,long double
// 指针
// 自定义类型

// 所表达的数的范围：char<short<int<float<double,1个字节到 16个字节不等
// (字节数可以通过sizeof()来查询字节数,不过sizeof()是静态运算符,其结果在编译时就已经决定了，因此其不会去运行其内部式子来得到字节数)
//#include <stdio.h>
//int main() {
//	int a=6;
//	printf("整数%d的字节数为%d\n",a,sizeof(a));
//	printf("a*a的字节数为%d?\n",sizeof(a*a));  // 字节数通过sizeof()传递出来的值不变
//
//	printf("%d\n",sizeof(char));
//	printf("%d\n",sizeof(short));
//	printf("%d\n",sizeof(int));
//	printf("%d\n",sizeof(long));
//	printf("%d\n",sizeof(long long));
//	return 0;
//}
// 计算机中 CPU(中央处理器)与 RAM(内存)之间用总线连接，每当 CPU从 RAM中取出数据并通过总线传输至CPU内部的寄存器时，单次可传输的字长即为一个寄存器的存储量大小，同时也以此为依据标定了int类型的大小
// 所以对于不同的 CPU(32/64位寄存器)，int类型所占的字节数可能不同



// 补码的使用利用了0溢出，也可以理解为最高位既是符号位也是数值位(可能理解不准确，但计算一般不会出错)
// 因此对于同一个二进制数存储时，不同存储字长的数据类型:如 char与 int之间就会产生结果上的差异！！！
//#include <stdio.h>
//int main() {
//	char a=255;    // 以二进制形式读入内存(若超出char类型的 8位,可截断 9位及以上的数)，CPU调用时按照补码规则计算;
//	int b=255;
//	printf("a=%d\n",a);
//	printf("b=%d",b);
//	return 0;     
//}
// 最终会得到 a=-1,b=255;
// 因为对于char类型：0000 0000(8个bit,1Byte)-->255存储为二进制形式1111 1111,而这对应着补码中的-1；
// 而对于 int类型：(0000 0000) (0000 0000) (0000 0000) (0000 0000) (0000 0000) (0000 0000) (0000 0000) (1111 1111) 为其255的存储状态(32bit,4Byte),而这对应着补码中的255;

// 但是如果想用char来表示正整数255：
//#include <stdio.h>
//int main() {
//	unsigned char a=255;   // unsigned是一个无符号类型修饰符，它只能表示正数或者 0；因此也便释放了最高位上的符号位，使得所表示的数的范围相较于原来扩大了两倍；
//	printf("a=%d\n",a);    // 故得到 a的值为255 (1111 1111)
//}


// int--%d；long long--%ld；unsigned--%u；unsigned long long--%lu
//#include <stdio.h>
//int main() {
//	char a=128;  // 无论以何种数据类型输入，编译器均会将他们转变为二进制并在计算机内部存储，变化的只是输出格式的转变，即我们以什么方式去看待这个数
//	int b=127;
//	printf("a=%d\n",a);
//	a-=1;
//	printf("a=%d\n",a);
//	//
//	printf("a=%u\nb=%u",a,b);   // 直接按照输出类型进行强制转换
//}


// 八进制与十六进制同理
//#include <stdio.h>
//int main() {
//	int z=012;
//	int y=0x12;
//	printf("z=0%o\ny=0x%x\n",z,y);    // %o,%x分别表示八进制与十六进制的输出格式
//	printf("z=%d\ny=%d",z,y);         // 十六进制很适合用于表示二进制，因为 4位二进制即为一位十六进制数；同理，一位八进制数可用3位二进制数表示
//	return 0;
//}


// 浮点数类型
//#include <stdio.h>
//int main() {
//	printf("float类型占%d字节\ndouble类型占%d字节",sizeof(float),sizeof(double));
//	return 0;
//}
// float类型占 4字节,double类型占 8字节

// 一个浮点数可用科学计数法 %e表示或者用 %f或用 %lf表示
//#include <stdio.h>
//int main() {
//	float a=124.6556745;
//	printf("a=%f\na=%lf\na=%e\n",a,a,a);   // printf:输出时 %f和 %lf没有区别; 但是scanf：输入时必须严格区分 %f(float类型)和 %lf(double类型)
//	//
//	float b;
//	scanf("%f",&b);
//	printf("b=%f\nb=%e\n",b,b);   // 输入的浮点数与用 %f,%lf输出的数精度总是有所差别，这是由于计算机无法用二进制准确表达十进制中的小数
//	printf("b=%.3f\n",b);
//	//
//	printf("%f\n",12.0/0.0);  // --inf(+-无穷,超出表达范围的数)
//	return 0;
//}


// 由于浮点数的精度丢失问题 (一般没有特殊尽量直接使用double(64bit)，精度更高且在64位的电脑上寄存器可做到一次性读取该数，故效率不会差于float)
//#include <stdio.h>
//int main() {
//	float a=1.2341241;
//	float b=1.2231242;
//	float c=a+b;
//	if (c==2.4572483) {
//		printf("Ture");   // 精度丢失导致判别式结果不为 True
//	}
//	else {
//		printf("False");
//	}
//}


// char不仅是一种整数类型，也是"字符"类型(注意与字符串相区别--字符串用双引号括起来)
//#include <stdio.h>
//int main() {
//	char a=127;
//	char b='7';
//	printf("%d\n",a==b);  // 结果为0，表明两者不等
//	printf("%d\n",a);
//	//
//	printf("%d\n",b);
//	printf("%c\n",b);
//	//
//	int x;
//	char y;
//	scanf("%d %c",&x,&y);  // 注意读入时有没有空格是不一样的，有空格时读完整数之后，再读完所有后面的空格直至读到字符为止；
//						   // 但当输入格式没有预留空格时却在命令行中输入空格，字符处便会输出空字符对应的 ASCII码；所以一定要注意空字符也有对应的ASCII码值！
//	printf("x=%d\ny=%c\ny=%d\n",x,y,y);
//	//
//	int c;
//	char d;
//	scanf("%d%c",&c,&d);
//	printf("c=%d\nd=%c\nd=%d",c,d,d);
//	return 0;
//}


// 字符同样可以在计算机内部进行数值运算
//#include <stdio.h>
//int main() {
//	char a='A';
//	printf("a+1=%c",a+1);  // a+1在计算机内部为字符 a对应的ASCII码值+1后再以二进制方式存储，之后再以补码形式输出，根据所存储的补码ASCII值可以对应到相应字符，最终按照 %c格式输出
//	return 0;
//}


// 逃逸字符
// 例如: \b  \t  \n  \"  \'
//#include <stdio.h>
//int main() {
//	printf("123\bA456\n");  // 会发现在\b之后输入A会使回退的那一格中的内容被 A替代掉；\n已常见，为换行符
//	printf("123\n456\n");
//	//
//	printf("123\t456\n");    // 制表符\t不会有固定的移动位数，其记录的是固定的位置而非位数，比如常用的 Tab键
//	printf("12\t456\n");
//	// 
//	printf("Elon Musk said:\"Kimi is a great artificial intelligence company\"\n");
//	char a='\'';  //  \'可用于字符等需要在已有引号环境中仍被单引号包围的场景，\"则可用于需要在已有引号环境中仍被双引号包围的场景
//	printf("%c\n",a);
//	//
//	printf("AI is a \'two-sworded knife\'\n");
//	return 0;
//}


// 自动类型转化：
// 在 printf中float会自动转变为double,因此由于默认类型提升导致浮点数输出时均变为double类型，所以使用 %f与使用 %lf没有区别；此外对于任何小于 int类型的数，同理会自动转为 int类型
// 但在scanf()中须严格按照double类型与float类型的输入字符 %lf与 %f;同理对于short类型需要严格按照 %hd读入，其不会自动转为 int类型

// 强制类型转化：
//#include <stdio.h>
//int main() {
//	int a=32768;
//	short b=(short)a;
//	printf("%d\n",sizeof(short)); // short类型占据 2Byte,即16bit,故最大表示数值为2^(16)-1=32767
//	//
//	printf("%d\n",a);  // 强制类型换换不改变原数的状态
//	printf("%d\n",b);
//	return 0;
//}


// bool类型--本质上仍为整数类型,只不过只能表示 0和 1
//#include <stdio.h>
//#include <stdbool.h> // 需添加头文件
//int main() {
//	bool a=6>5;
//	bool b=2==2;
//	a=0; // 会判断是否非零，若是则赋值为 1，否则为0
//	printf("a=%d\n",a);
//	a=32;
//	printf("a=%d\nb=%d",a,b);
//	return 0;
//}


// 逻辑运算：!(逻辑非)(单目运算符，运算优先级高于比较运算符)，&&(逻辑与)，||(逻辑或)
// 注意区分 !=与 ！是两码事，一个是比较运算符，一个是逻辑运算符
//#include <stdio.h>
//int main() {
//	int a=!2==0;
//	printf("%d\n",a);
//	//
//	int b=1;
//	if (a==0 && b++>0) {   
//		printf("True\n");
//	}
//	else {
//		printf("False\n");
//	}
//	printf("%d",b);   // 由于a==0这个条件已经不满足，&&这个逻辑运算符会发生“短路”，即不会再去执行后面的比较运算，由 b++未被执行可以看出 
//	return 0;
//}
