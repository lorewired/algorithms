n = int(input())
def fib(num: int) -> int:
    if num == 2: return 1
    if num == 1: return 0
    return fib(num-1) + fib(num-2)
print(fib(n))