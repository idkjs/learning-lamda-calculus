# the game of text life from daily programmer
# https://www.reddit.com/r/dailyprogrammer/comments/3m2vvk/20150923_challenge_233_intermediate_game_of_text/
# by Anjana and Alicia

import random

def gridafy(inputString):
	""" INPUT: a string with new line returns, 
	OUTPUT: a list of strings that each fit on one line, with shorter lines padded with spaces """
	splitted = inputString.split("\n")

	longest = max(splitted, key=lambda x: len(x))
	gridWidth = len(longest)
	# print (longest, gridWidth)

	grid  = []
	for row in splitted:
		extraSpaces = gridWidth - len(row)
		# print extraSpaces
		newRow = row + " " * extraSpaces
		# print newRow
		grid.append(newRow)

	return grid


def findNeighbors(inputList, (row,col)):
	""" INPUT: a list of strings (that make a grid) and a row, column tuple specifying a point
	OUTPUT: a list of all neighbor characters of that point """
	neighborList = []

	deltaList = [(-1,-1), (-1,0), (-1,1),
				(0,-1), (0,1),
				(1,-1), (1,0), (1,1)]

	for (delR, delC) in deltaList:
		#print (delR, delC)
		#print (row+delR, col+delC)
		
		if row+delR >= 0 and col+delC >= 0:
			try:
				neighborList.append(inputList[row+delR][col+delC])
			except IndexError:
		#		print "exception"
				continue

	return neighborList


def countAliveNeighbors(neighborList):
	"""INPUT: list of neighbor strings, OUTPUT: integer of number of alive neighbors"""
	counter = 0

	for neighbor in neighborList:
		if neighbor != " ":
			counter += 1

	return counter

def getBornCell(neighborList):
	"""INPUT: list of neighbors (strings)
	OUTPUT: randomly selected new string to put in the cell (not a space)"""
	aliveNeighbors = [n for n in neighborList if n != " "]
	return random.choice(aliveNeighbors)

def updateStatus(cellString, neighborList):
	"""INPUT: contents (string) of the cell, list of strings of neighbors
	OUTPUT: new contents of the cell (string)"""

	isAlive = (cellString != " ")

	numAliveNeighbors = countAliveNeighbors(neighborList)

	if isAlive:
		if numAliveNeighbors > 1 and numAliveNeighbors < 4: 
			# cell stays alive
			newString = cellString
		else:
			# cell dies
			newString = " "

	else: 
		if numAliveNeighbors == 3:
			newString = getBornCell(neighborList)
		else:
			newString = " " #same as cellString

	return newString

def transition(inputString):
	"""INPUT: string containing newlines, representing a grid
	OUTPUT: string containing newlines, representing grid updated according to game of life"""

	grid = gridafy(inputString)

	newGrid = []

	for (r, row) in enumerate(grid):
		newRow = ""
		for (c, char) in enumerate(row):
			neighborList = findNeighbors(grid, (r,c))
			newChar = updateStatus(char, neighborList)
			newRow += newChar
		newGrid.append(newRow)

	outputString = "\n".join(newGrid)

	return outputString



# print "TESTS"
# print gridafy("first line \n second line")
# print ""

# #testString = "A C\n EF\nGH "
# testString = " *\n****\n  *"
# print "expecting 5: " + str(countAliveNeighbors(findNeighbors(gridafy(testString), (1,1))))
# print "expecting 1: " + str(countAliveNeighbors(findNeighbors(gridafy(testString), (0,0))))
# print "expecting 3: " + str(countAliveNeighbors(findNeighbors(gridafy(testString), (2,2))))

# print ""
# print testString
# print gridafy(testString)
# print transition(testString)


if __name__ == '__main__':
	print "Welcome to game of life"

	currentString = "What?\nThis is exceedingly silly.\n\nReally, we would like some ACTUAL programming challenges around here."

	while True:
		print ""
		newString = transition(currentString)
		print newString
		currentString = newString
		x = raw_input("type something: ")
		if x == "quit":
			break

	print "Goodbye"