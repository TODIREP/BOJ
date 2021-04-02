import java.util.*
class Solution {
    fun linkable(nodeA: String, nodeB: String): Boolean {
        var diff = 0
        val size = nodeA.length
        repeat(size) {
            if (nodeA[it] != nodeB[it]) diff++
        }
        return (diff == 1)
    }
    
    fun solution(begin: String, target: String, words: Array<String>): Int {
        var destination = -1
        val size = words.size
        val link = Array(size) { mutableListOf<Int>() }
        val dis = IntArray(size) { 60 }
        val queue: Queue<Int> = LinkedList()
        
        words.forEachIndexed { index1, word1 -> 
            if (word1 == target) destination = index1
            if (linkable(word1, begin)) {
                queue.add(index1)
                dis[index1] = 1
            }
            words.forEachIndexed next@ { index2, word2 -> 
                if (index1 == index2) return@next
                if (linkable(word1, word2)) {
                    link[index1].add(index2)
                    link[index2].add(index1)
                }
            }
        }
        if (destination == -1) return 0
        
        while (queue.isNotEmpty()) {
            val current = queue.remove()
            for (nxt in link[current]) {
                if (dis[current] + 1 < dis[nxt]) {
                    dis[nxt] = dis[current] + 1
                    queue.add(nxt)
                }
            }
        }
        return dis[destination]
    }
}