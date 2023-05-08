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

    ops = [0] * (n + 1)

    for i in range(2, n + 1):
        ops[i] = float('inf')
        for j in range(1, i):
            if i % j == 0:
                ops[i] = min(ops[i], ops[j] + i // j)

    return ops[n] if ops[n] != float('inf') else 0
