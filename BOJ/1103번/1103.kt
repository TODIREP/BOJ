fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, m) = br.readLine().split(" ").map(String::toInt)
    val board = Array(n) { IntArray(m) }
    repeat(n) { x ->
        val input = br.readLine()
        repeat(m) { y ->
            when (input[y]) {
                in '0'..'9' -> board[x][y] = input[y] - '0'
                'H' -> board[x][y] = 0
            }
        }
    }
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)
    val distance = Array(n) { IntArray(m) { -1 } }
    val visit = Array(n) { BooleanArray(m) { false } }
    fun search(cx: Int, cy: Int): Int {
        repeat(4) { dir ->
            val nx = cx + dx[dir] * board[cx][cy]
            val ny = cy + dy[dir] * board[cx][cy]
            distance[cx][cy] = distance[cx][cy].coerceAtLeast(
                when {
                    (nx < 0) or (nx >= n) or (ny < 0) or (ny >= m) -> 1
                    board[nx][ny] == 0 -> 1
                    visit[nx][ny] -> return -1
                    distance[nx][ny] != -1 -> distance[nx][ny] + 1
                    else -> {
                        visit[nx][ny] = true
                        val next = search(nx, ny)
                        visit[nx][ny] = false
                        if (next == -1) return -1
                        next + 1
                    }
                }
            )
        }
        return distance[cx][cy]
    }
    distance[0][0] = 0
    visit[0][0] = true
    bw.write("${search(0, 0)}")
    bw.close()
}