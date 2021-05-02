class SegmentTree(private val treeSize: Int, array: IntArray) {
    private val minValue = 0
    private val maxValue = 1e9.toInt() + 1
    private val maxTree = IntArray(treeSize * 2) { minValue }
    private val minTree = IntArray(treeSize * 2) { maxValue }

    init {
        val size = array.size
        for (index in 0 until size) {
            maxTree[index + treeSize] = array[index]
            minTree[index + treeSize] = array[index]
        }
        for (index in treeSize - 1 downTo 1) {
            maxTree[index] = maxTree[index * 2].coerceAtLeast(maxTree[index * 2 + 1])
            minTree[index] = minTree[index * 2].coerceAtMost(minTree[index * 2 + 1])
        }
    }
    fun getResult(left: Int, right: Int): Pair<Int, Int> = getResult(1, left, right, 0, treeSize - 1)
    private fun getResult(node: Int, left: Int, right: Int, start: Int, end: Int): Pair<Int, Int> {
        return when {
            left > end || right < start -> Pair(minValue, maxValue)
            left <= start && end <= right -> Pair(maxTree[node], minTree[node])
            else -> {
                val mid = (start + end) / 2
                val leftNode = getResult(node * 2, left, right, start, mid)
                val rightNode = getResult(node * 2 + 1, left, right, mid + 1, end)
                Pair((leftNode.first).coerceAtLeast(rightNode.first), (leftNode.second).coerceAtMost(rightNode.second))
            }
        }
    }
}
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, m) = br.readLine().split(" ").map(String::toInt)
    val array = IntArray(n)
    for (it in 0 until n) array[it] = br.readLine().toInt()
    var treeSize = 1
    while (treeSize < n) treeSize *= 2
    val st = SegmentTree(treeSize, array)
    for (it in 0 until m) {
        val (a, b) = br.readLine().split(" ").map(String::toInt)
        val result = st.getResult(a - 1, b - 1)
        bw.write("${result.second} ${result.first}\n")
    }
    bw.close()
}