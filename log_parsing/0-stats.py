#!/usr/bin/python3
import sys
import signal
import re
from collections import defaultdict


def print_statistics(file_size, status_codes):
    print("File size: {}".format(file_size))
    for status_code in sorted(status_codes.keys()):
        print("{}: {}".format(status_code, status_codes[status_code]))


def signal_handler(signal, frame):
    print_statistics(total_file_size, status_codes)
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)

total_file_size = 0
status_codes = defaultdict(int)
line_pattern = re.compile(
    r'^(?P<ip>\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}) - \[.*\] "GET /projects/260'
    r' HTTP/1.1" (?P<status_code>\d{3}) (?P<file_size>\d+)$'
)

line_count = 0
for line in sys.stdin:
    match = line_pattern.match(line)
    if match:
        total_file_size += int(match.group("file_size"))
        status_codes[int(match.group("status_code"))] += 1
        line_count += 1

    if line_count % 10 == 0:
        print_statistics(total_file_size, status_codes)

print_statistics(total_file_size, status_codes)
