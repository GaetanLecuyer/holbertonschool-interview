#!/usr/bin/python3
"""
Affiche les statistiques, y compris la taille totale du fichier et le nombre d'occurrences pour chaque code d'état.

Args:
    total_size (int): Taille totale du fichier.
    status_counts (dict): Dictionnaire avec les codes d'état en tant que clés et le nombre d'occurrences en tant que valeurs.
"""

import sys
from collections import defaultdict

def print_statistics(total_size, status_counts):
    print("File size: {}".format(total_size))
    for status_code in sorted(status_counts):
        print("{}: {}".format(status_code, status_counts[status_code]))

def parse_line(line):

    try:
        parts = line.split()
        ip_address = parts[0]
        status_code = int(parts[-2])
        file_size = int(parts[-1])
        return ip_address, status_code, file_size
    except (ValueError, IndexError):
        return None, None, None

def main():
    total_size = 0
    status_counts = defaultdict(int)
    line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            ip_address, status_code, file_size = parse_line(line)

            if ip_address is not None and status_code is not None and file_size is not None:
                total_size += file_size
                status_counts[status_code] += 1
                line_count += 1

            if line_count % 10 == 0:
                print_statistics(total_size, status_counts)

    except KeyboardInterrupt:
        pass  # Gère l'interruption CTRL+C

    finally:
        print_statistics(total_size, status_counts)

if __name__ == "__main__":
    main()
