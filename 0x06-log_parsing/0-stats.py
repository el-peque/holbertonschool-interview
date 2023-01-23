#!/usr/bin/python3
import sys
i, j = 0, 0
line_count = 0
total_size = 0
status_code = []
for line in sys.stdin:
    stats = line.split()
    if stats[-2] and (stats[-2]).isdigit():
        status_code.append(stats[-2])
    file_size = int(stats[-1])
    total_size += file_size
    if line_count % 10 == 0 and line_count > 0:
        print(f"File size: {total_size}")
        i = j
        sorted_status = sorted(status_code[i:])
        for i, status in enumerate(sorted_status):
            if status not in sorted_status[i+1:]:
                print(f"{status}: {status_code.count(status)}")
            j += 1
    line_count += 1
