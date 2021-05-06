import java.util.*
class Solution {
    fun solution(gems: Array<String>): IntArray {
        val boseok = TreeSet<String>()
        gems.forEach { boseok.add(it) }
        val size = boseok.size
        var al = 0
        var ar = gems.size
        
        var count = 0
        var left = 0
        var right = 0
        val gem = TreeMap<String, Int>()
        while (left <= right) {
            if (count == size) {
                if (right - left < ar - al) {
                    al = left
                    ar = right
                }
                val value = gem.getOrDefault(gems[left], 0)
                if (value == 1) count--
                gem[gems[left++]] = value - 1
            } else {
                if (right == gems.size) break
                val value = gem.getOrDefault(gems[right], 0)
                if (value == 0) count++
                gem[gems[right++]] = value + 1
            }
        }
        return intArrayOf(al + 1, ar)
    }
}