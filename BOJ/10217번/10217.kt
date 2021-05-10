import java.util.*
data class Link(val start: Int, val price: Int, val time: Int): Comparable<Link> {
    override fun compareTo(other: Link) = time - other.time
}
fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val t = readLine().toInt()
    val limit = 1e9.toInt()
    for (it in 0 until t) {
        var token = StringTokenizer(readLine())
        val n = token.nextToken().toInt()
        val m = token.nextToken().toInt()
        val k = token.nextToken().toInt()

        val node = Array(n) { mutableListOf<Link>() }
        val take = Array(n) { IntArray(m + 1) { limit } }

        for (ticket in 0 until k) {
            token = StringTokenizer(readLine())
            val u = token.nextToken().toInt() - 1
            val v = token.nextToken().toInt() - 1
            val c = token.nextToken().toInt()
            val d = token.nextToken().toInt()
            node[u].add(Link(v, c, d))
        }
        val queue = PriorityQueue<Link>()
        take[0][m] = 0
        queue.add(Link(0, m, take[0][m]))

        while (queue.isNotEmpty()) {
            val cur = queue.peek().start
            val curPrice = queue.peek().price
            val curTime = queue.remove().time

            if (curTime != take[cur][curPrice]) continue

            for (move in node[cur]) {
                val nextTime = curTime + move.time
                if (curPrice < move.price) continue

                if (nextTime < take[move.start][curPrice - move.price]) {
                    take[move.start][curPrice - move.price] = nextTime
                    queue.add(Link(move.start, curPrice - move.price, nextTime))
                }
            }
        }
        var answer = limit
        for (ticket in 0..m) {
            if (take[n - 1][ticket] < limit) answer = answer.coerceAtMost(take[n - 1][ticket])
        }
        bw.write("${
            if (answer == limit) "Poor KCM"
            else answer
        }\n")
    }
    bw.close()
}