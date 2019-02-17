# -*- coding: utf-8 -*-
# Lukasavicus - 1241
import sys, string

def main():
	TC = int(input())
	for line in sys.stdin:
		n1 = str(line.split(' ')[0]).strip()
		n2 = str(line.split(' ')[1]).strip()
		if(n1.endswith(n2) == False):
			print('nao ', end='')
		print('encaixa')

if (__name__ == "__main__"):
	main()