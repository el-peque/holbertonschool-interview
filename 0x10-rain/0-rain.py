#!/usr/bin/python3
"""0. Rain"""


def rain(walls):
    """
    Given a list of non-negative integers representing the heights of walls
    with unit width 1, as if viewing the cross-section of a relief map, it
    calculates how many square units of water will be retained after it rains.
    """
    wall = 0
    filled_water = 0
    start = 0
    for i in range(len(walls)):
        if walls[i] != 0 and start != 0:
            if wall != (i + 1 and i - 1):
                filled_water += min(walls[wall], walls[i]) * (i - wall - 1)
            wall = i
        if walls[i] > 0:
            start = 1
            wall = i

    return filled_water
