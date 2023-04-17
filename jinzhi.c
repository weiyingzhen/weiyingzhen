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
	printf("二进制转为十进制输入1;\n");
	printf("十进制转为二进制输入2;\n");
	printf("十进制转为十六进制输入3;\n");
	printf("十六进制转为十进制输入4;\n");
	printf("二进制转为十六进制输入5;\n");
	printf("十六进制转为二进制输入6;\n");
	printf("选择进行的进制转化：");
	scanf("%d",&a);
	if(a==1)
	{
		printf("输入一个二进制数：");
		scanf("%11d",&n);
		printf("二进制数 %lld 转换为十进制为 %d\n", n,function1(n));
	}

	if(a==2)
	{
		printf("输入一个十进制数：");
		scanf("%d",&b);
		printf("十进制数 %d 转换为二进制为 %11d\n", b,function2(b));
	}

	if(a==3)
	{
		printf("输入一个十进制数：");
		scanf("%d",&c);		
		printf("十进制数 %d 转换为十六进制为", c);
		d=function3(c);

	}

	if(a==4)
	{
		printf("输入一个十六进制数：");
		scanf("%s",&e);
		printf("十六进制数 %s 转换为十进制为 %d\n", e,function4(e));

	}

	if(a==5)
	{
		printf("输入一个二进制数：");
		scanf("%11d",&n);		
		printf("二进制数 %11d 转换为十六进制为", n);
		f=function5(n);	
	}

	if(a==6)
	{
		printf("输入一个十六进制数：");
		scanf("%s",&e);		
		printf("十六进制数 %s 转换为二进制为 %11d\n", e,function6(e));
	}
	return 0;
		
}