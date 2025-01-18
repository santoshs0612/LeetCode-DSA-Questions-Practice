class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        minHeap = []

        heapq.heapify(minHeap)

        for num in nums:
            heapq.heappush(minHeap,num)
            if len(minHeap) >k:
                heapq.heappop(minHeap)
        
        return heapq.heappop(minHeap)