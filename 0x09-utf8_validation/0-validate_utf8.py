#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""
    binary = []
    byte = 0
    for i, value in enumerate(data):
        binary = to_binary(value)
        if byte > 0 and binary[:2] != [1, 0]:
            return False
        if byte == 0:
            byte = binary.index(0)
        byte -= 1
    return True


def to_binary(n):
    """Converts n to its binary representation"""
    mult = [128, 64, 32, 16, 8, 4, 2, 1]
    binary = [0] * 8
    for i, e in enumerate(mult):
        if n - e >= 0:
            n -= e
            binary[i] = 1
    return binary
