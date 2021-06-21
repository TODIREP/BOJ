import java.util.*
import java.io.*
fun main() {
    val io = FastIo()
    val limit = 1e18.toLong()
    repeat(io.nextInt()) {
        val n = io.nextInt()
        val m = io.nextInt()
        val w = io.nextInt()
        val link = Array(n) { mutableListOf<Pair<Int, Long>>() }
        val distance = LongArray(n) { limit }
        var returnable = false
        repeat(m) {
            val s = io.nextInt() - 1
            val e = io.nextInt() - 1
            val t = io.nextLong()
            link[s].add(Pair(e, t))
            link[e].add(Pair(s, t))
        }
        repeat(w) {
            link[io.nextInt() - 1].add(Pair(io.nextInt() - 1, -io.nextLong()))
        }
        repeat(n) { turns ->
            repeat(n) { start ->
                repeat(link[start].size) { index ->
                    val next = link[start][index].first
                    val dis = link[start][index].second

                    if (distance[start] + dis < distance[next]) {
                        distance[next] = distance[start] + dis
                        if (turns == n - 1) returnable = true
                    }
                }
            }
        }
        io.print(when (returnable) {
            true -> "YES\n"
            false -> "NO\n"
        })
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