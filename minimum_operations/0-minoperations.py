#!/usr/bin/python3


def minOperations(n):
    if n == 1:
        return 0
    
    ops = [0] * (n + 1)
    
    for i in range(2, n + 1):
        ops[i] = float('inf')
        for j in range(1, i):
            if i % j == 0:
                ops[i] = min(ops[i], ops[j] + i // j)
    
    return ops[n] if ops[n] != float('inf') else 0
