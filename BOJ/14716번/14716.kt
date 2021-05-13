import java.util.*
fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    var token = StringTokenizer(readLine())
    val m = token.nextToken().toInt()
    val n = token.nextToken().toInt()
    val banner = Array(m) { IntArray(n) }
    for (x in 0 until m) {
        token = StringTokenizer(readLine())
        for (y in 0 until n) banner[x][y] = token.nextToken().toInt()
    }
    var answer = 0
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    for (x in 0 until m) for (y in 0 until n) {
        if (banner[x][y] == 1) {
            banner[x][y] = 0
            answer++
            queue.add(Pair(x, y))

            while (queue.isNotEmpty()) {
                val cx = queue.peek().first
                val cy = queue.remove().second

                for (dx in -1..1) for (dy in -1..1) {
                    val nx = cx + dx
                    val ny = cy + dy
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue
                    if (banner[nx][ny] == 0) continue
                    banner[nx][ny] = 0
                    queue.add(Pair(nx, ny))
                }
            }
        }
    }
    bw.write("$answer")
    bw.close()
}