import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    val (r, c) = readLine().split(" ").map { it.toInt() }
    val word = Array(r) { CharArray(c) }

    for (x in 0 until r) {
        word[x] = readLine().toCharArray()
    }

    var answer = 0
    val check = BooleanArray(26)
    val dx = listOf(1, 0, -1, 0)
    val dy = listOf(0, 1, 0, -1)

    fun search(sx: Int, sy: Int, count: Int) {
        answer = if (count > answer) count else answer
        check[word[sx][sy] - 'A'] = true

        for (dir in 0 until 4) {
            val nx = sx + dx[dir]
            val ny = sy + dy[dir]

            when {
                (nx < 0) or (nx >= r) or (ny < 0) or (ny >= c) -> continue
                check[word[nx][ny] - 'A'] -> continue
                else -> {
                    search(nx, ny, count + 1)
                    check[word[nx][ny] - 'A'] = false
                }
            }
        }
    }
    search(0, 0, 1)

    bufferedWriter.write(answer.toString())
    bufferedWriter.close()
}

fun main() {
    solution()
}