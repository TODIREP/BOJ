import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

data class Puzzle(val cx: Int, val cy: Int, val cur: String)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)
    val start = StringBuilder()
    val end = "123456780"
    var s = 0
    repeat(3) { x ->
        readLine().split(" ").forEachIndexed { y, num ->
            start.append(num)
            if (num == "0") s = x * 3 + y
        }
    }
    fun move(target: String, c: Int, t: Int): String {
        val res = StringBuilder()
        val size = target.length
        repeat(size) {
            when (it) {
                t -> res.append(target[c])
                c -> res.append(target[t])
                else -> res.append(target[it])
            }
        }
        return res.toString()
    }

    val tree = TreeMap<String, Int>()
    tree[start.toString()] = 0

    val queue: Queue<Puzzle> = LinkedList()
    queue.add(Puzzle(s / 3, s % 3, start.toString()))

    while (queue.isNotEmpty()) {
        val cx = queue.peek().cx
        val cy = queue.peek().cy
        val cur = queue.remove().cur
        val curCnt = tree.getValue(cur)

        if (cur == end) break

        repeat(4) loop@{ dir ->
            val nx = cx + dx[dir]
            val ny = cy + dy[dir]
            if ((nx < 0) or (nx >= 3) or (ny < 0) or (ny >= 3)) return@loop
            val next = move(cur, cx * 3 + cy, nx * 3 + ny)
            if (!tree.contains(next)) {
                tree[next] = curCnt + 1
                queue.add(Puzzle(nx, ny, next))
            }
        }
    }
    bw.write("${if (!tree.contains(end)) -1 else tree.getValue(end)}")
    bw.close()
}