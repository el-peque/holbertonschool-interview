#!/usr/bin/python3
"""Count it!"""
import requests
import sys


def count_words(subreddit, word_list):
    """Count words in subreddit"""
    r = requests.get('https://www.reddit.com/r/{}/hot.json'.format(subreddit))
    print(r.status_code)
    if r.status_code != '200':
        return

    data = r.json().get('data')
    children = data.get('children')
    word_count = {k: v for k, v in zip(
        [word.lower() for word in word_list], [0] * len(word_list))}
    for child in children:
        title = child.get('data').get('title').lower()
        for word in word_count.keys():
            word_count[word] += title.count(word)

    if sum(word_count.values()) == 0:
        return
    sorted_word_count = sorted(word_count.items(), key=lambda x: x[1])
    for k, v in sorted_word_count.items():
        print('{}: {}'.format(k, v))


if __name__ == '__main__':
    count_words(sys.argv[1], sys.argv[2:])
