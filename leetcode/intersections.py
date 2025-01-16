class Exercise:
    nums1: list
    nums2: list

    def __init__(self, nums1, nums2):
        self.nums1 = nums1
        self.nums2 = nums2
        self.solve()

    def solve(self) -> set:
        return set(self.nums1).intersection(self.nums2)

ex = Exercise([4, 9, 5], [9, 4, 9, 8, 4])
inter = ex.solve()
for n in inter:
    print(n, " ")