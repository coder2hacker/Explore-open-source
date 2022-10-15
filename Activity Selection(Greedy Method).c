#include <stdio.h>
void greedy_activity_selector(int s[], int f[], int n)
{
    int i = 0;
    printf("activity 0\n");
    for (int m = 1; m < n; m++)
    {
        if (s[m] >= f[i])
        {
            printf("activity %d\n", m);
            i = m;
        }
    }
}
int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    greedy_activity_selector(start, finish, 6);
}
