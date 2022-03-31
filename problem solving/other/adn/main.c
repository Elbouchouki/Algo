#include <stdlib.h>
#include <stdio.h>
int main()
{
    char adn[] = {'A',
                  'A',
                  'B',
                  'B',
                  'B',
                  'B',
                  'B',
                  'H',
                  'H',
                  'H'};
    int n = 10;
    int cpt = 1, current_char = adn[0], cpt_max = 0;
    for (int i = 1; i < n; i++)
    {
        if (current_char == adn[i])
        {
            cpt++;
        }
        else
        {
            if (cpt > cpt_max)
                cpt_max = cpt;
            cpt = 1;
            current_char = adn[i];
        }
    }
    printf("%d", cpt_max);
}
