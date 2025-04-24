#!/usr/bin/python3
"""Minimum Operations project"""


def minOperations(n):
    """Calculate the fewest number of operations to get n Hs"""
    if n < 2:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
