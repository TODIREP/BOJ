import java.util.*
class Solution {
    fun solution(n: Int, computers: Array<IntArray>): Int {
        var answer = 0
        
        val queue: Queue<Int> = LinkedList()
        repeat(n) { x -> 
            repeat(n) { y ->
                if (computers[x][y] == 1) {
                    computers[x][y] = 0
                    queue.add(x)
                    answer++
                    
                    while (queue.isNotEmpty()) {
                        val cur: Int = queue.remove()
                        
                        computers[cur].forEachIndexed { index, nxt ->
                            if (nxt == 1) {
                                computers[cur][index] = 0
                                queue.add(index)
                            }
                        }
                    }
                }
            }
        }
        return answer
    }
}