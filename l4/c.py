import sys

def solve():

    try:
        l, d, n = map(int, sys.stdin.readline().split())
    except ValueError:
        return

    total_new_birds = 0
    first_available = 6
    last_available = l - 6

    if n == 0:
        start_pos = first_available
        end_pos = last_available
        
        if end_pos >= start_pos:
            total_new_birds = (end_pos - start_pos) // d + 1
    
    else:
        birds = []
        for _ in range(n):
            birds.append(int(sys.stdin.readline()))

        birds.sort()

        start_pos = first_available
        end_pos = birds[0] - d
        if end_pos >= start_pos:
            total_new_birds += (end_pos - start_pos) // d + 1

        for i in range(n - 1):
            start_pos = birds[i] + d
            end_pos = birds[i+1] - d
            if end_pos >= start_pos:
                total_new_birds += (end_pos - start_pos) // d + 1
        
        start_pos = birds[n-1] + d
        end_pos = last_available
        if end_pos >= start_pos:
            total_new_birds += (end_pos - start_pos) // d + 1

    print(total_new_birds)

solve()