import java.util.*
data class Road(val x: Int, val y: Int, val corner: Int, val dir: Int)
class Solution {
    private val dx = intArrayOf(0, 1, 0, -1)
    private val dy = intArrayOf(1, 0, -1, 0)
    private val limit = 1e9.toInt()
    fun solution(board: Array<IntArray>): Int {
        val len = board.size
        val queue: Queue<Road> = LinkedList()
        val dis = Array(len) { Array(len) { Array(len * len + 1) { IntArray(4) { limit } } } }
        // 0 = 가로, 1 = 세로
        dis[0][0][0][0] = 0
        dis[0][0][0][1] = 0
        queue.add(Road(0, 0, 0, 0))
        queue.add(Road(0, 0, 0, 1))
        
        while (queue.isNotEmpty()) {
            val cx = queue.peek().x
            val cy = queue.peek().y
            val cc = queue.peek().corner
            val cd = queue.remove().dir
            
            if (cx == len - 1 && cy == len - 1) continue
            for (dir in 0 until 4) {
                val nx = cx + dx[dir]
                val ny = cy + dy[dir]
                val nc = cc + if (dir % 2 != cd % 2) 1 else 0
                val next = dis[cx][cy][cc][cd] + 1
                if (nx < 0 || nx >= len || ny < 0 || ny >= len || nc > len * len) continue
                if (board[nx][ny] == 1) continue
                if (dis[nx][ny][nc][dir] <= next) continue
                dis[nx][ny][nc][dir] = next
                queue.add(Road(nx, ny, nc, dir))
            }
        }
        var answer = limit
        for (it in 0..(len*len)) {
            for (dir in 0 until 4) {
                if (dis[len - 1][len - 1][it][dir] != limit) {
                    answer = answer.coerceAtMost(dis[len - 1][len - 1][it][dir] * 100 + it * 500)
                }
            }
        }
        return answer
    }
}