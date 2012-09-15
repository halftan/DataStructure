sum=1
for x in range(0b00000000,0b11111111):
	if x & 0b10000000:
		sum += 1
	elif ~x & 0b00000010 and ~x & 0b00000001:
		sum += 1

print(sum)
