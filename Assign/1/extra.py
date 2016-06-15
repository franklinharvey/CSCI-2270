import sys
from random import randint
from random import randrange
#from random import sample

def write():
	text = open("randomdata.txt", 'w')
	docLength = randint(0,100) #doc being 100 or less entries
	print docLength #tells user how many elements are in the doc

	for num in range (0,docLength):
		typeAssignment(text) #chicken, bike, etc
		status(text) #wanted or for sale
		price(text, num ,docLength) #10000 or less

	text.close()

def typeAssignment(text): 
	typeAssignNum = randint(0,4)	
	if typeAssignNum == 0:
		wordAssign = "bike, "
	elif typeAssignNum == 1:
		wordAssign = "microwave, "
	elif typeAssignNum == 2:
		wordAssign = "dresser, "
	elif typeAssignNum == 3:
		wordAssign = "truck, "
	else:
		wordAssign = "chicken, "
	#wordAssign = sample(["bike ", "microwave, ", "dresser, ", "truck, ", "chicken, "],  1)
	text.write(wordAssign)
	#print wordAssign

def status(text):
	saleStatus = randint(0,1)
	if saleStatus == 0:
		saleStatusAssign = "for sale, "
	else:
		saleStatusAssign = "wanted, "
	text.write(saleStatusAssign)

def price(text, num, docLength):
	priceAssign = randrange(0,10000, 100)
	if num == docLength-1:
		text.write(str(priceAssign)) #last one
	else:
		text.write(str(priceAssign) + '\n') #adds line break

def main():
	write()



if __name__ == '__main__':
	main()