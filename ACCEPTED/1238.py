# -*- coding: utf-8 -*-
# Lukasavicus - 1238
import sys, string

def main():
	TC = int(input())
	for line in sys.stdin:
		n1 = str(line.split(' ')[0]).strip()
		n2 = str(line.split(' ')[1]).strip()

		l1 = list(n1)
		l2 = list(n2)

		while True:
			if(l1 != []):
				print(l1.pop(0), end = '')

			if(l2 != []):
				print(l2.pop(0), end = '')

			if(l1 == [] and l2 == []):
				break
		print('')

if (__name__ == "__main__"):
	main()