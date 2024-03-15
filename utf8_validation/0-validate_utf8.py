#!/usr/bin/python3
"""
Defines a method that determines if a given data set
represents valid UTF-8 encoding
"""


def validUTF8(data):
    if type(data) is not list:
        return False
    for i in data:
        if type(i) is not int:
            return False
    return True
