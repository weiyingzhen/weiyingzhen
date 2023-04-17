#include <stdio.h>
#include <math.h>
 
char function1(long n)
{
	char result=0,i=0,remainder;
	while(n!=0)
	{
		remainder=n%10;
		n/=10;
		result+=remainder*pow(2,i);
		++i;
	}

	return result;
}

long function2(char n)
{
	long result = 0;
    char remainder;
	int i=1;

    while (n!=0)
    {
        remainder = n%2;
        n /= 2;
        result += remainder*i;
        i *= 10;
    }
    return result;
}

char function3(char n)
{
	char result[32] ={ 0 };
	char a;
	int y=0,i=0;
	while(n!=0)
	{
		y++;
		result[y]=n%16;
		n=n/16;
		if(result[y]>9)
			result[y]='a'+(result[y]-10);
		else
			result[y]='0'+result[y];

	}
	for (i = y; i > 0; i--)
	{
		printf("%c", result[i]);
	}
	printf("\n");
	return 0;
	
}

char function4(char n[32])
{
	int i,j,sum=0;
	char result=0;
	char a[32]={0};
	while(n[sum]!='\0')
	{
		if(n[sum]>'a' && n[sum]<='f')
		{
			a[sum]=n[sum]-'a'+10;
			sum++;
		}
		else
		{
			a[sum]=n[sum]-'0';
			sum++;
		}

	}
	for(i = 0; i < sum; i++)
	{
		a[sum - 1 - i] = a[sum - 1 - i] * pow(16, i);
	}
	for (j = 0;j<sum;j++) 
	{
		result = result + a[j];
	}

	return result;

}

char function5(long n)
{
	char a,b;
	a=function1(n);
	b=function3(a);
	return 0;
}

long function6(char n[32])
{
	char a;
	long result;
	a=function4(n);
	result=function2(a);
	return result;
}

int main()
{
	char a,b,c,d,f;
	char e[32];
	long n;
	printf("������תΪʮ��������1;\n");
	printf("ʮ����תΪ����������2;\n");
	printf("ʮ����תΪʮ����������3;\n");
	printf("ʮ������תΪʮ��������4;\n");
	printf("������תΪʮ����������5;\n");
	printf("ʮ������תΪ����������6;\n");
	printf("ѡ����еĽ���ת����");
	scanf("%d",&a);
	if(a==1)
	{
		printf("����һ������������");
		scanf("%11d",&n);
		printf("�������� %lld ת��Ϊʮ����Ϊ %d\n", n,function1(n));
	}

	if(a==2)
	{
		printf("����һ��ʮ��������");
		scanf("%d",&b);
		printf("ʮ������ %d ת��Ϊ������Ϊ %11d\n", b,function2(b));
	}

	if(a==3)
	{
		printf("����һ��ʮ��������");
		scanf("%d",&c);		
		printf("ʮ������ %d ת��Ϊʮ������Ϊ", c);
		d=function3(c);

	}

	if(a==4)
	{
		printf("����һ��ʮ����������");
		scanf("%s",&e);
		printf("ʮ�������� %s ת��Ϊʮ����Ϊ %d\n", e,function4(e));

	}

	if(a==5)
	{
		printf("����һ������������");
		scanf("%11d",&n);		
		printf("�������� %11d ת��Ϊʮ������Ϊ", n);
		f=function5(n);	
	}

	if(a==6)
	{
		printf("����һ��ʮ����������");
		scanf("%s",&e);		
		printf("ʮ�������� %s ת��Ϊ������Ϊ %11d\n", e,function6(e));
	}
	return 0;
		
}