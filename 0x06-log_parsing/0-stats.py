#!/usr/bin/python3
"""Log parsing"""
import sys


def print_parsed_stats(stats, total_size):
    print("File size: {}".format(total_size))
    for code in sorted(stats.keys()):
        if stats[code] > 0:
            print("{}: {}".format(code, stats[code]))


if __name__ == '__main__':
    stats = {'200': 0, '301': 0, '400': 0, '401': 0,
             '403': 0, '404': 0, '405': 0, '500': 0}
    line_count = 0
    total_size = 0
    status_code = []
    try:
        for line in sys.stdin:
            line_tok = line.split()
            try:
                status_code = line_tok[-2]
                file_size = int(line_tok[-1])
            except Exception:
                continue
            if status_code in stats.keys():
                stats[status_code] += 1
            total_size += file_size
            if line_count % 10 == 0 and line_count > 0:
                print_parsed_stats(stats, total_size)
            line_count += 1
    except KeyboardInterrupt:
        print_parsed_stats(stats, total_size)
        raise
