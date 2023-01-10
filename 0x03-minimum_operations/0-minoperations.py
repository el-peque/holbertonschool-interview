#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """
    In a text file, there is a single character H.
    Your text editor can execute only two operations in this file:
    -Copy All and Paste.
    Given a number n, write a method that calculates the fewest number
    of operations needed to result in exactly n H characters in the file.
    """
    H = 1
    op = 0
    copied = 0
    for i in range(1, n):
        if n == H:
            break
        if op == 0 or (n % H == 0 and (n / 2) >= H):
            op += 2
            copied = H
        else:
            op += 1
        H += copied
    return op
