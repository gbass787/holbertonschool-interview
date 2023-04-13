#!/usr/bin/python3
"""
minimum operations
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in
    exactly n H characters in a text file.
    Args:
    n (int): the desired number of H characters in the file
    Returns:
    int: the minimum number of operations needed to achieve n H characters
    If n is impossible to achieve, returns 0
    """
    if n <= 0:
        return 0

    ops = 0
    div = 2

    while n > 1:
        while n % div == 0:
            ops += div
            n //= div
        div += 1
        if div * div > n:
            if n > 1:
                ops += n
            break

    return ops
