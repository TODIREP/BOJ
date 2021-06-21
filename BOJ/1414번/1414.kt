import java.util.*
import java.io.*
class Mst(size: Int) {
    private val root = IntArray(size) { -1 }
    private val link = mutableListOf<Computer>()
    private var totalLAN = 0
    private fun findRoot(node: Int): Int {
        return when (root[node] < 0) {
            true -> node
            else -> {
                root[node] = findRoot(root[node])
                root[node]
            }
        }
    }
    private fun unionRoot(a: Int, b: Int): Boolean {
        val aRoot = findRoot(a)
        val bRoot = findRoot(b)
        return when (aRoot == bRoot) {
            true -> false
            else -> {
                root[bRoot] = aRoot
                true
            }
        }
    }
    fun addLink(node: Int, nextNode: Int, distance: Int) {
        link.add(Computer(node, nextNode, distance))
        totalLAN += distance
    }
    fun makeMst(): Int {
        link.sort()
        repeat(link.size) {
            if (unionRoot(link[it].start, link[it].next)) totalLAN -= link[it].dis
        }
        return when (root.count { it < 0 } == 1) {
            true -> totalLAN
            false -> -1
        }
    }
    data class Computer(val start: Int, val next: Int, val dis: Int): Comparable<Computer> {
        override fun compareTo(other: Computer): Int {
            return dis - other.dis
        }
    }
}
fun main() {
    val io = FastIo()
    val n = io.nextInt()
    val mst = Mst(n)
    repeat(n) { x ->
        val lan = io.nextString()
        repeat(n) { y ->
            if (lan[y] != '0') {
                mst.addLink(x, y, when (lan[y] in 'a'..'z') {
                    true -> lan[y] - 'a' + 1
                    false -> lan[y] - 'A' + 27
                })
            }
        }
    }
    io.print("${mst.makeMst()}")
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