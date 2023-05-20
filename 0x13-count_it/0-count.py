#!/usr/bin/python3
"""Count it!"""
import requests
import sys
import json


def count_words(subreddit, word_list):
    """Count words in subreddit"""
    r = requests.get('https://www.reddit.com/r/{}/hot.json'.format(subreddit))
    data = r.json().get('data')
    if not data:
        return
    children = data.get('children')
    word_count = {k: v for k, v in zip(
        [word.lower() for word in word_list], [0] * len(word_list))}
    for child in children:
        title = child.get('data').get('title').lower()
        for word in word_count.keys():
            word_count[word] += title.count(word)
    if sum(word_count.values()) == 0:
        return
    for k, v in word_count.items():
        print('{}: {}'.format(k, v))


if __name__ == '__main__':
    count_words(sys.argv[1], sys.argv[2:])
