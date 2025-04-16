from time import sleep

inp = input()
s = ''
for c in inp:
    s += c
    print(f"\r{s}", end='', flush=True)
    sleep(.08)