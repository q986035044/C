# 指针
区分指针和指针变量，掌握一级指针和二级指针

**为了不混淆，不要把指针变量简称为指针**

**为了不混淆，不要把指针变量简称为指针**

**为了不混淆，不要把指针变量简称为指针**

+ 指针
  简单来说，指针就是地址
+ 指针变量
  而指针变量是存放着指针也就是地址的变量
+ 一级指针
一级指针就是普通的指针变量，存放着指针的变量
+ 二级指针
所谓二级指针，就是指针变量的地址，怎么理解呢？
指针变量不过是存放指针的变量，终究是变量，作为变量，他还是有属于自己的地址

### 一级指针

例子如下：
一级指针在函数中传参

```C
#include <stdio.h>

int a=10;
int b=100;
int* p=NULL;

void func(int *p);

int main()
{
	printf("%s:&a = %p &b = %p &p = %p\r\n",__func__,&a,&b,&p);
	p = &a;
	printf("after p = &a\r\n");
	printf("%s:*p = %d p = %p &p = %p\r\n",__func__,*p,p,&p);
	func(p);
	printf("%s:*p = %d p = %p &p = %p\r\n",__func__,*p,p,&p);
	return 0;
}

void func(int *tp)
{
	printf("\r\n");
	printf("%s:*tp = %d tp = %p &tp = %p\r\n",__func__,*tp,tp,&tp);
	tp = &b;
	printf("after tp = &b\r\n");
	printf("%s:*tp = %d tp = %p &tp = %p\r\n",__func__,*tp,tp,&tp);
	printf("\r\n");
}
```
一级指针运行结果：

这里的指针终究是个变量，在作函数形参传递时，tp只是存放着变量a的地址，对tp解引用就是a的值

但是tp的地址不是全局变量p的地址，这不过是函数创建了一个临时指针指向了a的地址，还是那句话

**为了不混淆，不要把指针变量简称为指针**

指针变量不过也是个变量，也有自己的地址

![一级指针程序结果](D:\794QYH\program\C\pointer\pointer.png)

---

### 二级指针

二级指针在函数中传参

```C
#include <stdio.h>

int a=10;
int b=100;
int* p=NULL;

void func(int **p);

int main()
{
	printf("%s:&a = %p &b = %p &p = %p\r\n",__func__,&a,&b,&p);
	p = &a;
	printf("%s:*p = %d p = %p &p = %p\r\n",__func__,*p,p,&p);
	func(&p);
	printf("%s:*p = %d p = %p &p = %p\r\n",__func__,*p,p,&p);
	return 0;
}

void func(int **tp)
{
	printf("\r\n");
	printf("%s:**tp = %d *tp = %p tp = %p &tp = %p\r\n",__func__,**tp,*tp,tp,&tp);
	*tp = &b;
	printf("after *tp = &b\r\n");
	printf("%s:**tp = %d *tp = %p tp = %p &tp = %p\r\n",__func__,**tp,*tp,tp,&tp);
	printf("\r\n");
}
```

二级指针运行结果：

在这个程序，函数的参数是二级指针，就是要求传进指针变量的地址

函数里让全局变量p重新指向变量b的地址，所以跳出函数之后，p仍然存放着b的地址

![二级指针程序结果](D:\794QYH\program\C\pointer\pointer_to_pointer.png)

### 补充

#### 一. 指针的类型

把指针声明语句里的指针名字去掉，剩下部分就是这个指针的类型。这是指针本身所具有的类型。

```C
int *p;//指针类型是int*
char *p;//char*
int **p;//int**
int (*p)[3];//int(*)[3]
int *(*p)[4];//int*(*)[4]
```

#### 二. 指针所指向的类型

当用指针访问指针指向的内存时，指针指向的类型决定了编译器把那个内存当成什么类型的内容。

辨别方法：把指针名字和左边的指针声明符*去掉

```C
int *p;//指针指向int类型
char *p;//指向char
int **p;//指向int*
int (*p)[3];//指向int()[3]
int *(*p)[4];//指向int*()[4]
```

#### 三. 指针的值

指针的值就是指针本身存储的数值，这个值被编译器当作一个地址

==遇到一个指针应优先弄清楚这三个问题，指针的类型，指针所指向的类型，指针的值==

#### 注意的点

通过结构体指针访问结构体成员时，不要通过以下方式访问

```C
*p//假设p是一个结构体指针
*(p+1)
*(p+2)
```

参考内存对齐规则

#### 一些指针类型

- **int p;** -- 这是一个普通的整型变量
-  **int \*p;** -- 首先从 p 处开始，先与 ***** 结合，所以说明 p 是一个指针, 然后再与 int 结合, 说明指针所指向的内容的类型为 int 型。所以 p 是一个返回整型数据的指针。
-  **int p[3]** -- 首先从 p 处开始，先与 **[]** 结合，说明 p 是一个数组, 然后与 int 结合, 说明数组里的元素是整型的, 所以 p 是一个由整型数据组成的数组。
-  **int \*p[3];** -- 首先从 p 处开始, 先与 [] 结合，因为其优先级比 ***** 高,所以 p 是一个数组, 然后再与 * 结合, 说明数组里的元素是指针类型, 然后再与 int 结合, 说明指针所指向的内容的类型是整型的, 所以 p 是一个由返回整型数据的指针所组成的数组。
-  **int (\*p)[3];** -- 首先从 p 处开始, 先与 * 结合,说明 p 是一个指针然后再与 [] 结合(与"()"这步可以忽略,只是为了改变优先级), 说明指针所指向的内容是一个数组, 然后再与int 结合, 说明数组里的元素是整型的。所以 p 是一个指向由整型数据组成的数组的指针。
-  **int \**p;** -- 首先从 p 开始, 先与 * 结合, 说是 p 是一个指针, 然后再与 * 结合, 说明指针所指向的元素是指针, 然后再与 int 结合, 说明该指针所指向的元素是整型数据。由于二级指针以及更高级的指针极少用在复杂的类型中, 所以后面更复杂的类型我们就不考虑多级指针了, 最多只考虑一级指针。
-  **int p(int);** -- 从 p 处起,先与 () 结合, 说明 p 是一个函数, 然后进入 () 里分析, 说明该函数有一个整型变量的参数, 然后再与外面的 int 结合, 说明函数的返回值是一个整型数据。
-  **int (\*p)(int);** -- 从 p 处开始, 先与指针结合, 说明 p 是一个指针, 然后与()结合, 说明指针指向的是一个函数, 然后再与()里的 int 结合, 说明函数有一个int 型的参数, 再与最外层的 int 结合, 说明函数的返回类型是整型, 所以 p 是一个指向有一个整型参数且返回类型为整型的函数的指针。
-  **int \*(\*p(int))[3];** -- 可以先跳过, 不看这个类型, 过于复杂从 p 开始,先与 () 结合, 说明 p 是一个函数, 然后进入 () 里面, 与 int 结合, 说明函数有一个整型变量参数, 然后再与外面的 * 结合, 说明函数返回的是一个指针, 然后到最外面一层, 先与[]结合, 说明返回的指针指向的是一个数组, 然后再与 * 结合, 说明数组里的元素是指针, 然后再与 int 结合, 说明指针指向的内容是整型数据。所以 p 是一个参数为一个整数据且返回一个指向由整型指针变量组成的数组的指针变量的函数。