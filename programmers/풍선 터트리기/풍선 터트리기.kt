class Solution {
    fun solution(a: IntArray): Int {
        var answer: Int = 0
        val size = a.size
        var treeSize = 1
        while (treeSize < size) {
            treeSize *= 2
        }
        val tree = IntArray(treeSize * 2) { 1000000001 }
        repeat(size) { index -> 
            tree[treeSize + index] = a[index]
        }
        for (index in treeSize - 1 downTo 1) {
            tree[index] = tree[index * 2].coerceAtMost(tree[index * 2 + 1])
        }
        fun getMin(node: Int, left: Int, right: Int, start: Int, end: Int): Int {
            return when {
                (left > end) or (right < start) -> 1000000001
                (left <= start) and (end <= right) -> tree[node]
                else -> {
                    val mid = (start + end) / 2
                    getMin(node * 2, left, right, start, mid).coerceAtMost(getMin(node * 2 + 1, left, right, mid + 1, end))
                }
            }
        }
        repeat(size) { index -> 
            val left = getMin(1, 0, index - 1, 0, treeSize - 1)
            val right = getMin(1, index + 1, treeSize - 1, 0, treeSize - 1)
            if ((a[index] < left) or (a[index] < right)) {
                answer++
            }
        }
        return answer
    }
}