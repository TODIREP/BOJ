import java.util.*
class Solution {
    fun solution(nodeinfo: Array<IntArray>): Array<IntArray> {
        val node = nodeinfo.indices.groupBy { nodeinfo[it] }
            .toList()
            .sortedByDescending { it.first[1] }
            .sortedBy { it.first[0] }
            .toList()
            
        val child = TreeMap<Int, Int>()
        val level = node.sortedByDescending { it.first[1] }.map { it.first[1] }.toSet().toIntArray()
        val levelDepth = level.size
        for (index in 0 until levelDepth - 1) {
            child[level[index]] = level[index + 1]
        }
        
        fun getLeftLeaf(curHeight: Int, start: Int, end: Int): Int {
            if (start > end) return -1
            for (index in end downTo start) {
                val childHeight = child.getOrDefault(curHeight, -1)
                if ((childHeight == -1) or (node[index].first[1] > curHeight)) return -1
                if (node[index].first[1] == childHeight) {
                    return index
                }
            }
            return -1
        }
        
        fun getRightLeaf(curHeight: Int, start: Int, end: Int): Int {
            if (start > end) return -1
            for (index in start until end) {
                val childHeight = child.getOrDefault(curHeight, -1)
                if ((childHeight == -1) or (node[index].first[1] > curHeight)) return -1
                if (node[index].first[1] == childHeight) {
                    return index
                }
            }
            return -1
        }
        
        val size = nodeinfo.size
        val link = Array(size) { IntArray(2) { -1 } } // 0 : left, 1 : right
        val linkNumber = IntArray(size) { 0 }
        var rootNode = 0
        var rootHeight = 0
        
        node.forEachIndexed { index, value ->
            linkNumber[index] = value.second[0] + 1
            if (value.first[1] > rootHeight) {
                rootHeight = value.first[1]
                rootNode = index
            }
            val leftLeaf = getLeftLeaf(value.first[1], 0, index - 1)
            val rightLeaf = getRightLeaf(value.first[1], index + 1, size)
            link[index][0] = leftLeaf
            link[index][1] = rightLeaf
        }
        
        val pre = mutableListOf<Int>()
        fun preOrder(current: Int) {
            if (current == -1) return
            pre.add(linkNumber[current])
            preOrder(link[current][0])
            preOrder(link[current][1])
        }
        
        val post = mutableListOf<Int>()
        fun postOrder(current:Int) {
            if (current == -1) return
            postOrder(link[current][0])
            postOrder(link[current][1])
            post.add(linkNumber[current])
        }
        
        preOrder(rootNode)
        postOrder(rootNode)
        return arrayOf(pre.toIntArray(), post.toIntArray())
    }
}