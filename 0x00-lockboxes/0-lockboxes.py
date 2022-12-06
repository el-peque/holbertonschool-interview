#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes."""

    boxes_state = [True] + [False] * (len(boxes) - 1)

    for box in range(len(boxes)):
        for key in boxes[box]:
            if key != box and key < len(boxes):
                boxes_state[key] = True

    if False in boxes_state:
        return False

    return True
