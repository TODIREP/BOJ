import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, t, g) = readLine().split(" ").map(String::toInt)
    val queue: Queue<Int> = LinkedList()
    val dis = IntArray(100000) { 1000000 }
    dis[n] = 0
    queue.add(n)

    while (queue.isNotEmpty()) {
        val cur = queue.remove()
        if (cur == 99999) continue

        if (dis[cur] + 1 < dis[cur + 1]) {
            dis[cur + 1] = dis[cur] + 1
            queue.add(cur + 1)
        }

        if (cur > 0) {
            var next = cur * 2
            if (next > 99999) continue
            var delta = 1
            while (delta * 10 <= next) delta *= 10
            next -= delta
            if (dis[cur] + 1 < dis[next]) {
                dis[next] = dis[cur] + 1
                queue.add(next)
            }
        }
    }
    bw.write("${if (dis[g] <= t) dis[g] else "ANG"}")
    bw.close()
}

fun main() {
    solution()
}