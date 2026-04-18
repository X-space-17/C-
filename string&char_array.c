// 数组是“容器”，字符数组是“装了字符的容器”，而字符串是“遵循特定规矩（结尾有\0）的字符数组”
// 数组 > 字符数组(char *word={'A','D','S'};//char word[]={'A','D','S'};) > 字符串(char *word="ADS";//char word[]="ADS";//char word[]={'A','D','S','\0'};) > 字符(char a="A";)

// #include <stdio.h>
// int main() {
//     char word[]={'A','B','C','D'};   // C语言中禁止直接定义空数组:char word[];
//     printf("%c\n",word[0]);
//     //
//     char word_1[]={'A','B','C','D','\0'};    // 字符串最原始的写法
//     printf("%s\n",word_1);
//     // 字符串以数组的形式(也是指针)存在，以指针或数组的形式访问; 故必须严格区分双引号与单引号,例如"A"表示一串地址，'A'对应ASCII码中一个数
//     char *str="Hello World!";
//     printf("%s\n",str);
//     char str_1[6]="Hello";  // 必须留给\0一个字节
//     printf("%s\n",str_1);
//     return 0;
// }

// 字符串输入输出
// #include <stdio.h>
// int main() {
//     char word_1[8];
//     char word_2[8];
//     scanf("%7s",word_1);
//     scanf("%7s",word_2);   // 可以用此来限制输入的字符串长度
//     printf("%s\n",word_1);
//     printf("%s\n",word_2);
//     //
//     int check = 111; 
//     char word[4];    
//     scanf("%s", word);
//     printf("word内容: %s\n", word);  // 如果输入内容超过3个字符，将会越界访问直至字符串数组中的内容全部输入--\0(停止),从而会覆盖掉stack的更高处存放的更早定义的变量的部分数据
//     printf("邻居check的值: %d\n", check);
//     return 0;
// }


// 字符串数组(将多个字符串存入一个数组中)(char *a[]或 char a[][])
// #include <stdio.h>
// #include <string.h>
// int main() {
//     int input;
//     scanf("%d",&input);
//     // char month[12][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
//     // if (input>=1 && input<=12){
//     //     printf("%s\n",month[input-1]);
//     // }                      // 但是这样会浪费很多内存，因为每个英文单词根本不可能占到20个字符
    
//     // 换为用指针表示二维数组(即字符串数组,因为每个字符串即为由多个字符组成的一维数组)
//     char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
//     if (input>=1 && input<=12){
//         printf("%s\n",month[input-1]);
//     }

//     // 如果我们想找到第i个字符串中第j个字符具体是什么： 
//     int i,j;
//     scanf("%d %d",&i,&j);
//     if (i>=1 && i<=12 && j>=1 && j<=strlen(*(month+i-1))) {
//         printf("%c\n",*(*(month+i-1)+j-1));
//         printf("%c\n",month[i-1][j-1]);  // 与上面解指针的运算等价，不过可读性更好
//     }
//     return 0;
// }


// main函数参数
// #include <stdio.h>
// int main(int argc,char const *argv[]) {
//     int i;
//     for (i=0;i<argc;i+=1) {
//         printf("%d:%s\n",argc,argv[i]);
//     }
//     return 0;
// }


// 单字符输入输出
// #include <stdio.h>
// int main() {
//     int ch;
//     while ((ch=getchar())!=EOF) {   // getchar()从标准输入(如键盘)读取一个字符,填入shell的缓冲区,getchar,putchar均从shell中去读取与修改  // 同时注意赋值运算符=优先级低于逻辑运算符!=
//         putchar(ch);                // EOF 是"文件结束符"(End Of File),在终端中通常通过 Ctrl+Z/Ctrl+C(Windows)触发,表示输入结束            
//     } 
//     printf("EOF\n");
//     return 0;
// }


// C语言中处理字符串的函数
// 1.strlen  // 注意不包括字符串末尾的'\0'!!!
// #include <stdio.h>
// #include <string.h>
// int selflen(const char*s) {
//     int count=0;
//     int index=0;
//     while (s[index]!='\0') {
//         count+=1;
//         index+=1;
//     }
//     return count;
// }
// int main() {                       // 注意：sizeof是一个编译时的运算符,不是运行时函数,因此编译器在编译代码时,就已经知道所有变量的类型定义,因此数组无法在其面前退化为指针,指针也无法在其面前视作数组!
//     char word[]="Hello_World";     // --故此处字符串必须按照数组的标准来定义,否则返回的便是指针这种类型的大小(8Byte)
//     printf("%d\n",sizeof(word));   
//     printf("%d\n",strlen(word));
//     printf("%d\n",selflen(word));
//     return 0;
// }


// 2.strcmp(string compare)
// #include <stdio.h>
// #include <string.h>
// int selfcmp(const char *s1,const char *s2) {
//     int index=0;
//     while (s1[index]==s2[index] && s1[index]!='\0' && s2[index]!='\0') {        
//             index+=1;
//     }
//     return s1[index]-s2[index];
// }
// int main() {
//     char s1[]="abc";
//     char s2[]="Abc";
//     printf("%d\n",s1==s2);     // 地址不同，返回0，此处比较的不是字符串
//     printf("%d\n",strcmp(s1,s2));  // 标准并没有强制要求返回"字符之差",很多编译器为了效率或规范,会将所有大于的情况统一返回 1,所有小于的情况统一返回-1
//     printf("%d\n",selfcmp(s1,s2));
//     return 0;
// }


// 3.strcpy(string copy)
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// void selfcpy(const char*p1,char* p2) {
//     // int i;
//     // int length=strlen(p1)+1;
//     // for (i=0;i<length;i+=1) {
//     //     p2[i]=p1[i];
//     // }
//     // 也可以直接移动指针进行逐位复制:(简洁明了!)
//     while (*p2++ = *p1++);    // *p2从p1[0]开始复制,读至p1最后'\0'处停止继续读取(将'赋值'与'条件判断'与'循环内操作'融为一体)
// }
// int main() {
//     char s1[]="Hello";
//     char *s2_cpy=(char*)malloc(strlen(s1)+1);
//     selfcpy(s1,s2_cpy);
//     printf("%s",s2_cpy);
//     free(s2_cpy);   // 一定不要忘记清理内存
//     return 0;
// }


// 4.strchr(string char--从左至右,返回指针类型)/strrchr(从右至左)--(字符串搜索函数)
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// int main() {
//     char s[]="Hello";
//     char *p_1=strchr(s,'l');   // 先用strchr函数搜索到'l'
//     printf("%p\n",p_1);
//     printf("%c\n",*p_1);
//     printf("%s\n",p_1);   // %s的期望：它需要一个内存地址(即char*指针),然后从这个地址开始往后读字符,直到遇到\0
//     // 若从第二个'l'开始读:
//     char *p_2=p_1+1;
//     printf("%s\n",p_2);
//     // 或者可以：
//     char *p_3=strchr(p_1+1,'l');
//     printf("%s\n",p_3);
//     // 拷贝'l'之后的内容
//     char *p_cpy=(char*)malloc(strlen(p_1)+1);
//     strcpy(p_cpy,p_1);
//     printf("%s\n",p_cpy);
//     free(p_cpy);
//     //
//     // 若想拷贝'l'之前的内容(手动添加"终止符": '\0')
//     char *p_before=(char*)malloc(strlen(s)+1);
//     *p_1='\0';
//     strcpy(p_before,s);  // 将 s 拷贝至 p_before 
//     printf("%s\n",p_before);
//     return 0;
// }