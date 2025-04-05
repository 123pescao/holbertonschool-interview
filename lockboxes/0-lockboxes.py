#!/bin/bash
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
