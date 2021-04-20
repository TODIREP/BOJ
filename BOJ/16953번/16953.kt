import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val limit = 1000000
    val (a, b) = readLine().split(" ").map(String::toLong)
    val tree = TreeMap<Long, Int>()
    val queue = PriorityQueue<Long>()
    tree[a] = 0
    queue.add(a)

    while (queue.isNotEmpty()) {
        val cur = queue.remove()
        if (cur >= b) break
        val next = tree.getOrDefault(cur, 0) + 1

        longArrayOf(cur * 2, cur * 10 + 1).forEach { nextNum ->
            val nextCnt = tree.getOrDefault(nextNum, limit)
            if (next < nextCnt) {
                tree[nextNum] = next
                queue.add(nextNum)
            }
        }
    }
    bw.write("${tree.getOrDefault(b, -2) + 1}")
    bw.close()
}