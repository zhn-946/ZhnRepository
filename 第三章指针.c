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
	
	github 605854183@qq.com password：260814hn..
	github 链接 git clone https://github.com/zhn-946/ZhnRepository.git
	如果出现fatal: unable to access 'https://github.com/zhn-946/ZhnRepository.git/': OpenSSL SSL_read: Connection was reset, errno 10054报错问题
	产生原因：一般是这是因为服务器的SSL证书没有经过第三方机构的签署，所以才报错
	解决办法： 解除ssl验证后，再次git即可——>git config --global http.sslVerify false
	
	GitHub signin登录有一个链接with a code 填写链接里的8个字符然后输入密码确认即可连接成功。
	
3.3.野指针问题

3.4.const关键字与指针

3.5.深入学习一下数组

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