import java.util.*
class Solution {
    fun solution(n: Int, edge: Array<IntArray>): Int {
        val dis = IntArray(n) { 30000 }
        dis[0] = 1
        
        val queue: Queue<Int> = LinkedList()
        queue.add(0)
        
        val link = Array(n) { mutableListOf<Int>() }
        edge.forEach {
            link[it[0] - 1].add(it[1] - 1)
            link[it[1] - 1].add(it[0] - 1)
        }
        
        var maximum = 1
        while (queue.isNotEmpty()) {
            val current = queue.remove()
            for (nxt in link[current]) {
                if (dis[current] + 1 < dis[nxt]) {
                    dis[nxt] = dis[current] + 1
                    maximum = Math.max(maximum, dis[nxt])
                    queue.add(nxt)
                }
            }
        }
        
        var answer = 0
        repeat(n) {
            if (dis[it] == maximum) answer++
        }
        return answer
    }
}