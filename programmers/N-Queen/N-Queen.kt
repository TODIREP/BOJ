class Solution {
    fun solution(n: Int): Int {
        var answer = 0
        val verticalCheck = BooleanArray(n) { false }
        val leftCross = BooleanArray(n * 2 - 1) { false }
        val rightCross = BooleanArray(n * 2 - 1) { false }
        
        fun search(x: Int) {
            if (x >= n) {
                answer++
                return
            }
            repeat(n) loop@ { y -> 
                if (verticalCheck[y] or leftCross[x - y + n - 1] or rightCross[x + y]) return@loop
                verticalCheck[y] = true
                leftCross[x - y + n - 1] = true
                rightCross[x + y] = true
                search(x + 1)
                verticalCheck[y] = false
                leftCross[x - y + n - 1] = false
                rightCross[x + y] = false
            }
        }
        search(0)
        return answer
    }
}