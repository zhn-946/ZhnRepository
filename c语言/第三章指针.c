C语言学习
第三部分 指针
3.1.指针到底是什么？
    1.指针的实质就是一个变量
    int a;  //定义int变量，名字叫a; 编译器做的操作就是把一个内存空间和门牌号a绑定
    int *p; //定义指针变量，名字叫p,p指向一个int型变量
	(其中int*p;如果是一个局部变量,定义一个局部变量且未初始化，值是随机的)
    目前两句代码编译器做的操作相同,a和p都是绑定了相同的格子大小
    a = 4; //ok
    普通变量可以赋值int类型的数值
    p = 4; //编译器不允许， 
    "指针与普通变量用途不同，用来存储另一个变量的地址，不是用来随意存储赋值"
	p = (int *)4; //强制转换int*——> 4其实是一个地址(int类型变量的地址)
	2.指针实现间接访问
	3.指针如何使用：定义指针变量、给指针变量赋值——绑定指针、解引用
	定义指针变量——>int *p; int a = 23;
	给指针变量赋值——>让这个指针指向另一个变量——> p = &a; p = (int *)4; 
		绑定指针的作用：让指针指向一个可以访问，应该访问的内存
	解引用——>*p =555;//把555放入p指向的变量中，相当于a的值变成了555 
		"指针存储的是指针指向变量的地址，解引用就是引用指针指向的变量的值"
	example:
		int a = 10;
		int *p = &a;
		printf("%p\n",&a);
		printf("%p\n",p);//%p，p打印的是指针本身 也可以写成
		printf("0x%x\n",p);//与%p打印指针内容一样，打印的是指针的data域，也就是指向变量的地址。
		//如果想要打印指向地址的内存内容，需要解引用，打印*p的值就是a的值printf("%d\n",*p);
		*p = 20;//解引用可以修改指针指向变量a的值
		printf("%d\n",a);
		return 0;
	其中&a和p的printf输出的地址相同，用a的指针p，修改p就是修改a    
3.2.指针带来的一些符号的理解
	4.星号*的用法
	"*号结合数据类型构成一个指向某种数据类型变量的指针"
	example:
		int *p1,*p2;
		int *p1,p2;//p1是一个指向int类型变量的指针，p2是一个int类型变量
	"*号用来指针解引用，解引用时*p表示p指向变量本身"
	example:
		int a = 23;
		int b = 0;
		int *p;
		p = &a;
		b = *p;	//b = 23 解引用就是引用指向变量的内容
		printf("b = &d.\n",b);
	注意：
		*号放在=号左边给内存赋值，写内存——>*p = 22;
		*号放在=号右边取指向变量内存的值，读内容——>int b = *p;
	5.取地址符号&的用法
	"取地址符号&与某一个变量结合构成一个地址，是某一个变量的地址"
	6.指针定义并初始化、与指针定义然后赋值区别
	example:	
		int a = 23;
		定义并初始化		定义然后在赋值
		int *p = &a;等价于	int *p;
							p = &a;//不能写成*p = &a;操作指针本身都是用p,用*p操作的都是修改p指向的变量，而不是p
		注意：指针赋值操作操作p本身，不是用*p
	7.左值与右值
	当一个变量做左值时，更看重这个变量对应的内存空间;当一个变量做右值时，更看重这个变量的内容，也就是变量对应内存空间中存储的数。
	
	
	8.git一些上传问题
	github 605854183@qq.com password：260814hn..
	github 链接 git clone https://github.com/zhn-946/ZhnRepository.git
	如果出现fatal: unable to access 'https://github.com/zhn-946/ZhnRepository.git/': OpenSSL SSL_read: Connection was reset, errno 10054报错问题
	产生原因：一般是这是因为服务器的SSL证书没有经过第三方机构的签署，所以才报错
	解决办法： 解除ssl验证后，再次git即可——>git config --global http.sslVerify false
	
	GitHub signin登录有一个链接with a code 填写链接里的8个字符然后输入密码确认即可连接成功。
	
