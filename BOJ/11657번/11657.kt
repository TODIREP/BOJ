import java.util.*
import java.io.*
fun main() {
    val io = FastIo()
    val n = io.nextInt()
    val limit = 1e18.toLong()
    val link = Array(n) { mutableListOf<Pair<Int, Long>>() }
    val distance = LongArray(n) { limit }
    var valid = true
    distance[0] = 0
    repeat(io.nextInt()) {
        link[io.nextInt() - 1].add(Pair(io.nextInt() - 1, io.nextLong()))
    }
    repeat(n) { turns ->
        repeat(n) { start ->
            repeat(link[start].size) { index ->
                val next = link[start][index].first
                val dis = link[start][index].second

                if (distance[start] != limit) {
                    if (distance[start] + dis < distance[next]) {
                        distance[next] = distance[start] + dis
                        if (turns == n - 1) valid = false
                    }
                }
            }
        }
    }
    when (valid) {
        true -> {
            for (index in 1 until n) {
                io.print("${
                    when (distance[index]) {
                        limit -> -1
                        else -> distance[index]
                    }
                }\n")
            }
        }
        false -> io.print("-1")
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