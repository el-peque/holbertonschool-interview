#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding"""
    binary = []
    for i, value in enumerate(data):
        binary.append(to_binary(value))
        if binary[0][:1] == '0' and binary[i][:1] != '0':
            return False
        if binary[0][:3] == '110' and i != 0 and binary[i][:2] != '10':
            return False
        if binary[0][:4] == '1110' and i != 0 and binary[i][:2] != '10':
            return False
        if binary[0][:5] == '11110' and i != 0 and binary[i][:2] != '10':
            return False
    return True


def to_binary(n):
    """Converts n to its binary representation"""
    mult = [128, 64, 32, 16, 8, 4, 2, 1]
    binary = ""
    for i, e in enumerate(mult):
        if n - e >= 0:
            n -= e
            binary += '1'
            continue
        binary += '0'
    return binary
