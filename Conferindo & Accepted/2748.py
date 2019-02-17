# -*- coding: utf-8 -*-
# Lukasavicus - 2748
import sys, string

def _2748():
	hline = "-" * 39
	vlines = "|" + " "* 37 + "|"
	pre_space = " " * 8
	vline_w_content = lambda x : "|" + pre_space + x + " " * (29 - len(x)) + "|"

	print(hline)
	print(vline_w_content("Roberto"))
	print(vlines)
	print(vline_w_content("5786"))
	print(vlines)
	print(vline_w_content("UNIFEI"))
	print(hline)

if __name__ == "__main__":
	_2748()