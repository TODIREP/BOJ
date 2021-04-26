import java.util.*
data class Node(val x: Int, val y: Int, val dis: Int)
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readLine().toInt()
    val world = Array(1001) { IntArray(1001) }
    val limit = 1e9.toInt()
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)
    repeat(t) {
        val (w, h) = br.readLine().split(" ").map(String::toInt)
        fun range(x: Int, y: Int): Boolean { return (x < 0) or (x >= h) or (y < 0) or (y >= w) }
        var answer = limit
        val person: Queue<Node> = LinkedList()
        val bool: Queue<Node> = LinkedList()
        for (x in 0 until h) {
            val map = br.readLine()
            for (y in 0 until w) {
                world[x][y] = when (map[y]) {
                    '#' -> -2
                    '@' -> {
                        person.add(Node(x, y, 0))
                        0
                    }
                    '*' -> {
                        bool.add(Node(x, y, 0))
                        -1
                    }
                    else -> 0
                }
            }
        }
        while (bool.isNotEmpty()) {
            val (cx, cy, cd) = bool.remove()
            for (dir in 0 until 4) {
                val (nx, ny, nd) = intArrayOf(cx + dx[dir], cy + dy[dir], cd + 1)
                if (range(nx, ny)) continue
                if (world[nx][ny] != 0 && world[nx][ny] <= nd) continue
                world[nx][ny] = nd
                bool.add(Node(nx, ny, nd))
            }
        }
        while (person.isNotEmpty()) {
            val (cx, cy, cd) = person.remove()
            for (dir in 0 until 4) {
                val (nx, ny, nd) = intArrayOf(cx + dx[dir], cy + dy[dir], cd + 1)
                if (range(nx, ny)) {
                    answer = answer.coerceAtMost(nd)
                    continue
                }
                if (world[nx][ny] != 0 && world[nx][ny] <= nd) continue
                world[nx][ny] = nd
                person.add(Node(nx, ny, nd))
            }
        }

        bw.write(
            if (answer == limit) "IMPOSSIBLE\n"
            else "$answer\n"
        )
    }
    bw.close()
}