3.3.野指针问题
	9.野指针
		野指针，就是指针指向的位置是不可知的(随机的、不正确的、没有明确限制的) wild pointer
			int *p;
			*P = 4;//Segmentation fault (core dumped) 运行时段错误
			//core dumped内存操作不当，核心转储
			链接：https://blog.csdn.net/LSZ520LSZ/article/details/120294766
	3种情况：
	1>指向不可访问的地址(操作系统不允许访问的敏感地址,example:内核空间)
		result：触发段错误
	2>指向一个可用的无意义的空间
		result：example：指向一个曾经使用过的栈空间或者堆,运行不会出错;其实还是有问题
	3>指向一个可用空间
		result：正在被使用的内存空间,野指针的解引用就会修改变量的值，导致变量被莫名其妙改变，程序出现离奇错误,导致程序崩溃或者数据被损坏
	10.如何避免野指针
		来源：指针定义无初始化,无赋值,没有明确指向一个可用的内存空间就去解引用
		避免方法：在指针解引用之前一定确保指针指向一个绝对可用的空间
	常规做法：
		1在定义指针时,同时初始化为NULL int a; int *p = NULL;	
		2在指针解引用之前先去判断这个指针是不是NULL	if (p != NULL) 
		3指针使用完之后将其赋值为NULL p = NULL; 
		4在指针使用之前将其赋值绑定给一个可用地址空间
	11.NULL是什么？
		NULL在c/c++中定义为：
			#ifdef _cplusplus		//定义这个符号表示当前是c++环境
			#define NULL 0			//在c++中null就是0
			#else
			#define NULL (void *)0	//在c中null是强制类型转换为void *的0
			#endif
			注意:C++中允许指针等于0，没有严格的类型检查，但c语言中int *p;可以p = (int *)0;不能直接p = 0;(因为类型不相同)
		"NULL的实质就是0"
		为什么给指针赋初值为NULL,指针指向0地址处：
			原因1：0地址作为特殊地址,认为指针没有被初始化,是野指针，指针解引用前判断是不是NULL,就是判断指针是不是野指针
			原因2：在一般操作系统中地址0都是不可被访问的,不判断是不是NULL直接解引用会触发段错误
	12.判断指针是否野指针时写成："if(NULL != p)"

3.4.const关键字与指针
	13.const用来修饰变量,表示这个变量是常量,不能在被改变
	14.const修饰指针常见有4种形式
		1>const int *p;	 //p是一个指针,指向的变量是一个常量
			example：*p = 3; //error：assignment of read-only location "*p"
		2>int const *p;	 //与上行同理 p是一个指针,指向的变量是一个常量
		3>int * const p; //p本身是一个常量指针,指向的变量是一个int型
			example:
				int a = 5;
				p = &a;//error: assignment of read-only variable "p"
		4>const int * const p; //p是const 指向变量也是const
	15.一个关键字const,修饰一个变量;指针变量涉及2个变量:一个是指针变量p本身,另一个是p指向的变量*p
	16.Const修饰变量可以被改变吗
		example：const int a = 5;
				 //a = 6; //error: assignment of read-only variable "a"
				 int *p;
				 //p = &a;  //warning:assignment discards "const" qualifier from pointer target type[enabled by default]
				 p = (int *)&a; //无警告,以上warning用强制类型转换可以消除,p是一个指针,a是一个const变量,type不一致警告
				 *p = 6;
				 printf("a = %d.\n",a);//a = 6;const修饰的a被改变
		以上example说明const修饰变量在gcc环境下可以被改变,且const类型变量不能修改是编译错误,不是运行错误
	"其他在某些单片机环境下,const修饰的变量不可以被改变,取决于具体环境,C语言本身并没有完全一致严格要求"
	17.const正确使用
		const往后看紧挨着p,说明const修饰的是指针本身,如果没有紧挨着p,隔着一些数据类型或者星号的话,说明const修饰的是指针指向的变量
3.5.深入学习一下数组
	18.数组从内存角度上理解是内存中连续多个内存地址相接的空间;从编译器角度来讲,数组是变量;
	19.变量的本质就是一个地址;地址在编译器中决定具体数值,具体数值和变量名绑定,变量类型决定这个地址的延续长度;
	20.变量与数组的区别
		相同点：不论变量还是数组单个单独独立使用
		不同点：变量单独定义时地址可能随机,数组多个元素地址依次相连,且适合使用指针操作
3.6.指针与数组的天生姻缘

3.7.指针与强制类型转换

3.8.指针、数组与sizeof运算符

3.9.指针与函数传参

3.10.输入型参数与输出型参数





#include <stdio.h>
#include <stdbool.h>

#define MAX_ITERATIONS 4
#define CLOSE_STATE 0x0F

int main() 
{
    int oldState = 0;
    int newState = 0;
    int counter = 0;
    int result = 0;

    // Start the timer

    while (true) 
	{
        // Check if new state is received from the main loop
        if (newState != oldState) 
		{
            if (newState < oldState) 
			{
                result |= 1; // Set the first bit of result to 1
            } 
			else if (newState > oldState) 
			{
                result &= ~1; // Set the first bit of result to 0
            }

            oldState = newState;
            counter++;

            // Check if 4 iterations are completed
            if (counter == MAX_ITERATIONS) 
			{
                if (result == CLOSE_STATE) 
				{
                    printf("Close state detected!\n");
                }

                // Reset variables for the next iteration
                counter = 0;
                result = 0;
            }
        }

        // Continue with other tasks in the main loop
    }

    return 0;
}