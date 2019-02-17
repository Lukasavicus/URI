from __future__ import print_function
# -*- coding: utf-8 -*-
# Lukasavicus - 2772
import sys, string

def main():
	while True:
		line = sys.stdin.readline()
		if (line == ""):
			break
		print("line: "+line)
		print("Gotcha")
		N = int(line.split(' ')[0].strip())
		K = int(line.split(' ')[1].strip())
		T = int(line.split(' ')[2].strip())
		L = [T] * N
		for _ in range(K):
			line = sys.stdin.readline()
			r = int(line.split(' ')[0].strip())-1
			l = int(line.split(' ')[1].strip())-1
			for i in range(N):
				L[i] -= 1
			for i in range(r,l+1):
				if(L[i] > 0):
					L[i] = T
				print(L[i], end=' ')
			print("")
			
		for i in range(N):
			print("L[{}]: {}".format(i, L[i]), end=' ')
		print("")

if (__name__ == "__main__"):
	main()