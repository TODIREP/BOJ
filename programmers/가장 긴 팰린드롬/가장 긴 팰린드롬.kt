class Solution {
    fun solution(s: String): Int {
        var answer = 0
        val size = s.length
        fun search(l: Int, r: Int, c: Int): Int {
            var cur = c
            var left = l
            var right = r
            while ((left >= 0) and (right < size)) {
                if (s[left] == s[right]) {
                    cur += 2
                    left--
                    right++
                } else {
                    break
                }
            }
            return cur
        }
        repeat(size) { index -> 
            val a = search(index, index + 1, 0)
            val b = search(index - 1, index + 1, 1)
            answer = answer.coerceAtLeast(a.coerceAtLeast(b))
        }
        return answer
    }
}