#include <stdio.h>
#include <string.h>

int main()
{
    int n, q;

    scanf("%d", &n);

    char strings[n][21];

    // Read the strings
    for (int i = 0; i < n; i++)
    {
        scanf("%20s", strings[i]);
    }

    scanf("%d", &q);

    char query[21];

    // Process each query
    for (int i = 0; i < q; i++)
    {
        scanf("%20s", query);

        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (strcmp(strings[j], query) == 0)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
