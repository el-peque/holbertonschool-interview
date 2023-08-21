#!/usr/bin/python3
"""Count it!"""
import requests
import sys


def count_words(subreddit, word_list):
    """Count words in subreddit"""
    r = requests.get(url='https://www.reddit.com/r/{}/hot.json'.format(subreddit),
                     params={"limit": 100},
                     headers={'User-Agent': 'Mozilla/5.0'})
    if r.status_code != 200:
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
    sorted_word_count = sorted(
        word_count.items(), key=lambda x: x[1], reverse=True)
    for item in sorted_word_count:
        if item[1] != 0:
            print('{}: {}'.format(item[0], item[1]))


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: python script.py subreddit word1 word2 word3 ...")
        sys.exit(1)

    subreddit = sys.argv[1]
    word_list = sys.argv[2:]
    count_words(subreddit, word_list)
