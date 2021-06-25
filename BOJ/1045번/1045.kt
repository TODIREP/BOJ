import java.io.IOException
import java.util.*

class Mst(private val road: Array<Pair<Int, Int>>, private val citySet: Int, city: Int) {
    private val root = IntArray(city) { -1 }
    private val result = IntArray(city) { 0 }
    private fun findRoot(node: Int): Int {
        return when (root[node] < 0) {
            true -> node
            false -> {
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
            false -> {
                root[bRoot] = aRoot
                true
            }
        }
    }

    fun makeMst(): IntArray {
        var count = 0
        val check = BooleanArray(road.size)
        for (index in road.indices) {
            val (start, end) = road[index]
            if (unionRoot(start, end)) {
                check[index] = true
                result[start]++
                result[end]++
                count++
            }
        }
        for (index in road.indices) {
            when {
                count == citySet -> break
                check[index] -> continue
                else -> {
                    val (start, end) = road[index]
                    check[index] = true
                    result[start]++
                    result[end]++
                    count++
                }
            }
        }
        return when (root.count { it < 0 } == 1 && count == citySet) {
            true -> result
            false -> intArrayOf(-1)
        }
    }
}

fun main() {
    val io = FastIo()
    val (n, m) = io.nextInt() to io.nextInt()
    val link = mutableListOf<Pair<Int, Int>>()
    for (x in 0 until n) {
        val city = io.nextString()
        for (y in x until n) if (city[y] == 'Y') link.add(x to y)
    }
    val mst = Mst(link.toTypedArray(), m, n)
    io.print(mst.makeMst().joinToString(" "))
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