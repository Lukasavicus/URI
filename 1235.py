# -*- coding: utf-8 -*-
# Lukasavicus - 1235
import sys, string

def main():
	TC = int(input())
	for line in sys.stdin:
		mid = (len(line) // 2) #- 1
		insideout = ((line[0:mid][::-1]).strip() + (line[mid:][::-1]).strip())
		print(insideout)

if (__name__ == "__main__"):
	main()