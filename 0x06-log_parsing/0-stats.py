#!/usr/bin/python3
"""Log parsing"""
import sys


if __name__ == '__main__':
    stats = {'200': 0, '301': 0, '400': 0, '401': 0,
             '403': 0, '404': 0, '405': 0, '500': 0}

    def print_parsed_stats(total_size):
        """Prints stast in '{status_code}: {number}' format"""
        print("File size: {}".format(total_size))
        for code in sorted(stats.keys()):
            if stats[code] > 0:
                print("{}: {}".format(code, stats[code]))

    def parse_line(line):
        """Parses line and return file size"""
        try:
            line_tok = line.split()
            status_code = line_tok[-2]
            file_size = int(line_tok[-1])
            if status_code in stats.keys():
                stats[status_code] += 1
            return file_size
        except Exception:
            return 0

    line_count = 1
    total_size = 0
    try:
        for line in sys.stdin:
            file_size = parse_line(line)
            total_size += file_size
            if line_count % 10 == 0:
                print_parsed_stats(total_size)
            line_count += 1
    except KeyboardInterrupt:
        print_parsed_stats(total_size)
        raise
    print_parsed_stats(total_size)
