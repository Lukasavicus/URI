# -*- coding: utf-8 -*-
# Lukasavicus - 2486
import sys, string

def _2486():
	vit_c = {
		"suco de laranja" 	: 120,
		"morango fresco" 	: 85,
		"mamao" 			: 85,
		"goiaba vermelha" 	: 70,
		"manga" 			: 56,
		"laranja" 			: 50,
		"brocolis" 			: 34
	}

	while True:
		qnt_c = 0
		n = int(input())
		if(not n):
			break
		while n:
			line = raw_input()
			line = line.split(" ")
			qnt = int(line[0])
			food = " ".join(line[1:])
			qnt_c += vit_c[food] * qnt
			n -= 1
		if(qnt_c > 130):
			print("Menos " + str(qnt_c - 130) + " mg")
		elif(qnt_c < 110):
			print("Mais " + str(110 - qnt_c) + " mg")
		else:
			print(str(qnt_c) + " mg")


if __name__ == "__main__":
	_2486()