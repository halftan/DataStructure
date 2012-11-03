#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 50125

int LCS(char *str1, char *str2);

int main(void){
    char *s1,*s2;
    s1 = (char*)calloc(sizeof(char), MAX);
    s2 = (char*)calloc(sizeof(char), MAX);
    scanf("%s%s",s1,s2);
    printf("%d",LCS(s1,s2));
    free(s1);
    free(s2);
    return 0;
}

int LCS(char *str1, char *str2){
    int len1,len2;
    int col,row,flag;
    int max = 0;
    len1 = strlen(str1);
    len2 = strlen(str2);
    int dp[len1][2];
    for(row = 0; row < len1; ++row)
        dp[row][0] = dp[row][1] = 0;
    
    for(row = 1, flag = 1; row < len2; ++row, flag = flag^1)
        for(col = 0; col < len1; ++col){
            if(col == 0)
                continue;
            if(str1[col - 1] == str2[row - 1]){
                dp[col][flag] = dp[col - 1][flag^1] + 1;
                max  = dp[col][flag] > max ?
                    dp[col][flag]:max;
            }else
                dp[col][flag] = 0;
        }
    free(dp);
    return max;
}
