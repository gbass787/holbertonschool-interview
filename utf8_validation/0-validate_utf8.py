#!/usr/bin/python3
"""Challenge UTF-8"""


def validUTF8(data):
    """
    Bit manipulation leetcode.com implementation
    method that determines if a given data
    set represents a valid UTF-8 encoding
    Args:
        data: data will be represented by a list
              of integers
    Return: True if data is a valid UTF-8 encoding,
            else return False
    """
    n_bytes = 0

    m1 = 1 << 7
    m2 = 1 << 6

    if not data or len(data) == 0:
        return True
    for num in data:
        bit = 1 << 7
        if n_bytes == 0:
            while (bit & num):
                n_bytes += 1
                bit = bit >> 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num & m1 and not (num & m2)):
                return False
        n_bytes -= 1
    if n_bytes:
        return False
    else:
        return True
