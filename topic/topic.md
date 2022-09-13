# C语言题目

### 1.宏大小

用宏定义的方式比较两个数的大小

```C
#define	MIN_NUM		((a<b)?a:b)
```

### 2.结构体成员数量

我们经常使用的点类Point结构体，其中包含两个int变量x与y，这是属于二维平面上点类。现假设我们的点类Point是属于多维空间中的点，其中包含多个相同类型（类型未知）的变量（第一个一定是x）表示坐标，你能否使用宏定义的方式，从使用空间的角度算出这个点类有多少个变量？

```C
(sizeof(point))/sizeof(typeof(point.x))
```

### 3.递归

在一个递归函数recursion中，有一个static修饰的变量m，它被初始化为0。现在该函数输入了一个数字n，牛牛在每次递归调用该函数的时候，都将m+n的值赋值给变量m，直到n为0时结束递归。于是牛牛就想知道这个m最后到底等于多少，你能帮牛牛实现这个递归函数，返回m的值吗？

```C
int recursion(int n ) {
    // write code here
    static int m=0;
    m += n--;
    if(n)
    {
        recursion(n);
    }
    return m;
}
```

### 4.const

牛牛正在学习C语言的const语言，它发现被const修饰变量不允许被修改，但是被const修饰的指针却不一定，想让你帮忙测试一下。现牛牛输入n，请你创建一个可以被修改的const指针变量p，将其初始化为n，请返回p++的结果。

```C
int const_test(int n ) {
    // write code here
    int const *p=n;
    return ++p;
}
```

### 5.volatile

牛牛在嵌入式中学习到了volatile的方法，想要考考你。请创建一个square函数，输入volatile类型的整型指针p，返回p指向值的平方。p的初始指向值为预置函数fun的输入值n。

```C
//应注意这里的参数也是volatile，不加会报错
int square(volatile int * p)
{
    return *p * *p;
}

int fun(int n ) {
    // write code here
    volatile int * p = &n;
    return square(p);
}
```

### 6.typedef

牛牛在学习C语言的预定义，他所知道的有方式有#define和typedef两种。请你选择一种方式声明int类型指针的同义字int_p，要求使用语句“ int_p p1, p2; ” 能够直接声明两个指针，将两个指针分别指向输入的数组首部m和n，并返回两个指针各自自增后的结果之和。

```C
typedef int* int_p;
int fun(int* m, int mLen, int* n, int nLen ) {
    // write code here
    int_p p1 = m;
    int_p p2 = n;
    int temp=0;
    temp=(*++p1)+(*++p2);
    return temp;
}
```

### 7.字符串的sizeof和strlen

牛牛在学习字符串的时候，发现统计字符串所占据空间有多种方式，比如关键字sizeof与strlen()函数，牛牛想让你验证一下这两种方式的结果是不是一致的，请你根据输入字符串返回两种方式的结果是否相等的bool值。

```C
bool fun(char* str ) {
    // write code here
    if(sizeof(str)==strlen(str))
        return true;
    else
        return false;
}
```

### 8.机器的大小端

什么是大小端

```C
/*
int i=0x12345678;
内存地址：
	低--------------------------->高
大端：0x12 	34 		56 		78
小端：0x78		56		34		12
*/
```

区分大小端

```C
/*
这里是用到char和int的大小
char 1个字节
int  4个字节
让char等于int会截断数据得到低地址，这时候如果是1，就是小端，0就是大端
*/
int judge(int n ) {
    // write code here
    n=1;
    return *(char*)&n;
}
/*
	还有一种方法，union，联合体/共用体
	union{
		char c;
		int i;
	}
	union的成员是共用一块内存地址，并且union的大小是成员里最大的，其次是成员都是连续储存的，原理跟char和int的大小差不多
*/
```

### 9.大小端转换

假设一个数据以小端模式保存在机器，将其转换至大端形式

```C
int convert(int n ) {
    // write code here
    char temp=0xff;
    int res=0;
    unsigned char a=temp&n;n>>=8;
    unsigned char b=temp&n;n>>=8;
    unsigned char c=temp&n;n>>=8;
    unsigned char d=temp&n;n>>=8;
    res=(a<<24)|(b<<16)|(c<<8)|d;
    return res;
}
```

### 10.不用排序找数字

给出1000个整数，每个数字都在1-200之间，数字随机排布。在不允许排序的条件下，找出第450小的数字

```C
/*
思路：类似键值对，把每个数字出现的频率统计在count，key是数字(numbers[i])，value是频次(count[numbers[i]])。从小到大遍历数字，第450个数字就是要找的
*/
int find(int* numbers, int numbersLen ) {
    // write code here
    int i=0;
    int sum=0;
    int count[201]={0};
    for(i=0;i<numbersLen;i++)
    {
        count[numbers[i]]++;
    }
    for(i=0;i<201;i++)
    {
        sum+=count[i];
        if(sum>450)
            return i;
    }
    return 0;
}
```

### 11.结构体对齐

牛牛需要建立一个结构体Nowcoder，该结构体包括三个成员，其类型分别是int、double和char。假设牛牛想让这个结构体所占据的内存最小，请问你该怎么建立该结构体？（输入三个相应类型的变量用于初始化结构体）

```C
#pragma pack(1)
struct Nowcoder{
    char c;
    int n;
    double d;
};
int smaller_space(int n, double d, char c ) {
    // write code here
    //这里应该有结构体成员赋值，省略了
    return sizeof(struct Nowcoder);
}
```



