def main():
	num = 10000000
	for i in range(0,num):
		if i%2==0:
			print i*i
		elif i%3==0:
			print i/3
		else:
			print i/i*i


if __name__ == '__main__':
	main()