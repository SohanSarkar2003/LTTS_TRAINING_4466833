#include <stdio.h>
#include <string.h>

void stringsXOR(const char *s, const char *t, char *result) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == t[i])
            result[i] = '0';
        else
            result[i] = '1';
    }
    result[len] = '\0';  
}

int main() {
    char s[101], t[101], result[101];  

    fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);

    
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    if (strlen(s) != strlen(t)) {
        printf("Error\n");
        return 1;
    }

    stringsXOR(s, t, result);
    printf("%s\n", result);

    return 0;
}
