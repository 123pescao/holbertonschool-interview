#!/usr/bin/python3
"""
Module provides function to determine if
all lockboxes can be unlocked. 
Each box contains keys to other boxes.
Goal is to reach all boxes starting from 0.
"""


def canUnlockAll(boxes):
    n = len(boxes)
    visited = set([0])
    stack = [0]

    while stack:
        box = stack.pop()
        for key in boxes[box]:
            if key < n and key not in visited:
                visited.add(key)
                stack.append(key)
    return len(visited) == n
