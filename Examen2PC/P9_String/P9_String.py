"""
	autor: Joel Perca
	problema: String de Beecrowd https://www.beecrowd.com.br/judge/en/runs/code/25455085
"""

def best_array_fixed_k( arr, length, k ):
    _sum = 0
    best = 0
    for x in range( 0, length ):
        _sum = _sum + arr[x%(len(arr))]
        if x >= k:
            _sum = _sum - arr[(x - k)%(len(arr))]
        if x >= k - 1:
            best = max( best, _sum )
    return best

def max_sum( arr, length, k):
    best = 0
    for x in range( 1, k + 1):
        best = max( best, best_array_fixed_k(arr, length, x ) )
    return best

while(True):
	line = input()
	m = int(line) * 10
	if line == "":
		break
	arr = list(map(lambda x: int(x), input().split()))
	print(max_sum(arr, len(arr) * 2, m) % 100000000)