class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size *= 2
        # initialize tree and lazy arrays
        self.tree = [float('-inf')] * (2 * self.size)
        self.lazy = [0] * (2 * self.size)
        # Build leaves (we use 0-indexed positions for the leaves)
        for i in range(self.n):
            self.tree[self.size + i] = data[i]
        for i in range(self.n, self.size):
            self.tree[self.size + i] = float('-inf')
        for i in range(self.size - 1, 0, -1):
            self.tree[i] = max(self.tree[2 * i], self.tree[2 * i + 1])
    
    def _apply(self, idx, val):
        self.tree[idx] += val
        self.lazy[idx] += val

    def _push(self, idx):
        # Push lazy value from node idx to its children.
        if self.lazy[idx]:
            self._apply(2 * idx, self.lazy[idx])
            self._apply(2 * idx + 1, self.lazy[idx])
            self.lazy[idx] = 0

    def update_range(self, l, r, val, idx=1, left_bound=0, right_bound=None):
        if right_bound is None:
            right_bound = self.size - 1
        if r < left_bound or l > right_bound:
            return
        if l <= left_bound and right_bound <= r:
            self._apply(idx, val)
            return
        self._push(idx)
        mid = (left_bound + right_bound) // 2
        self.update_range(l, r, val, 2 * idx, left_bound, mid)
        self.update_range(l, r, val, 2 * idx + 1, mid + 1, right_bound)
        self.tree[idx] = max(self.tree[2 * idx], self.tree[2 * idx + 1])

    def query_range(self, l, r, idx=1, left_bound=0, right_bound=None):
        if right_bound is None:
            right_bound = self.size - 1
        if r < left_bound or l > right_bound:
            return float('-inf')
        if l <= left_bound and right_bound <= r:
            return self.tree[idx]
        self._push(idx)
        mid = (left_bound + right_bound) // 2
        return max(
            self.query_range(l, r, 2 * idx, left_bound, mid),
            self.query_range(l, r, 2 * idx + 1, mid + 1, right_bound)
        )


def max_distinct_sum_segment_tree(arr):
    n = len(arr)
    if n < 3:
        return 0

    # Precompute prefix: prefix[i] = distinct(arr[0..i])
    prefix = [0] * n
    seen = {}
    distinct = 0
    for i in range(n):
        if arr[i] not in seen:
            distinct += 1
        seen[arr[i]] = seen.get(arr[i], 0) + 1
        prefix[i] = distinct

    # Precompute suffix: suffix[i] = distinct(arr[i..n-1])
    suffix = [0] * n
    seen = {}
    distinct = 0
    for i in range(n - 1, -1, -1):
        if arr[i] not in seen:
            distinct += 1
        seen[arr[i]] = seen.get(arr[i], 0) + 1
        suffix[i] = distinct

    # Our re–formulation (using 0-indexing for arr):
    # We choose indices i and j with 0 <= i < j-1, so that:
    #   left = arr[0..i]         (distinct = prefix[i])
    #   middle = arr[i+1..j-1]     (we want to compute its distinct count quickly)
    #   right = arr[j..n-1]        (distinct = suffix[j])
    #
    # Let L = i+1 and m = j-1. Then valid L are in [1, m] (with L >= 1 so that left is non–empty)
    # and m can vary from 1 to n-2. We want to compute:
    #   DP(m) = max_{L in [2, m+1]} { prefix[L-2] + distinct(arr[L..m]) }
    # (Here we use 1-indexing for the partitioning; equivalently, if we set x = L-1, then x ranges from 1 to m-1.)
    #
    # For our implementation we re–parameterize:
    # Let x = i (0-indexed, the last index of the left segment). Then the middle segment is arr[x+1 .. m-1]
    # and the candidate is: prefix[x] + distinct(arr[x+1 .. m-1]) + suffix[m].
    # We want to maximize over x in [0, m-2] for m in [2, n-1].
    #
    # We will maintain an array F[x] for x in [0, n-1] where initially F[x] = prefix[x].
    # As m (the right segment start) increases from 2 to n-1,
    # a new element arr[m-1] is added to the middle segment.
    # Let p be the previous occurrence (in arr) of arr[m-1] among indices in the middle part.
    # Then for every x with x such that x+1 > p (i.e. x >= p) the middle segment [x+1, m-1] gets one extra distinct.
    #
    # We use a segment tree (over indices x = 0..n-1) to support range–addition updates and range–maximum queries.
    #
    # Valid x for a given m are 0 <= x <= m-2 (because middle must be non–empty).
    data = prefix[:]  # data[x] corresponds to the value for left ending at index x.
    seg = SegmentTree(data)
    last_occ = {}  # tracks last occurrence (0-indexed) of elements in the middle part.
    ans = 0
    # m will be the starting index of the right segment. For a valid partition, m must be at least 2.
    for m in range(2, n):
        # New element in the middle segment is arr[m-1]
        x_val = arr[m - 1]
        # p is the last occurrence of x_val (if never seen in the middle, use -1)
        p = last_occ.get(x_val, -1)
        # For every x in [max(p, 0), m-2] the new element is counted as a new distinct element.
        l_range = max(p, 0)
        r_range = m - 2
        if l_range <= r_range:
            seg.update_range(l_range, r_range, 1)
        last_occ[x_val] = m - 1

        # For the current m, valid x are in [0, m-2]. Query the maximum DP value.
        if m - 2 >= 0:
            dp_val = seg.query_range(0, m - 2)
            # The candidate sum is dp_val (which is prefix[x] + distinct in middle) plus suffix[m]
            candidate = dp_val + suffix[m]
            ans = max(ans, candidate)
    return ans


# For testing:
def main():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    n = int(data[0])
    arr = list(map(int, data[1:1+n]))
    print(max_distinct_sum_segment_tree(arr))


if __name__ == '__main__':
    main()
