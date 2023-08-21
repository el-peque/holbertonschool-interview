#!/usr/bin/python3
"""Count it!"""
import requests
import sys


def count_words(subreddit, word_list):
    """Count words in subreddit"""
    word_count = {k: v for k, v in zip(
        [word.lower() for word in word_list], [0] * len(word_list))}

    def count_words_recursive(subreddit, word_list, after=None):
        """Count words recursively"""
        if after:
            params = {"after": after}
        else:
            params = {}

        r = requests.get(url='https://www.reddit.com/r/{}/hot.json'.format(
            subreddit),
            params=params,
            headers={'User-Agent': 'Mozilla/5.0'})
        if r.status_code != 200:
            return

        data = r.json().get('data')
        children = data.get('children')

        for child in children:
            title = child.get('data').get('title').lower()
            for word in word_count.keys():
                word_count[word] += title.split(' ').count(word)
        after = data.get('after')
        if after:
            count_words_recursive(subreddit, word_list, after)

    count_words_recursive(subreddit, word_list)

    if sum(word_count.values()) == 0:
        return
    sorted_word_count = sorted(
        word_count.items(), key=lambda x: (-x[1], x[0].lower()))
    for item in sorted_word_count:
        if item[1] != 0:
            print('{}: {}'.format(item[0], item[1]))


if __name__ == '__main__':
    count_words(sys.argv[1], sys.argv[2:])
