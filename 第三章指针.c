C����ѧϰ
�������� ָ��
3.1.ָ�뵽����ʲô��
    1.ָ���ʵ�ʾ���һ������
    int a;  //����int���������ֽ�a; ���������Ĳ������ǰ�һ���ڴ�ռ�����ƺ�a��
    int *p; //����ָ����������ֽ�p,pָ��һ��int�ͱ���
	(����int*p;�����һ���ֲ�����,����һ���ֲ�������δ��ʼ����ֵ�������)
    Ŀǰ���������������Ĳ�����ͬ,a��p���ǰ�����ͬ�ĸ��Ӵ�С
    a = 4; //ok
    ��ͨ�������Ը�ֵint���͵���ֵ
    p = 4; //������������ 
    "ָ������ͨ������;��ͬ�������洢��һ�������ĵ�ַ��������������洢��ֵ"
	p = (int *)4; //ǿ��ת��int*����> 4��ʵ��һ����ַ(int���ͱ����ĵ�ַ)
	2.ָ��ʵ�ּ�ӷ���
	3.ָ�����ʹ�ã�����ָ���������ָ�������ֵ������ָ�롢������
	����ָ���������>int *p; int a = 23;
	��ָ�������ֵ����>�����ָ��ָ����һ����������> p = &a; p = (int *)4; 
		��ָ������ã���ָ��ָ��һ�����Է��ʣ�Ӧ�÷��ʵ��ڴ�
	�����á���>*p =555;//��555����pָ��ı����У��൱��a��ֵ�����555 
		"ָ��洢����ָ��ָ������ĵ�ַ�������þ�������ָ��ָ��ı�����ֵ"
	example:
		int a = 10;
		int *p = &a;
		printf("%p\n",&a);
		printf("%p\n",p);//%p��p��ӡ����ָ�뱾�� Ҳ����д��
		printf("0x%x\n",p);//��%p��ӡָ������һ������ӡ����ָ���data��Ҳ����ָ������ĵ�ַ��
		//�����Ҫ��ӡָ���ַ���ڴ����ݣ���Ҫ�����ã���ӡ*p��ֵ����a��ֵprintf("%d\n",*p);
		*p = 20;//�����ÿ����޸�ָ��ָ�����a��ֵ
		printf("%d\n",a);
		return 0;
	����&a��p��printf����ĵ�ַ��ͬ����a��ָ��p���޸�p�����޸�a    
3.2.ָ�������һЩ���ŵ����
	4.�Ǻ�*���÷�
	"*�Ž���������͹���һ��ָ��ĳ���������ͱ�����ָ��"
	example:
		int *p1,*p2;
		int *p1,p2;//p1��һ��ָ��int���ͱ�����ָ�룬p2��һ��int���ͱ���
	"*������ָ������ã�������ʱ*p��ʾpָ���������"
	example:
		int a = 23;
		int b = 0;
		int *p;
		p = &a;
		b = *p;	//b = 23 �����þ�������ָ�����������
		printf("b = &d.\n",b);
	ע�⣺
		*�ŷ���=����߸��ڴ渳ֵ��д�ڴ桪��>*p = 22;
		*�ŷ���=���ұ�ȡָ������ڴ��ֵ�������ݡ���>int b = *p;
	5.ȡ��ַ����&���÷�
	"ȡ��ַ����&��ĳһ��������Ϲ���һ����ַ����ĳһ�������ĵ�ַ"
	6.ָ�붨�岢��ʼ������ָ�붨��Ȼ��ֵ����
	example:	
		int a = 23;
		���岢��ʼ��		����Ȼ���ڸ�ֵ
		int *p = &a;�ȼ���	int *p;
							p = &a;//����д��*p = &a;����ָ�뱾������p,��*p�����Ķ����޸�pָ��ı�����������p
		ע�⣺ָ�븳ֵ��������p����������*p
	7.��ֵ����ֵ
	��һ����������ֵʱ�����������������Ӧ���ڴ�ռ�;��һ����������ֵʱ��������������������ݣ�Ҳ���Ǳ�����Ӧ�ڴ�ռ��д洢������
	
	github 605854183@qq.com password��260814hn..
	github ���� git clone https://github.com/zhn-946/ZhnRepository.git
	�������fatal: unable to access 'https://github.com/zhn-946/ZhnRepository.git/': OpenSSL SSL_read: Connection was reset, errno 10054��������
	����ԭ��һ����������Ϊ��������SSL֤��û�о���������������ǩ�����Բű���
	����취�� ���ssl��֤���ٴ�git���ɡ���>git config --global http.sslVerify false
	
	GitHub signin��¼��һ������with a code ��д�������8���ַ�Ȼ����������ȷ�ϼ������ӳɹ���
	
3.3.Ұָ������

3.4.const�ؼ�����ָ��

3.5.����ѧϰһ������

3.6.ָ���������������Ե

3.7.ָ����ǿ������ת��

3.8.ָ�롢������sizeof�����

3.9.ָ���뺯������

3.10.�����Ͳ���������Ͳ���





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