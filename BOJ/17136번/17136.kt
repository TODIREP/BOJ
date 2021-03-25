import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

const val n = 10
val paper = Array(n) { BooleanArray(n) }
var answer = 2000
val count = IntArray(6) { 0 }

fun isInvalidPaper(sx: Int, sy: Int, size: Int): Boolean {
    for (x in sx until sx + size) {
        for (y in sy until sy + size) {
            if (!paper[x][y]) {
                return true
            }
        }
    }
    return false
}

fun attachPaper(sx: Int, sy: Int, size: Int, isAttach: Boolean) {
    for (x in sx until sx + size) {
        for (y in sy until sy + size) {
            paper[x][y] = isAttach
        }
    }
}

fun search(cnt: Int) {
    var x = -1
    var y = -1
    var found = false

    for (p in 0 until n) {
        for (q in 0 until n) {
            if (paper[p][q]) {
                found = true
                x = p
                y = q
                break
            }
        }
        if (found) break
    }

    if (!found) {
        answer = if (answer > cnt) cnt else answer
        return
    }
    if (answer <= cnt) return

    for (size in 5 downTo 1) {
        if ((x + size > n) or (y + size > n) or (count[size] == 5)) continue
        if (isInvalidPaper(x, y, size)) continue

        attachPaper(x, y, size, false)
        count[size]++
        search(cnt + 1)
        attachPaper(x, y, size, true)
        count[size]--
    }
}

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    for (i in 0 until n) {
        val token = StringTokenizer(readLine())
        for (x in 0 until n) {
            paper[i][x] = (token.nextToken().toInt() == 1)
        }
    }
    search(0)

    bufferedWriter.write("${if (answer == 2000) -1 else answer}")
    bufferedWriter.close()
}

fun main() {
    solution()
}