#!/usr/bin/python3
"""Count it!"""
import requests
import sys


def count_words(subreddit, word_list, after=None, counts=None):
    """Count words in subreddit"""
    if counts is None:
        counts = {word.lower(): 0 for word in word_list}
    if after is None:
        after = ''

    url = f'https://www.reddit.com/r/{subreddit}/hot.json'

    params = {"limit": 100, "after": after}

    r = requests.get(url, params=params, headers={'User-Agent': 'Mozilla/5.0'})

    if r.status_code != 200:
        print("No posts match or the subreddit is invalid.")
        return

    data = r.json().get('data')
    children = data.get('children')

    for child in children:
        title = child.get('data').get('title').lower()
        for word in counts.keys():
            counts[word] += title.count(word)

    after = data.get('after')

    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_word_count = sorted(
            counts.items(), key=lambda x: (-x[1], x[0].lower()))
        for item in sorted_word_count:
            if item[1] != 0:
                print('{}: {}'.format(item[0], item[1]))


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: python script.py subreddit word1,word2,word3")
        sys.exit(1)

    subreddit = sys.argv[1]
    word_list = sys.argv[2].split(",")
    count_words(subreddit, word_list)
