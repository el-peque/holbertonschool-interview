#!/usr/bin/python3
"""0. Rain"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map, it
    calculates how many square units of water will be retained after it rains.
    """
    water = 0
    for i in range(len(walls) - 1):
        for j in range(i + 1, len(walls)):
            if walls[j] > walls[i]:
                for k in range(i + 1, j):
                    if walls[i] - walls[k] > 0:
                        sum = walls[i] - walls[k]
                        water += sum
                        walls[k] += walls[i] - walls[k]

    walls.reverse()
    for i in range(len(walls) - 1):
        for j in range(i + 1, len(walls)):
            if walls[j] > walls[i]:
                for k in range(i + 1, j):
                    if walls[i] - walls[k] > 0:
                        sum = walls[i] - walls[k]
                        water += sum
                        walls[k] += walls[i] - walls[k]

    return water
