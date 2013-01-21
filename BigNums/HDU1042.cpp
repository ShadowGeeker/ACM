/*
	Author: ShadowGeeker
	GitHub: https://github.com/ShadowGeeker/
	Blog:   http://liuke.org/
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class BigInteger
{
public:
	BigInteger()
	{
		for (int i = 0; i < MAX_BUFF_LEN; ++i)
		{
			_nData[i] = 0;
		}
		_nLen = 0;
	}
	
	BigInteger(unsigned int uiValue)
	{
		_nLen = 0;
		while (uiValue > MAX_BASE_VALUE)
		{
			_nData[_nLen] = uiValue % (MAX_BASE_VALUE + 1);
			_nLen++;
			uiValue /= (MAX_BASE_VALUE + 1);
		}
		_nData[_nLen] = uiValue;
		_nLen++;
	}
	
	BigInteger(const BigInteger& rhs)
	{
		_nLen = rhs._nLen;
		for(int i = 0; i < MAX_BUFF_LEN; ++i)
		{
			_nData[i] = rhs._nData[i];
		}
	}
	
	BigInteger& operator=(const BigInteger& rhs)
	{
		_nLen = rhs._nLen;
		for(int i = 0; i < MAX_BUFF_LEN; ++i)
		{
			_nData[i] = rhs._nData[i];
		}
		return *this;
	}
	
	BigInteger operator*(const BigInteger& rhs)
	{
		BigInteger aInt;
		int i, j;
		unsigned int uiCarry = 0;
		unsigned int uiTmpPlus = 0;
		
		for (i = 0; i < _nLen; ++i)
		{
			uiCarry = 0;
			for (j = 0; j < rhs._nLen; ++j)
			{
				uiTmpPlus = _nData[i] * rhs._nData[j];
				uiTmpPlus += aInt._nData[i + j] + uiCarry;
				if (uiTmpPlus > MAX_BASE_VALUE)
				{
					uiCarry = uiTmpPlus / (MAX_BASE_VALUE + 1);
					uiTmpPlus %= (MAX_BASE_VALUE + 1);
				}
				else
				{
					uiCarry = 0;
				}
				aInt._nData[i + j] = uiTmpPlus;
			}
			if (uiCarry)
			{
				aInt._nData[i + j] = uiCarry;
			}
		}
		
		aInt._nLen = i + j;
		while (aInt._nData[aInt._nLen - 1] == 0 &&
			   aInt._nLen > 1)
		{
			aInt._nLen--;
		}
		
		return aInt;
	}
	
	void PrintValue()
	{
		int i = _nLen - 1;
		printf("%d", _nData[i--]);
		while (i >= 0)
		{
			printf("%04d", _nData[i--]);
		}
	}
private:
	enum
	{
		MAX_BASE_VALUE = 9999,
		MAX_BUFF_LEN   = 10000,
		UNIT_BUFF_LEN  = 4      // maybe used in PrintValue()
	};
	unsigned int _nData[MAX_BUFF_LEN];
	unsigned int _nLen;
};

int main(int argc, char **argv)
{
	int n, i;
	
	while (EOF != scanf("%d", &n))
	{
		if (n == 0 || n == 1)
		{
			printf("1\n");
			continue;
		}
		BigInteger aInt(1);
		for (i = 2; i <= n; ++i)
		{
			aInt = aInt*BigInteger(i);
		}
		aInt.PrintValue();
		putchar('\n');
	}
	
	return 0;
}
/*
	大数乘法
	字符串方法如果一位一位的乘的话太慢了，
	算1000还可以，10000就非常慢了
	这里的方法是通过整数数组来存储数据，
	只不过每4位数据存入一个int之中
*/