import java.util.*
fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val limit = 1e9.toInt()
    val n = readLine().toInt()
    val arr = Array(n) { IntArray(n) }
    for (x in 0 until n) {
        val token = StringTokenizer(readLine())
        for (y in 0 until n) arr[x][y] = token.nextToken().toInt()
    }
    val state = readLine()
    var start = 0
    var count = 0
    for (it in state.indices) if (state[it] == 'Y') {
        start = start or (1 shl it)
        count++
    }
    val p = readLine().toInt()
    val result = Array(n + 1) { IntArray(1 shl n) { limit } }
    var answer = limit
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    result[count][start] = 0
    queue.add(Pair(count, start))

    while (queue.isNotEmpty()) {
        val curCount = queue.peek().first
        val current = queue.remove().second

        if (curCount >= p) {
            answer = answer.coerceAtMost(result[curCount][current])
            continue
        }

        for (it in 0 until n) {
            if (current and (1 shl it) > 0) {
                for (index in 0 until n) {
                    if (current and (1 shl index) > 0) continue
                    val next = current or (1 shl index)
                    val nextResult = result[curCount][current] + arr[it][index]
                    if (nextResult < result[curCount + 1][next]) {
                        result[curCount + 1][next] = nextResult
                        queue.add(Pair(curCount + 1, next))
                    }
                }
            }
        }
    }
    bw.write("${if (answer == limit) -1 else answer}")
    bw.close()
}