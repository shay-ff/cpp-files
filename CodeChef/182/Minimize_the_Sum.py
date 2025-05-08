import sys
from bisect import bisect_right

def main():
    input_data = sys.stdin.buffer.read().split()
    t = int(input_data[0])
    index = 1
    output_lines = []
    for _ in range(t):
        N = int(input_data[index]); index += 1
        grid = []
        max_val = 0
        for _ in range(N):
            row = list(map(int, input_data[index:index+N]))
            index += N
            grid.append(row)
            max_val = max(max_val, max(row))
        
        # Pre-sort each row and compute prefix sums.
        sorted_rows = []
        prefix_sums = []
        for row in grid:
            sr = sorted(row)
            sorted_rows.append(sr)
            ps = [0]
            for x in sr:
                ps.append(ps[-1] + x)
            prefix_sums.append(ps)
        
        # Build candidate set.
        candidates = set()
        candidates.add(1)
        # It is enough to use the cell values from all rows.
        for r in grid:
            for x in r:
                candidates.add(x)
                # x+1 is also a candidate (this is when a tree "switches" from being counted by its height to being truncated)
                candidates.add(x+1)
        # Also add max_val explicitly (if not already)
        candidates.add(max_val)
        
        cand_list = sorted(candidates)
        
        # For each row, we will simulate a pointer (current count) and running sum.
        # We store for each row: pointer[i] and current_sum[i]
        N_rows = N
        pointers = [0] * N_rows  # pointer for each row in its sorted list
        cur_sums = [0] * N_rows  # current sum for each row

        best_score = -1
        best_K = None

        # Sweep over candidate values in ascending order.
        for K in cand_list:
            # For each row, update pointer and running sum where tree heights become <= K.
            for i in range(N_rows):
                # Move pointer while we have trees <= K.
                sr = sorted_rows[i]
                ps = prefix_sums[i]
                while pointers[i] < N and sr[pointers[i]] <= K:
                    pointers[i] += 1
                    # Using pointer as index in prefix sum array: cur_sums[i] becomes ps[pointers[i]]
                    # (We could update incrementally, but note that we already have a prefix-sum array.)
                # The current running sum for row i is then:
                # (prefix sum up to pointers[i])
                # and the remaining trees (from pointers[i] to N) all contribute K each.
                # We do not update cur_sums[i] incrementally here since we can use prefix sums:
                #   f(i,K) = prefix_sums[i][pointers[i]] + K * (N - pointers[i])
                # (The pointers for each row only move forward as K increases.)
            # Compute f for row 1:
            f1 = prefix_sums[0][pointers[0]] + K * (N - pointers[0])
            score = 0
            for i in range(1, N_rows):
                fi = prefix_sums[i][pointers[i]] + K * (N - pointers[i])
                if fi > f1:
                    score += 1
            # Update best answer if needed.
            if score > best_score:
                best_score = score
                best_K = K
            # (If score equals best_score, best_K remains as the smaller candidate, because our candidates are sorted.)
        
        output_lines.append(str(best_K))
    sys.stdout.write("\n".join(output_lines))


if __name__ == '__main__':
    main()
