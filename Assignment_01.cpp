#include <cstdio>

using namespace std;

template<typename C>
int StringCompare(C* _A, C* _B){
	int iA(0), iB(0);
	while(*_A && *_B){
		if(*_A != *_B)
			return (*_A - *_B);
		_A++;
		iA++;
		_B++;
		iB++;
	}
	while(*_A++)
		iA++;
	while(*_B++)
		iB++;
	return (iA - iB);
}

int main(void)
{
	int a[] = {1,5,9,10,2};
	int b[] = {1,5,8};
	if(StringCompare<int>(a,b) < 0)
		printf("Less\n");
	else printf("More or Equal\n");
	getchar();
}
