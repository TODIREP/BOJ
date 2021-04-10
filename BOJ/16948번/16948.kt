import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = readLine().toInt()
    val (sr, sc, er, ec) = readLine().split(" ").map(String::toInt)
    val chess = Array(n) { IntArray(n) { 500 } }
    val dx: IntArray = intArrayOf(-2, -2, 0, 0, 2, 2)
    val dy: IntArray = intArrayOf(-1, 1, -2, 2, -1, 1)
    val queue: Queue<Pair<Int, Int>> = LinkedList()

    chess[sr][sc] = 0
    queue.add(Pair(sr, sc))
    while (queue.isNotEmpty()) {
        val cur = queue.remove()

        repeat(6) loop@ { dir ->
            val nx = cur.first + dx[dir]
            val ny = cur.second + dy[dir]

            when {
                (nx < 0) or (nx >= n) or (ny < 0) or (ny >= n) -> return@loop
                chess[nx][ny] <= chess[cur.first][cur.second] + 1 -> return@loop
                else -> {
                    chess[nx][ny] = chess[cur.first][cur.second] + 1
                    queue.add(Pair(nx, ny))
                }
            }
        }
    }
    bw.write("${if (chess[er][ec] == 500) -1 else chess[er][ec]}")
    bw.close()
}
fun main() {
    solution()
}