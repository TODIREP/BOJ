import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    fun getInput() = readLine().split(" ")

    val (n, m, k) = getInput().map { it.toInt() }
    var treeSize = 1
    while (treeSize < n) {
        treeSize *= 2
    }
    val tree = MutableList<Long>(treeSize * 2) { 0 }
    fun init() {
        for (i in 0 until n) {
            tree[treeSize + i] = readLine().toLong()
        }
        for (index in treeSize - 1 downTo 1) {
            tree[index] = tree[index * 2] + tree[index * 2 + 1]
        }
    }
    fun sum(node: Int, left: Int, right: Int, start: Int, end: Int): Long {
        return when {
            (left > end) or (right < start) -> 0
            (left <= start) and (end <= right) -> tree[node]
            else -> {
                val mid = (start + end) / 2
                sum(node * 2, left, right, start, mid) + sum(node * 2 + 1, left, right, mid + 1, end)
            }
        }
    }
    fun update(i: Int, num: Long) {
        var index = i + treeSize
        tree[index] = num
        while (index > 1) {
            index /= 2
            tree[index] = tree[index * 2] + tree[index * 2 + 1]
        }
    }
    init()

    for (i in 0 until (m + k)) {
        val (a, b, c) = getInput().map { it.toLong() }
        when (a.toInt()) {
            1 -> {
                update(b.toInt() - 1, c)
            }
            else -> {
                val queryRes = sum(1, b.toInt() - 1, c.toInt() - 1, 0, treeSize - 1)
                bufferedWriter.write("$queryRes\n")
            }
        }
    }
    bufferedWriter.close()
}
fun main() {
    solution()
}