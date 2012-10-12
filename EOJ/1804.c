#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXS 1030

typedef struct string {
	char s[MAXS];
} string;

string* GetString();
int strlen_s(char*);
string* strcat_s(string*, char[]);
char* strsub_s(string*, int, int);
int strequ_s(string*, char[]);

int main(void) {
	string* str = GetString();
	int T;
	int a, b;
	char *t;
	char cmd[15];
	char buf[MAXS];
	scanf("%s", str->s);
	scanf("%d", &T);
	while (T--) {
		scanf("%s", cmd);
		switch (cmd[3]) {
		case 'c':
			scanf("%s", buf);
			printf("%s\n", strcat_s(str, buf)->s);
			break;
		case 's':
			scanf("%d%d", &a, &b);
			t = strsub_s(str, a, b);
			printf("%s\n", t);
			free(t);
			break;
		case 'e':
			scanf("%s", buf);
			if (strequ_s(str, buf))
				printf("yes\n");
			else
				printf("no\n");
			break;
		}
	}
	return 0;
}
string* GetString() {
	string *t = (string*) calloc(sizeof(string), 1);
	return t;
}
string* strcat_s(string* s, char* t) {
	int i = 0, len = strlen_s(s->s);
	while (t[i]) {
		s->s[i + len] = t[i];
		++i;
	}
	s->s[i + len] = 0;
	len = strlen_s(s->s);
	return s;
}
char* strsub_s(string* s, int a, int b) {
	int i, len = strlen_s(s->s);
	char *ret = (char*) calloc(sizeof(char), b - a + 3);
	if(a < 0 || b < 0 || a >= len || a + b > len){
		ret[0] = 'f';
		ret[1] = 'a';
		ret[2] = 'i';
		ret[3] = 'l';
		ret[4] = 0;
		return ret;
	}
	for(i = 0;i < b;++i)
		ret[i] = s->s[i + a];
	return ret;
}
int strequ_s(string* s, char* t) {
	int i = 0, len = strlen_s(s->s);
	while (t[i])
		++i;
	if (i != len)
		return 0;
	i = 0;
	while (i < len) {
		if (s->s[i] != t[i])
			return 0;
		++i;
	}
	return 1;
}
int strlen_s(char* s){
	int i = 0;
	while(s[i])i++;
	return i;
}
