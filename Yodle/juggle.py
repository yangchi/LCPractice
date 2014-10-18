#!/usr/bin/env python

import re

def filereader(filename):
    jugglers = []
    circuits = []
    pattern = '(?P<type>\w{1})\s+\w{1}(?P<id>\d+)\s+H:(?P<H>\d+)\s+E:(?P<E>\d+)\sP:(?P<P>\d+)(?P<pref>\s+\S+){0,1}'
    regex = re.compile(pattern)
    with open(filename, 'r') as f:
        for lines in f:
            m = regex.search(lines.strip())
            if m:
                if m.group('type') == 'J':
                    prefs = m.group('pref').strip().split(',')
                    prefs = [int(pref.strip('C')) for pref in prefs]
                    jugglers.append({int(m.group('id')): {'H': int(m.group('H')), 'E': int(m.group('E')), 'P': int(m.group('P')), 'pref': prefs}})
                else:
                    circuits.append({int(m.group('id')): {'H': int(m.group('H')), 'E': int(m.group('E')), 'P': int(m.group('P'))}})
    return circuits, jugglers


if __name__ == '__main__':
    filereader('jugglefest.txt')
