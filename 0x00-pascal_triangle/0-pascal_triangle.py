#!/usr/bin/python3
"""pascal_triangle"""


def pascal_triangle(n):
    """returns a list of lists of integers representing
       the Pascal’s triangle of n"""
    triangle = []
    for i in range(1, n + 1):
        row = []
        for j in range(i):
            print(f"j: {j}, i: {i}")
            print(triangle)
            if j == 0 or j == i - 1:
                row.append(1)
            elif j == 1 or j == i - 2:
                row.append(i - 1)
            else:
                row.append(triangle[i - 2][j - 1] + triangle[i - 2][j])
        triangle.append(row)
    return triangle
