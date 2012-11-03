
def gcd(x,y):
	a = max(x,y)
	b = min(x,y)
	while b != 0:
		t = a % b
		a = b
		b = t
	return a

def main():
	a = input()
	b = input()
	print(gcd(a,b))

if __name__ == '__main__':
	main()


