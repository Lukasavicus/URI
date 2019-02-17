# -*- coding: utf-8 -*-
# Lukasavicus - 1234
import sys, string

def main():
	for line in sys.stdin:
		i = 1
		for c in line:
			d = c
			if(c.isalpha()):
				if((i % 2) == 1):
					d = c.upper()
				else:
					d = c.lower()
				i += 1
			print(d, end = '')

if (__name__ == "__main__"):
	main()