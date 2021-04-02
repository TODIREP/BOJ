import java.util.*
class Solution {
    data class link(val start: Int, val next: Int, val distance: Int)
    
    fun solution(n: Int, costs: Array<IntArray>): Int {
        var answer = 0
        val arr = mutableListOf<link>()
        
        costs.forEach {
            val start = it[0]
            val next = it[1]
            val dis = it[2]
            arr.add(link(start, next, dis))
        }
        arr.sortWith(compareBy { it.distance } )
        
        val root = IntArray(n) { -1 }
        fun findRoot(num: Int): Int {
            when {
                root[num] < 0 -> return num
                else -> {
                    root[num] = findRoot(root[num])
                    return root[num]
                }
            }
        }
        fun unionRoot(a: Int, b: Int): Boolean {
            val aRoot = findRoot(a)
            val bRoot = findRoot(b)
            when (aRoot == bRoot) {
                true -> return false
                false -> {
                    root[bRoot] = aRoot
                    return true
                }
            }
        }
        for (value in arr) {
            if (unionRoot(value.start, value.next)) {
                answer += value.distance
            }
        }
        return answer
    }
}