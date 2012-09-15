#!/usr/bin/env python
# -*- coding: UTF-8 -*-

def PowSet(e):
	assert type(e) == set,str(e) + '不是集合'
	if not e:
		return [set()]
	elem = e.pop()
	rest = PowSet(e)
	e.add(elem)
	return reduce(lambda a,b:[c.union([b]) for c in a ] + a ,e, [set()])

def main():
	print('请输入一个集合，由{}包围')
	print(PowSet(input()))


if __name__ == "__main__":
	main()
