#include<stdio.h>
#include<string.h>
void exec3(void);
int main(void)
{
	
	// putchar(getchar());
	// getchar(putchar());
	// putchar('\007');

	int i = 0;
	char a[10] = "helloworld";
	// char ch;
	// for(;i < 20;i++) {
	// 	if(scanf("%c", &ch) == 1) {
	// 		a[i] = ch;
	// 	}
	// }
	// scanf("%s", a);
	printf("%d", strlen(a));
	printf("%zd", sizeof(a));

	return 0;
}

void exec3(void) {
	int ch;
	long lcount = 0, ucount = 0;
	while((ch = getchar()) != EOF) {
		if(ch >= 'a' && ch <= 'z') {
			lcount++;
		} else if(ch >= 'A' && ch <= 'Z') {
			ucount++;
		}
	}
	printf("lcount: %ld, ucount: %ld", lcount, ucount);
}