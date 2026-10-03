#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;

    scanf("%d %d", &n, &q);

    int **seq = malloc(n * sizeof(int *));
    int *size = calloc(n, sizeof(int));
    int *capacity = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        capacity[i] = 1;
        seq[i] = malloc(sizeof(int));
    }

    int lastAnswer = 0;

    for (int i = 0; i < q; i++)
    {
        int type, x, y;

        scanf("%d %d %d", &type, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (type == 1)
        {
            if (size[idx] == capacity[idx])
            {
                capacity[idx] *= 2;
                seq[idx] = realloc(seq[idx],
                                    capacity[idx] * sizeof(int));
            }

            seq[idx][size[idx]] = y;
            size[idx]++;
        }
        else if (type == 2)
        {
            lastAnswer = seq[idx][y % size[idx]];
            printf("%d\n", lastAnswer);
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(seq[i]);
    }

    free(seq);
    free(size);
    free(capacity);

    return 0;
}
