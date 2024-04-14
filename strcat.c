#include <string.h>
#include <stdio.h>

char longstr[2000000];

int main()
{
    char str[1000];
    while(scanf("%999s", str) > 0)
    {
	strcat(longstr, str);
    }
    printf("%s\n", longstr);
}
