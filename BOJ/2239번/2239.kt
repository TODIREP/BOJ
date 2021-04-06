import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = 9
    val sudoku = Array(n) { IntArray(n) { 0 } }
    val rowSudoku = Array(n) { BooleanArray(n + 1) { false } }
    val colSudoku = Array(n) { BooleanArray(n + 1) { false } }
    val sqrSudoKu = Array(n) { BooleanArray(n + 1) { false } }

    fun getIndex(x: Int, y: Int): Int {
        when {
            (x >= 6) -> return when {
                (y >= 6) -> 8
                (y >= 3) -> 7
                else -> 6
            }
            (x >= 3) -> return when {
                (y >= 6) -> 5
                (y >= 3) -> 4
                else -> 3
            }
            else -> return when {
                (y >= 6) -> 2
                (y >= 3) -> 1
                else -> 0
            }
        }
    }

    repeat(n) { x ->
        val input = readLine()
        repeat(n) { y ->
            sudoku[x][y] = input[y] - '0'
            if (sudoku[x][y] > 0) {
                rowSudoku[x][sudoku[x][y]] = true
                colSudoku[y][sudoku[x][y]] = true
                sqrSudoKu[getIndex(x, y)][sudoku[x][y]] = true
            }
        }
    }

    fun search(x: Int, y: Int): Boolean {
        var cx = x
        var cy = y

        if (cy >= n) {
            cy = 0
            cx++
        }

        if (cx >= n) {
            return true
        }
        if (sudoku[cx][cy] != 0) return search(cx, cy + 1)

        for (num in 1 until n + 1) {
            val sqrIndex = getIndex(cx, cy)
            if (rowSudoku[cx][num] or colSudoku[cy][num] or sqrSudoKu[sqrIndex][num]) continue
            rowSudoku[cx][num] = true
            colSudoku[cy][num] = true
            sqrSudoKu[sqrIndex][num] = true
            sudoku[cx][cy] = num
            if (search(cx, cy + 1)) return true
            rowSudoku[cx][num] = false
            colSudoku[cy][num] = false
            sqrSudoKu[sqrIndex][num] = false
            sudoku[cx][cy] = 0
        }
        return false
    }
    search(0, 0)

    repeat(n) { x ->
        repeat(n) { y ->
            bw.write("${sudoku[x][y]}")
        }
        bw.write("\n")
    }
    bw.close()
}
fun main() {
    solution()
}