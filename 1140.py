# -*- coding: utf-8 -*-
# Lukasavicus - 1140
import sys, string

def _1140():
	for line in sys.stdin:
		if line == "*":
			break
		#print(line)
		line = line.upper()
		line = line.split(" ")
		letter = line[0][0]
		diff = 0
		for l in line:
			diff += (l[0] != letter)

		if (diff > 0):
			print("N")
		else:
			print("Y")

if __name__ == "__main__":
	_1140()