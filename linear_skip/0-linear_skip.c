#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: list to search in
 * @value: searched value
 * Return: value or NULL if not present
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express_lane = list;
	size_t end = 0;

	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	end = list->index, list = express_lane;
	while (list->next)
	{
		if (express_lane->express)
			printf("Value checked at index [%zu] = [%d]\n",
				   express_lane->express->index, express_lane->express->n);

		if (express_lane->express && express_lane->express->n <= value)
		{
			express_lane = express_lane->express;
			list = express_lane;
			continue;
		}
		if (list->express)
			end = list->express->index;
		printf("Value found between indexes [%zu] and [%zu]\n", list->index, end);
		while (list)
		{
			printf("Value checked at index [%zu] = [%d]\n", list->index, list->n);
			if (list->n == value)
				return (list);
			if (list->next)
				list = list->next;
			else
				return (NULL);
		}
	}
	return (NULL);
}
