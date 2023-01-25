#!/usr/bin/python3
"""Log parsing"""
import sys


if __name__ == '__main__':
    i, j = 0, 0
    stats = {'200': 0, '301': 0, '400': 0, '401': 0,
             '403': 0, '404': 0, '405': 0, '500': 0}
    line_count = 0
    total_size = 0
    status_code = []
    for line in sys.stdin:
        line_tok = line.split()
        if line_tok[-2] in stats:
            stats[line_tok[-2]] += 1
        file_size = int(line_tok[-1])
        total_size += file_size
        if line_count % 10 == 0 and line_count > 0:
            print("File size: {}".format(total_size))
            for code, count in stats.items():
                if count > 0:
                    print("{}: {}".format(code, count))
        line_count += 1
