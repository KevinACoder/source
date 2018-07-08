from numpy import *
import knn

# n = 4
# rand_mat = mat(random.rand(n, n))
# inv_rand_mat = rand_mat.I
# Err = rand_mat*inv_rand_mat - eye(n)
# print "calculate error.." 
# print rand_mat*inv_rand_mat

group, labels = knn.create_dataset()
print group
print labels