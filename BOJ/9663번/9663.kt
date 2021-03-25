import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    val n = readLine().toInt()
    val checkVertical = BooleanArray(n) // index : y
    val checkLeftCross = BooleanArray(n * 2 - 1) // index : y - x + n - 1
    val checkRightCross = BooleanArray(n * 2 - 1) // index : x + y

    var answer = 0
    fun search(x: Int) {
        if (x >= n) {
            answer++
            return
        }
        for (y in 0 until n) {
            when {
                checkVertical[y] -> continue
                checkLeftCross[y - x + n - 1] -> continue
                checkRightCross[x + y] -> continue
                else -> {
                    checkVertical[y] = true
                    checkLeftCross[y - x + n - 1] = true
                    checkRightCross[x + y] = true
                    search(x + 1)
                    checkVertical[y] = false
                    checkLeftCross[y - x + n - 1] = false
                    checkRightCross[x + y] = false
                }
            }
        }
    }
    search(0)

    bufferedWriter.write("$answer")
    bufferedWriter.close()
}

fun main() {
    solution()
}