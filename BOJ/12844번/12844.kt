import java.io.IOException
import java.util.*

class SegmentTree(array: IntArray) {
    private val treeSize = 1 shl 19
    private val tree = IntArray(treeSize * 2) { 0 }
    private val lazy = IntArray(treeSize * 2) { 0 }

    init {
        for (index in array.indices) tree[index + treeSize] = array[index]
        for (index in treeSize - 1 downTo 1) tree[index] = tree[index * 2] xor tree[index * 2 + 1]
    }

    private fun propagate(node: Int, left: Int, right: Int) {
        when {
            lazy[node] == 0 -> return
            left == right -> tree[node] = tree[node] xor lazy[node]
            left < right -> {
                lazy[node * 2] = lazy[node * 2] xor lazy[node]
                lazy[node * 2 + 1] = lazy[node * 2 + 1] xor lazy[node]
            }
        }
        lazy[node] = 0
    }

    fun update(left: Int, right: Int, value: Int) = update(1, left, right, value, 0, treeSize - 1)
    private fun update(node: Int, left: Int, right: Int, value: Int, start: Int, end: Int) {
        propagate(node, start, end)
        when {
            left > end || right < start -> return
            left <= start && end <= right -> {
                lazy[node] = lazy[node] xor value
                propagate(node, start, end)
            }
            else -> {
                val mid = (start + end) / 2
                update(node * 2, left, right, value, start, mid)
                update(node * 2 + 1, left, right, value, mid + 1, end)
                tree[node] = tree[node * 2] xor tree[node * 2 + 1]
            }
        }
    }

    fun query(left: Int, right: Int): Int = query(1, left, right, 0, treeSize - 1)
    private fun query(node: Int, left: Int, right: Int, start: Int, end: Int): Int {
        propagate(node, start, end)
        return when {
            left > end || right < start -> 0
            left <= start && end <= right -> tree[node]
            else -> {
                val mid = (start + end) / 2
                query(node * 2, left, right, start, mid) xor query(node * 2 + 1, left, right, mid + 1, end)
            }
        }
    }
}

fun main() {
    val io = FastIo()
    val n = io.nextInt()
    val array = IntArray(n)
    for (index in 0 until n) array[index] = io.nextInt()
    val segTree = SegmentTree(array)
    repeat(io.nextInt()) {
        when (io.nextInt()) {
            1 -> segTree.update(io.nextInt(), io.nextInt(), io.nextInt())
            else -> io.print("${segTree.query(io.nextInt(), io.nextInt())}\n")
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