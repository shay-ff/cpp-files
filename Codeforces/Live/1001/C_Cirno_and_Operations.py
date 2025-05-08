def max_sequence_sum(arr):
    n = len(arr)
    
    # Initialize max sum tracking
    max_sum = max(arr)
    
    # If single element, return it directly
    if n == 1:
        return max_sum
    
    # Compute all possible transformations
    current = arr.copy()
    
    # Track seen sequences to prevent infinite loops
    seen = set(tuple(current))
    stack = [current]
    
    while stack:
        current = stack.pop()
        
        # Update max sum
        max_sum = max(max_sum, sum(current))
        
        # Stop if sequence is of length 1
        if len(current) == 1:
            continue
        
        # Reverse operation
        reversed_seq = current[::-1]
        rev_tuple = tuple(reversed_seq)
        if rev_tuple not in seen and len(reversed_seq) > 1:
            seen.add(rev_tuple)
            stack.append(reversed_seq)
        
        # Difference sequence operation
        diff_seq = [current[i+1] - current[i] for i in range(len(current)-1)]
        diff_tuple = tuple(diff_seq)
        if diff_tuple not in seen and len(diff_seq) > 1:
            seen.add(diff_tuple)
            stack.append(diff_seq)
    
    return max_sum

# Process multiple test cases
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    print(max_sequence_sum(arr))