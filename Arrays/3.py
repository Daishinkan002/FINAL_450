#Q. 


ary = list(map(int, input().split()))
n, k = ary[0], ary[1]
a = list(map(int, input().split()))
a = sorted(a)
print(a[k-1])



'''
Test Cases -------
5 4
7 10 4 20 15
Output: 15



input2:
6 3
7 10 4 3 20 15
Output: 7
'''