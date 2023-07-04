#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: list to search in
 * @value: searched value
 * Return: value or NULL if not present
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *express_lane, *prev;

    if (!list)
        return NULL;

    express_lane = list;
    while (express_lane)
    {
        if (express_lane->express == NULL || express_lane->express->n >= value)
        {
            printf("Value found between indexes [%zu] and [%zu]\n",
                   express_lane->index, express_lane->express->index);
            break;
        }
        express_lane = express_lane->express;
        printf("Value checked at index [%zu] = [%d]\n",
               express_lane->index, express_lane->n);
    }

    prev = express_lane;
    while (prev)
    {
        printf("Value checked at index [%zu] = [%d]\n",
               prev->index, prev->n);
        if (prev->n == value)
            return prev;
        prev = prev->next;
    }

    return NULL;
}
