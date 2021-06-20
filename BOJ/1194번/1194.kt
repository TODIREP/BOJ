import java.util.*
import java.io.*
class FastIo {
    private val br = System.`in`.bufferedReader()
    private val bw = System.out.bufferedWriter()
    private var token: StringTokenizer? = null
    private fun next(): String {
        while (token == null || !token!!.hasMoreElements()) {
            try {
                token = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }
        }
        return token!!.nextToken()
    }
    fun nextString() = next()
    fun nextInt() = next().toInt()
    fun nextLong() = next().toLong()
    fun nextDouble() = next().toDouble()
    fun nextLine(): String {
        val str = StringBuilder()
        try {
            str.append(br.readLine())
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return str.toString()
    }
    fun print(str: String) = bw.write(str)
    fun close() {
        br.close()
        bw.flush()
        bw.close()
    }
}
data class Position(val x: Int, val y: Int, val key: Int)
fun main() {
    val io = FastIo()
    val n = io.nextInt()
    val m = io.nextInt()
    val miro = Array(n) { IntArray(m) }
    val limit = 1e9.toInt()
    val distance = Array(n) { Array(m) { IntArray(1 shl 6) { limit } } }
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)
    val minSick: Queue<Position> = LinkedList()
    for (x in 0 until n) {
        val inputMiro = io.nextString()
        for (y in 0 until m) {
            miro[x][y] = when (inputMiro[y]) {
                in 'A'..'Z' -> inputMiro[y].toInt()
                in 'a'..'z' -> inputMiro[y].toInt()
                '#' -> -1
                '.' -> 0
                '1' -> 1
                else -> {
                    distance[x][y][0] = 0
                    minSick.add(Position(x, y, 0))
                    inputMiro[y] - '0'
                }
            }
        }
    }
    var answer = limit
    while (minSick.isNotEmpty()) {
        val (cx, cy, ckey) = minSick.poll()
        if (miro[cx][cy] == 1) {
            answer = answer.coerceAtMost(distance[cx][cy][ckey])
            continue
        }
        for (dir in 0 until 4) {
            val nx = cx + dx[dir]
            val ny = cy + dy[dir]
            var nkey = ckey
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue

            if (miro[nx][ny] == -1) continue
            if (miro[nx][ny] in 'A'.toInt()..'Z'.toInt()) {
                val check = (1 shl (miro[nx][ny] - 'A'.toInt()))
                if (nkey and check == 0) continue
            } else if (miro[nx][ny] in 'a'.toInt()..'z'.toInt()) {
                nkey = nkey or (1 shl (miro[nx][ny] - 'a'.toInt()))
            }
            if (distance[nx][ny][nkey] <= distance[cx][cy][ckey] + 1) continue
            distance[nx][ny][nkey] = distance[cx][cy][ckey] + 1
            minSick.add(Position(nx, ny, nkey))
        }
    }
    io.print("${if (answer == limit) -1 else answer}")
    io.close()
}