import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val limit = 1e9.toInt()
    val n = br.readLine().toInt()
    val price = Array(n) { IntArray(n) }
    val dis = Array(n) { IntArray(1 shl n) { -1 } }
    for (x in 0 until n) {
        val token = StringTokenizer(br.readLine())
        for (y in 0 until n) price[x][y] = token.nextToken().toInt()
    }
    fun search(cur: Int, visit: Int): Int {
        if (dis[cur][visit] != -1) return dis[cur][visit]
        if (visit == (1 shl n) - 1) {
            if (price[cur][0] != 0) return price[cur][0]
            return limit
        }
        var value = limit
        for (it in 0 until n) {
            if (visit and (1 shl it) != 0) continue
            if (price[cur][it] == 0) continue
            value = value.coerceAtMost(search(it, visit or (1 shl it)) + price[cur][it])
        }
        dis[cur][visit] = value
        return dis[cur][visit]
    }
    bw.write("${search(0, 1)}")
    bw.close()
}