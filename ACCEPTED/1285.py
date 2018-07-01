# -*- coding: utf-8 -*-
# Lukasavicus - 1285
import sys

for line in sys.stdin:
	q = 0
	bgn, end = (int(line.split(' ')[0]), int(line.split(' ')[1]))
	for i in range(bgn, end+1):
		str_i = str(i)
		#print(str_i)
		#print([j for j in str_i if str_i.count(j) > 1])
		q += ([j for j in str_i if str_i.count(j) > 1] == [])
	print(q) #, end=''
