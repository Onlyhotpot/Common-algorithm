#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char text[] = "abcbabcaadabcabc" ;
char pattern[] = "abcabc";
int s[20];

void get_SArray (char *p, int length)
{
    s[0] = -1;
    for (int  i = 0, j = -1; i < length; )
    {
        if (j == -1 || p[i] == p[j])
        {
            j++; i++;
            s[i] = j;
        }
        else
            j = s[j];
    }
}

int KMP (char *p, int length_p, char *t, int length_t)
{
    int i, j;
    for (i = 0, j = 0; i < length_p && j < length_t;)
    {
        if (i == -1 || p[i] == t[j])
        {
            j++; i++;
        }
        else
            i = s[i];
        if (i == length_p)
            return (j - i);
    }
    return (-1);
}

int main ()
{
    get_SArray (pattern, strlen(pattern));

    for (int i = 0, length = strlen(pattern); i < length; i++)
        printf ("s[%d] = %d ", i, s[i]);
    printf ("\n");

    printf ("result is %d\n", KMP(pattern, strlen(pattern), text, strlen(text)));

    return (0);
}
