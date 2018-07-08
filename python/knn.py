from numpy import *
import operator

def create_dataset():
	group = array([[1.0, 1.1], [1.0, 1.0], [0, 0], [0, 0.1]])
	label = ['a', 'a', 'b', 'b']
	return group, label

