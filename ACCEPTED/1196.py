# -*- coding: utf-8 -*-
# Lukasavicus - 1196
import sys

mapping = [
	'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\'',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'
]
clean_msg = ""
for cipher_msg in sys.stdin:
	for c in cipher_msg:
		if(c == ' ' or c == '\n'):
			clean_msg += c
		else:
			clean_msg += mapping[mapping.index(c)-1]
print(clean_msg, end='')