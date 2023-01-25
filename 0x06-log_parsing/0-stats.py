#!/usr/bin/python3
"""Log parsing"""
import sys


def line_parser(stats):
    if not line or len(stats) != 9 or stats[1] != '-':
        return False, 0, 0
    if not stats[-1].isdigit() or not stats[-2].isdigit():
        return False, 0, 0
    return True, stats[-2], int(stats[-1])


if __name__ == '__main__':
    stats = {'200': 0, '301': 0, '400': 0, '401': 0,
             '403': 0, '404': 0, '405': 0, '500': 0}
    line_count = 0
    total_size = 0
    status_code = []
    for line in sys.stdin:
        line_count += 1
        line_tok = line.split()
        valid, status_code, file_size = line_parser(line_tok)
        if not valid:
            continue
        if status_code in stats.keys():
            stats[status_code] += 1
        total_size += file_size
        if line_count % 10 == 0 and line_count > 1:
            print("File size: {}".format(total_size))
            for code, count in stats.items():
                if count > 0:
                    print("{}: {}".format(code, count))
