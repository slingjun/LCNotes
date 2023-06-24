from bisect import bisect_right, bisect_left
class HitCounter:

    def __init__(self):
        self.arr = []

    def hit(self, timestamp: int) -> None:
        self.arr.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        hit = bisect_right(self.arr, timestamp) - 1
        prev_5 = bisect_right(self.arr, timestamp-300)
        return 0 if hit == -1 else hit - prev_5 + 1
