import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

data class Node(val a: Int, val b: Int, val dis: Int)

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, m) = readLine().split(" ").map(String::toInt)
    val world = Array(n) { BooleanArray(n) { true } }
    val robot = mutableListOf<Pair<Int, Int>>()
    robot.add(Pair(0, 0))
    repeat(n) { x ->
        val input = readLine()
        repeat(n) { y ->
            when {
                input[y] == '1' -> world[x][y] = false
                input[y] == 'S' -> {
                    robot[0] = Pair(x, y)
                }
                input[y] == 'K' -> robot.add(Pair(x, y))
            }
        }
    }
    fun getDistance(start: Pair<Int, Int>): Array<IntArray> {
        val dis = Array(n) { IntArray(n) { 30000 } }
        val dx = intArrayOf(1, 0, -1, 0)
        val dy = intArrayOf(0, 1, 0, -1)
        val queue: Queue<Pair<Int, Int>> = LinkedList()
        dis[start.first][start.second] = 0
        queue.add(start)

        while (queue.isNotEmpty()) {
            val cx = queue.peek().first
            val cy = queue.remove().second

            repeat(4) loop@{ index ->
                val nx = cx + dx[index]
                val ny = cy + dy[index]

                if ((nx < 0) or (nx >= n) or (ny < 0) or (ny >= n)) return@loop
                if (!world[nx][ny] or (dis[nx][ny] <= dis[cx][cy] + 1)) return@loop
                dis[nx][ny] = dis[cx][cy] + 1
                queue.add(Pair(nx, ny))
            }
        }
        return dis
    }

    val root = IntArray(m + 1) { -1 }
    fun findRoot(r: Int): Int {
        return when {
            root[r] < 0 -> r
            else -> {
                root[r] = findRoot(root[r])
                root[r]
            }
        }
    }

    fun unionRoot(a: Int, b: Int): Boolean {
        val aRoot = findRoot(a)
        val bRoot = findRoot(b)
        if (aRoot == bRoot) return false
        root[bRoot] = aRoot
        return true
    }

    val link = mutableListOf<Node>()
    var move = 0
    robot.forEachIndexed { index, robo ->
        val reach = getDistance(robo)
        for (next in index + 1 until m + 1) {
            val nextDis = reach[robot[next].first][robot[next].second]
            if (nextDis != 30000) link.add(Node(index, next, nextDis))
        }
        if ((index == 0) and (link.size > 0)) {
            val connect = link.sortedBy { it.dis }[0]
            unionRoot(connect.a, connect.b)
            move = connect.dis
        }
    }

    link.sortedBy { it.dis }.forEach {
        if (unionRoot(it.a, it.b)) {
            move += it.dis
        }
    }
    var valid = 0
    repeat(m + 1) {
        if (root[it] == -1) valid++
    }
    bw.write("${if (valid == 1) move else -1}")
    bw.close()
}

fun main() {
    solution()
}