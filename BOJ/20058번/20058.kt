import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.math.pow

fun rotate(size: Int, segment: Int, target: Array<IntArray>): Array<IntArray> {
    val res = Array(size) { IntArray(size) }
    for (x in 0 until size step (segment)) {
        for (y in 0 until size step (segment)) {
            repeat(segment) { p ->
                repeat(segment) { q ->
                    res[x + p][y + q] = target[x + segment - q - 1][y + p]
                }
            }
        }
    }
    return res
}

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, q) = readLine().split(" ").map(String::toInt)
    val size = (2.0).pow(n).toInt()
    var ice = Array(size) { IntArray(size) }
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)
    repeat(size) { x -> ice[x] = readLine().split(" ").map(String::toInt).toIntArray() }
    fun check() {
        val target = mutableListOf<Pair<Int, Int>>()
        repeat(size) { x ->
            repeat(size) { y ->
                var cnt = 0
                repeat(4) { dir ->
                    val nx = x + dx[dir]
                    val ny = y + dy[dir]
                    if ((nx >= 0) and (nx < size) and (ny >= 0) and (ny < size)) {
                        if (ice[nx][ny] > 0) cnt++
                    }
                }
                if (cnt < 3) target.add(Pair(x, y))
            }
        }
        target.forEach {
            if (ice[it.first][it.second] > 0) ice[it.first][it.second]--
        }
    }
    readLine().split(" ").map(String::toInt).toIntArray().forEach {
        val segmentSize = (2.0).pow(it).toInt()
        ice = rotate(size, segmentSize, ice)
        check()
    }
    var sum = 0
    repeat(size) { sum += ice[it].sum() }
    var large = 0
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    repeat(size) { x ->
        repeat(size) { y ->
            if (ice[x][y] != 0) {
                queue.add(Pair(x, y))
                ice[x][y] = 0
                var cnt = 1
                while (queue.isNotEmpty()) {
                    val cx = queue.peek().first
                    val cy = queue.remove().second
                    repeat(4) { dir ->
                        val nx = cx + dx[dir]
                        val ny = cy + dy[dir]
                        if ((nx >= 0) and (nx < size) and (ny >= 0) and (ny < size)) {
                            if (ice[nx][ny] != 0) {
                                ice[nx][ny] = 0
                                cnt++
                                queue.add(Pair(nx, ny))
                            }
                        }
                    }
                }
                large = large.coerceAtLeast(cnt)
            }
        }
    }
    bw.write("$sum\n$large")
    bw.close()
}

fun main() {
    solution()
}