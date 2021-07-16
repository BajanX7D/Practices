class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        window = OrderedDict() # <bucket>: <value>
        
        for num in nums:
            if len(window) > k:
                window.popitem(last=False) # popleft

            bucket = num // (t or 1) # all candidate nums will hash to this bucket. or 1 for division by zero case
            for complement in range(bucket - 1, bucket + 2):
                if complement in window and abs(num - window[complement]) <= t:
                    return True
            
            window[bucket] = num
            
        return False
        
