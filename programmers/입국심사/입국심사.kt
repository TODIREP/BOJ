class Solution {
    fun solution(n: Int, times: IntArray): Long {
        var left: Long = 0
        var right: Long = times.max()!!.toLong() * n
        
        while (left < right) {
            val mid: Long = (left + right) / 2
            var count: Long = 0
            for (time in times) {
                count += (mid / time)
            }
            if (count >= n) right = mid
            else left = mid + 1
        }
        return left
    }
}