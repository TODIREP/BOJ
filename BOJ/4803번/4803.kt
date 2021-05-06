import java.util.*
class Tree(private val treeSize: Int) {
    private val invalidTree = (-1e9).toInt()
    private val root = IntArray(treeSize) { -1 }
    private fun findRoot(node: Int): Int {
        return when (root[node] < 0) {
            true -> node
            false -> {
                root[node] = findRoot(root[node])
                root[node]
            }
        }
    }
    fun unionRoot(a: Int, b: Int) {
        val aRoot = findRoot(a)
        val bRoot = findRoot(b)
        return when {
            aRoot == bRoot -> {
                root[aRoot] = invalidTree
                root[bRoot] = invalidTree
            }
            root[aRoot] == invalidTree || root[bRoot] == invalidTree -> {
                root[aRoot] = invalidTree
                root[bRoot] = invalidTree
            }
            else -> root[bRoot] = aRoot
        }
    }
    fun getTree(): Int {
        var count = 0
        for (it in 0 until treeSize) if (root[it] < 0 && root[it] != invalidTree) count++
        return count
    }
}
fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    var turn = 1
    while (true) {
        var token = StringTokenizer(readLine())
        val n = token.nextToken().toInt()
        val m = token.nextToken().toInt()
        if (n == 0 && m == 0) break
        val tree = Tree(n)
        for (it in 0 until m) {
            token = StringTokenizer(readLine())
            val a = token.nextToken().toInt() - 1
            val b = token.nextToken().toInt() - 1
            tree.unionRoot(a, b)
        }
        val count = tree.getTree()
        bw.write("Case ${turn++}: ${
            when (count) {
                0 -> "No trees."
                1 -> "There is one tree."
                else -> "A forest of $count trees."
            }
        }\n")
    }
    bw.close()
}