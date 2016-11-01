out="""1 1
1 2
1 3
2 2
2 3
2 4
3 3
3 4
3 5
4 4
4 5
4 6
5 5
5 6
5 1
6 6
6 1
6 2
1 4
2 5
3 6
4 1
5 2
6 3
1 5
2 6
3 1
4 2
5 3
6 4"""

count = {}
for x in out.split('\n'):
    (a, b) = x.split(' ')
    k = (min(a, b), max(a, b))
    if k in count:
        count[k] += 1
    else:
        count[k] = 1


print(count)