import java.io.IOException
import java.util.*

class SegmentTree(array: LongArray) {
    private val treeSize = 1 shl 17
    private val tree = LongArray(treeSize * 2) { 0 }
    private val lazy = LongArray(treeSize * 2) { 0 }

    init {
        for (index in array.indices) tree[index + treeSize] = array[index]
        for (index in treeSize - 1 downTo 1) tree[index] = tree[index * 2] + tree[index * 2 + 1]
    }

    private fun propagate(node: Int, left: Int, right: Int) {
        when {
            lazy[node] == 0L -> return
            left < right -> {
                lazy[node * 2] += lazy[node]
                lazy[node * 2 + 1] += lazy[node]
            }
        }
        tree[node] += lazy[node] * (right - left + 1)
        lazy[node] = 0
    }

    fun getValue(index: Int) = getValue(1, index, 0, treeSize - 1)
    private fun getValue(node: Int, index: Int, start: Int, end: Int): Long {
        propagate(node, start, end)
        return when {
            index > end || index < start -> 0
            index in end..start -> tree[node]
            else -> {
                val mid = (start + end) / 2
                getValue(node * 2, index, start, mid) + getValue(node * 2 + 1, index, mid + 1, end)
            }
        }
    }

    fun update(left: Int, right: Int, value: Long) = update(1, left, right, value, 0, treeSize - 1)
    private fun update(node: Int, left: Int, right: Int, value: Long, start: Int, end: Int) {
        propagate(node, start, end)
        when {
            left > end || right < start -> return
            left <= start && end <= right -> {
                lazy[node] += value
                propagate(node, start, end)
            }
            else -> {
                val mid = (start + end) / 2
                update(node * 2, left, right, value, start, mid)
                update(node * 2 + 1, left, right, value, mid + 1, end)
                tree[node] = tree[node * 2] + tree[node * 2 + 1]
            }
        }
    }
}

fun main() {
    val io = FastIo()
    val n = io.nextInt()
    val array = LongArray(n)
    for (index in 0 until n) array[index] = io.nextLong()
    val segTree = SegmentTree(array)
    repeat(io.nextInt()) {
        when (io.nextInt()) {
            1 -> segTree.update(io.nextInt() - 1, io.nextInt() - 1, io.nextLong())
            else -> io.print("${segTree.getValue(io.nextInt() - 1)}\n")
        }
    }
    io.close()
}

class FastIo {
    private val br = System.`in`.bufferedReader()
    private val bw = System.out.bufferedWriter()
    private var token: StringTokenizer? = null
    private fun next(): String {
        while (token == null || !token!!.hasMoreElements()) {
            try {
                token = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }
        }
        return token!!.nextToken()
    }

    fun nextString() = next()
    fun nextInt() = next().toInt()
    fun nextLong() = next().toLong()
    fun nextDouble() = next().toDouble()
    fun nextLine(): String {
        val str = StringBuilder()
        try {
            str.append(br.readLine())
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return str.toString()
    }

    fun print(str: String) = bw.write(str)
    fun close() {
        br.close()
        bw.flush()
        bw.close()
    }
}