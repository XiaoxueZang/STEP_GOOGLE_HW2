import matplotlib.pyplot as plt
import numpy, sys, time
x = []
y = []
######################################
# Write code to calculate C = A * B. #
for n in xrange(300):
    a = numpy.zeros((n, n)) # Matrix A
    b = numpy.zeros((n, n)) # Matrix B
    c = numpy.zeros((n, n)) # Matrix C

# Initialize the matrices to some values.
    for i in xrange(n):
        for j in xrange(n):
            a[i, j] = i * n + j
            b[i, j] = j * n + i
            c[i, j] = 0
    begin = time.time()
    for i in xrange(n):
        for j in xrange(n):
            result = 0
            for k in xrange(n):
                result = result + a[i,k]*b[k,j]
            c[i,j]= result
    end = time.time()
    x.append(n)
    y.append(end-begin)

plt.plot(x,y)
plt.title("python matrix")
plt.xlabel("matrix number")
plt.ylabel("execution time(s)")
plt.savefig("python_matrix.png")
