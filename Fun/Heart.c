#include<stdio.h>

int main()
{
    int i = 0;
    char q[] = "SY";
    for (float y = 1.5; y > -1.5; y -= 0.1){
        for (float x = -1.5; x < 1.5; x += 0.05){
            float a = x * x + y * y -1;
            if (a * a * a - x * x * y * y * y <= 0.0){
                if (q[i] == '\0'){
                    i = 0;
                }
                printf("%c",q[i]);
                ++i;
            }
            if (a * a * a - x * x * y * y * y > 0.0){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
