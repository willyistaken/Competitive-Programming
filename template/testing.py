def A000110_list(m):

    A = [0 for i in range(m)]

    A[0] = 1

    R = [1, 1]

    for n in range(1, m):

        A[n] = A[0]

        for k in range(n, 0, -1):

            A[k-1] += A[k]

        R.append(A[0])

    return R

p = A000110_list(10000)
print(p)