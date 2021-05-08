import java.util.*
class SegmentTree(size: Int, array: LongArray) {
    private var treeSize = 1
    private var tree: LongArray
    init {
        while (treeSize < size) treeSize *= 2
        tree = LongArray(treeSize * 2) { 1 }
        for (it in 0 until size) tree[treeSize + it] = array[it]
        for (it in treeSize - 1 downTo 1) tree[it] = (tree[it * 2] * tree[it * 2 + 1]) % mod
    }
    fun update(index: Int, num: Long) {
        var it = index + treeSize
        tree[it] = num
        while (it > 1) {
            it /= 2
            tree[it] = (tree[it * 2] * tree[it * 2 + 1]) % mod
        }
    }
    fun getSum(left: Int, right: Int) = getSum(1, left, right, 0, treeSize - 1)
    private fun getSum(node: Int, left: Int, right: Int, start: Int, end: Int): Long {
        return when {
            left > end || right < start -> 1
            left <= start && end <= right -> tree[node]
            else -> {
                val mid = (start + end) / 2
                (getSum(node * 2, left, right, start, mid) * getSum(node * 2 + 1, left, right, mid + 1, end)) % mod
            }
        }
    }
    companion object {
        private const val mod = (1e9 + 7).toLong()
    }
}
fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    var token = StringTokenizer(readLine())
    val n = token.nextToken().toInt()
    val m = token.nextToken().toInt() + token.nextToken().toInt()
    val array = LongArray(n)
    for (it in 0 until n) array[it] = readLine().toLong()
    val segmentTree = SegmentTree(n, array)
    for (it in 0 until m) {
        token = StringTokenizer(readLine())
        val a = token.nextToken().toInt()
        val b = token.nextToken().toInt()
        val c = token.nextToken().toLong()
        if (a == 1) segmentTree.update(b - 1, c)
        else bw.write("${segmentTree.getSum(b - 1, c.toInt() - 1)}\n")
    }
    bw.close()
}