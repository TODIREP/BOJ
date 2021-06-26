import java.io.IOException
import java.util.*

fun main() {
    val io = FastIo()
    val (n, m) = io.nextInt() to io.nextInt()
    val light = Array(n) { io.nextString().map { if (it == '\\') 0 else 1 } }
    val turn = Array(n) { Array(m) { IntArray(2) { 1e9.toInt() } } }
    val cross = arrayOf(
        arrayOf(1 to 1, -1 to -1),
        arrayOf(-1 to 1, 1 to -1)
    )
    val line = ArrayDeque<SunYeong>()
    turn[0][0][0] = when (light[0][0] == 1) {
        true -> 1
        false -> 0
    }
    line.offerLast(SunYeong(0, 0, 0))

    while (line.isNotEmpty()) {
        val (cx, cy, ct) = line.pollFirst()

        if (cx == n - 1 && cy == m - 1) break
        arrayOf(
            cx + 1 to cy,
            cx to cy + 1,
            cx - 1 to cy,
            cx to cy - 1
        ).forEach loop@{
            val (nx, ny) = it
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) return@loop
            val nt = (ct + 1) % 2
            when (ct == light[nx][ny]) {
                true -> {
                    if (turn[nx][ny][nt] <= turn[cx][cy][ct] + 1) return@loop
                    turn[nx][ny][nt] = turn[cx][cy][ct] + 1
                    line.offerLast(SunYeong(nx, ny, nt))
                }
                false -> {
                    if (turn[nx][ny][nt] <= turn[cx][cy][ct]) return@loop
                    turn[nx][ny][nt] = turn[cx][cy][ct]
                    line.offerFirst(SunYeong(nx, ny, nt))
                }
            }
        }
        cross[ct].forEach loop@{
            val (nx, ny) = (cx + it.first to cy + it.second)
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) return@loop
            when (ct == light[nx][ny]) {
                true -> {
                    if (turn[nx][ny][ct] <= turn[cx][cy][ct]) return@loop
                    turn[nx][ny][ct] = turn[cx][cy][ct]
                    line.offerFirst(SunYeong(nx, ny, ct))
                }
                false -> {
                    if (turn[nx][ny][ct] <= turn[cx][cy][ct] + 1) return@loop
                    turn[nx][ny][ct] = turn[cx][cy][ct] + 1
                    line.offerLast(SunYeong(nx, ny, ct))
                }
            }
        }
    }
    io.print(
        when (turn[n - 1][m - 1][0] == 1e9.toInt()) {
            true -> "NO SOLUTION"
            false -> "${turn[n - 1][m - 1][0]}"
        }
    )
    io.close()
}

data class SunYeong(val x: Int, val y: Int, val status: Int)
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